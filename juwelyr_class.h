#pragma once
#include "header.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <iomanip>
#include <memory>

using namespace std;

void EditCursor(int hight, int width)
{
	COORD position = { hight, width };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void Line(int a)
{
	for (int i = 0; i < a; i++)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"─";
		_setmode(_fileno(stdout), _O_TEXT);
	}
}

void LineUp()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"│";
	_setmode(_fileno(stdout), _O_TEXT);
}

void LineUpUgol(int a)
{
	if (a == 1)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"┌";
		_setmode(_fileno(stdout), _O_TEXT);
	}
	else if (a == 2)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"└";
		_setmode(_fileno(stdout), _O_TEXT);
	}
	else if (a == 3)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"┐";
		_setmode(_fileno(stdout), _O_TEXT);
	}
	else if (a == 4)
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"┘";
		_setmode(_fileno(stdout), _O_TEXT);
	}
}



class Myexcept : public exception
{
public:
	Myexcept(const char* message) : exception(message)
	{

	}
};

class Jewel
{
private:
	string name;
	string type;
	string material;
	float weight;
	float price;

public:
	Jewel()
	{
		name = "underfined";
		type = "underfinde";
		material = "underfined";
		weight = 0;
		price = 0;
	}

	Jewel(string name, string type, string material, float weight, float price)
	{
		this->name = name;
		this->type = type;
		this->material = material;
		this->weight = weight;
		this->price = price;
	}

	void display_product(int quantity)
	{
		cout << setw(30) << name;
		LineUp();
		cout << setw(30) << type;
		LineUp();
		cout << setw(28) << material;
		LineUp();
		cout << setw(15) << weight;
		LineUp();
		cout << setw(15) << quantity;
		LineUp();
		cout << setw(10) << price;
		LineUp();
	}

	void set_info()
	{
			cout << "Введите название товара: ";
			getline(cin, this->name);
			cout << "Введите тип товара: ";
			getline(cin, this->type);
			cout << "Введите материал товара: ";
			getline(cin, this->material);
			cout << "Введите вес товара: ";
			if (!(cin >> this->weight))
				throw "Неверный тип";
			cout << "Введите цену товара: ";
			if (!(cin >> this->price))
				throw "Неверный тип";
	}

	float get_price()
	{
		return price;
	}


};

void termFunc()
{
	cout << "Экстренное завершение программы" << endl;
	system("pause");
	exit(-1);
}

class OrderLine
{
private:
	Jewel product;
	int quantity;
	float line_price;
	
public:
	OrderLine()
	{
		
		quantity = 0;
		line_price = 0;
	}

	OrderLine(const OrderLine& service)
	{
		product = service.product;
	}

	void display_OrderLine()
	{
		this->product.display_product(quantity);
	}

	void set_info(Jewel product, int quantity)
	{
		this->product = product;
		this->quantity = quantity;

		line_price = quantity * this->product.get_price();
	}

	void SetQuantity(int quantity)
	{
		this->quantity = quantity;
	}

	int getLinePrise()
	{
		return line_price;
	}
};

class Order
{
private:
	OrderLine *line;
	int count_OrderLine;
	float total_price;

public:
	Order()
	{
		line = new OrderLine[1];
		count_OrderLine = 0;
		total_price = 0;
	}

	void display_Order(int j)
	{
		LineUp();
		cout << setw(4) << left << j + 1;
		LineUp();
		cout << setw(15) << left << total_price;
		LineUp();
		for (int i = 0; i < this->count_OrderLine; i++)
		{
			line[i].display_OrderLine();
			if (i + 1 != this->count_OrderLine)
			{
				LineUp();
				cout << setw(4) << left << " ";
				LineUp();
				cout << setw(15) << left << " ";
				LineUp();
			}
		}
		cout << endl;
		LineUp();
		Line(154);
		LineUp();
	}

	void remove_order(int number, int count)
	{

	}

	void add_OrderLine(Jewel product, int quantity, int number)
	{
		OrderLine* newLine;
		bad_alloc exept;
		try {
			if (!(newLine = new OrderLine[1000000000]))
				throw exept;
		}
		catch (bad_alloc exept) {
			cout << "Возникло исключение " << exept.what() << endl;
			system("pause");
			newLine = new OrderLine[count_OrderLine + 1];
		}

		for (int i = 0; i < count_OrderLine; ++i)
		{
			newLine[i] = line[i];
		}

		delete[] line;

		newLine[count_OrderLine].set_info(product, quantity);
		//newLine[count_OrderLine].SetQuantity(quantity);
		total_price += newLine[count_OrderLine].getLinePrise();

		++count_OrderLine;
		line = new OrderLine[count_OrderLine];
		line = newLine;

	}

	float get_TotalPrice()
	{
		return total_price;
	}

	int get_count_OrderLine()
	{
		return count_OrderLine;
	}

