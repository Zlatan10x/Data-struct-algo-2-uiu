#include<iostream>

using namespace std;

int main()
{
    int* ptr = new int ;
    *ptr = 100;
    cout << "Single integer value " << *ptr << std::endl;
    delete ptr;

    int* arr = new int [5];

    for (int i=0;i<5;i++)
    {
        arr[i]=i*100;
    }

    cout << "integer array values " ;
    for(int i=0;i<5;i++)
    {
        
        std::cout << arr[i] << "";
        if(i<4)
        {
            cout<< "," ;
        }
    }
    std::cout<< std::endl;
    delete[] arr;

    return 0;

}