#include "header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <Windows.h>
	

using namespace std;
HANDLE hConsole;


struct account
{
	string login;
	string password;
    string nickname;
};

int counter = 0, people, Number;
account* temp = new account[1];
account check;

extern int check_()
{
    int a;
    while (!(cin >> a))
    {
        Sleep(500);
        cout << "Введите значение";
        cin.clear();  cin.ignore(1024, '\n');
        cout << "Неверный ввод. Попробуйте снова!" << endl;
        Sleep(500);
        system("cls");
    }

    return a;
}

extern int check_1()
{
    int a;
    while (1)
    {
   //     menu_();
   //     EditCursor(89, 10);
        while (!(cin >> a))
        {
    //        menu_();
            EditCursor(89, 10);
            cin.clear();
            cin.ignore(1024, '\n');
            EditCursor(60, 10);
            cout << "Неверный ввод. Попробуйте снова                                            " << endl;
            Sleep(1000);
            system("cls");
      //      menu_();
            EditCursor(89, 10);
        }
        if (cin.get() != '\n') {
            EditCursor(60, 10);
            cout << "Вы ввели либо пробел либо несколько значений                               " << endl;
            Sleep(1000);
            system("cls");
            cin.clear();
            cin.ignore(1025, '\n');
            continue;
        }
        if (a <= 0) {
            EditCursor(60, 10);
            cout << "Введите положительное значение                                              " << endl;
            Sleep(1000);
            system("cls");
            continue;
        }
        else break;
        system("cls");
    }
    return a;
}