	void set_count_OrderLine(int count_OrderLine)
	{
		this->count_OrderLine = count_OrderLine;
	}
};

class Person
{
protected:
	string name;
	string surname;
	string address;
public:
	Person()
	{
		name = "Неопределено";
		surname = "Неопределено";
		address = "Неопределено";
	}

	virtual void SetPersonal_data() = 0;
	virtual void Display_contact() = 0;

	string GetSurname()
	{
		return surname;
	}

	string GetName()
	{
		return name;
	}

	string GetAddress()
	{
		return address;
	}
};

class Manager : public Person
{
private:

public:
	Manager()
	{

	}

	void SetPersonal_data() override
	{
		cout << "Введите фамилию: ";
		cin >> this->surname;
		cout << "Введите имя: ";
		cin >> this->name;
	}

	void Display_contact() override
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"⠀   ⢀⣤⣶⡶⠿⠿⠿⠿⢶⣶⣤⡀⠀⠀" << endl;
		wcout << L"⠀⠀⣠⣾⠟⠉⠀⠀⠀ ⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
		wcout << L"⠀⣴⡟⠁⠀⠀⠀⢰⣿⣿⣿⣿⡆⠀⠀⠀⠈⢻⣦⠀" << endl;
		wcout << L"⢸⡿⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⢿⡇" << endl;
		wcout << L"⣿⡇⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⢸⣿" << endl;
		wcout << L"⣿⡇⠀⠀⠀⠀⠀⠀⣸⣿⣿⣃⠀⠀⠀⠀⠀⠀⢸⣿" << endl;
		wcout << L"⢸⣷⠀⠀⠀⣴⣾⣿⣿⣿⣿⣿⣿⣷⣦⠀⠀⠀⣼⡇" << endl;
		wcout << L" ⠻⣧⡀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⢀⣼⠟⠀" << endl;
		wcout << L"⠀ ⠙⢿⣦⣀⠀⠀⠉⠉⠉⠁⠀⠀⣀⣴⡿⠋⠀⠀" << endl;
		wcout << L"⠀   ⠈⠛⠿⠷⣶⣶⣶⣶⠶⠿⠛⠁⠀⠀⠀⠀" << endl;
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "       Менеджер" << endl;
		Line(156);
		for (int i = 0; i < 11; i++)
		{
			EditCursor(21, i);
			LineUp();
		}

		EditCursor(23, 0);
		cout << "Фамилия: " << this->surname;
		EditCursor(23, 2);
		cout << "Имя: " << this->name;

		EditCursor(0, 13);
	}

	void Add_product(Jewel *product, int count_product, int *quantity)
	{
			product[count_product].set_info();
			cout << "Введите количество товара: ";
			if (!(cin >> quantity[count_product]))
				throw "Неверный тип";
			getchar();
	}

	void Display_product(Jewel* product, int count_product, int* quantity)
	{
		LineUpUgol(1);
		Line(139);
		LineUpUgol(3);
		cout << endl;

		LineUp();
		cout << setw(5) << left << " №";
		LineUp();
		cout << setw(30) << left << "                  Название";
		LineUp();
		cout << setw(30) << left << "            Тип";
		LineUp();
		cout << setw(28) << left << "          Материал";
		LineUp();
		cout << setw(15) << left << "    Вес (г)";
		LineUp();
		cout << setw(15) << left << "   Количество";
		LineUp();
		cout << setw(10) << left << "Цена (BYN)";
		LineUp();

		cout << endl;
		LineUp();
		Line(139);
		LineUp();

		cout << endl;
		for (int i = 0; i < count_product; i++)
		{
			LineUp();
			cout << setw(5) << left << i + 1;
			LineUp();
			product[i].display_product(quantity[i]);
			cout << endl;
			if (i != count_product - 1)
			{
				LineUp();
				Line(139);
				LineUp();
			}
			else
			{
				LineUpUgol(2);
				Line(139);
				LineUpUgol(4);
			}
			cout << endl;
		}

		cout << endl << endl;
	}

	void AddOrder()
	{

	}

	void Display_order()
	{

	}

	void delete_Order()
	{}

	void deleteOrder(Jewel* product, int &count_product, int* quantity, int count)
	{
		for (int i = count - 1; i < count_product - 1; i++)
		{
			product[i] = product[i + 1];
		}

		count_product--;

		Jewel* newProduct = new Jewel[count_product];

		for (int i = 0; i < count_product; ++i)
		{
			newProduct[i] = product[i];
		}

		product = newProduct;
	}
};

class Customer : public Person
{
private:
	float credit;
	Order *order;
	int count_Order;

public:
	Customer()
	{
		order = nullptr;
		credit = 0;
		count_Order = 0;
	}

	Customer(float credit)
	{
		this->order = order;
		if (credit <= 0)
			throw exception("Передано неверное значение");
		this->credit = credit;
	}

