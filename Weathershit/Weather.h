#pragma once

class Weather
{
public:
	string main;
	string date;
	double temp;
	double tempMin;
	double tempMax;
	double tempDay;
	double tempNight;
	double windSpeed;
	double cloudiness;
	void ResolveDate()
	{
		const time_t dateTemp = stoi(date);
		struct tm time;
		localtime_s(&time, &dateTemp);
		char d[20];
		strftime(d, 20, "%d.%m.%Y", &time);
		date = d;
	}
	void ResolveDateTime()
	{
		const time_t dateTemp = stoi(date);
		struct tm time;
		localtime_s(&time, &dateTemp);
		char d[20];
		strftime(d, 20, "%d.%m.%Y %R", &time);
		date = d;
	}
};

class DateTimeList
{
public:
	string date;
	string cityName;
	vector<Weather> weather;
};

class WeatherInfo
{
public:
	string cityName;
	vector<Weather> weather;
	vector<DateTimeList> ToDateTimeList()
	{
		vector<DateTimeList> dtList;
		string temp;
		for (int i = 0; i < weather.size();)
		{
			DateTimeList tempList;
			tempList.cityName = cityName;
			if (temp != weather[i].date.substr(0, 10))
			{
				tempList.date = weather[i].date.substr(0, 10);
				temp = weather[i].date.substr(0, 10);
			}
			while(temp == weather[i].date.substr(0, 10))
			{
				Weather tempWeather = weather[i];
				tempWeather.date = tempWeather.date.substr(11, 9);
				tempList.weather.push_back(tempWeather);
				i++; if (i >= weather.size()) break;
			}
			dtList.push_back(tempList);
		}
		return dtList;
	}
};