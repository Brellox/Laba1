
#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

class Payment // описание класса
{
public:
    double salaryCount(); //рассчет суммы зарплаты
    double pension(); //отчисления в пенсионный фонд
    double plotiNologe(); //подоходный нологе
    char* toString(); //представление в стринг
    Payment(); //конструктор
    Payment(char* creds, double salary, int year, int days); //конструктор с параметрами
    virtual ~Payment(); //деструктор
    Payment(const Payment &t); //конструктор копированиия
    void setCreds(char* creds);
    void setSalary(double salary);
    void setYear(int year);
    void setDays(int days); //сеттеры
    char* getCreds();
    double getSalary();
    int getYear();
    int getDays(); //геттеры
    static double koeff; //районный коэффициент
    static double nolog;// процент налога
    static double pens;// процент пенсии
    char* buff = new char [512];
    Payment& operator=(const Payment &arg);//оператор присваивания;
    friend const Payment operator+(const Payment &left, const double right);
    friend const Payment operator-(const Payment &left, const double right);
    friend Payment& operator+=(Payment& left, const double right);
    friend Payment& operator-=(Payment& left, const double right);
    friend const Payment& operator++(Payment& i);
    friend const Payment operator++(Payment& i, int a);
    friend const Payment& operator--(Payment& i);
    friend const Payment operator--(Payment& i, int a);
    double operator()();
    friend ostream& operator<<(ostream& out, const Payment& rabotyaga);
    friend istream& operator>>(istream& in, Payment& rabotyaga);
    friend ifstream& operator>>(ifstream& in, Payment& rabotyaga);
    void write(ofstream& out);
    static ifstream& read(ifstream& in, Payment& rabotyaga);
    
    
protected:
    
    double salary; // оклад за день
    int year; //год поступления
    int days; //кол-во отработанных дней за месяц
    char* creds; //ФИО
};

class CoWorker : public Payment
{
public:
    CoWorker(); //конструктор
    CoWorker(char* creds, double salary, int year, int days, char* position, double wk); //конструктор с параметрами
    ~CoWorker(); //деструктор
    CoWorker(const CoWorker &t); //конструктор копированиия
    void setWk(double wk);
    void setPosition(char* position);
    double getWk();
    char* getPosition();
    double salaryCount(); //рассчет суммы зарплаты
    double pension(); //отчисления в пенсионный фонд
    double plotiNologe(); //подоходный нологе
    char* toString();
    friend ostream& operator<<(ostream& out, const CoWorker& cw);
    friend istream& operator>>(istream& in, CoWorker& cw);
    
private:
    double wk;
    char* position;
};

class Worker : public Payment
{
public:
    Worker(); //конструктор
    Worker(char* creds, double salary, int year, int days, char* profession, int hours); //конструктор с параметрами
    ~Worker(); //деструктор
    Worker(const Worker &t); //конструктор копированиия
    void setHours(int hours);
    void setProfession(char* profession);
    int getHours();
    char* getProfession();
    double salaryCount(); //рассчет суммы зарплаты
    double pension(); //отчисления в пенсионный фонд
    double plotiNologe(); //подоходный нологе
    char* toString();
    friend ostream& operator<<(ostream& out, const Worker& work);
    friend istream& operator>>(istream& in, Worker& work);
    
private:
    int hours;
    char* profession;
};

#endif /* Header_h */