	void Add_product(Jewel* product, int& count_product, int* quantity)
	{
		int number;
		int count;

		Order* newOrder = new Order[count_Order + 1];

		for (int i = 0; i < count_Order; ++i)
		{
			newOrder[i] = order[i];
		}

		int* number_ = new int[1];
		int* count_ = new int[1];
		int cout_ = 0;
		char exit;
		do {
			Display_product(product, count_product, quantity);

			int* new_number = new int[cout_ + 1];
			int* new_count = new int[cout_ + 1];

			cout << endl << "Введите номер товара: ";
			if (!(cin >> number) || number <= 0 || number > count_product)
				throw exception("1");
			cout << "Введите количество товара: ";
			if (!(cin >> count) || count <= 0 || count > count_product)
				throw exception("1");

			for (int i = 0; i < cout_ + 1; i++)
			{
				new_number[i] = number;
				new_count[i] = count;
			}

			delete[] number_;
			delete[] count_;

			cout_++;
			number_ = new int[cout_];
			count_ = new int[cout_];

			for (int i = 0; i < cout_ + 1; i++)
			{
				number_[i] = new_number[i];
				count_[i] = new_count[i];
			}

			delete[] new_number;
			delete[]  new_count;

			// make exception whith try
				if (quantity[number - 1] - count < 0)
				{
					system("cls");
					throw Myexcept("Данного товара не хватает");
				}
				quantity[number - 1] -= count;
				newOrder[count_Order].add_OrderLine(product[number - 1], count, number);

			if (quantity[number - 1] == 0)
			{
 				for (int i = number - 1; i < count_product - 1; i++)
				{
					product[i] = product[i + 1];
				}

				for (int i = number - 1; i < count_product - 1; i++)
				{
					quantity[i] = quantity[i + 1];
				}

				count_product--;

				Jewel* newProduct = new Jewel[count_product];
				int* newQuantity = new int[count_product];

				for (int i = 0; i < count_product; ++i)
				{
					newQuantity[i] = quantity[i];
				}

				for (int i = 0; i < count_product; ++i)
				{
					newProduct[i] = product[i];
				}

				/*delete[] quantity;
				delete[] product;

				quantity = new int[count_product];
				product = new Jewel[count_product];*/

				for (int i = 0; i < count_product; ++i)
				{
					product[i] = newProduct[i];
				}

				for (int i = 0; i < count_product; ++i)
				{
					quantity[i] = newQuantity[i];
				}
			}
			cout << endl << "Для выхода нажмите клавишу ESP, для продолжерия любую другую клавишу";
			exit = _getch();
			system("cls");
			Display_contact();
		} while (exit != 27);

		if (this->credit < newOrder[count_Order].get_TotalPrice())
		{
			for (int i = 0; i < cout_; i++)
				quantity[number_[i] - 1] += count_[i];
			throw Myexcept("Недостаточно средств");
		}

		//newOrder[count_Order]

		count_Order++;
		delete[] order;
		order = new Order[count_Order];
		order = newOrder;
		this->credit -= order[count_Order - 1].get_TotalPrice();
	}

	void delete_Order()
	{
		int count_;
		cout << "Введите номер заказа, который хотите отменить: ";
		if (!(cin >> count_) || count_ <= 0 || count_ > count_Order)
			throw exception("1");
		this->credit += order[count_ - 1].get_TotalPrice();
		for (int i = count_ - 1; i < count_Order - 1; i++)
		{
			order[i] = order[i + 1];
		}

		count_Order--;

		Order *newOrder = new Order[count_Order];

		for (int i = 0; i < count_Order; ++i)
		{
			newOrder[i] = order[i];
		}

		order = newOrder;
	}

	void deleteOrder(Jewel* product, int count_product, int* quantity, int count)
	{

	}

	void Display_product(Jewel* product, int count_product, int* quantity)
	{
		LineUpUgol(1);
		Line(139);
		LineUpUgol(3);
		cout << endl;

		LineUp();
		cout << setw(5) << left << " №";
		LineUp();
		cout << setw(30) << left << "                  Название";
		LineUp();
		cout << setw(30) << left << "            Тип";
		LineUp();
		cout << setw(28) << left << "          Материал";
		LineUp();
		cout << setw(15) << left << "    Вес (г)";
		LineUp();
		cout << setw(15) << left << "   Количество";
		LineUp();
		cout << setw(10) << left << "Цена (BYN)";
		LineUp();

		cout << endl;
		LineUp();
		Line(139);
		LineUp();

		cout << endl;
		for (int i = 0; i < count_product; i++)
		{
			LineUp();
			cout << setw(5) << left << i + 1;
			LineUp();
			product[i].display_product(quantity[i]);
			cout << endl;
			if (i != count_product - 1)
			{
				LineUp();
				Line(139);
				LineUp();
			}
			else
			{
				LineUpUgol(2);
				Line(139);
				LineUpUgol(4);
			}
			cout << endl;
		}

		cout << endl << endl;
	}

