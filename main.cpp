#include "juwelyr_class.h"
#include "header.h"


template <class T>
void make(T& person, Jewel * &product, int& count_product, int * &quantity)
{
	int choice_;
	do
	{
		system("cls");
		person.Display_contact();

		cout << "1. Ввод личных данных" << endl;
		if (is_same<T, Customer>::value)
		{
			cout << "2. Сделать заказ" << endl;
			cout << "3. Посмотреть заказы" << endl;
			cout << "4. Отменить заказ" << endl;
		}
		else
		{
			cout << "2. Заказать товар" << endl;
			cout << "3. Посмотреть заказанные товары" << endl;
			cout << "4. Отменить заказанный товар" << endl;
		}
		cout << "5. Выход" << endl << endl;

		cout << "Сделайте выбор: ";
		while (true)
		{
			try {
				if (!(cin >> choice_) || cin.get() != '\n')
					throw istream::failure("Введите значения(1 - 5)");
				break;
			}
			catch (istream::failure& error)
			{
				cout << error.what() << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				system("pause");
			}
		}

		system("cls");
		person.Display_contact();

		switch (choice_)
		{
		case 1:
			do {
				try {
					person.SetPersonal_data();
					break;
				}
				catch (exception& error) {
					cout << error.what();
					cin.clear();
					cin.ignore(1024, '\n');
					system("pause");
					system("cls");
					person.Display_contact();
				}
			} while (true);
			break;
		case 2:
			if (is_same<T, Customer>::value)
			{
				try {
					person.Add_product(product, count_product, quantity);
				}
				catch (Myexcept& error) {
					cout << error.what() << endl;
					system("pause");
				}
				catch (...)
				{
					cout << "Данного товара не найдено" << endl;
					system("pause");
				}
			}
			else
			{
				char exit;
				do {

				Jewel* newProduct = new Jewel[count_product + 1];
				int *newQuantity = new int[count_product + 1];

				for (int i = 0; i < count_product; i++)
				{
					newProduct[i] = product[i];
					newQuantity[i] = quantity[i];
				}

				person.Add_product(newProduct, count_product, newQuantity);
				delete[] product;
				delete[] quantity;
				count_product++;

				product = new Jewel[count_product];
				quantity = new int[count_product];

				for (int i = 0; i < count_product; i++)
				{
					product[i] = newProduct[i];
					quantity[i] = newQuantity[i];
				}

				delete[] newProduct;
				delete[] newQuantity;

				cout << endl << "Для выхода нажмите клавишу ESP, для продолжерия любую другую клавишу";
				exit = _getch();
				system("cls");
				person.Display_contact();
				} while (exit != 27);
			}
			break;
		case 3:
			if (is_same<T, Customer>::value)
			{
				person.Display_order();
			}
			else
			{
				person.Display_product(product, count_product, quantity);
			}
			system("pause");
			break;
		case 4:
			system("cls");
			person.Display_contact();
			
			if (is_same<T, Customer>::value)
			{
				person.Display_order();
				try {
					person.delete_Order();
				}
				catch (...)
				{
					cout << "Данного товара не найдено" << endl;
					system("pause");
				}
			}
			else
			{
				person.Display_product(product, count_product, quantity);
				int count;
				cout << "Введите номер продукта, который хотите отменить: ";
				cin >> count;
				person.deleteOrder(product, count_product, quantity, count);
			}
			break;
		}
	} while (choice_ != 5); 
	
}


int main()
{
	set_terminate(termFunc);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int* quantity = new int[3]
		{
			int(3), int(1), int(4)
		};
	int count_product = 3;
	Jewel* product = new Jewel[3]
	{
		Jewel("Монах", "Кольцо", "Золото", 3, 120),
		Jewel("Пламя дракона", "Ожереьле", "Белое золото", 5, 480),
		Jewel("Древо", "Кулон", "Янтарь", 4, 80)
	};
	Manager manager;

	try {
		Customer customer_(-1);
	}
	catch (exception& error){
		cout << error.what() << endl;
		system("Pause");
		system("cls");
	}
	Customer customer(10000);

	int choice;
	do
	{
		cout << "1. Пользователь" << endl;
		cout << "2. Менеджер" << endl;
		cout << "3. Выход" << endl;
		cout << "Сделайте выбор: ";
		while (true)
		{
			try {
				if (!(cin >> choice) || cin.get() != '\n')
					throw istream::failure("Введите значения(1 - 5)");
				break;
			}
			catch (istream::failure& error)
			{
				cout << error.what() << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				system("pause");
			}
		}
		system("cls");

		switch (choice)
		{
		case 1:
			make(customer, product, count_product, quantity);
			break;
		case 2:
			make(manager, product, count_product, quantity);
			break;
		}

	} while (choice != 3);

}