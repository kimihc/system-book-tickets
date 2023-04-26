#include "header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;
extern HANDLE hConsole;

struct Tickets {
    string name;
    double price;
    int dateDay;
    int dateMonth;
    int dateYear;
    int timeHour;
    int timeMin;
    string genre;
    string duration;
    int rating;
    int column;
    int line;
}; 

struct Personal {
    string nameUser;
    string SurenameUser;
    string Otchestvo;
    int year;
    int day;
    int month;
};

Personal dataUser;
Tickets* ticket = new Tickets[1];

extern struct perfomance {
    string name;
    double price;
    int dateDay;
    int dateMonth;
    int dateYear;
    int timeHour;
    int timeMin;
    string genre;
    string duration;
    int rating;
    string description;
};

extern struct account
{
    string nickname;
};
extern int kollPerf, Number;
extern perfomance *temp_admin;
extern account* temp;
extern account check;

void first_user()
{
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    Menu_user();
    while (1) {
        EditCursor(0, 0);
        if (GetCursorPos((LPPOINT)&POINT))
        {
            Sleep(50);
            if (Mouse() == false && POINT.x > 651 && POINT.x < 842 && POINT.y > 266 && POINT.y < 306)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(67, 13);
                cout << "--------------------";
                EditCursor(67, 14);
                cout << "Ввести личные данные";
                EditCursor(67, 15);
                cout << "--------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 652 && POINT.x < 841 && POINT.y > 343 && POINT.y < 384)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(67, 17);
                cout << "--------------------";
                EditCursor(67, 18);
                cout << "Забронировать  билет";
                EditCursor(67, 19);
                cout << "--------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 622 && POINT.x < 880 && POINT.y > 419 && POINT.y < 462)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(64, 21);
                cout << "---------------------------";
                EditCursor(64, 22);
                cout << "Посмотреть  список  фильмов";
                EditCursor(64, 23);
                cout << "---------------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 622 && POINT.x < 880 && POINT.y > 497 && POINT.y < 536)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(62, 25);
                cout << "------------------------------";
                EditCursor(62, 26);
                cout << "Посмотреть список моих билетов";
                EditCursor(62, 27);
                cout << "------------------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && (POINT.x < 651 || POINT.x > 842 || POINT.y < 266 || POINT.y > 306) && (POINT.x < 652 || POINT.x > 841 || POINT.y < 343 || POINT.y > 384) && (POINT.x < 622 || POINT.x > 880 || POINT.y < 419 || POINT.y > 462) && (POINT.x < 603 || POINT.x > 889 || POINT.y < 497 || POINT.y > 536))
            {

                SetConsoleTextAttribute(hConsole, 7);
                Menu_user();
            }

            SetConsoleTextAttribute(hConsole, 7);
            
             if (Mouse() == true && POINT.x > 651 && POINT.x < 842 && POINT.y > 266 && POINT.y < 306)
            {
                system("CLS");
                Sleep(300);
                add_Personal_data();
            }
            else if (Mouse() == true && POINT.x > 652 && POINT.x < 841 && POINT.y > 343 && POINT.y < 384)
            {
                system("cls");
                Sleep(300);
                bookTicket();
            }
            else if (Mouse() == true && POINT.x > 622 && POINT.x < 880 && POINT.y > 419 && POINT.y < 462)
            {
                system("cls");
                Sleep(300);
                
                user_pictures();
                Print_perfomance();
            }
            else if (Mouse() == true && POINT.x > 622 && POINT.x < 880 && POINT.y > 497 && POINT.y < 536)
            {
                system("cls");
                Sleep(300);

                break;

            }
        }
    }
}


void Menu_user()
{
    user_pictures();
	EditCursor(67, 13);
	cout << "--------------------";
	EditCursor(67, 14);
	cout << "Ввести личные данные";
	EditCursor(67, 15);
	cout << "--------------------";

	EditCursor(67, 17);
	cout << "--------------------";
	EditCursor(67, 18);
	cout << "Забронировать  билет";
	EditCursor(67, 19);
	cout << "--------------------";

	EditCursor(64, 21);
	cout << "---------------------------";
	EditCursor(64, 22);
    cout << "Посмотреть  список  фильмов";
	EditCursor(64, 23);
	cout << "---------------------------";

    EditCursor(62, 25);
    cout << "------------------------------";
    EditCursor(62, 26);
    cout << "Посмотреть список моих билетов";
    EditCursor(62, 27);
    cout << "------------------------------";


}

