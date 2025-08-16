#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string string1 ="Data structure ";
    string string2 = "algorithm";

    int L = string1.length();

    cout << "Length of the first string : " << L << endl;


    char c=string1.at(2);

    cout << "character at index 2 : " << c << endl;

    string coursename = string1 + "and "+ string2 +to_string(2);

    cout << "course name :" << coursename << endl;

    return 0;
}