#include <iostream>
#include <windows.h>
#include <function/functions.h>
#include <stdexcept>
#include <string>



using namespace std;

void menu() {
	system("cls");
	cout << "Что вы хотите сделать? Введите цифру от 1 до 6" << endl;
	cout << "1 - вставить элемент в список по указанному индексу" << endl;
	cout << "2 - удалить элемент из списка по указанному индексу" << endl;
	cout << "3 - вывести список на экран" << endl;
	cout << "4 - узнать баланс" << endl;
	cout << "5 - узнать счет с максимальным балансом" << endl;
	cout << "6 - завершить программу" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int s = 0;
	int idx, type;
	int n;
	int m;
	int b = 0;
	string p;
	shared_ptr<Settlement> settlement = make_shared<Settlement>();
	shared_ptr<Credit> credit = make_shared<Credit>();
	shared_ptr<Deposit> deposit = make_shared<Deposit>();
	AccountList f = AccountList();
	while (s != 6) {
		menu();
		std::cin >> s;
		switch (s)
		{
		case 1:
			system("cls");
			std::cout << "Ввведите индекс" << endl;
			std::cin >> idx;
			std::cout << "Введите тип: (0-Рассчетный, 1-Накопительный, 2-Кредитный)" << endl;
			std::cin >> type;
			switch (type) {
			case 0:
				std::cin >> settlement;
				f.insert(idx, settlement);
				break;
			case 1:
				std::cin >> deposit;
				f.insert(idx, deposit);
				break;
			case 2:
				std::cin >> credit;
				f.insert(idx, credit);
				break;
			}
			break;

		case 2:
			system("cls");
			std::cout << "Введите индекс удаляемого элемента" << endl;
			std::cin >> idx;
			f.remove(idx);
			break;
		case 3:
			system("cls");
			f.show_all();
			break;
		case 4:
			system("cls");
			std::cout << "Введите индекс: ";
			std::cin >> idx;
			b = f[idx]->accrual();
			std::cout << "Баланс: " << b << endl;
			break;
		case 5:
			system("cls");
			idx = f.max_balance();
			std::cout << "Индекс счёта с максимальным балансом: " << idx << endl;
			break;
		}
		if (s != 6) {
			system("pause");
		}
	}
}
