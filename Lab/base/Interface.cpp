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
	} while (code != 6);
}