#include "stdafx.h"

COORD endPos;

void PrintTitle()
{
	Center(82); cout << " __          __        _   _                 ______                           _   \n";
	Center(82); cout << " \\ \\        / /       | | | |               |  ____|                         | |  \n";
	Center(82); cout << "  \\ \\  /\\  / /__  __ _| |_| |__   ___ _ __  | |__ ___  _ __ ___  ___ __ _ ___| |_ \n";
	Center(82); cout << "   \\ \\/  \\/ / _ \\/ _` | __| '_ \\ / _ \\ '__| |  __/ _ \\| '__/ _ \\/ __/ _` / __| __|\n";
	Center(82); cout << "    \\  /\\  /  __/ (_| | |_| | | |  __/ |    | | | (_) | | |  __/ (_| (_| \\__ \\ |_ \n";
	Center(82); cout << "     \\/  \\/ \\___|\\__,_|\\__|_| |_|\\___|_|    |_|  \\___/|_|  \\___|\\___\\__,_|___/\\__|\n";
	cout << "\n\n";
}
void PrintNow()
{
	auto initPos = getCursorPos();
	cout << " _   _  ______          __    ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "| \\ | |/ __ \\ \\        / /  _ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << "|  \\| | |  | \\ \\  /\\  / /  (_)";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "| . ` | |  | |\\ \\/  \\/ /      ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "| |\\  | |__| | \\  /\\  /     _ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "|_| \\_|\\____/   \\/  \\/     (_)";
	SetConsoleCursorPosition(ConsoleH, cursorPos);
}
void Num0()
{
	auto initPos = getCursorPos();
	cout << "   ___  ";
	
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "  / _ \\ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << " | | | |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << " | | | |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << " | |_| |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "  \\___/ ";
	endPos = getCursorPos();
}
void Num1()
{
	COORD initPos = getCursorPos();//uzima trenutnu poziciju kursora
	cout << "   __   ";//ispisuje prvu liniju
	cursorPos = getCursorPos();//ubacuje u globalnu varijablu poziciju zadnjeg chara ispisanog da bi ostali brojevi radili
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });//postavlja kursor 1 liniju ispod pocetne pozicije
	cout << "  /_ |  ";//ispisuje drugu liniju...
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });//2 linije ispod...
	cout << "   | |  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "   | |  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "   | |  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "   |_|  ";
	endPos = getCursorPos();//potrebno za ispis znaka stepena
}
void Num2()
{
	COORD initPos = getCursorPos();
	cout << "  ___   ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << " |__ \\  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << "    ) | ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "   / /  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "  / /_  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << " |____| ";
	endPos = getCursorPos();
}
void Num3()
{
	COORD initPos = getCursorPos();
	cout << "  ____  ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << " |___ \\ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << "   __) |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "  |__ < ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "  ___) |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << " |____/ ";
	endPos = getCursorPos();
}
void Num4()
{
	COORD initPos = getCursorPos();
	cout << "  _  _   ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << " | || |  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << " | || |_ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << " |__   _|";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "    | |  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "    |_|  ";
	endPos = getCursorPos();
}
void Num5()
{
	COORD initPos = getCursorPos();
	cout << "  _____ ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << " | ____|";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << " | |__  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << " |___ \\ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "  ___) |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << " |____/ ";
	endPos = getCursorPos();
}
void Num6()
{
	COORD initPos = getCursorPos();
	cout << "    __  ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "   / /  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << "  / /_  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << " | '_ \\ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << " | (_) | ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "  \\___/ ";
	endPos = getCursorPos();
}
void Num7()
{
	COORD initPos = getCursorPos();
	cout << "  ______ ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << " |____  |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << "     / / ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "    / /  ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "   / /   ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "  /_/    ";
	endPos = getCursorPos();
}
void Num8()
{
	COORD initPos = getCursorPos();
	cout << "   ___  ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "  / _ \\ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << " | (_) |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "  > _ < ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << " | (_) |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "  \\___/ ";
	endPos = getCursorPos();
}
void Num9()
{
	COORD initPos = getCursorPos();
	cout << "   ___  ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "  / _ \\ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << " | (_) |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "  \\__, |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 4 });
	cout << "    / / ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 5 });
	cout << "   /_/  ";
	endPos = getCursorPos();
}
void MinusSign()
{
	COORD initPos = getCursorPos();
	cout << "        ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "        ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << " ______ ";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 3 });
	cout << "|______|";
}
void Degree()
{
	SetConsoleCursorPosition(ConsoleH, cursorPos);
	COORD initPos = getCursorPos();
	cout << " ___ ";
	cursorPos = getCursorPos();
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 1 });
	cout << "|   |";
	SetConsoleCursorPosition(ConsoleH, COORD{ initPos.X, initPos.Y + 2 });
	cout << "|___|";
	SetConsoleCursorPosition(ConsoleH, endPos);
	cout << endl;
}
void PrintNum(int num)
{
	cursorPos = getCursorPos();
	if (num < 0)//ako je broj negativan ispisi minus
	{
		MinusSign();
		num *= -1;
	}
	vector<int> digit;//vektor brojki
	if (num >= 10)// ako je dvocifren razlozi
		while (num > 0)
		{
			digit.insert(digit.begin(), num % 10);//ubacuje cifre u prvu poziciju vektora jer se razlazu u obrnutom redu
			num /= 10;
		}
	else digit.push_back(num);//ako nije onda samo ubaci u vektor
	for (auto d : digit)//za svaku cifru ispisi broj
	{
		SetConsoleCursorPosition(ConsoleH, cursorPos);
		switch (d)
		{
		case 0:
			Num0();
			break;
		case 1:
			Num1();
			break;
		case 2:
			Num2();
			break;
		case 3:
			Num3();
			break;
		case 4:
			Num4();
			break;
		case 5:
			Num5();
			break;
		case 6:
			Num6();
			break;
		case 7:
			Num7();
			break;
		case 8:
			Num8();
			break;
		case 9:
			Num9();
			break;
		}
	}
	Degree();//na kraju ispisi znak stepeni
}