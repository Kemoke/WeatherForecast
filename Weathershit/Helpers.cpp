#include "stdafx.h"
CONSOLE_SCREEN_BUFFER_INFO temp;
//Funckija za ciscenje unosa (wchar_t je isto sto i char samo podrzava vise znakova da ne bi program crashao)
wchar_t CleanInput(wchar_t key)
{
	if (key == 167 || key == 166)// ako je ž ili Ž ubaci z itd...
		return L'z';
	if (key == 159 || key == 134 || key == 172 || key == 143)
		return L'c';
	if (key == 231 || key == 230)
		return L's';
	if (key == 208 || key == 209)
		return L'd';
	return key;
}

void Input(wstring& city)
{
	wchar_t key = _getch();//uzima prvi znak
	while (key != 13)// dok nije pritisnut enter uzimaj znakove
	{
		if (key == 8)//ako je pritisnut backspace izbrisi 1 znak
		{
			if (city.size() > 0)//ako je broj znakova veci od 0 brisi
			{
				cursorPos = getCursorPos();//uzima trenutnu poziciju
				SetConsoleCursorPosition(ConsoleH, COORD{ cursorPos.X - 1, cursorPos.Y });//vraca kursor nazad 1 char
				cout << " ";//brise znak
				SetConsoleCursorPosition(ConsoleH, COORD{ cursorPos.X - 1, cursorPos.Y });//vraca ga nazad ponovo
				city.pop_back();// izbacuje znak iz stringa
			}
		}
		else//ubaci znak u string
		{
			city.push_back(CleanInput(key));
			wcout << CleanInput(key);//ispisuje string
		}
		key = _getch();//uzima znakove
	}
}

void Center(string item, int i)
{
	GetConsoleScreenBufferInfo(ConsoleH, &csbi);//uzima trenutne informacije o konzoli i stavlja u buffer
	auto columns = csbi.srWindow.Right + 1;//kolone = koordinata zadnjeg chara koji se moze ispisati u konzoli + 1
	auto rows = csbi.srWindow.Bottom + 1;// redovi = koordinata zadnjeg chara koji se moze ispisati na dnu konzole + 1
	csbi.dwCursorPosition.X = (columns - item.size()) / 2;//postavlja kursor udaljen pola duzine stringa od centra konzole u bufferu
	csbi.dwCursorPosition.Y = (rows / 2) - 2 + 2 * i;//postavlja kursor 2 mjesta ispod centra + 2*pozicija stringa u konzoli u bufferu
	SetConsoleCursorPosition(ConsoleH, csbi.dwCursorPosition);//na kraju stavi cursor na mjesto postavljeno u bufferu
}

void Center(int length)
{
	GetConsoleScreenBufferInfo(ConsoleH, &csbi);
	auto columns = csbi.srWindow.Right + 1;
	csbi.dwCursorPosition.X = (columns - length) / 2;
	SetConsoleCursorPosition(ConsoleH, csbi.dwCursorPosition);
}
void Center(int length, bool y)
{
	GetConsoleScreenBufferInfo(ConsoleH, &csbi);
	auto columns = csbi.srWindow.Right + 1;
	auto rows = csbi.srWindow.Bottom + 1;
	csbi.dwCursorPosition.X = (columns - length) / 2;
	csbi.dwCursorPosition.Y = (rows / 2);
	SetConsoleCursorPosition(ConsoleH, csbi.dwCursorPosition);
}

void Center(int length, int yOffset)
{
	GetConsoleScreenBufferInfo(ConsoleH, &csbi);
	auto columns = csbi.srWindow.Right + 1;
	auto rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	csbi.dwCursorPosition.X = (columns - length) / 2;
	csbi.dwCursorPosition.Y = rows - yOffset;
	SetConsoleCursorPosition(ConsoleH, csbi.dwCursorPosition);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;//buffer za informacije o kursoru
	GetConsoleCursorInfo(ConsoleH, &cursorInfo);
	cursorInfo.bVisible = false;//sakriva kursor
	SetConsoleCursorInfo(ConsoleH, &cursorInfo);
}

void ShowCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(ConsoleH, &cursorInfo);
	cursorInfo.bVisible = true;//pokazuje kursor
	SetConsoleCursorInfo(ConsoleH, &cursorInfo);
}

void cls()
{
	DWORD count;//var za broj karaktera ispisanih
	DWORD cellCount;//broj charova koji se mogu ispisati u konzoli
	COORD homeCoords = { 0, 7 };//koordinate gornjeg lijevog coska
	GetConsoleScreenBufferInfo(ConsoleH, &csbi);
	cellCount = csbi.dwSize.X * csbi.dwSize.Y-12;//broj charova = sirina po x * sirina po y
	FillConsoleOutputCharacter(ConsoleH, static_cast<TCHAR>(' '), cellCount, homeCoords, &count);//ispisuje prazne charove CellCount puta u konzolu
	FillConsoleOutputAttribute(ConsoleH, csbi.wAttributes, cellCount, homeCoords, &count);//vraca boje na staro ako su izmijenjane
	SetConsoleCursorPosition(ConsoleH, homeCoords);//vraca kursor na gornji lijevi cosak
}

COORD getCursorPos()
{
	GetConsoleScreenBufferInfo(ConsoleH, &csbi);
	return COORD{ csbi.dwCursorPosition.X , csbi.dwCursorPosition.Y };//vraca koordinate kursora
}
void ResizeWindow(int width, int height)
{
	auto console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}