extern void EditCursor(int hight, int width)
{
	COORD position = { hight, width };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

extern void Back()
{
    EditCursor(8, 38);
    cout << "-----";
    EditCursor(8, 39);
    cout << "Назад";
    EditCursor(8, 40);
    cout << "-----";
    EditCursor(7, 38);
    cout << "|";
    EditCursor(7, 39);
    cout << "|";
    EditCursor(7, 40);
    cout << "|";
    EditCursor(13, 38);
    cout << "|";
    EditCursor(13, 39);
    cout << "|";
    EditCursor(13, 40);
    cout << "|";
    EditCursor(0, 0);
}

extern void Menu_1()
{
    EditCursor(30, 5);
	cout << "Добро пожаловать в систему бронирования билетов в кинотеатр, пожалуйста выберите необходимое действие";
	EditCursor(45, 12);
    cout << "------------------";
    EditCursor(45, 13);
	cout << "Зарегистрироваться ";
    EditCursor(45, 14);
    cout << "------------------";
	EditCursor(95, 12);
    cout << "-----";
    EditCursor(95, 13);
	cout << "Войти ";
    EditCursor(95, 14);
    cout << "-----";
    EditCursor(94, 12);
    cout << "|";
    EditCursor(100, 12);
    cout << "|";
    EditCursor(94, 13);
    cout << "|";
    EditCursor(100, 13);
    cout << "|";
    EditCursor(94, 14);
    cout << "|";
    EditCursor(100, 14);
    cout << "|";

    EditCursor(44, 12);
    cout << "|";
    EditCursor(63, 12);
    cout << "|";
    EditCursor(44, 14);
    cout << "|";
    EditCursor(63, 14);
    cout << "|";
    EditCursor(44, 13);
    cout << "|";
    EditCursor(63, 13);
    cout << "|";

    EditCursor(74, 12);
    cout << "|";
    EditCursor(80, 12);
    cout << "|";
    EditCursor(74, 14);
    cout << "|";
    EditCursor(80, 14);
    cout << "|";
    EditCursor(74, 13);
    cout << "|";
    EditCursor(80, 13);
    cout << "|";
    EditCursor(75, 13);
    cout << "Выйти";
    EditCursor(75, 12);
    cout << "-----";
    EditCursor(75, 14);
    cout << "-----";
    EditCursor(0, 0);
}

extern void Print_registr()
{
    EditCursor(45, 12);
    cout << "------------------";
    EditCursor(45, 13);
    cout << "Зарегистрироваться ";
    EditCursor(45, 14);
    cout << "------------------";
    EditCursor(44, 12);
    cout << "|";
    EditCursor(63, 12);
    cout << "|";
    EditCursor(44, 14);
    cout << "|";
    EditCursor(63, 14);
    cout << "|";
    EditCursor(44, 13);
    cout << "|";
    EditCursor(63, 13);
    cout << "|";
    EditCursor(0, 0);
}

extern void Print_log()
{
    EditCursor(95, 12);
    cout << "-----";
    EditCursor(95, 13);
    cout << "Войти ";
    EditCursor(95, 14);
    cout << "-----";
    EditCursor(94, 12);
    cout << "|";
    EditCursor(100, 12);
    cout << "|";
    EditCursor(94, 13);
    cout << "|";
    EditCursor(100, 13);
    cout << "|";
    EditCursor(94, 14);
    cout << "|";
    EditCursor(100, 14);
    cout << "|";
    EditCursor(0, 0);
}

extern void Print_exit()
{

    EditCursor(74, 12);
    cout << "|";
    EditCursor(80, 12);
    cout << "|";
    EditCursor(74, 14);
    cout << "|";
    EditCursor(80, 14);
    cout << "|";
    EditCursor(74, 13);
    cout << "|";
    EditCursor(80, 13);
    cout << "|";
    EditCursor(75, 13);
    cout << "Выйти";
    EditCursor(75, 12);
    cout << "-----";
    EditCursor(75, 14);
    cout << "-----";
    EditCursor(0, 0);
}

extern void Print_role()
{
    cout << "Кто?" << endl;
    EditCursor(45, 15);
    cout << "-------------";
    EditCursor(45, 16);
    cout << "Администратор ";
    EditCursor(45, 17);
    cout << "-------------";
    EditCursor(90, 15);
    cout << "---------";
    EditCursor(90, 16);
    cout << "Бухгалтер ";
    EditCursor(90, 17);
    cout << "---------";
    EditCursor(89, 15);
    cout << "|";
    EditCursor(99, 15);
    cout << "|";
    EditCursor(89, 16);
    cout << "|";
    EditCursor(99, 16);
    cout << "|";
    EditCursor(89, 17);
    cout << "|";
    EditCursor(99, 17);
    cout << "|";

    EditCursor(44, 15);
    cout << "|";
    EditCursor(58, 15);
    cout << "|";
    EditCursor(44, 16);
    cout << "|";
    EditCursor(58, 16);
    cout << "|";
    EditCursor(44, 17);
    cout << "|";
    EditCursor(58, 17);
    cout << "|";

    EditCursor(67, 15);
    cout << "|";
    EditCursor(80, 15);
    cout << "|";
    EditCursor(67, 16);
    cout << "|";
    EditCursor(80, 16);
    cout << "|";
    EditCursor(67, 17);
    cout << "|";
    EditCursor(80, 17);
    cout << "|";
    EditCursor(68, 16);
    cout << "Пользователь";
    EditCursor(68, 15);
    cout << "------------";
    EditCursor(68, 17);
    cout << "------------";
    Back();
    EditCursor(0, 0);
}

extern void Print_cashier()
{
    EditCursor(90, 15);
    cout << "---------";
    EditCursor(90, 16);
    cout << "Бухгалтер ";
    EditCursor(90, 17);
    cout << "---------";
    EditCursor(89, 15);
    cout << "|";
    EditCursor(99, 15);
    cout << "|";
    EditCursor(89, 16);
    cout << "|";
    EditCursor(99, 16);
    cout << "|";
    EditCursor(89, 17);
    cout << "|";
    EditCursor(99, 17);
    cout << "|";
    EditCursor(0, 0);
}

extern void Print_user()
{
    EditCursor(67, 15);
    cout << "|";
    EditCursor(80, 15);
    cout << "|";
    EditCursor(67, 16);
    cout << "|";
    EditCursor(80, 16);
    cout << "|";
    EditCursor(67, 17);
    cout << "|";
    EditCursor(80, 17);
    cout << "|";
    EditCursor(68, 17);
    cout << "------------";
    EditCursor(68, 16);
    cout << "Пользователь";
    EditCursor(68, 15);
    cout << "------------";
    EditCursor(0, 0);
}

extern void Print_admin()
{
    EditCursor(45, 15);
    cout << "—————————----";
    EditCursor(45, 16);
    cout << "Администратор ";
    EditCursor(45, 17);
    cout << "—————————----";
    EditCursor(44, 15);
    cout << "|";
    EditCursor(58, 15);
    cout << "|";
    EditCursor(44, 16);
    cout << "|";
    EditCursor(58, 16);
    cout << "|";
    EditCursor(44, 17);
    cout << "|";
    EditCursor(58, 17);
    cout << "|";
    EditCursor(0, 0);
}

extern bool Mouse()
{
	short status;

	for (;;)
	{

		status = GetKeyState(VK_LBUTTON);   

        if (status == -127 || status == -128)
        {
            return true;
        }
        else 
            return false;
		Sleep(1);
	}
}

extern void Click()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 1); okrras

   SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

   auto h = ::GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi = {};
    cfi.cbSize = sizeof(cfi);
    ::GetCurrentConsoleFontEx(h, FALSE, &cfi);
    cfi.dwFontSize.Y *= 3;
    ::SetCurrentConsoleFontEx(h, FALSE, &cfi);
    ::SetCurrentConsoleFontEx(h, FALSE, &cfi);
}

