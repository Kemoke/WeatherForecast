#pragma once
///<summary>
/// Meni za izabir izmedju trenutnog vremena i 5 dan prognoze
///</summary>
int MainMenu();
///<summary>
/// Prvi meni koji se otvori
///</summary>
int InitMenu();
///<summary>
/// Meni za izabir datuma
///</summary>
///<param name="args">Klasa za vrijeme formatirana preko json funckija</param>
int WeatherList(WeatherInfo weather);
///<summary>
/// Meni za izabir vremena
///</summary>
///<param name="args">Klasa za vrijeme formatirana preko json funckija</param>
///<param name="choice">Odabir koji vraca funckija za datum</param>
Weather TimeList(DateTimeList weather, string city);
Weather DayMenu(WeatherInfo weather);