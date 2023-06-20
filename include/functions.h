#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Account {
protected:
	Account() = default; //поля+дефолтный конструктор
	string name;
	double balance;
	double percent;

public:
	Account(const Account& rhs) = delete; //правило трех
	Account& operator=(const Account& rhs) = delete;
	virtual ~Account()=default;

	string get_name() const; //гетеры и сетеры
	double get_balance() const;
	void set_name(string name);
	void set_balance(double balance);

	virtual double accrual(double balance, double percent) const = 0; //метод для функционала

	virtual unique_ptr<Account> clone() const = 0; //методы для сравнения, копирования и принт
	virtual bool equals(shared_ptr<Account>) const = 0;
	virtual void print(ostream& out) const = 0;

};

class Settlement : public Account {
public:
	Settlement();
	Settlement(string name, double balance);
	~Settlement();

	virtual unique_ptr<Account> clone() const override;
	virtual bool equals(shared_ptr<Account>) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual(double balance, double percent) const override = 0;

	friend std::istream& operator>>(std::istream& in, shared_ptr<Account>& t);

};

class Deposit : public Account {
public:
	Deposit();
	Deposit(string name, double balance);
	Deposit();

	virtual unique_ptr<Account> clone() const override;
	virtual bool equals(shared_ptr<Account>) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual(double balance, double percent) const override;

	friend std::istream& operator>>(std::istream& in, shared_ptr<Deposit>& t);

};

class Credit : public Account {
public:
	Credit();
	Credit(string name, double balance);
	Credit();

	virtual unique_ptr<Account> clone() const override;
	virtual bool equals(shared_ptr<Account>) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual(double balance, double percent) const override;

	friend std::istream& operator>>(std::istream& in, shared_ptr<Credit>& t);

};


class AccountList {

	vector <Account> _account;
};