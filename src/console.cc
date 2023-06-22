#include <iostream>
#include <windows.h>
#include <function/functions.h>
#include <stdexcept>
#include <string>



using namespace std;

void menu() {
	system("cls");
	cout << "��� �� ������ �������? ������� ����� �� 1 �� 6" << endl;
	cout << "1 - �������� ������� � ������ �� ���������� �������" << endl;
	cout << "2 - ������� ������� �� ������ �� ���������� �������" << endl;
	cout << "3 - ������� ������ �� �����" << endl;
	cout << "4 - ������ ������" << endl;
	cout << "5 - ������ ���� � ������������ ��������" << endl;
	cout << "6 - ��������� ���������" << endl;
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
			std::cout << "�������� ������" << endl;
			std::cin >> idx;
			std::cout << "������� ���: (0-����������, 1-�������������, 2-���������)" << endl;
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
			std::cout << "������� ������ ���������� ��������" << endl;
			std::cin >> idx;
			f.remove(idx);
			break;
		case 3:
			system("cls");
			f.show_all();
			break;
		case 4:
			system("cls");
			std::cout << "������� ������: ";
			std::cin >> idx;
			b = f[idx]->accrual();
			std::cout << "������: " << b << endl;
			break;
		case 5:
			system("cls");
			idx = f.max_balance();
			std::cout << "������ ����� � ������������ ��������: " << idx << endl;
			break;
		}
		if (s != 6) {
			system("pause");
		}
	}
}
