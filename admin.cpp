#include "header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>


// 155 длинна
using namespace std;
extern HANDLE hConsole;
extern int people;
// название фильма, дата проведения, время, цена билета, год выпуска, жанр, продолжительность, описание, рейтинг

struct perfomance
{
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
int kollPerf = 0;
perfomance* temp_admin = new perfomance[1];

void admin_pictures()
{
    EditCursor(0, 0);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"⠀   ⢀⣤⣶⡶⠿⠿⠿⠿⢶⣶⣤⡀⠀⠀" << endl;
    wcout << L"⠀⠀⣠⣾⠟⠉⠀⠀⠀⣀⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
    wcout << L"⠀⣴⡟⠁⠀⠀⠀⢰⣿⣿⣿⣿⡆⠀⠀⠀⠈⢻⣦⠀" << endl;
    wcout << L"⢸⡿⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⢿⡇" << endl;
    wcout << L"⣿⡇⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⢸⣿" << endl;
    wcout << L"⣿⡇⠀⠀⠀⠀⠀⠀⣸⣿⣿⣃⠀⠀⠀⠀⠀⠀⢸⣿" << endl;
    wcout << L"⢸⣷⠀⠀⠀⣴⣾⣿⣿⣋⣹⣿⣿⣷⣦⠀⠀⠀⣼⡇" << endl;
    wcout << L" ⠻⣧⡀⠀⢿⣿⣿⣿⠃⠸⣿⣿⣿⡿⠀⢀⣼⠟⠀" << endl;
    wcout << L"⠀ ⠙⢿⣦⣀⠀⠀⠉⠉⠉⠁⠀⠀⣀⣴⡿⠋⠀⠀" << endl;
    wcout << L"⠀   ⠈⠛⠿⠷⣶⣶⣶⣶⠶⠿⠛⠁⠀⠀⠀⠀" << endl;
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
    
}


void first() //начало
{
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    Menu_admin();
    while (1) {
        Sleep(100);
        EditCursor(0, 0);
        if (GetCursorPos((LPPOINT)&POINT))
        {
            Sleep(50);
            if (Mouse() == false && POINT.x > 728 && POINT.x < 784 && POINT.y > 285 && POINT.y < 324)
            {
                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(75, 14);
                cout << "------";
                EditCursor(75, 15);
                cout << "Сеансы";
                EditCursor(75, 16);
                cout << "------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 698 && POINT.x < 814 && POINT.y > 362 && POINT.y < 400)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(72, 18);
                cout << "------------";
                EditCursor(72, 19);
                cout << "Пользователи";
                EditCursor(72, 20);
                cout << "------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 659 && POINT.x < 842 && POINT.y > 438 && POINT.y < 478)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(68, 22);
                cout << "-------------------";
                EditCursor(68, 23);
                cout << "Удалить всю систему";
                EditCursor(68, 24);
                cout << "-------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 660 && POINT.x < 842 && POINT.y > 516 && POINT.y < 553)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(68, 26);
                cout << "-------------------";
                EditCursor(68, 27);
                cout << "Выйти  с  акккаунта";
                EditCursor(68, 28);
                cout << "-------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && (POINT.x < 728 || POINT.x > 784 || POINT.y < 285 || POINT.y > 324) && (POINT.x < 698 || POINT.x > 814 || POINT.y < 362 || POINT.y > 400) && (POINT.x < 659 || POINT.x > 842 || POINT.y < 438 || POINT.y > 478) && (POINT.x < 660 || POINT.x > 842 || POINT.y < 516 || POINT.y > 553))
            {
                SetConsoleTextAttribute(hConsole, 7);
                Menu_admin();
            }

            SetConsoleTextAttribute(hConsole, 7);
           if (Mouse() == true && POINT.x > 728 && POINT.x < 784 && POINT.y > 285 && POINT.y < 324)
            {
                system("CLS");
                Sleep(300);
                second();
                break;
            }
            else if (Mouse() == true && POINT.x > 698 && POINT.x < 814 && POINT.y > 362 && POINT.y < 400)
            {
                system("cls");
                Sleep(300);
                
            }
            else if (Mouse() == true && POINT.x > 659 && POINT.x < 842 && POINT.y > 438 && POINT.y < 478)
            {
                system("cls");
                Sleep(300);
                cout << "Легко сделать";
                Sleep(3000);
            }
            else if (Mouse() == true && POINT.x > 660 && POINT.x < 842 && POINT.y > 516 && POINT.y < 553)
            {
                system("cls");
                Sleep(300);
                Menu_();
            }
        }
    }
}



void Menu_admin() 
{
    admin_pictures();
	EditCursor(68, 12);
	cout << "Меню администратора";

	EditCursor(75, 14);
	cout << "------";
	EditCursor(75, 15);
	cout << "Сеансы";
	EditCursor(75, 16);
	cout << "------";

	EditCursor(72, 18);
	cout << "------------";
	EditCursor(72, 19);
	cout << "Пользователи";
	EditCursor(72, 20);
	cout << "------------";

	EditCursor(68, 22);
	cout << "-------------------";
	EditCursor(68, 23);
	cout << "Удалить всю систему";
	EditCursor(68, 24);
	cout << "-------------------";

    EditCursor(68, 26);
    cout << "-------------------";
    EditCursor(68, 27);
    cout << "Выйти  с  акккаунта";
    EditCursor(68, 28);
    cout << "-------------------";



	EditCursor(0, 0);
}

void Menu_admin_perfomance()
{
    admin_pictures();

    EditCursor(71, 12);
    cout << "--------------";
    EditCursor(71, 13);
    cout << "Добавить сеанс";
    EditCursor(71, 14);
    cout << "--------------";

    EditCursor(68, 16);
    cout << "-------------------";
    EditCursor(68, 17);
    cout << "Редактировать сеанс";
    EditCursor(68, 18);
    cout << "-------------------";

    EditCursor(71, 20);
    cout << "--------------";
    EditCursor(71, 21);
    cout << "Просмотр сеанс";
    EditCursor(71, 22);
    cout << "--------------";

    EditCursor(71, 24);
    cout << "--------------";
    EditCursor(71, 25);
    cout << "Отменить сеанс";
    EditCursor(71, 26);
    cout << "--------------";

    EditCursor(0, 0);
}

void second()
{
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    Menu_admin_perfomance();
    while (1) {
        EditCursor(0, 0);
        if (GetCursorPos((LPPOINT)&POINT))
        {
            Sleep(50);
            if (Mouse() == false && POINT.x > 690 && POINT.x < 823 && POINT.y > 246 && POINT.y < 286)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(71, 12);
                cout << "--------------";
                EditCursor(71, 13);
                cout << "Добавить сеанс";
                EditCursor(71, 14);
                cout << "--------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 660 && POINT.x < 842 && POINT.y > 324 && POINT.y < 362)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(68, 16);
                cout << "-------------------";
                EditCursor(68, 17);
                cout << "Редактировать сеанс";
                EditCursor(68, 18);
                cout << "-------------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 686 && POINT.x < 825 && POINT.y > 402 && POINT.y < 439)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(71, 20);
                cout << "--------------";
                EditCursor(71, 21);
                cout << "Просмотр сеанс";
                EditCursor(71, 22);
                cout << "--------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && POINT.x > 686 && POINT.x < 825 && POINT.y > 478 && POINT.y < 517)
            {

                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(71, 24);
                cout << "--------------";
                EditCursor(71, 25);
                cout << "Отменить сеанс";
                EditCursor(71, 26);
                cout << "--------------";
                EditCursor(0, 0);
            }
            else if (Mouse() == false && (POINT.x < 690 || POINT.x > 823 || POINT.y < 246 || POINT.y > 286) && (POINT.x < 660 || POINT.x > 842 || POINT.y < 324 || POINT.y > 362) && (POINT.x < 686 || POINT.x > 825 || POINT.y < 402 || POINT.y > 439) && (POINT.x < 686 || POINT.x > 825 || POINT.y < 478 || POINT.y > 517))
            {

                SetConsoleTextAttribute(hConsole, 7);
                Menu_admin_perfomance();
            }

            SetConsoleTextAttribute(hConsole, 7);
           /* if (Mouse() == true)
            {
                EditCursor(0, 0);
                cout << POINT.x << "  " << POINT.y;
            }
            else*/ if (Mouse() == true && POINT.x > 690 && POINT.x < 823 && POINT.y > 246 && POINT.y < 286)
            {
                system("CLS");
                Sleep(300);
                increaseColumn_admin();
                break;
            }
            else if (Mouse() == true && POINT.x > 660 && POINT.x < 842 && POINT.y > 324 && POINT.y < 362)
            {
                system("cls");
                Sleep(300);
                Edit_perfomance();
                break;
            }
            else if (Mouse() == true && POINT.x > 686 && POINT.x < 825 && POINT.y > 402 && POINT.y < 439)
            {
                system("cls");
                Sleep(300);
                Print_perfomance();
                break;

            }
            else if (Mouse() == true && POINT.x > 686 && POINT.x < 825 && POINT.y > 478 && POINT.y < 517)
            {
                 system("cls");
                 Sleep(300);
                 delete_perfomance();
                 break;

            }
        }
    }
}

/*
    string name;
    double price;
    string date;
    string time;
    string genre;
    string duration; // продожительность сеанса
    int rating;
    string description; // описание
*/

void delete_perfomance()
{
    int p = 0;
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    EditCursor(48, 13);
    cout << "Выберите, сеанс и  который хотите отменить";
    admin_pictures();
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
                        EditCursor(48, 13);
                        cout << "Выберите, сеанс и параметр который хотите отменить";
                        Print_perfomance();
                        admin_pictures();
                    }

                    SetConsoleTextAttribute(hConsole, 7);
                    if (Mouse() == true && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                    {
                        kollPerf--;
                        int t;
                        t = i;
                        perfomance* new_array = new perfomance[kollPerf];

                        for (int i = t; i < kollPerf; i++)
                        {
                            temp_admin[i].dateDay = temp_admin[i + 1].dateDay;
                            temp_admin[i].dateMonth = temp_admin[i + 1].dateMonth;
                            temp_admin[i].dateYear = temp_admin[i + 1].dateYear;
                            temp_admin[i].duration = temp_admin[i + 1].duration;
                            temp_admin[i].genre = temp_admin[i + 1].genre;
                            temp_admin[i].name = temp_admin[i + 1].name;
                            temp_admin[i].price = temp_admin[i + 1].price;
                            temp_admin[i].rating = temp_admin[i + 1].rating;
                            temp_admin[i].timeHour = temp_admin[i + 1].timeHour;
                            temp_admin[i].timeMin = temp_admin[i + 1].timeMin;
                        }

                        for (int i = 0; i < kollPerf; i++)
                        {
                            new_array[i].dateDay = temp_admin[i].dateDay;
                            new_array[i].dateMonth = temp_admin[i].dateMonth;
                            new_array[i].dateYear = temp_admin[i].dateYear;
                            new_array[i].duration = temp_admin[i].duration;
                            new_array[i].genre = temp_admin[i].genre;
                            new_array[i].name = temp_admin[i].name;
                            new_array[i].price = temp_admin[i].price;
                            new_array[i].rating = temp_admin[i].rating;
                            new_array[i].timeHour = temp_admin[i].timeHour;
                            new_array[i].timeMin = temp_admin[i].timeMin;
                        }

                        delete[] temp_admin;
                        perfomance* temp_admin = new perfomance[kollPerf];

                        for (int i = 0; i < kollPerf; i++)
                        {
                            temp_admin[i].dateDay = new_array[i].dateDay;
                            temp_admin[i].dateMonth = new_array[i].dateMonth;
                            temp_admin[i].dateYear = new_array[i].dateYear;
                            temp_admin[i].duration = new_array[i].duration;
                            temp_admin[i].genre = new_array[i].genre;
                            temp_admin[i].name = new_array[i].name;
                            temp_admin[i].price = new_array[i].price;
                            temp_admin[i].rating = new_array[i].rating;
                            temp_admin[i].timeHour = new_array[i].timeHour;
                            temp_admin[i].timeMin = new_array[i].timeMin;
                        }

                        delete[] new_array;
                        system("cls");
                        EditCursor(0, 0);
                        p = 1;
                        break;
                    }


                }
            }
        }
    }
}

