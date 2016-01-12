#pragma once
///<summary>
/// Clean text input
///</summary>
///<param name="city">City string</param>
void Input(wstring& city);
///<summary>
/// Centrira string i odvaja po poziciji
///</summary>
///<param name="item">String value</param>
///<param name="i">Pozicija stringa</param>
void Center(string item, int i);
///<summary>
/// Centrira text zadane duzine
///</summary>
///<param name="length">Duzina texta</param>
void Center(int length);
///<summary>
/// Centrira text zadane duzine na obje ose
///</summary>
///<param name="length">Duzina texta</param>
///<param name="y">Staviti true da centrira i po y osi</param>
void Center(int length, bool y);
///<summary>
/// Centrira text zadane duzine sa razmakom od dna konzole
///</summary>
///<param name="length">Duzina texta</param>
///<param name="yOffset">Broj linija po y osi od dna konzole</param>
void Center(int length, int yOffset);
///<summary>
/// Krije cursor u konzoli
///</summary>
void HideCursor();
///<summary>
/// Pokazuje cursor u konzoli
///</summary>
void ShowCursor();
///<summary>
/// Cisti ekran u konzoli
///</summary>
void cls();
///<summary>
/// Uzima trenutne koordinate cursora
///</summary>
COORD getCursorPos();
void ResizeWindow(int width, int height);
wstring NumInput();