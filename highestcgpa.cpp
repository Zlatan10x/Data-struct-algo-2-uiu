#include "MYheaders.h"

struct Student
{
    string name;
    int id;
    double cgpa; 
};

Student cghigh(vector<Student> &student,int l,int r)

{
    if(l==r) return student[l];

    if(r==l+1)
    {
        if(student[l].cgpa>student[r].cgpa)
        {
            return student[l];
        }
        else
        {
            return student[r];
        }
    }

    int mid = (r+l)/2;

    Student lefth = cghigh(student,l,mid);
    Student righth = cghigh(student,mid+1,r);

    return (lefth.cgpa>righth.cgpa) ? lefth : righth;                            

}

int main()
{
    vector<Student> student =
    {
        {"Adnan",361,2.5},
        {"Sadi",161,2.67},
        {"Evan",111,2.58}
    };

    Student result = cghigh(student,0,student.size()-1);

    cout << result.name << "," << result.cgpa << endl;

    return 0;
}
