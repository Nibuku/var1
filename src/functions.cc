#include <function\functions.h>
#include <stdexcept>
#include <cstdlib>


string Account::get_name() const {
    return name;
}
double Account::get_balance() const {
    return balance;
}
void Account::set_name(string name) {
    this->name = name;
}
void Account::set_balance(double balance) {
    this->balance = balance;
}

double Credit::get_percent() const {
    return percent;
}
void Credit::set_percent(double percent) {
    this->percent = percent;
}

double Deposit::get_percent() const {
    return percent;
}
void Deposit::set_percent(double percent) {
    this->percent = percent;
}


Settlement::Settlement() {
    name = "Александер Швепс";
    balance = 1000;
}
Credit::Credit() {
    name = "Александер Швепс";
    balance = 1000;
    percent = 0;
}
Deposit::Deposit() {
    name = "Александер Швепс";
    balance = 1000;
    percent = 0;
}
Deposit::Deposit(double persent) {
    name = "Марьяна Романова";
    balance = 1500;
    percent = 0.02;
}
Credit::Credit(double persent) {
    name = "Дмитрий Матвеев";
    balance = 500;
    percent = 0.03;
}

double Settlement::accrual() const {
    return balance;
}
double Deposit::accrual() const {
    return balance + (balance * percent) / 12;
}
double Credit::accrual() const {
    double n = abs(balance);
    return balance - (n * percent) / 12;
} 

AccountPtr Settlement::clone() const
{
    return make_shared<Settlement>();
}
AccountPtr Deposit::clone() const
{
    return make_shared<Deposit>(percent);
}
AccountPtr Credit::clone() const
{
    return make_shared<Credit>(percent);
}


bool Settlement::equals(AccountPtr other) const {
    const auto d_other = dynamic_pointer_cast<Settlement>(other);
    if (d_other == nullptr) {
        return false;
    }
    return (name == d_other->name && balance == d_other->balance);
}
bool Credit::equals(AccountPtr other) const {
    const auto d_other = dynamic_pointer_cast<Credit>(other);
    if (d_other == nullptr) {
        return false;
    }
    return (name == d_other->name && balance == d_other->balance && percent == d_other->percent);
}
bool Deposit::equals (AccountPtr other) const {
    const auto d_other = dynamic_pointer_cast<Deposit>(other);
    if (d_other == nullptr) {
        return false;
    }
    return (name == d_other->name && balance == d_other->balance && percent == d_other->percent);
}


void Settlement::print(ostream& out) const
{
    cout << "Settlement" << name << balance << endl;
}
void Credit::print(ostream& out) const
{
    cout << "Credit" << name << balance << percent<< endl;
}
void Deposit::print(ostream& out) const
{
    cout << "Deposit" << name << balance << percent << endl;
}

istream& operator>>(istream& in, shared_ptr<Settlement>& t)
{
    cout << "Введите имя владельца:\n ";
    in >> t->name;
    cout << "Введите текущий баланс:\n ";
    in >> t->balance;
    return in;
}
istream& operator>>(istream& in, shared_ptr<Credit>& t)
{
    cout << "Введите имя владельца:\n ";
    in >> t->name;
    cout << "Введите текущий баланс:\n ";
    in >> t->balance;
    cout << "Введите процет:\n";
    in >> t->percent;
    return in;
}
istream& operator>>(istream& in, shared_ptr<Deposit>& t)
{
    cout << "Введите имя владельца:\n ";
    in >> t->name;
    cout << "Введите текущий баланс:\n ";
    in >> t->balance;
    cout << "Введите процет:\n";
    in >> t->percent;
    return in;
}


AccountList::AccountList() {
    for (int i = 0; i < 6; ++i) {
       _account.push_back(make_shared<Settlement>());
    }
}

AccountList::AccountList(const AccountList& other) {
    this->_account = other._account;
}

void AccountList::Swap(AccountList& other)  {
    swap(_account, other._account);
}

AccountList& AccountList:: operator=(const AccountList& other) {
    AccountList copy(other);
    copy.Swap(*this);
    return *this;
}

int AccountList::size() {
    return static_cast<int>(_account.size());
}

void AccountList::insert(int index, AccountPtr rhs) {
    if (index > _account.size() || index < 0) {
        throw runtime_error("uncorrect index");
    }
    _account.insert(_account.begin() + index, rhs);
}

void AccountList::remove(int index) {
    if (index >= _account.size() || index < 0) {
        throw runtime_error("error1");
    }
    _account.erase(_account.begin() + index);
}

ItemPtr AccountList:: operator[](int index) const {
    if (index >= _account.size() || index < 0) {
        throw runtime_error("error1");
    }
    return _account[index];
}
ItemPtr& AccountList:: operator[](int index) {
    if (index >= _account.size() || index < 0) {
        throw runtime_error("error1");
    }
    return _account[index];
}
AccountPtr AccountList:: get_index(int index) {
    return _account[index];
}
bool operator==(const AccountList& list, const AccountList& other) {
    return ((list._account) == (other._account));
}
bool operator!=(const AccountList& list, const AccountList& other)
{
    return !(list == other);
}

void AccountList::print_current(int index) {
    _account[index]->print(cout);
}
void AccountList::show_all() {
    cout << "Текущий список:\n";
    for (int i = 0; i < _account.size(); ++i) {
        cout << i << ':';
        print_current(i);
        cout << endl;
    }
}

int AccountList::max_balance() {
    int index = 0;
    double max_balance = 0;
    for (int i = 0; i < _account.size(); ++i)
    {
        double cur_balance = _account[i]->get_balance();
        if (cur_balance > max_balance)
        {
            index = i;
            max_balance = cur_balance;
        }
    }
    return index;
}

void AccountList::clear() {
    return _account.clear();
}





