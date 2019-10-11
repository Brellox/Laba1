#include "Header.h"

//laba1
int menu()
{
    int a;
    cout << "1 - вычислить месячный оклад работяги" << "\n";
    cout << "2 - узнать сколько работяга отдает в пфр" << "\n";
    cout << "3 - узнать сколько нологе платит работяга" << "\n";
    cout << "4 - вывести данные работяги" << "\n";
    cin >> a;
    return a;
    
}

void addInfo ()
{
    char* creds;
    double salary;
    int year, days, a;
    cout << "Введите имечко фамилию" << "\t";
    cin >> creds;
    cout << "Введите дневной оклад" << "\t";
    cin >> salary;
    cout << "Введите в каком году работяга поступил на завод" << "\t";
    cin >> year;
    cout << "Введите сколько дней в месяце отработал работяга" << "\t";
    cin >> days;
    cout << "Выберите работягу: 1,2,3" << "\n";
    cin >> a;
    switch (a)
    {
    case 1:
        {
            Payment rabotyaga1 (creds,salary, year, days);
            break;
            
        }
    case 2:
        {
            Payment rabotyaga2 (creds,salary, year, days);
            break;
        }
    case 3:
        {
            Payment rabotyaga3 (creds,salary, year, days);
            break;
        }
        default: cout << "Нет такого работяги" << "\n";
        
    }
    
}


int main()
{
    setlocale(LC_ALL,"Russian");
    Payment rabotyaga1;
    Payment rabotyaga2 ("Vasya Pupkin",3215.67, 2007, 22);
    Payment rabotyaga3 = rabotyaga2;
    
   rabotyaga3.setCreds("Pupa Lupin");
    rabotyaga3.setSalary(3551.64);
    rabotyaga3.setYear(2013);
    rabotyaga3.setDays(19);
     
    for(;;)
    {
        switch (menu()) {
            case 1:
            {
                cout << rabotyaga1.salaryCount() << "\n";
                cout << rabotyaga2.salaryCount() << "\n";
                cout << rabotyaga3.salaryCount() << "\n";
                break;
                
            }
            case 2:
            {
             cout << rabotyaga1.pension() << "\n";
             cout << rabotyaga2.pension() << "\n";
             cout << rabotyaga3.pension() << "\n";
             break;
            }
            case 3:
            {
            cout << rabotyaga1.plotiNologe() << "\n";
            cout << rabotyaga2.plotiNologe() << "\n";
            cout << rabotyaga3.plotiNologe() << "\n";
            }
            case 4:
            {
             cout << rabotyaga1.toString() << "\n";
             cout << rabotyaga2.toString() << "\n";
             cout << rabotyaga2.toString() << "\n";
             break;
            }
                
            default:
                return 0;
        }
    }
        
    /*
    
    cout << rabotyaga3.getCreds() << "\n";
    cout << rabotyaga3.getSalary() << "\n";
    cout << rabotyaga3.getYear() << "\n";
    cout << rabotyaga3.getDays() << "\n";
    
    cout <<"------------------------------" << "\n";
    
    cout << rabotyaga2.salaryCount() << "\n";
    cout << rabotyaga2.pension() << "\n";
    cout << rabotyaga2.plotiNologe() << "\n";
    cout << rabotyaga2.toString() << "\n";
    cout << rabotyaga3.toString() << "\n";*/
    
}
