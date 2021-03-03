#include "Console.h"

void Console::start()
{
	bool operation = true;
	while (operation)
	{
		print_menu();

		int check = dialog_get_data();

		switch (check)
		{
		case 1:
			dialog_push_front();
			break;
		case 2:
			dialog_push_back();
			break;
		case 3:
			dialog_pop_front();
			break;
		case 4:
			dialog_pop_back();
			break;
		case 5:
			dialog_print_list();
			break;
		case 6:
			dialog_insert();
			break;
		case 7:
			dialog_swap();
			break;
		case 8:
			operation = false;
		}
	}
}

int Console::dialog_get_data()
{
	int data;
	std::cin >> data;
	return data;
}

void Console::dialog_push_front() 
{
	std::cout << "Введите число для добавления в голову: ";
	_list.push_front(dialog_get_data());
}

void Console::dialog_push_back() 
{
	std::cout << "Введите число для добавления в хвост: ";
	_list.push_back(dialog_get_data());
}

void Console::dialog_pop_front() 
{
	_list.pop_front();
}

void Console::dialog_pop_back() 
{
	_list.pop_back();
}

void Console::dialog_print_list()
{
	for (auto itr = _list.begin(); itr != _list.end(); itr++)
	{
		std::cout << " | " << *itr << " | " << std::endl;
	}
}

void Console::dialog_insert()
{
	std::cout << "Введите место куда добавить число: ";
	int count = dialog_get_data();

	std::cout << "Введите число для добавления: ";
	int data = dialog_get_data();

	try
	{
		auto it = _list.begin();
		for (int i = 0; i < count - 1; i++)
		{
			it++;
		}
		_list.insert(it, data);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void Console::dialog_swap()
{
	_list.swap();
}

void Console::print_menu() const
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Что вы хотите сделать?:" << std::endl;
	std::cout << "1. Добавить узел в голову списка" << std::endl;
	std::cout << "2. Добавить узел в хвост списка" << std::endl;
	std::cout << "3. Удалить узел из головы списка" << std::endl;
	std::cout << "4. Удалить узел из хвоста списка" << std::endl;
	std::cout << "5. Вывод спика" << std::endl;
	std::cout << "6. Добавить новый узел в указанную позицию" << std::endl;
	std::cout << "7. Поменять местами первый и последний узлы" << std::endl;
	std::cout << "8. Выход" << std::endl;
	std::cout << "-----------------------------" << std::endl;
}