#include<iostream>
#include<string>

class Myclass
{
    public :
        Myclass() {std::cout << "Myclass constructed\n";}
        ~Myclass() {std::cout << "Myclass destroyed";}

};

int main ()
{
    Myclass* myobject = new Myclass();
    delete myobject;

    int sizearr = 3;
    Myclass* Myarrayobj = new Myclass[sizearr];
    delete[] Myarrayobj;

    return 0;
}