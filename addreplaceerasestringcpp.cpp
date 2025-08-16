#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1 = "Hello !!";

    str1.insert(6,"world");
    cout << str1 << endl;

    str1.replace(6,5,"Sadi");
    cout << str1 << endl;

    str1.erase(0,6);
    cout << str1 << endl;
}