#include "stdafx.h"

void PrintMenu(int choice, string menu[], int size)
{
	for (auto i = 0; i < size; i++)
	{
		if (choice == i)
			SetConsoleTextAttribute(ConsoleH, 240);//Ako je to izabrano oboji ga
		Center(menu[i], i);
		cout << menu[i];
		SetConsoleTextAttribute(ConsoleH, 15);//Ovo ostalo vrati na staru boju
	}
}

void PrintTimeMenu(int choice, vector<Weather> items)
{
	for (auto i = 0; i <= items.size(); i++)
	{
		if (choice == i)
			SetConsoleTextAttribute(ConsoleH, 240);
		if (i == items.size())
		{
			Center(4, 4); cout << "Back";
		}
		else
		{
			Center(items[i].date.size());
			cout << items[i].date << endl;
		}
		SetConsoleTextAttribute(ConsoleH, 15);
	}
}
//ispisi meni
void PrintMenu(int choice, vector<DateTimeList> items)
{
	for (int i = 0; i <= items.size(); i++)
	{
		if (choice == i)
			SetConsoleTextAttribute(ConsoleH, 240);
		if (i == items.size())
		{
			Center(4, 4); cout << "Back";
		}
		else
		{
			Center(items[i].date.size());
			cout << items[i].date << endl;
		}
		SetConsoleTextAttribute(ConsoleH, 15);
	}
}

int WeatherList(WeatherInfo weather)
{
	int choice = 0;
	int key = 0;
	cls();
	cursorPos = getCursorPos();
	while (key != 13)
	{
		if (key == 80)
			if (choice != weather.ToDateTimeList().size())
				choice++;
		if (key == 72)
			if (choice != 0)
				choice--;
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		Center(20 + weather.cityName.size()); cout << "Weather forecast for " << weather.cityName << endl;
		Center(12); cout << "Pick a date: \n\n";
		PrintMenu(choice, weather.ToDateTimeList());
		key = _getch();
	}
	return choice;
}

void PrintDayMenu(int choice,vector<Weather> items)
{
	for (auto i = 0; i <= items.size(); i++)
	{
		if (choice == i)
			SetConsoleTextAttribute(ConsoleH, 240);
		if (i == items.size())
		{
			Center(4, 4); cout << "Back";
		}
		else
		{
			Center(items[i].date.size());
			cout << items[i].date << endl;
		}
		SetConsoleTextAttribute(ConsoleH, 15);
	}
}

Weather DayMenu(WeatherInfo weather)
{
	int choice = 0;
	int key = 0;
	cls();
	cursorPos = getCursorPos();
	while (key != 13)
	{
		if (key == 80)
			if (choice != weather.weather.size())
				choice++;
		if (key == 72)
			if (choice != 0)
				choice--;
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		Center(28 + weather.cityName.size()); cout << "Weather daily forecast for " << weather.cityName << endl;
		Center(12); cout << "Pick a day: \n\n";
		PrintDayMenu(choice, weather.weather);
		key = _getch();
	}
	if (choice == weather.weather.size())
	{
		Weather w;
		w.main = "back";
		return w;
	}
	return weather.weather[choice];
}

Weather TimeList(DateTimeList weather, string city)
{
	int choice = 0;
	int key = 0;
	cls();
	cursorPos = getCursorPos();
	while (key != 13)
	{
		if (key == 80)
			if (choice != weather.weather.size())
				choice++;
		if (key == 72)
			if (choice != 0)
				choice--;
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		Center(20 + city.size()); cout << "Weather forecast for " << city << endl;
		Center(12); cout << "Pick a time: \n\n";
		PrintTimeMenu(choice, weather.weather);
		key = _getch();
	}
	if (choice == weather.weather.size())
	{
		Weather w;
		w.main = "back";
		return w;
	}
	return weather.weather.at(choice);
}

int InitMenu()
{
	int choice = 0;
	cls();
	string menu[2] = { "Enter City Name", "Quit" };
	int key = 0;
	while (key != 13)
	{
		if (key == 80)
			if (choice != 1)
				choice++;
		if (key == 72)
			if (choice != 0)
				choice--;
		PrintMenu(choice, menu, 2);
		key = _getch();
	}
	return choice;
}

int MainMenu()
{
	cls();
	int choice = 0;
	string menu[4] = { "Current weather", "Five day (3 hour interval) forecast", "Daily forecast", "Back" };
	int key = 0;
	while (key != 13)//dok nije enter pritisnut drzi meni otvoren
	{
		if (key == 80)// ako je pritisnuta strelica dolje povecaj izbor
			if (choice != 3)
				choice++;
		if (key == 72)// ako je pritisnuta strelica gore smanji izbor
			if (choice != 0)
				choice--;
		PrintMenu(choice, menu, 4);
		key = _getch();
	}
	return choice;
}