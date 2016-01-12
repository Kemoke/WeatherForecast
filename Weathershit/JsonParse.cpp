#include "stdafx.h"

string SendRequest(wstring args)
{
	wstring_convert<codecvt_utf8_utf16<wchar_t>> convert;//konvertor iz wstringa u string i obrnuto
	wstring query = L"http://api.openweathermap.org/data/2.5/" + args + L"&APPID=" + APIKEY;//formatiranje adrese upita
	WinHttpClient client(query);//pravi klijent za konekciju na openweather api
	client.SendHttpRequest();//salje upit
	wstring response = client.GetResponseContent();//kupi JSON odgovor u wstring
	return convert.to_bytes(response);//vraca json konvertovan u string iz wstringa
}

WeatherInfo ParseDaily(string data)
{
	WeatherInfo weather;
	Value root;
	Reader reader;
	reader.parse(data, root, false);
	weather.cityName = root["city"]["name"].asString();
	for (auto list : root["list"])
	{
		static Weather temp_list;
		temp_list.date = list["dt"].asString();
		temp_list.tempDay = list["temp"]["day"].asDouble() - 273.15;
		temp_list.tempMin = list["temp"]["min"].asDouble() - 273.15;
		temp_list.tempMax = list["temp"]["max"].asDouble() - 273.15;
		temp_list.tempNight = list["temp"]["night"].asDouble() - 273.15;
		temp_list.main = list["weather"][0]["main"].asString();
		temp_list.cloudiness = list["clouds"].asDouble();
		temp_list.windSpeed = list["speed"].asDouble();
		temp_list.ResolveDate();
		weather.weather.push_back(temp_list);
	}
	return weather;
}

WeatherInfo ParseFiveDay(string data)
{
	WeatherInfo weather;//klasa za vrijeme
	Value root;
	Reader reader;
	reader.parse(data, root, false);
	weather.cityName = root["city"]["name"].asString();
	for (auto list : root["list"])//za svaki element koji se nalazi u listi u jsonu napravi element i ubaci u klasu za vrijeme
	{
		static Weather temp_list;
		temp_list.temp = list["main"]["temp"].asDouble() - 273.15;
		temp_list.tempMin = list["main"]["temp_min"].asDouble() - 273.15;
		temp_list.tempMax = list["main"]["temp_max"].asDouble() - 273.15;
		temp_list.main = list["weather"][0]["main"].asString();
		temp_list.cloudiness = list["clouds"]["all"].asInt();
		temp_list.windSpeed = list["wind"]["speed"].asDouble();
		temp_list.date = list["dt"].asString();
		temp_list.ResolveDateTime();
		weather.weather.push_back(temp_list);
	}
	return weather;
}

WeatherInfo ParseCurrent(string data)
{
	WeatherInfo weather;
	Weather temp_list;
	Value root;
	Reader reader;
	reader.parse(data, root, false);
	temp_list.main = root["weather"][0]["main"].asString();
	temp_list.temp = root["main"]["temp"].asDouble() - 273.15;
	temp_list.tempMin = root["main"]["temp_min"].asDouble() - 273.15;
	temp_list.tempMax = root["main"]["temp_max"].asDouble() - 273.15;
	temp_list.windSpeed = root["wind"]["speed"].asDouble();
	temp_list.cloudiness = root["clouds"]["all"].asInt();
	weather.weather.push_back(temp_list);
	weather.cityName = root["name"].asString();
	return weather;
}