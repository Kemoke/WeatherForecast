#include "stdafx.h"

HANDLE ConsoleH = GetStdHandle(STD_OUTPUT_HANDLE);//uzima handle konzole
COORD cursorPos = {0,0};//init. poziciju kursora
chrono::milliseconds span(100);
CONSOLE_SCREEN_BUFFER_INFO csbi;

//Funkcija za prikaz trenutnog vremena
void CurrentWeather(wstring city)
{
	WeatherInfo weather;
	auto result(async(SendRequest, L"weather?q=" + city));//future kupi return iz funkcije da ga mogu posle iskoristiti
	cls();
	Center(16, true); cout << "Fetching data";
	cursorPos = getCursorPos();
	for (int i = 0; result.wait_for(span) != future_status::ready; i++)
	{
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		switch (i % 4)
		{
			case 0:
				cout << "   ";
				break;
			case 1:
				cout << ".  ";
				break;
			case 2:
				cout << ".. ";
				break;
			case 3:
				cout << "...";
		}
		if (i > 50)
		{
			Center(16, true);
			cout << "  Fetch failed  ";
			SetConsoleTextAttribute(ConsoleH, 240);
			Center(4, 4);
			cout << "Back";
			SetConsoleTextAttribute(ConsoleH, 15);
			while (_getch() != 13);
			return;
		}
	}
	weather = ParseCurrent(result.get());
	if (weather.cityName.size() < 1)
	{
		Center(16, true);
		cout << "  Fetch failed  ";
		SetConsoleTextAttribute(ConsoleH, 240);
		Center(4, 4);
		cout << "Back";
		SetConsoleTextAttribute(ConsoleH, 15);
		while (_getch() != 13);
		return;
	}
	cls();
	Center(19 + city.size()); cout << "Current Weather in " << weather.cityName << "\n";
	Center(38); PrintNow(); PrintNum(static_cast<int>(weather.weather[0].temp)); cout << endl;
	Center(26); cout << "Max temp: " << weather.weather[0].tempMax << "  Min temp: " << weather.weather[0].tempMin << "\n\n\n";
	Center(19); cout << "Weather: " << weather.weather[0].main << endl;
	Center(19); cout << "Cloudiness: " << weather.weather[0].cloudiness << "%" << endl;
	Center(19); cout << "Wind speed: " << weather.weather[0].windSpeed << " m/s" << endl;
	SetConsoleTextAttribute(ConsoleH, 240);
	Center(4, 4);
	cout << "Back";
	SetConsoleTextAttribute(ConsoleH, 15);
	while (_getch() != 13);
}

void PrintWeather(Weather weather, string city)
{
	cls();
	Center(21 + city.size()); cout << "Weather at " << weather.date << " in " << city << "\n";
	Center(15); PrintNum(static_cast<int>(weather.temp)); cout << endl;
	Center(26); cout << "Max temp: " << weather.tempMax << "  Min temp: " << weather.tempMin << "\n\n\n";
	Center(19); cout << "Weather: " << weather.main << endl;
	Center(19); cout << "Cloudiness: " << weather.cloudiness << "%" << endl;
	Center(19); cout << "Wind speed: " << weather.windSpeed << " m/s" << endl;
	SetConsoleTextAttribute(ConsoleH, 240);
	Center(4, 4);
	cout << "Back";
	SetConsoleTextAttribute(ConsoleH, 15);
	while (_getch() != 13);
}

