#pragma once
#include <iostream>
#include "List.h"

class Console
{
public:
	void start();
private:
	List _list;

	int dialog_cin_data();
	void dialog_push_front();
	void dialog_push_back();
	void dialog_pop_front();
	void dialog_pop_back();
	void dialog_print_list();

	void print_menu() const;
};