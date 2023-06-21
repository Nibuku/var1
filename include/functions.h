#pragma once
#include <iostream>
#include <vector>
#include <memory>

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

	virtual double accrual(double balance, double percent) const = 0; //метод для функционала

	virtual unique_ptr<Account> clone() const = 0; //методы для сравнения, копирования и принт
	virtual bool equals(shared_ptr<Account>) const = 0;
	virtual void print(ostream& out) const = 0;

};

using AccountPtr = shared_ptr <Account>;

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
	double percent;
public:
	Deposit();
	Deposit(double percent);
	~Deposit();

	double get_percent() const;

	virtual unique_ptr<Account> clone() const override;
	virtual bool equals(shared_ptr<Account>) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual(double balance, double percent) const override;

	friend std::istream& operator>>(std::istream& in, shared_ptr<Deposit>& t);

};

class Credit : public Account {
	double percent;
public:
	Credit();
	Credit(double percent);
	~Credit();

	double get_percent() const;

	virtual unique_ptr<Account> clone() const override;
	virtual bool equals(shared_ptr<Account>) const override;
	virtual void print(ostream& out) const override;

	virtual double accrual(double balance, double percent) const override;

	friend std::istream& operator>>(std::istream& in, shared_ptr<Credit>& t);

};


class AccountList {

	vector <AccountPtr> _account;

public: 

	AccountList();
	AccountList(const AccountList& other);
	AccountList& operator=(const AccountList& other);

	int size();
	void add(int index, AccountPtr rhs);
	void remove(int index);

	string max_balance();

	AccountPtr operator[](int index) const;
	AccountPtr& operator[](int ind);
	AccountPtr& operator=(const AccountPtr& rhs);
	friend bool operator==(const AccountPtr& list, const AccountPtr& other);
	friend bool operator!=(const AccountPtr& list, const AccountPtr& other);
	AccountList& operator>>(AccountList& rhs);

	void Swap(AccountList& other) noexcept;
	void show_all();
	void clear();
};