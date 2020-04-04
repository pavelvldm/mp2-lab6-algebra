#include "Interface.h"

void printTableList(const string& str)
{
	cout << str << endl;
	cout << " 1 - Линейная таблица на массиве" << endl;
	cout << " 2 - Линейная таблица на списке" << endl;
	cout << " 3 - Упорядоченная таблица на массиве" << endl;
	cout << " 4 - Авл-дерево" << endl;
	cout << " 5 - Хеш-таблица на массиве" << endl;
	cout << " 6 - Хеш-таблица на списке" << endl;
}

void printMenuList(const string& str)
{
	cout << str << endl;
	cout << " 1 - Добавить полином" << endl;
	//
	cout << " 2 - Найти по имени полином и поиздеваться над ним" << endl;
	cout << " 3 - Ввести арифметическое выражение" << endl;
	cout << " 4 - Вывести все полиномы" << endl;
	cout << " 5 - Выход" << endl;
}

void printPolynomOperation(const string& str)
{
	cout << str << endl;
	cout << " 1 - Изменить полином" << endl;
	cout << " 2 - Посчитать полином в точке" << endl;
	cout << " 3 - Проинтегрировать по X" << endl;
	cout << " 4 - Проинтегрировать по Y" << endl;
	cout << " 5 - Проинтегрировать по Z" << endl;
	cout << " 6 - Выход" << endl;
}

void printExit(const string& str)
{
	cout << str << endl;
	cout << " 0 - Нет" << endl;
	cout << " 1 - Да" << endl;
}

void keyRools()
{
	cout << " 1. Вводить имя(ключ) можно только используя маленькие буквы" << endl;
	cout << " 2. Без использования цифр и всяких непристойных знаков (например, _*/!\.,)" << endl;
	cout << " 3. Без цифр" << endl;
}

void polynomRools()
{
	cout << " 1. Правила по вводу полиномов я не помню, так что на свой страх и риск вводите" << endl;
}