void Edit_perfomance()
{

    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    EditCursor(48, 13);
    cout << "Выберите, сеанс и параметр который хотите отредактировать";
    Print_perfomance();
    admin_pictures();
    while (1) {
        for (int i = 0; i < kollPerf; i++)
        {
            int j = 1;
            EditCursor(0, 0);
            if (GetCursorPos((LPPOINT)&POINT))
            {
                Sleep(50);
                if (Mouse() == false && POINT.x > 10 && POINT.x < 210 && POINT.y > i*35 + 345 && POINT.y < i*35 +375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(11, 2 * i + 18);
                    cout << temp_admin[i].name;
            
                    EditCursor(0, 0);
                }
                else if (Mouse() == false && POINT.x > 210 && POINT.x < 430 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(33, 2 * i + 18);
                    cout << temp_admin[i].genre;
               
                    EditCursor(0, 0);
                }
                else if (Mouse() == false && POINT.x > 430 && POINT.x < 640 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(55, 2 * i + 18);
                    cout << temp_admin[i].dateDay << "." << temp_admin[i].dateMonth << "." << temp_admin[i].dateYear;
                    
                    EditCursor(0, 0);
                }
                else if (Mouse() == false && POINT.x > 640 && POINT.x < 850 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(77, 2 * i + 18);
                    cout << temp_admin[i].timeHour << ":" << temp_admin[i].timeMin;
                    
                    EditCursor(0, 0);
                }
                else if (Mouse() == false && POINT.x > 850 && POINT.x < 1060 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(94, 2 * i + 18);
                    cout << temp_admin[i].duration << " минут";
                
                    EditCursor(0, 0);
                }
                else if (Mouse() == false && POINT.x > 1060 && POINT.x < 1270 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(121, 2 * i + 18);
                    cout << temp_admin[i].price << "$";

                    EditCursor(0, 0);
                }
                else if (Mouse() == false && POINT.x > 1270 && POINT.x < 1480 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                    SetConsoleTextAttribute(hConsole, 6);
                    EditCursor(143, 2 * i + 18);
                    cout << temp_admin[i].rating;
                    EditCursor(0, 0);
                }
                else if (Mouse() == false && (POINT.x < 1270 || POINT.x > 1480 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375) && (POINT.x < 10 || POINT.x > 210 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375) && (POINT.x < 210 || POINT.x > 430 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375) && (POINT.x < 430 || POINT.x > 640 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375) && (POINT.x < 640 || POINT.x > 850 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375) && (POINT.x < 850 || POINT.x > 1060 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375) && (POINT.x < 1060 || POINT.x > 1270 || POINT.y < i * 35 + 375 || POINT.y > i * 35 + 375))
                {

                    SetConsoleTextAttribute(hConsole, 7);
                    EditCursor(48, 13);
                    cout << "Выберите, сеанс и параметр который хотите отредактировать";
                    Print_perfomance();
                    admin_pictures();
                }

                SetConsoleTextAttribute(hConsole, 7);
                if (Mouse() == true && POINT.x > 10 && POINT.x < 210 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {
                    EditCursor(11, 2 * i + 18);
                    cout << "             ";
                    EditCursor(11, 2 * i + 18);
                    cin >>  temp_admin[i].name;

                    EditCursor(0, 0);
                }
                else if (Mouse() == true && POINT.x > 210 && POINT.x < 430 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                
                    EditCursor(33, 2 * i + 18);
                    cout << "             ";
                    EditCursor(33, 2 * i + 18);
                    cin >> temp_admin[i].genre;

                    EditCursor(0, 0);
                }
                else if (Mouse() == true && POINT.x > 430 && POINT.x < 640 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {
                    EditCursor(55, 2 * i + 18);
                    cout << "             ";
                    EditCursor(55, 2 * i + 18);
                    cin >> temp_admin[i].dateDay;
                    cout << ".";
                    EditCursor(57, 2 * i + 18);
                    cin >> temp_admin[i].dateMonth;
                    cout << ".";
                    EditCursor(59, 2 * i + 18);
                    cin >> temp_admin[i].dateYear;

                    EditCursor(0, 0);
                }
                else if (Mouse() == true && POINT.x > 640 && POINT.x < 850 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                   
                    EditCursor(77, 2 * i + 18);
                    cout << "           ";
                    EditCursor(77, 2 * i + 18);
                    cin >> temp_admin[i].timeHour;
                    cout << ":";
                    EditCursor(79, 2 * i + 18);
                    cin >> temp_admin[i].timeMin;

                    EditCursor(0, 0);
                }
                else if (Mouse() == true && POINT.x > 850 && POINT.x < 1060 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {

                   
                    EditCursor(94, 2 * i + 18);
                    cout << "            ";
                    EditCursor(94, 2 * i + 18);
                    cin >> temp_admin[i].duration;
                    EditCursor(94, 2 * i + 18);
                    cout << "            ";
                    EditCursor(94, 2 * i + 18);
                    cout << temp_admin[i].duration << " минут";

                    EditCursor(0, 0);
                }
                else if (Mouse() == true && POINT.x > 1060 && POINT.x < 1270 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {   
                    EditCursor(121, 2 * i + 18);
                    cout << "            ";
                    EditCursor(121, 2 * i + 18);
                    cin >> temp_admin[i].price;
                    EditCursor(121, 2 * i + 18);
                    cout << "            ";
                    EditCursor(121, 2 * i + 18);
                   cout << temp_admin[i].price << "$";

                    EditCursor(0, 0);
                }
                else if (Mouse() == true && POINT.x > 1270 && POINT.x < 1480 && POINT.y > i * 35 + 345 && POINT.y < i * 35 + 375)
                {
                    EditCursor(143, 2 * i + 18);
                    cout << "            ";
                    EditCursor(143, 2 * i + 18);
                    cin >> temp_admin[i].rating;
                    EditCursor(0, 0);
                }
            }
        }
    }
}

void Print_perfomance()
{
    for (int i = 0; i < 156; i++)
    {
        EditCursor(i, 15);
        cout << "-";
        EditCursor(i, 17);
        cout << "-";
    }
    int a = 0;
    while (a < 155)
    {
        if (a == 154)
        {
            EditCursor(155, 16);
            cout << "|";
            a = 155;
        }
        else
        {
            EditCursor(a, 16);
            cout << "|";
            a = a + 22;
        }
    }

    EditCursor(7, 16);
    cout << "Название";
    EditCursor(31, 16);
    cout << "Жанр";
    EditCursor(48, 16);
    cout << "Дата проведения";
    EditCursor(69, 16);
    cout << "Время проведения";
    EditCursor(90, 16);
    cout << "Продолжительность";
    EditCursor(115, 16);
    cout << "Цена билета";
    EditCursor(137, 16);
    cout << "Рейтинг фильма";


    for (int i = 0; i < kollPerf; i++)
    {
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
        }
    }
}

void increaseColumn_admin()
{
    perfomance* new_array = new perfomance[kollPerf + 1];

    for (int i = 0; i < kollPerf; i++)
    {
        new_array[i].dateDay = temp_admin[i].dateDay;
        new_array[i].dateMonth = temp_admin[i].dateMonth;
        new_array[i].dateYear = temp_admin[i].dateYear;
        new_array[i].description = temp_admin[i].description;
        new_array[i].duration = temp_admin[i].duration;
        new_array[i].genre = temp_admin[i].genre;
        new_array[i].name = temp_admin[i].name;
        new_array[i].price = temp_admin[i].price;
        new_array[i].rating = temp_admin[i].rating;
        new_array[i].timeHour = temp_admin[i].timeHour;
        new_array[i].timeMin = temp_admin[i].timeMin;
    }

    delete[] temp_admin;

    temp_admin = new perfomance[kollPerf + 1];

    system("cls");
    EditCursor(65, 0);
    cout << "Введите необходимую информацию";
    EditCursor(65, 1);
    cout << "Название фмльма: ";
    cin >> new_array[kollPerf].name;
    EditCursor(65, 2);
    cout << "Жанр фильма: ";
    cin >> new_array[kollPerf].genre;
    EditCursor(65, 3);

    cout << "дата проведения сеанса: **.**.**** ";
    EditCursor(89, 3);
    cin >> new_array[kollPerf].dateDay;
    EditCursor(92, 3);
    cin >> new_array[kollPerf].dateMonth;
    EditCursor(95, 3);
    cin >> new_array[kollPerf].dateYear;

    EditCursor(65, 4);
    cout << "Время проведения сеанса : ##:##";
    EditCursor(91, 4);
    cin >> new_array[kollPerf].timeHour;
    EditCursor(94, 4);
    cin >> new_array[kollPerf].timeMin;

    EditCursor(65, 5);
    cout << "Продолжительность сеанса(минутах): ";
    cin >> new_array[kollPerf].duration;
    EditCursor(65, 6);
    cout << "Цена билета: ";
    cin >> new_array[kollPerf].price;
    EditCursor(65, 7);
    cout << "рейтинг";
    cin >> new_array[kollPerf].rating;



    for (int i = 0; i < kollPerf + 1; i++)
    {
        temp_admin[i].dateDay = new_array[i].dateDay;
        temp_admin[i].dateMonth = new_array[i].dateMonth;
        temp_admin[i].dateYear = new_array[i].dateYear;
        temp_admin[i].duration = new_array[i].duration;
        temp_admin[i].genre = new_array[i].genre;
        temp_admin[i].name = new_array[i].name;
        temp_admin[i].price = new_array[i].price;
        temp_admin[i].rating = new_array[i].rating;
        temp_admin[i].timeHour = new_array[i].timeHour;
        temp_admin[i].timeMin = new_array[i].timeMin;
    }

    kollPerf++;
    delete[] new_array;
}


void Recording_admin()
{
    ofstream Perfomance;

    Perfomance.open("Perfomance.txt", ofstream::trunc);
    if (!Perfomance.is_open())
        cout << "Error" << endl;
    else
    {
        for (int i = 0; i < kollPerf; i++)
        {
            Perfomance << temp_admin[i].dateDay << setw(5) << temp_admin[i].dateMonth << setw(5) << temp_admin[i].dateYear << setw(5) << temp_admin[i].duration << setw(5) << temp_admin[i].genre << setw(15) << temp_admin[i].name << setw(5) << temp_admin[i].price << setw(5) << temp_admin[i].rating << setw(5) << temp_admin[i].timeHour << setw(5) << temp_admin[i].timeMin << endl;
        }
    }
    Perfomance.close();

}

void Reading_admin()
{
    ifstream Perfomance;
    Perfomance.open("Perfomance.txt");
    if (!Perfomance.is_open())
        cout << "Не открывается ублюдок" << endl;
    else
    {
        int i = 0;
        while (!Perfomance.eof())
        {
            Perfomance >> temp_admin[i].dateDay;
            Perfomance >> temp_admin[i].dateMonth;
            Perfomance >> temp_admin[i].dateYear;
            Perfomance >> temp_admin[i].duration;
            Perfomance >> temp_admin[i].genre;
            Perfomance >> temp_admin[i].name;
            Perfomance >> temp_admin[i].price;
            Perfomance >> temp_admin[i].rating;
            Perfomance >> temp_admin[i].timeHour;
            Perfomance >> temp_admin[i].timeMin; 
            i++;
        }
    }
    Perfomance.close();
}

void memory_perfomance()
{
    kollPerf = numberPerfomance();
    delete[] temp_admin;
    temp_admin = new perfomance[kollPerf + 1];
    EditCursor(0, 0);
}

int numberPerfomance()
{
    int count = 0;
    ifstream Perfomance;
    Perfomance.open("Perfomance.txt");
    if (!Perfomance.is_open())
        cout << "Error" << endl;
    else
    {
        while (!Perfomance.eof())
        {
            Perfomance >> temp_admin[0].name;
            count++;
        }
        count = count / 10;
        EditCursor(0, 5);
        cout << count; 
        Perfomance.close();
    }
    return(count);
}

void Menu_AdminUser()
{
    
    cout << "Прсмотр пользователей системы";
    cout << "Забанить пользователя";

}