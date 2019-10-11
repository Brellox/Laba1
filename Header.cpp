#include "Header.h"
//laba1

double Payment::koeff = 1.68;

Payment::Payment()
{
    this->creds = new char[2];
    strcpy(this->creds, " ");
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
}

Payment::Payment(const Payment &t)
{
    this->creds = new char[strlen(t.creds)];
    strcpy(this->creds, t.creds);
    this->salary = t.salary;
    this->year = t.year;
    this->days = t.days;

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
    return this->salaryCount() * 0.01;
}

double Payment::plotiNologe()
{
    return this->salaryCount() * 0.13;
}

char* Payment::toString()
{
    char* buff = new char [512];
    sprintf(buff, "%s %f %d %d", this->creds, this->salary, this->year, this->days);
    return buff;
}

