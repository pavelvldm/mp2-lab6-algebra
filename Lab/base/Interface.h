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

class Interface
{
	BaseTable* Base;
	int inputControl(string left_board, string right_board, void (*print)());
	void exceptionHandling(int code);
	void controlKey(const string& key);
public:
	Interface()
	{
		Base = nullptr;
	}
	void Menu();
	void tableSelection();
	void Add();
	void Print();
};

void printTableList();
void printMenuList();
#endif