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