extern int Menu_() // начало меню
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    int a;
    Sleep(300);
    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    Menu_1();
    while (1) {
       
        
            // Сохраняем текущие атрибуты консоли
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;

            // Устанавливаем новый фон для определенной области консоли
            COORD startCoord = { 42, 5 };
            DWORD count = 3;
            WORD newAttributes = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN;
            FillConsoleOutputAttribute(hConsole, newAttributes << 0, 62, startCoord, &count);
            // Возвращаем старые атрибуты консоли
            SetConsoleTextAttribute(hConsole, saved_attributes);


            
        
        EditCursor(0, 0);
        cout << " ";
        EditCursor(0, 0);
        if (GetCursorPos((LPPOINT)&POINT))
        {
            Sleep(50);
            if (Mouse() == false && POINT.x > 433 && POINT.x < 619 && POINT.y > 244 && POINT.y < 286)
            {
                
                SetConsoleTextAttribute(hConsole, 6);
                Print_registr();

            }
            else if (Mouse() == false && POINT.x > 913 && POINT.x < 973 && POINT.y > 244 && POINT.y < 286)
            {
                
                SetConsoleTextAttribute(hConsole, 6);
                Print_log();
            }
            else if (Mouse() == false && POINT.x > 722 && POINT.x < 781 && POINT.y > 244 && POINT.y < 286)
            {
                
                SetConsoleTextAttribute(hConsole, 6);
                Print_exit();
            }
            else if (Mouse() == false && (POINT.x < 433 || POINT.x > 619 || POINT.y < 244 || POINT.y > 286) && (POINT.x < 913 || POINT.x > 973 || POINT.y < 244 || POINT.y > 286) && (POINT.x < 722 || POINT.x > 781 || POINT.y < 244 || POINT.y > 286) )
            {
               
                SetConsoleTextAttribute(hConsole, 7);
                Menu_1();
            }

            SetConsoleTextAttribute(hConsole, 7);

            if (Mouse() == true && POINT.x > 433 && POINT.x < 619 && POINT.y > 244 && POINT.y < 286)
            {
                system("CLS");
                Sleep(300);
                if (Menu_2() == 1)
                    Menu_();
                else
                    return 0;
            }
            else if (Mouse() == true && POINT.x > 913 && POINT.x < 973 && POINT.y > 244 && POINT.y < 286)
            {
                system("cls");
                Sleep(300); 
                a = Menu_3();
                if (a == 1)
                    return 1;
                else if (a == 2)
                    return 2;
                else
                    return 3;
            }
            else if (Mouse() == true && POINT.x > 722 && POINT.x < 781 && POINT.y > 244 && POINT.y < 286)
            {
                system("cls");
                return 0;
            }
        }
    }
}

