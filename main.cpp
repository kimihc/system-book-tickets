#include "header.h"
#include <locale.h>
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    memory();
    Reading(); 
    Click();
    memory_perfomance();
    Reading_admin();
    
    int a, count;
    a = Menu_();
    if (a == 1)
        first();
    else if (a == 2)
        first_user();
    else if (a == 3)
        cout << "";
   

    Recording_admin();

    Recording();

    
}


/*

 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;

        // Сохраняем текущие атрибуты консоли
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;

        // Устанавливаем новый фон для определенной области консоли
        COORD startCoord = { 0, 0 };
        DWORD count = 3;
        WORD newAttributes = BACKGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_GREEN;
        FillConsoleOutputAttribute(hConsole, newAttributes << 0, 20, startCoord, &count);
        cin >> key;
        // Возвращаем старые атрибуты консоли
        SetConsoleTextAttribute(hConsole, saved_attributes);

*/