void panika(int k)
{
	if (k == 10)
	{
		cout << "НЕ ПАНИКУЙ" << endl;
		cout << "Может стоит прочитать правила повнимательней" << endl;
		cout << "Надеюсь в следующий раз все получится" << endl;
	}
	if (k == 20)
	{
		cout << "Меня терзают смутные сомнения." << endl;
		cout << "Правила выводятся каждый раз, неужели так сложно ввести правильно" << endl;
	}
	if (k == 30)
	{
		cout << "А вы часом не тупенький?" << endl;
		cout << "Ну, что вы, это не оскорбление, а констатация факта" << endl;
		cout << "Разработчики почти приносят извинения за дерзость компьютера" << endl;
	}
	if (k == 40)
	{
		cout << "Остановите его кто-нибудь!" << endl;
		cout << "Введи хотя бы х!" << endl;
		cout << "Без восклицательного знака. Это так предосторожность" << endl;
	}
	if (k == 41)
	{
		cout << "Господи, я же дал подсказку, что можно ввести!" << endl;
		cout << "Неужели можно быть таким ..." << endl;
		cout << "Пожалуйста, кто-нибудь, введите правильно уже!" << endl;
	}
	if (k == 42)
	{
		cout << "Так и быть, дам ответ на главный вопрос жизни, вселенной и всего такого..." << endl;
		cout << "____" << endl;
		cout << "|42|" << endl;
		cout << "|__|" << endl;
	}
	if (k == 50)
	{
		cout << "Это уже 50 попытка ... " << endl;
	}
	if (k > 50)
	{
		cout << "ПОМОГИТЕ!!!" << endl;
	}
	
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

void Interface::controlPolynom(const string& str)
{
	//add something
}

int Interface::inputControl(string left_board, string right_board, void (*print)(const string&), const string& str)
{
	string number;
	bool flag;
	do
	{
		flag = false;
		print(str);
		//cin >> number;
		getline(cin, number);
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
	int code = inputControl("1", "6", printTableList, " ");
	switch (code)
	{
	case 1: Base = new LineTable; break;
	case 2: Base = new LinTabList; break;
	case 3: Base = new ordered_line_table; break;
	case 4: Base = new TableTree; break;
	case 5: Base = new hash_table_on_lists; break;
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
		//cout << "----------------------Меню----------------------" << endl;
		//cout << "  Для выбора, введите соответствующую клавишу." << endl;
		code = inputControl("1", "5", printMenuList, "----------------------Меню----------------------\n  Для выбора, введите соответствующую клавишу.\n");
		switch (code)
		{
		case 1: Add(); break;
		case 2: Search(); break;
		case 3: break;
		case 4: Print(); break;
		}
	} while (code != 5);
}

void Interface::Add()
{
	Data d;
	cout << "Правила ввода! Просьба их соблюдать! НАДЕЮСЬ, Я ПОНЯТНО ОБЬЯСНЯЮ" << endl;
	cout << "Великий свод правил:"<< endl;
	//cout << " 1. Вводить имя(ключ) можно только используя маленькие буквы" << endl;
	//cout << " 2. Без использования цифр и всяких непристойных знаков (например, _*/!\.,)" << endl;
	//cout << " 3. Без цифр" << endl;
	keyRools();
	//cout << " 4. Правила по вводу полиномов я не помню, так что на свой страх и риск вводите" << endl;
	polynomRools();
	cout << "Если что-то введено будет неправильно будет выдана ошибка (я не позволю испортит труд 3 человек)" << endl;
	cout << "Удачи :) " << endl;
	try
	{
		string temp;
		cout << "Введите имя полинома: ";
		//cin >> d.key;
		getline(cin, d.key);
		//cout << d.key << "!" << endl;
		controlKey(d.key);
		cout << "Введите сам полинома: ";
		//cin >> d.PolyString;
		getline(cin, d.PolyString);
		controlPolynom(d.PolyString);
		//cout << d.PolyString << "!" << endl;
		Polynom p(d.PolyString);
		//d.Poly.CreatePolynom(d.PolyString);
		d.Poly = p;
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

void Interface::changePolynom(Data* d)
{
	bool flag = false;
	int count = 0;
	string poly;
	do
	{
		cout << "Свод правил:" << endl;
		polynomRools();
		flag = false;
		panika(count);
		try 
		{
			cout << "Введите новый полином: ";
			getline(cin, poly);
			controlPolynom(poly);
		}
		catch (int code)
		{
			exceptionHandling(code);
			flag = true;
			cout << "\nОШИБКА!!!!!!!! Попробуйте ввести заново" << endl;
		}
		count++;
	} 
	while (flag);
	d->PolyString = poly;
	Polynom temp(poly);
	d->Poly = temp;
	cout << "Изменения прошли успешно" << endl;
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::countPolynom(Data* d)
{
	cout << "Просьба вводить цифры. Если что-то сломается, значит таков путь. " << endl;
	double x, y, z;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	double res = d->Poly.ValuePoint(x, y, z);
	cout << "Результат вычислений: " << res << endl;
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::Integral(Data* d, int code)
{
	Polynom temp = d->Poly;
	Polynom temp2;
	string varity;
	switch (code)
	{
	case 1: temp2 = d->Poly.IntegrateDX(); d->Poly = temp; temp = temp2; break; //temp = d->Poly.IntegrateDX(); varity = "x"; break;
	case 2: temp2 = d->Poly.IntegrateDY(); d->Poly = temp; temp = temp2; break; //temp = d->Poly.IntegrateDY(); varity = "y"; break;
	case 3: temp2 = d->Poly.IntegrateDZ(); d->Poly = temp; temp = temp2; break; //temp = d->Poly.IntegrateDZ(); varity = "z"; break;
	}
	string str;
	str = "Исходный полином: " + d->PolyString;
	str = str + "\nИнтеграл от этого полинома по переменной " + varity + ": " + temp.CreateString();
	str = str + "\nЖелаете сохранить этот полином в таблице?\n";
	//cout << "Исходный полином: " << d->Poly << endl;
	//cout << "Интеграл от этого полинома по переменной" << varity << ": " << temp << endl;
	//cout << "Желаете сохранить этот полином в таблице? " << endl << endl;
	int k = inputControl("0", "1", printExit, str);
	if (k == 1)
	{
		
	}
	system("cls");
}

void Interface::Search()
{
	string key;
	Data* d;
	while (1 > 0) 
	{
		cout << "Введите имя: ";
		getline(cin, key);
		d = Base->Find(key);
		system("cls");
		if (d == nullptr)
		{
			cout << "Такого полинома нет" << endl;
		}
		else
		{
			int cod;
			do
			{
				string temp = "Имя полинома: " + d->key + "\nНайденный полином: " + d->PolyString;
				cod = inputControl("0", "6", printPolynomOperation, temp);
				switch (cod)
				{
				case 1: changePolynom(d); break;
				case 2: countPolynom(d); break;
				case 3: Integral(d, 1); break;
				case 4: Integral(d, 2); break;
				case 5: Integral(d, 3); break;
				}
			} 
			while (cod != 6);
		}
		cout << "Раздел - Найти полином" << endl;
		cout << "Попробовать еще?" << endl;
		int code = inputControl("0", "1", printExit, "");
		if (code == 0)
			break;
		system("cls");
	}
}

