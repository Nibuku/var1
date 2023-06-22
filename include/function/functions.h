#pragma once
#include <iostream>
#include <vector>
#include <memory>
#define ItemPtr shared_ptr<Account> 
using namespace std;

class Account {
protected:
	Account() = default; //поля+дефолтный конструктор
	Account(const Account& rhs) = delete; //правило трех
	Account& operator=(const Account& rhs) = delete;

	string name;
	double balance;

public:
	
	virtual ~Account()=default;

	string get_name() const; //гетеры и сетеры
	double get_balance() const;
	void set_name(string name);
	void set_balance(double balance);

	virtual double accrual() const = 0; //метод для функционала

	virtual shared_ptr<Account> clone() const = 0; //методы для сравнения, копирования и принт
	virtual bool equals(shared_ptr <Account> other) const = 0;
	virtual void print(ostream& out) const = 0;

};

using AccountPtr = shared_ptr <Account>;

class Settlement : public Account {
	double percent = 0;
public:
	Settlement();

	virtual AccountPtr clone() const override;
	virtual bool equals(AccountPtr other) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual() const;

	friend istream& operator>>(istream& in, shared_ptr<Settlement>& t);

};

class Deposit : public Account {
	double percent;
public:
	Deposit();
	Deposit(double percent);

	double get_percent() const;
	void set_percent(double percent);

	virtual AccountPtr clone() const override;
	virtual bool equals(AccountPtr other) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual() const override;

	friend istream& operator>>(istream& in, shared_ptr<Deposit>& t);

};

class Credit : public Account {
	double percent;
public:
	Credit();
	Credit(double percent); 

	double get_percent() const;
	void set_percent(double percent);

	virtual AccountPtr clone() const override;
	virtual bool equals(AccountPtr) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual() const override;

	friend std::istream& operator>>(std::istream& in, shared_ptr<Credit>& t);

};


class AccountList {

	vector <ItemPtr> _account; //вектор указателей типа Account

public: 

	AccountList();
	AccountList(const AccountList& other);
	AccountList& operator=(const AccountList& other);

	int size();
	void insert(int index, AccountPtr rhs);
	void remove(int index);

	int max_balance();

	ItemPtr operator[](int index) const;
	ItemPtr& operator[](int index);
	friend bool operator==(const AccountList& list, const AccountList& other);
	friend bool operator!=(const AccountList& list, const AccountList& other);
	AccountPtr get_index(int index);

	void Swap(AccountList& other);
	void show_all();
	void print_current(int index);
	void clear();
};