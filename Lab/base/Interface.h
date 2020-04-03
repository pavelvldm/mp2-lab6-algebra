//#pragma once

#ifndef __INTERFACR_H__
#define __INTERFACE_H__

#include "LineTable.h"
#include "TreeTable.h"
#include "HashTabLin.h"
#include "hash_table_on_lists.h"
#include "ordered_line_table.h"
#include "LinTabList.h"

class Interface
{
	BaseTable* Base;
	int inputControl(string left_board, string right_board, void (*print)());
public:
	Interface()
	{
		Base = nullptr;
	}
	void Menu();
	void tableSelection();
};

void printTableList();
void printMenuList();
#endif