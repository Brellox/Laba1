#include "Header.h"

vector <Payment> rabotyaga;
int menu()
{
    int a;
    cout << "1 - добавить работягу" << "\n";
    cout << "2 - прибавить работяге к окладу" << "\n";
    cout << "3 - сменить год поступления работяги" << "\n";
    cout << "4 - рассчитать зп работяги" << "\n";
    cin >> a;
    return a;
    
}

void addRabotyaga ()
{
    char* creds = new char [64];
    double salary;
    int year, days;
    cout << "Введите имечко фамилию" << "\t";
    cin.getline(creds,64);
    cout << "Введите дневной оклад" << "\t";
    cin >> salary;
    cout << "Введите в каком году работяга поступил на завод" << "\t";
    cin >> year;
    cout << "Введите сколько дней в месяце отработал работяга" << "\t";
    cin >> days;
    Payment rabotyaga1(creds,salary,year,days);
    rabotyaga.push_back(rabotyaga1);
    delete [] creds;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    for(;;)
    {
        switch (menu()) {
            case 1:
            {
                addRabotyaga();
                break;
                
            }
            case 2:
            {
             
             break;
            }
            case 3:
            {
            
                break;
            }
            case 4:
            {
             
             break;
            }
            default:
                return 0;
        }
    }
}
