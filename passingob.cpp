#include<iostream>
#include<string>

using namespace std;
class Car 
{
public: 
    string brand;
    int year;

    Car(string b,int y)
    {
        brand = b;
        year = y; 
    }
    void display() const 
    {
        std::cout << "I have " << brand << " from " <<year << std::endl;
    }

};

void modcar(Car &car)
{
    car.brand = "Tesla";
    car.year = 2025;
    car.display();
}

int main ()
{
    Car mycar("Toyota", 2012);
    mycar.display();

    modcar(mycar);
    mycar.display();

    return 0;
}