	void SetPersonal_data() override
	{
		cout << "Введите фамилию: ";
		cin >> this->surname;
		cout << "Введите имя: ";
		cin >> this->name;
		cout << "Введите адрес: ";
		getchar();
		getline(cin, this->address);
		cout << "Введите количество денежные средства: ";
		cin >> this->credit;
		if (this->credit <= 0)
			throw exception("Количество денежных средств является натуральным числом. Попробуйте снова");

	}

	void Display_contact() override
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"    ⢀⣤⣶⠶⠟⠛⠛⠻⠶⣶⣤⡀⠀⠀⠀⠀" << endl;
		wcout << L"⠀⠀⣠⣾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
		wcout << L"⠀⣴⡟⠁⠀⠀⠀⣠⣴⠶⠶⣦⣄⠀⠀⠀⠈⢻⣦⠀" << endl;
		wcout << L"⢸⡟⠀⠀⠀⠀⣾⠋⠀⠀⠀⠀⠙⣷⠀⠀⠀⠀⢻⣇" << endl;
		wcout << L"⣿⠁⠀⠀⠀⠸⣿⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠈⣿" << endl;
		wcout << L"⣿⡀⠀⠀⠀⠀⠻⣦⣀⠀⠀⣀⣴⠟⠀⠀⠀⠀⢀⣿" << endl;
		wcout << L"⢸⣧⠀⠀⠀⢀⣤⡾⠿⠛⠛⠿⢷⣤⡀⠀⠀⠀⣼⡏" << endl;
		wcout << L"⠀⠻⣧⡀⢠⡿⠉⠀⠀⠀⠀⠀⠀⠉⢿⡄⢀⣼⠟⠀" << endl;
		wcout << L"  ⠙⢿⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⣈⣿⡿⠋⠀⠀" << endl;
		wcout << L"⠀ ⠀⠀⠈⠛⠿⢶⣦⣤⣤⣴⡶⠿⠛⠁⠀⠀" << endl;
		_setmode(_fileno(stdout), _O_TEXT);
		cout << "    Пользователь" << endl;
		Line(156);
		for (int i = 0; i < 11; i++)
		{
			EditCursor(21, i);
			LineUp();
		}

		EditCursor(23, 0);
		cout << "Фамилия: " << this->surname;
		EditCursor(23, 2);
		cout << "Имя: " << this->name;
		EditCursor(23, 4);
		cout << "Адрес: " << this->address;
		EditCursor(23, 6);
		cout << "Денежные средства: " << this->credit;

		EditCursor(0, 13);
	}

	void Display_order()
	{
		LineUpUgol(1);
		Line(154);
		LineUpUgol(3);
		cout << endl;

		LineUp();
		cout << setw(20) << left << "       Заказ";
		LineUp();
		cout << setw(30) << left << "         Название";
		LineUp();
		cout << setw(30) << left << "            Тип";
		LineUp();
		cout << setw(28) << left << "          Материал";
		LineUp();
		cout << setw(15) << left << "    Вес (г)";
		LineUp();
		cout << setw(15) << left << "   Количество";
		LineUp();
		cout << setw(10) << left << "Цена (BYN)";
		LineUp();

		cout << endl;
		LineUp();
		Line(20);
		LineUp();
		cout << setw(30) << " ";
		LineUp();
		cout << setw(30) << " ";
		LineUp();
		cout << setw(28) << " ";
		LineUp();
		cout << setw(15) << " ";
		LineUp();
		cout << setw(15) << " ";
		LineUp();
		cout << setw(10) << " ";
		LineUp();

		cout << endl;
		LineUp();
		cout << setw(4) << left << " №";
		LineUp();
		cout << setw(10) << left << "Общая стоимость";
		LineUp();
		cout << setw(30) << " ";
		LineUp();
		cout << setw(30) << " ";
		LineUp();
		cout << setw(28) << " ";
		LineUp();
		cout << setw(15) << " ";
		LineUp();
		cout << setw(15) << " ";
		LineUp();
		cout << setw(10) << " ";
		LineUp();

		cout << endl;
		LineUp();
		Line(154);
		LineUp();

		float all_price = 0;
		cout << endl;
		for (int i = 0; i < count_Order; i++)
		{
			order[i].display_Order(i);
			all_price += order[i].get_TotalPrice();
		}

		LineUp();
		cout << "Стоимость всех заказов: " <<setw(126) << left << all_price << left << " BYN";
		LineUp();
		LineUpUgol(2);
		Line(154);
		LineUpUgol(4);

		cout << endl << endl;
	}

	float GetCredit()
	{
		return credit;
	}

};