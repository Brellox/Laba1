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
    delete [] creds;
    creds = new char[strlen(arg.creds)+1];
    memcpy(creds, arg.creds, strlen(arg.creds)+1);
    //creds = arg.creds;
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

ostream& operator<<(ostream& out, const Payment& rabotyaga)
{
    out << rabotyaga.creds << "\n" << rabotyaga.salary << "\n" << rabotyaga.year << "\n" << rabotyaga.days;
    return out;
}

istream& operator>>(istream& in, Payment& rabotyaga)
{
    char* temp = new char[64];
    in.getline (temp, 63);
    rabotyaga.setCreds(temp);
    in >> rabotyaga.salary;
    in >> rabotyaga.year;
    in >> rabotyaga.days;
    return in;
}

void Payment::write(ofstream& out)
{
    out.write((char*)&this->salary, sizeof(double));
    out.write((char*)&this->year, sizeof(int));
    out.write((char*)&this->days, sizeof(int));
    int temp = strlen(this->creds);
    out.write((char*)&temp, sizeof(int));
    out.write((char*)this->creds, temp);
}

ifstream& Payment::read(ifstream& in, Payment& rabotyaga)
{
    in.read((char*)&rabotyaga.salary, sizeof(double));
    in.read((char*)&rabotyaga.year, sizeof(int));
    in.read((char*)&rabotyaga.days, sizeof(int));
    int temp = 0;
    in.read((char*)&temp, sizeof(int));
    rabotyaga.creds = new char[temp+1];
    in.read((char*)rabotyaga.creds, temp);
    rabotyaga.creds[temp]='\0';
    return in;
}

CoWorker::CoWorker()
{
    Payment();
    this->position = new char[2];
    strcpy(this->position, "");
    this->wk = 0;
}

CoWorker::CoWorker(char* creds, double salary, int year, int days, char* position, double wk)
{
    Payment(creds, salary, year, days);
    this->position = new char[strlen(position)+1];
    strcpy(this->position, position);
    this->wk = wk;
}

CoWorker::~CoWorker()
{
    delete [] this->position;
}

CoWorker::CoWorker(const CoWorker &t)
{
   
}

void CoWorker::setWk(double wk)
{
    this->wk = wk;
}
void CoWorker::setPosition(char* position)
{
    delete this->position;
    this->position = new char[strlen(position)+1];
    strcpy(this->position, position);
}

double CoWorker::getWk()
{
    return wk;
}

char* CoWorker::getPosition()
{
    return position;
}
