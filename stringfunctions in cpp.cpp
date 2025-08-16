#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1 = "my name is tonima Sadi";
    string str2 = "my name is Adnan's Sadi";

    if (str1==str2) cout << "equal string"<< endl;
    else cout << "not equal" << endl;

    str1[11]=toupper(str1[11]);

    cout << str1 << endl;

    int index = str1.find("Sadi");
    cout<< "Sadi was found at index " << index << endl;

    string sub = str1.substr(18,4);
    cout << sub << endl;

    cout << str2 << endl;

    return 0;

}