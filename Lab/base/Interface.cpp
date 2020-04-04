#include "Interface.h"

void printTableList()
{
	cout << " 1 - Линейная таблица на массиве" << endl;
	cout << " 2 - Линейная таблица на списке" << endl;
	cout << " 3 - Упорядоченная таблица на массиве" << endl;
	cout << " 4 - Авл-дерево" << endl;
	cout << " 5 - Хеш-таблица на массиве" << endl;
	cout << " 6 - Хеш-таблица на списке" << endl;
}

void printMenuList()
{
	cout << " 1 - Добавить полином" << endl;
	cout << " 2 - Найти по имени полином" << endl;
	cout << " 3 - Ввести арифметическое выражение" << endl;
	cout << " 4 - Вывести все полиномы" << endl;
	cout << " 5 - Посчитать полином" << endl;
	cout << " 6 - Выход" << endl;
}

void Interface::exceptionHandling(int code)
{
	switch (code)
	{
	case 1: cout << "Пусто" << endl; break;
	case 2: cout << "Нет такого ключа" << endl; break;
	case 3: cout << "Уже есть объект с таким ключом" << endl; break;
	case 4: cout << "Неверный ключ" << endl; break;
	case 5: cout << "Нет места" << endl; break;
	case 6: cout << "Неверная степень" << endl; break;
	case 7: cout << "Несовпадение степеней мономов" << endl; break;
	}
}

void Interface::controlKey(const string& key)
{
	//здесь что-то будет
}

int Interface::inputControl(string left_board, string right_board, void (*print)())
{
	string number;
	bool flag;
	do
	{
		flag = false;
		print();
		cin >> number;
		system("cls");
		if ((number > right_board) || (number < left_board) || (number.length() != 1))
		{
			cout << "ОШИБКА ВВОДА! ВВЕДИТЕ ЕЩЕ РАЗ!" << endl;
			flag = true;
		}
	} while (flag);
	return stoi(number);
}

void Interface::tableSelection()
{
	int code = inputControl("1", "6", printTableList);
	switch (code)
	{
	case 1: Base = new LineTable; break;
	case 2: Base = new LinTabList; break;
	case 3: Base = new LineTable; break;
	case 4: Base = new TableTree; break;
	case 5: Base = new TableTree; break;
	case 6: Base = new HashTabLin; break;
	}
}

void Interface::Menu()
{
	cout << "Выберите таблицу, которой хотите пользоваться" << endl;
	tableSelection();
	int code;
	do
	{
		cout << "----------------------Меню----------------------" << endl;
		cout << "  Для выбора, введите соответствующую клавишу." << endl;
		code = inputControl("1", "6", printMenuList);
		switch (code)
		{
		case 1: Add(); break;
		case 2: break;
		case 3: break;
		case 4: Print(); break;
		case 5: break;
		}
	} while (code != 6);
}

void Interface::Add()
{
	Data d;
	cout << "Правила ввода! Просьба их соблюдать! НАДЕЮСЬ Я ПОНЯТНО ОБЬЯСНЯЮ" << endl;
	cout << "Великий свод правил:"<< endl;
	cout << " 1. Вводить имя(ключ) можно только используя маленькие буквы" << endl;
	cout << " 2. Без использования цифр и всяких непристойных знаков (например, _*/!\.,)" << endl;
	cout << " 3. Без цифр" << endl;
	cout << " 4. Правила по вводу полиномов я не помню, так что на свой страх и риск вводите" << endl;
	cout << "Если что-то введено будет неправильно будет выдана ошибка (я не позволю испортит труд 3 человек)" << endl;
	cout << "Удачи :) " << endl;
	try
	{
		cout << "Введите имя полинома: ";
		cin >> d.key;
		controlKey(d.key);
		cout << "Введите сам полинома: ";
		getline(cin,d.PolyString);
		d.Poly.CreatePolynom(d.PolyString);
		Base->Insert(d);
	}
	catch (int code)
	{
		exceptionHandling(code);
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::Print()
{
	Base->Print();
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}