void user_pictures()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout <<L"    ⢀⣤⣶⠶⠟⠛⠛⠻⠶⣶⣤⡀⠀⠀⠀⠀" << endl;
	wcout <<L"⠀⠀⣠⣾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
	wcout <<L"⠀⣴⡟⠁⠀⠀⠀⣠⣴⠶⠶⣦⣄⠀⠀⠀⠈⢻⣦⠀" << endl;
	wcout <<L"⢸⡟⠀⠀⠀⠀⣾⠋⠀⠀⠀⠀⠙⣷⠀⠀⠀⠀⢻⣇" << endl;
	wcout <<L"⣿⠁⠀⠀⠀⠸⣿⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠈⣿" << endl;
	wcout <<L"⣿⡀⠀⠀⠀⠀⠻⣦⣀⠀⠀⣀⣴⠟⠀⠀⠀⠀⢀⣿" << endl;
	wcout <<L"⢸⣧⠀⠀⠀⢀⣤⡾⠿⠛⠛⠿⢷⣤⡀⠀⠀⠀⣼⡏" << endl;
	wcout <<L"⠀⠻⣧⡀⢠⡿⠉⠀⠀⠀⠀⠀⠀⠉⢿⡄⢀⣼⠟⠀" << endl;
	wcout <<L"  ⠙⢿⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⣈⣿⡿⠋⠀⠀" << endl;
	wcout <<L"⠀ ⠀⠀⠈⠛⠿⢶⣦⣤⣤⣴⡶⠿⠛⠁⠀⠀"   << endl;
    _setmode(_fileno(stdout), _O_TEXT);

    for (int i = 0; i < 156; i++)
    {
        EditCursor(i, 11);
        cout << "-";
    }
    for (int i = 0; i < 11; i++)
    {
        EditCursor(21, i);
        cout << "|";
    }

    if (dataUser.day == 0)
    {
        EditCursor(23, 2);
        cout << "Фамилия: нет данных";
        EditCursor(23, 4);
        cout << "Имя: нет данных";
        EditCursor(23, 6);
        cout << "Отчество: нет данных";
        EditCursor(23, 8);
        cout << "Дата рождения: нет данных";
    }
    else
    {
        EditCursor(23, 2);
        cout << "Фамилия: " << dataUser.SurenameUser;
        EditCursor(23, 4);
        cout << "Имя: " << dataUser.nameUser;
        EditCursor(23, 6);
        cout << "Отчество: " << dataUser.Otchestvo;
        EditCursor(23, 8);
        cout << "Дата рождения: " << dataUser.day << "." << dataUser.month << "." << dataUser.year;
    }

}

void add_Personal_data()
{
    cout << "Введите фамилию: ";
    cin >> dataUser.SurenameUser;
    cout << "Введите имя: ";
    cin >> dataUser.nameUser;
    cout << "Введите Отчество: ";
    cin >> dataUser.Otchestvo;
    cout << "Введите дату рождения: **.**.****";
    cin >> dataUser.day;
    cin >> dataUser.month;
    cin >> dataUser.year;
    system("cls");
}


void bookTicket()
{
    user_pictures();
    int p = 0;
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    EditCursor(48, 13);
    cout << "Выберите, сеанс  который хотите забронировать";
    Print_perfomance();
    while (1)
    {
        if (p == 1)
            break;
        else
        {
            for (int i = 0; i < kollPerf; i++)
            {
                int j = 1;
                EditCursor(0, 0);
                if (GetCursorPos((LPPOINT)&POINT))
                {
                    Sleep(50);
                    if (Mouse() == false && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                    {

                        SetConsoleTextAttribute(hConsole, 6);
                        int j = 1;
                        EditCursor(j + 10, 2 * i + 18);
                        cout << temp_admin[i].name;
                        j = j + 22;
                        EditCursor(j + 10, 2 * i + 18);
                        cout << temp_admin[i].genre;
                        j = j + 22;
                        EditCursor(j + 10, 2 * i + 18);
                        cout << temp_admin[i].dateDay << "." << temp_admin[i].dateMonth << "." << temp_admin[i].dateYear;
                        j = j + 22;
                        EditCursor(j + 10, 2 * i + 18);
                        cout << temp_admin[i].timeHour << ":" << temp_admin[i].timeMin;
                        j = j + 22;
                        EditCursor(j + 5, 2 * i + 18);
                        cout << temp_admin[i].duration << " минут";
                        j = j + 22;
                        EditCursor(j + 10, 2 * i + 18);
                        cout << temp_admin[i].price << "$";
                        j = j + 22;
                        EditCursor(j + 10, 2 * i + 18);
                        cout << temp_admin[i].rating;

                        for (int q = 0; q < 155; q++)
                        {
                            EditCursor(q, 2 * i + 19);
                            cout << "-";
                        }

                        int z = 0;
                        while (z < 155)
                        {
                            if (z == 154)
                            {
                                EditCursor(155, 2 * i + 18);
                                cout << "|";
                                z = 155;
                            }
                            else
                            {
                                EditCursor(z, 2 * i + 18);
                                cout << "|";
                                z = z + 22;
                            }
                            EditCursor(0, 0);
                        }
                    }

                    else if (Mouse() == false && (POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375))
                    {

                        SetConsoleTextAttribute(hConsole, 7);
                        user_pictures();
                        EditCursor(48, 13);
                        cout << "Выберите, сеанс который хотите забронировать";
                        Print_perfomance();
                        
                    }

                    SetConsoleTextAttribute(hConsole, 7);
                    if (Mouse() == true && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                    {

                    }


                }
            }
        }
    }
}


void Broni_user(int i)
{
    user_pictures();
    int p = 0;
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    EditCursor(48, 12);
    cout << "Выберите, место  которое хотите забронировать";
    pole();
    while (1)
    {
                int j = 1;
                EditCursor(0, 0);
                if (GetCursorPos((LPPOINT)&POINT))
                {
                    Sleep(50);
                    if (Mouse() == false && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                    {

                        SetConsoleTextAttribute(hConsole, 6);
                                
                            EditCursor(0, 0);
                    }

                    else if (Mouse() == false && (POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375))
                    {

                        SetConsoleTextAttribute(hConsole, 7);
                        user_pictures();
                        EditCursor(48, 13);
                        cout << "Выберите, место которое хотите забронировать";
                        pole();

                    }

                    SetConsoleTextAttribute(hConsole, 7);
                    if (Mouse() == true && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                    {

                    }


                }
        
    }
}

void pole()
{

    int j = 0, k = 0;
    while(k < 7)
    {
        int i = 37;
        while (i < 117)
        {
            EditCursor(i, j + 13);
            cout << "----";
            EditCursor(i, j + 14);
            cout << "|";
            EditCursor(i + 3, j + 14);
            cout << "|";
            EditCursor(i, j + 15);
            cout << "----";
            i = i + 8;
        }
        j = j + 4;
        k++;
    }
}




