#pragma once
#include <iostream>
#include "List.h"

class Console
{
public:
	Console() = default;
	~Console() = default;
	void start();
private:
	List _list;
	int dialog_get_data();
	void dialog_push_front();
	void dialog_push_back();
	void dialog_pop_front();
	void dialog_pop_back();
	void dialog_print_list();
	void dialog_insert();
	void dialog_swap();
	void print_menu() const;
};