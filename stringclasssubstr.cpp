#include<iostream>
#include<string>

using namespace std;

int main()
{
    string string1 = "hello world";
    string string2 = "hola world";

    int position = string1.find("world");
    cout << "the world word starts at index no : " << position << endl;

    string substring = string1.substr(1,5);
    cout << "sub string " << substring << endl;

    return 0;
}