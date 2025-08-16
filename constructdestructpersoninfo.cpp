#include<iostream>
#include<string>

using namespace std;

struct Person
{
    string name;

    int day,month,year;

    Person(string _name, int _day,int _month, int _year)
    {
        name=_name;
        day=_day;
        month=_month;
        year=_year;
    }
    void printname()
    {
        cout<< "My name is "<< name << endl;
    }
    void printdob()
    {
        cout << "day :" << day << " month:" << month << " year:" << year << endl;
    }
    ~Person()
    {
        cout << "Me " << name << " was destroyed" << endl;
    }

};

int main ()

{
    string takename;
    int _day,_month,_year;

    cout << "Enter your full name :" << endl;
    getline(cin, takename);

    cout << "Enter date of birth :" << endl;
    cout << "Day" << endl;
    cin >> _day;
    cout << "month" << endl;
    cin >> _month;
    cout << "year" << endl;
    cin >> _year;

    Person person1(takename,_day,_month,_year);
    person1.printname();
    person1.printdob();

    return 0;
}