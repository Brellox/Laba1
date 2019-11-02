#include "Header.h"

vector <Payment> rabotyaga;

void bOut()
{
    ofstream binout;
    int i;
    cout << "Введите номер работяги, которого хотите вывести в бинарник" << "\t";
    cin >> i;
    binout.open("binout.dat", ios::binary);
    rabotyaga[i].write(binout);
    binout.close();
}

void bIn()
{
    ifstream binin;
    binin.open("bin.dat", ios::binary);
    Payment temprabotyaga;
    Payment::read(binin, temprabotyaga);
    binin.close();
    rabotyaga.push_back(temprabotyaga);
}
void fout()
{
    ofstream out;
    int i;
    cout << "Введите номер работяги, которого собираетесь вывести:" << "\t";
    cin >> i;
    out.open("out.txt");
    out <<rabotyaga[i];
    out.close();
}

void fin()
{
    Payment trabotyaga;
    ifstream in;
    in.open("in.txt");
    in >> trabotyaga;
    in.close();
    rabotyaga.push_back(trabotyaga);
}

int menu()
{
    int a;
    cout << "1 - добавить работягу" << "\n";
    cout << "2 - изменить данные работяги" << "\n";
    cout << "3 - изменить оклад работяги" << "\n";
    cout << "4 - изменить год поступления работяги" << "\n";
    cout << "5 - рассчитать зп работяги" << "\n";
    cout << "6 - вывести данные работяги" << "\n";
    cout << "7 - файловый вывод" << "\n";
    cout << "8 - файловый ввод" << "\n";
    cout << "9 - считать из бинарника" << "\n";
    cout << "10 - записать в бинарник" << "\n";
    cout << "99 - просто показать что оно живое" << "\n";
    cin >> a;
    return a;
    
}

void test ()
{
    double diff = 12.34;
    rabotyaga[0] = rabotyaga[1] + diff;
    rabotyaga[1] = rabotyaga[2] - diff;
}


void out()
{
    int n;
    cout << "Введите номер работяги которого хотите вывести:" << "\t";
    cin >> n;
    cout << rabotyaga[n].toString() << "\n";
}

void countSalary()
{
    int n;
    double t;
    cout << "Введите номер работяги, зарплату которого хотите рассчитать:" << "\t";
    cin >> n;
    t = rabotyaga[n]();
    cout << "Зарплата с учетом вычета всех процентов составит: " << t << "\n";
}

void changeYear()
{
    int n, a;
    cout << "Введите номер работяги, год поступления которого хотите изменить:" << "\t";
    cin >> n;
    cout << "1 - повысить год поступления" << "\n";
    cout << "2 - понизить год поступления" << "\n";
    cin >> a;
    switch (a)
    {
        case 1:
        {
            rabotyaga[n]++;
            break;
            
        }
        case 2:
        {
            rabotyaga[n]--;
         break;
        }
    }
}

void changeSalary()
{
    int n, a;
    double dif;
    cout << "Введите номер работяги, оклад которого хотите изменить:" << "\t";
    cin >> n;
    cout << "Введите насколько вы хотите изменить размер оклада:" << "\t";
    cin >> dif;
    cout << "1 - повысить оклад" << "\n";
    cout << "2 - понизить оклад" << "\n";
    cin >> a;
    switch (a)
    {
        case 1:
        {
            rabotyaga[n]+=dif;;
            break;
            
        }
        case 2:
        {
            rabotyaga[n]-=dif;
         break;
        }
    }
}

void changeInfo()
{
    char* creds = new char [64];
    double salary;
    int year, days, n;
    cout << "Введите имечко фамилию" << "\t";
    cin.get();
    cin.getline(creds,64);
    cout << "Введите дневной оклад" << "\t";
    cin >> salary;
    cout << "Введите в каком году работяга поступил на завод" << "\t";
    cin >> year;
    cout << "Введите сколько дней в месяце отработал работяга" << "\t";
    cin >> days;
    Payment rabotyaga1(creds,salary,year,days);
    cout << "Введите номер работяги, данные которого хотите изменить:" << "\t";
    cin >> n;
    rabotyaga[n] = rabotyaga1;
    delete [] creds;
}


void addRabotyaga ()
{
    char* creds = new char [64];
    double salary;
    int year, days;
    cout << "Введите имечко фамилию" << "\t";
    cin.get();
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
        switch (menu())
        {
            case 1:
            {
                addRabotyaga();
                break;
                
            }
                
            case 2:
            {
                changeInfo();
                break;
            }
                
            case 3:
            {
                changeSalary();
                break;
            }
                
            case 4:
            {
                changeYear();
                break;
            }
            case 5:
            {
                countSalary();
                break;
            }
            case 6:
            {
                out();
                break;
            }
            case 7:
            {
                fout();
                break;
            }
            case 8:
            {
                fin();
                break;
            }
            case 9:
            {
                bIn();
                break;
            }
            case 10:
            {
                bOut();
                break;
            }
            case 99:
            {
                test();
                break;
            }
            default:
                return 0;
        }
    }
}
