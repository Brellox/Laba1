#include "Header.h"

vector <Payment> rabotyaga;
vector <CoWorker> cw;
vector <Worker> work;

void bOut()
{
    ofstream binout;
    int i;
    cout << "Введите номер работяги, которого хотите вывести в бинарник" << "\t";
    cin >> i;
    binout.open("bin.dat", ios::binary | ios::app);
    rabotyaga[i].write(binout);
    binout.close();
}

void bIn()
{
    Payment temprabotyaga;
    ifstream binin;
    binin.open("bin.dat", ios::binary);
    for (int i = 0; binin.peek() != EOF; i++)
    {
        Payment::read(binin, temprabotyaga);
        if (!binin.eof())
            rabotyaga.push_back(temprabotyaga);
    }
    binin.close();
}
void fout()
{
    ofstream out;
    int i;
    cout << "Введите номер работяги, которого собираетесь вывести:" << "\t";
    cin >> i;
    out.open("text.txt", ios::app);
    if(!out.is_open())
        out.open("text.txt");
    out <<rabotyaga[i];
    out.close();
}

void fin()
{
    Payment trabotyaga;
    ifstream in;
    in.open("text.txt");
    for (int i = 0; in.peek() != EOF; i++)
    {
        in >> trabotyaga;
        if (!in.eof())
            rabotyaga.push_back(trabotyaga);
    }
    in.close();
    
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
    cout << "11 - добавить сотрудника" << "\n";
    cout << "12 - добавить работягу" << "\n";
    cout << "13 - заставить работать сотрудника" << "\n";
    cout << "14 - заставить работать работягу" << "\n";
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

void addCoWorker ()
{
    char* creds = new char [64];
    char* position = new char[64];
    double salary, wk;
    int year, days;
    cout << "Введите имечко фамилию" << "\t";
    cin.get();
    cin.getline(creds,64);
    cout << "Введите должность" << "\n";
    cin.getline(position,64);
    cout << "Введите коэффициент надбавки за должность" << "\t";
    cin >> wk;
    cout << "Введите дневной оклад" << "\t";
    cin >> salary;
    cout << "Введите в каком году работяга поступил на завод" << "\t";
    cin >> year;
    cout << "Введите сколько дней в месяце отработал работяга" << "\t";
    cin >> days;
    CoWorker rabotyaga1(creds,salary,year,days,position,wk);
    cw.push_back(rabotyaga1);
    delete [] creds;
    delete [] position;
}

void addWorker ()
{
    char* creds = new char [64];
    char* profession = new char[64];
    double salary;
    int year, days, hours;
    cout << "Введите имечко фамилию" << "\t";
    cin.get();
    cin.getline(creds,64);
    cout << "Введите профессию" << "\n";
    cin.getline(profession,64);
    cout << "Введите заработок за час" << "\t";
    cin >> salary;
    cout << "Введите сколько часов отработал работник" << "\t";
    cin >> hours;
    cout << "Введите в каком году работяга поступил на завод" << "\t";
    cin >> year;
    cout << "Введите сколько дней в месяце отработал работяга" << "\t";
    cin >> days;
    Worker rabotyaga1(creds,salary,year,days,profession,hours);
    work.push_back(rabotyaga1);
    delete [] creds;
    delete [] profession;
}

void workWorker()
{
    int i;
    cout << "Введите номер рабочего, которого заставляем работать:" << "\t";
    cin >> i;
    cout << work[i].toString() << "\n";
    cout << "Зарплата работяги: " << work[i].salaryCount() << "\n";
    cout << "Отчисления в ПФР: " << work[i].pension() << "\n";
    cout << "Отчисления в ФНС: " << work[i].plotiNologe() << "\n";
    
}

void workCoWorker()
{
    int i;
    cout << "Введите номер сотрудника, которого заставляем работать:" << "\t";
    cin >> i;
    cout << cw[i].toString() << "\n";
    cout << "Доход сотрудника: " << cw[i].salaryCount() << "\n";
    cout << "Отчисления в ПФР: " << cw[i].pension() << "\n";
    cout << "Отчисления в ФНС: " << cw[i].plotiNologe() << "\n";
    
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
            case 11:
            {
                addCoWorker();
                break;
            }
            case 12:
            {
                addWorker();
                break;
            }
            case 13:
            {
                workCoWorker();
                break;
            }
            case 14:
            {
                workWorker();
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
//comment
