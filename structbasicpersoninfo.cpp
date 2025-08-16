#include<iostream>
#include<string>

using namespace std;

struct Person
{
    string name ;
    int day;
    int month;
    int year;

    void setname(string _name)
    {
        name=_name; 
    }
    void setdate(int _day,int _month,int _year)
    {
        day=_day;
        month = _month;
        year= _year;
    }

    void printname ()
    {
        cout<< "My name is :"<< name << endl;
    }

    void printdob()
    {
        cout<< "day:" << day << " month:" << month << " year:" << year << endl;
    }
};

int main ()
{
    string takename ;
    Person person1;

    int _day,_month,_year;

    cout<< "Enter your full name :"<< endl;
    getline (cin, takename);

    cout<< "Enter your date of birth as 00 00 0000 using space" << endl;
    cin >> _day >> _month >> _year ;
    person1.setname(takename);
    person1.setdate(_day,_month,_year);

    person1.printname();
    person1.printdob();

    return 0;
}