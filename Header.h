
#ifndef Header_h
#define Header_h

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Payment
{
public:
    double salaryCount(); //рассчет суммы зарплаты
    double pension(); //отчисления в пенсионный фонд
    double plotiNologe(); //подоходный нологе
    char* toString(); //представление в стринг
    Payment(); //конструктор
    Payment(char* creds, double salary, int year, int days); //конструктор с параметрами
    ~Payment(); //деструктор
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
    
private:
    char* creds; //ФИО
    double salary; // оклад за день
    int year; //год поступления
    int days; //кол-во отработанных дней за месяц
};
// laba1


#endif /* Header_h */
