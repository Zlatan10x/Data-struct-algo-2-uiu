#include "MYheaders.h"

bool isvowel(char c)
{
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');

}

int countv(const string &str,int l,int r)
{
    int count=0;

    if(l==r) 
    {
        if(isvowel(str[l])) count++;
        return count;
    }

    if(r==l+1)
    {
        if(isvowel(str[l])) count++;
        if(isvowel(str[r])) count++;

        return count;
    }

    int mid = (l+r)/2;

    count += countv(str,l,mid);
    count += countv(str,mid+1,r);
    return count;
}

int main()
{
    string str = "Hello world how are you";

    int total = countv(str,0,str.size()-1);

    cout << total << endl;

    return 0;
}