extern int Menu_2() // регистрация
{
    system("cls");
    Print_role();

    struct tagPOINT {
        LONG x;
        LONG y;
    } POINT;
    while (1)
    {
        if (GetCursorPos((LPPOINT)&POINT))
        {
            Sleep(50);
            if ( Mouse() == false && POINT.x > 434 && POINT.x < 569 && POINT.y > 300 && POINT.y < 350)
            {
                SetConsoleTextAttribute(hConsole, 3);
                    Print_admin();
                
            }
            else if (Mouse() == false && POINT.x > 655 && POINT.x < 781 && POINT.y > 300 && POINT.y < 350)
            {
                SetConsoleTextAttribute(hConsole, 3);
                Print_user();
            }
            else if (Mouse() == false && POINT.x > 865 && POINT.x < 965 && POINT.y > 300 && POINT.y < 350)
            {
                SetConsoleTextAttribute(hConsole, 3);
                Print_cashier();
            }
            else if (Mouse() == false && POINT.x > 78 && POINT.x < 135 && POINT.y > 743 && POINT.y < 785)
            {
                SetConsoleTextAttribute(hConsole, 3);
                Back();
            }
            else if (Mouse() == false && (POINT.x < 434 || POINT.x > 569 || POINT.y < 300 || POINT.y > 350) && (POINT.x < 655 || POINT.x > 781 || POINT.y < 300 || POINT.y > 350) && (POINT.x < 865 || POINT.x > 965 || POINT.y < 300 || POINT.y > 350) && (POINT.x < 78 || POINT.x > 135 || POINT.y < 743 || POINT.y > 785))
            {
                SetConsoleTextAttribute(hConsole, 7);
                Print_role();
            }

            SetConsoleTextAttribute(hConsole, 7);
            if (Mouse() == true && POINT.x > 434 && POINT.x < 569 && POINT.y > 300 && POINT.y < 350)
            {
                 EditCursor(0, 0);
                 Sleep(300);
                increaseColumn();
                temp[people].nickname = "администратор";
                system("cls");
                EditCursor(45, 5);
                cout << "Регистрация прошла успешно. Вы зарегистрировались как " << temp[people].nickname;
                people++;
                EditCursor(0, 0);
                Sleep(3500);
                return 1;
            }
            else if (Mouse() == true && POINT.x > 655 && POINT.x < 781 && POINT.y > 300 && POINT.y < 350)
            {
                EditCursor(0, 0);
                Sleep(300);
                increaseColumn();
                temp[people].nickname = "пользователь";
                system("cls");
                EditCursor(45, 5);
                cout << "Регистрация прошла успешно. Вы зарегистрировались как " << temp[people].nickname;
                people++;
                EditCursor(0, 0);
                Sleep(3500);
                return 1;
            }
            else if (Mouse() == true && POINT.x > 865 && POINT.x < 965 && POINT.y > 300 && POINT.y < 350)
            {
                 EditCursor(0, 0);
                Sleep(300);
                increaseColumn();
                temp[people].nickname = "бухгалтер";
                system("cls");
                EditCursor(45, 5);
                cout << "Регистрация прошла успешно. Вы зарегистрировались как " << temp[people].nickname;
                people++;
                EditCursor(0, 0);
                Sleep(3500);
                return 1;
            }
           else if (Mouse() == true && POINT.x > 78 && POINT.x < 135 && POINT.y > 743 && POINT.y < 785)
            {
                system("cls");
                Menu_();
                return 0;
            }
        }
    }
}

string Hash() ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
    char c;
    string password = "";
    while (true) {
        c = _getch();
        if (c == 13) {
            break;
        }
        else if (c == 8 && password.size()) {
            password.pop_back();
            wcout << '\b' << ' ' << '\b';
        }
        else if (c != 8) {
            cout << '*';
            password.push_back(c);
        }
    }
    cout << '\n';
    return password;
}