void FiveDayForecast(wstring city)
{
	WeatherInfo weather;
	Weather weatherI;
	auto result(async(SendRequest, L"forecast?q=" + city));
	cls();
	Center(16, true); cout << "Fetching data";
	cursorPos = getCursorPos();
	for (int i = 0; result.wait_for(span) != future_status::ready; i++)
	{
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		switch (i % 4)
		{
		case 0:
			cout << "   ";
			break;
		case 1:
			cout << ".  ";
			break;
		case 2:
			cout << ".. ";
			break;
		case 3:
			cout << "...";
		}
		if (i > 50)
		{
			Center(16, true);
			cout << "  Fetch failed  ";
			SetConsoleTextAttribute(ConsoleH, 240);
			Center(4, 4);
			cout << "Back";
			SetConsoleTextAttribute(ConsoleH, 15);
			while (_getch() != 13);
			return;
		}
	}
	weather = ParseFiveDay(result.get());
	if (weather.cityName.size() < 1)
	{
		Center(16, true);
		cout << "  Fetch failed  ";
		SetConsoleTextAttribute(ConsoleH, 240);
		Center(4, 4);
		cout << "Back";
		SetConsoleTextAttribute(ConsoleH, 15);
		while (_getch() != 13);
		return;
	}
	int choice;
	for (;;)
	{
		choice = WeatherList(weather);
		if (choice != weather.ToDateTimeList().size())
		{
			weatherI = TimeList(weather.ToDateTimeList()[choice], weather.cityName);
			if (weatherI.main != "back")
				PrintWeather(weatherI, weather.cityName);
		}
		else break;
	}
}

void PrintDaily(Weather weather, string city)
{
	cls();
	Center(21 + city.size()); cout << "Weather at " << weather.date << " in " << city << "\n\n";
	Center(26); cout << "Day temp: " << weather.tempDay << "  Night temp: " << weather.tempNight << endl;
	Center(26); cout << "Max temp: " << weather.tempMax << "  Min temp: " << weather.tempMin << "\n\n\n";
	Center(19); cout << "Weather: " << weather.main << endl;
	Center(19); cout << "Cloudiness: " << weather.cloudiness << "%" << endl;
	Center(19); cout << "Wind speed: " << weather.windSpeed << " m/s" << endl;
	SetConsoleTextAttribute(ConsoleH, 240);
	Center(4, 4);
	cout << "Back";
	SetConsoleTextAttribute(ConsoleH, 15);
	while (_getch() != 13);
}

void DailyForecast(wstring city)
{
	WeatherInfo weather;
	int c = 0;
	ShowCursor();
	while (c < 1 || c > 16)
	{
		cls();
		Center(32, true); cout << "Input number of days to show(1-16): ";
		string temp;
		cin >> temp;
		if (!((temp[0] < 48 || temp[0] > 57) && (temp[1] < 48 || temp[0] > 57)))
			c = stoi(temp.substr(0,2));
	}
	HideCursor();
	wchar_t count[3];
	_itow_s(c, count, 10);
	auto result(async(SendRequest, L"forecast/daily?q=" + city + L"&cnt=" + count));
	cls();
	Center(16, true); cout << "Fetching data";
	cursorPos = getCursorPos();
	for (int i = 0; result.wait_for(span) != future_status::ready; i++)
	{
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		switch (i % 4)
		{
		case 0:
			cout << "   ";
			break;
		case 1:
			cout << ".  ";
			break;
		case 2:
			cout << ".. ";
			break;
		case 3:
			cout << "...";
		}
		if (i > 50)
		{
			Center(16, true);
			cout << "  Fetch failed  ";
			SetConsoleTextAttribute(ConsoleH, 240);
			Center(4, 4);
			cout << "Back";
			SetConsoleTextAttribute(ConsoleH, 15);
			while (_getch() != 13);
			return;
		}
	}
	weather = ParseDaily(result.get());
	auto weatherI = DayMenu(weather);
	if (weatherI.main == "back")
		return;
	PrintDaily(weatherI, weather.cityName);
}

int main()
{
	ResizeWindow(800, 600);
	SetConsoleTitle(TEXT("Weather Forecast"));
	HideCursor();
	PrintTitle();
	bool quit;
	for (;;)
	{
		wstring city;
		switch (InitMenu())
		{
			case 0:

				quit = false;
				cls();
				Center(25, true); cout << "Enter city name: ";
				ShowCursor();
				while (city.size() == 0)
					Input(city);
				HideCursor();
				while (!quit)
					switch (MainMenu())
					{
						case 0:
							CurrentWeather(city);
							break;
						case 1:
							FiveDayForecast(city);
							break;
						case 2:
							DailyForecast(city);
							break;
						case 3:
							quit = true;
					}
				break;
			case 1:
				return 0;
		}
	}
}

