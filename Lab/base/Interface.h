//#pragma once

#ifndef __INTERFACR_H__
#define __INTERFACE_H__

#include "LineTable.h"
#include "TreeTable.h"
#include "HashTabLin.h"
#include "hash_table_on_lists.h"
#include "ordered_line_table.h"
#include "LinTabList.h"
#include <conio.h>
#include "postfix.h"

class Interface
{
	BaseTable* Base;
	int inputControl(string left_board, string right_board, void (*print)(const string&), const string& str);
	void exceptionHandling(int code);
	void controlKey(const string& key);
	void controlPolynom(const string& str);
	void tableSelection();
	void Add();
	void Print();
	void Search();
	void changePolynom(Data* d);
	void countPolynom(Data* d);
	void Integral(Data* d, int code);
public:
	Interface()
	{
		Base = nullptr;
	}
	void Menu();
};

void printTableList(const string& str);
void printMenuList(const string& str);
void printPolynomOperation(const string& str);
void printExit(const string& str);
void keyRools();
void polynomRools();
void panika(int k);
#endif