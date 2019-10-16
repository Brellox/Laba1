#include "Header.h"
//laba1

double Payment::koeff = 1.68;
double Payment::nolog = 0.13;
double Payment::pens = 0.1;

Payment::Payment()
{
    this->creds = new char[2];
    strcpy(this->creds, "");
    this->salary = 0;
    this->year = 0;
    this->days = 0;
}

Payment::Payment(char* creds, double salary, int year, int days)
{
    this->creds = new char[strlen(creds)+1];
    strcpy(this->creds, creds);
    this->salary = salary;
    this->year = year;
    this->days = days;
    
}

Payment::~Payment()
{
    delete [] this->creds;
    delete [] this->buff;
}

Payment::Payment(const Payment &t)
{
    this->creds = new char[strlen(t.creds)+1];
    strcpy(this->creds, t.creds);
    this->salary = t.salary;
    this->year = t.year;
    this->days = t.days;
    cout << this->creds << "\n";
    cout << this->salary << "\n";
    cout << this->year << "\n";
    cout << this->days << "\n";

}

void Payment::setCreds(char* creds)
{
    delete this->creds;
    this->creds = new char[strlen(creds)+1];
    strcpy(this->creds, creds);
    
}

char* Payment::getCreds()
{
    return creds;
}

void Payment::setSalary(double _salary)
{
    this->salary = _salary;
}

double Payment::getSalary()
{
    return salary;
}

void Payment::setYear(int _year)
{
    this->year = _year;
}

int Payment::getYear()
{
    return year;
}

void Payment::setDays(int _days)
{
    this->days = _days;
}

int Payment::getDays()
{
    return days;
}

double Payment::salaryCount()
{
    return this->salary * this->days * koeff;
}

double Payment::pension()
{
    return this->salaryCount() * pens;
}

double Payment::plotiNologe()
{
    return this->salaryCount() * nolog;
}

char* Payment::toString()
{
    sprintf(this->buff, "%s %f %d %d", this->creds, this->salary, this->year, this->days);
    return this->buff;
}

Payment& Payment::operator=(const Payment &arg)
{
    if (this == &arg) {
        return *this;
    }
    creds = arg.creds;
    salary = arg.salary;
    year = arg.year;
    days = arg.days;
    return *this;
}

const Payment operator+(const Payment &left, const double right)
{
    return Payment(left.creds, left.salary + right, left.year, left.days);
}

const Payment operator-(const Payment &left, const double right)
{
    return Payment(left.creds, left.salary - right, left.year, left.days);
}

Payment& operator+=(Payment &left, const double right)
{
    left.salary += right;
    return left;
}

Payment& operator-=(Payment &left, const double right)
{
    left.salary -= right;
    return left;
}

const Payment& operator++(Payment& i)
{
    i.year++;
    return i;
}

const Payment operator++(Payment& i, int a)
{
    Payment oldValue(i.creds, i.salary, i.year, i.days);
    i.year++;
    return oldValue;
}

const Payment& operator--(Payment& i)
{
    i.year--;
    return i;
}

const Payment operator--(Payment& i, int a)
{
    Payment oldValue(i.creds, i.salary, i.year, i.days);
    i.year--;
    return oldValue;
}

double Payment::operator() ()
{
    return this->salary*koeff*this->days - this->salary*koeff*this->days*pens - this->salary*koeff*this->days*nolog;
}

