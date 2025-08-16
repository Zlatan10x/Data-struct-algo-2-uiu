#include<iostream>

using namespace std;

void increament (int &n)
{
    n=n+1;
}

int main()
{
    int num = 5;
    cout << "Number " << num << " Is before increament" <<endl;

    increament(num);
    cout << "Number " << num << " is after increament" << endl;
}