extern int Menu_3() // войти
{
    do {
        EditCursor(0, 0);
        system("cls");
        for (int i = 0; i < people; i++)
        {
            cout << temp[i].nickname << "  ";
            cout << temp[i].login << "  ";
            cout << temp[i].password << endl << endl;

        }
        EditCursor(65, 0);
        cout << "Введите логин и пароль";
        EditCursor(65, 1);
        cout << "Логин: ";
        cin >> check.login;
        EditCursor(65, 2);
        cout << "Пароль: ";
        cin >> check.password;
        system("cls");
    } while (!Login());

    int a;
    for (int i = 0; i < people; i++)
    {
        if (check.login == temp[i].login)
        {
            a = i;
            Number = i;
            break;
        }
    }
    if (temp[a].nickname == "администратор")
        return 1;
    else if (temp[a].nickname == "пользователь")
        return 2;
    else
        return 3;
}

extern bool Login()
{
    int a = -1;
    for (int i = 0; i < people; i++)
    {
        if (temp[i].login == check.login && temp[i].password == check.password)
        {
            a = i;
        }
    }
    EditCursor(65, 2);
    if (a == -1)
    {
        cout << "Неверный логин или пароль";
        Sleep(3500);
        system("cls");
        return 0;
    }
    else
    {
        cout << "Вы вошли как " << temp[a].nickname;
        Sleep(3500);
        system("cls");
        return 1;
    }
}

extern void Registration()
{
    
}

extern void Recording()
{
    ofstream Credentials;

    Credentials.open("Credentials.txt", ofstream::trunc);
    if (!Credentials.is_open())
        cout << "Error" << endl;
    else
    {
        for (int a = 0; a < people + 1; a++)
        {
            Credentials<< setw(13) << temp[a].nickname << setw(13) << temp[a].login << setw(15) << temp[a].password << endl;
        }
    }
    Credentials.close();

}

extern void Reading()
{
    ifstream Credentials;
    Credentials.open("Credentials.txt");
    if (!Credentials.is_open())
        cout << "Error" << endl;
    else
    {
        int i = 0;
        while (!Credentials.eof())
        {
            Credentials >> temp[i].nickname;
            Credentials >> temp[i].login;
            Credentials >> temp[i].password;          
            i++;
        }
    }
    Credentials.close();
}


extern void increaseColumn()
{
    account* new_array = new account[people + 1];

    for (int i = 0; i < people; i++)
    {
        new_array[i] = temp[i];
    }

    delete[] temp;
   
    temp = new account[people + 1];
   
        system("cls");
        EditCursor(65, 0);
        cout << "Введите логин и пароль";
        EditCursor(65, 1);
        cout << "Логин: ";
        cin >> new_array[people].login;
        EditCursor(65, 2);
        cout << "Пароль: ";
        cin >> new_array[people].password;
    
    for (int i = 0; i < people + 1; i++) 
    {
        temp[i] = new_array[i];
    }
    

    delete[] new_array;
}

extern int numberPeople()
{
    int count = 0;
    ifstream Credentials;
    Credentials.open("Credentials.txt");
    if (!Credentials.is_open())
        cout << "Error" << endl;
    else
    {
        while (!Credentials.eof())
        {
            Credentials >> temp[0].nickname;
            count++;
        }
        count = count / 3;
    }
    Credentials.close();
    return(count);
}

extern void memory()
{
    people = numberPeople();
    delete[] temp;
    temp = new account[people + 1];
    EditCursor(0, 0);
}

extern void Menu_Admin()
{
    system("cls");
    EditCursor(72, 9);
    cout << "Добавить сеанс";
    EditCursor(72, 11);
    cout << "Удалить  сеанс";
    EditCursor(65, 13);
    cout << "Добавитиь информацию о фильме";
    EditCursor(60, 15);
    cout << "Просмотреть информацию о пользователях";
    EditCursor(0, 0);
    Sleep(5000);

}
