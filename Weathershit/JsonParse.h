#pragma once
///<summary>
/// Salje zahtjev za prognozu na openweather api
///</summary>
///<param name="args">Argumenti</param>
string SendRequest(wstring args);
///<summary>
/// Ubacuje iz JSON-a podatke u vremensku klasu za 5 dana
///</summary>
///<param name="data">String koji vraca SendRequest funkcija</param>
WeatherInfo ParseFiveDay(string data);
///<summary>
/// Ubacuje iz JSON-a podatke u vremensku klasu za danasnji dan
///</summary>
///<param name="data">String koji vraca SendRequest funkcija</param>
WeatherInfo ParseCurrent(string data);
WeatherInfo ParseDaily(string data);