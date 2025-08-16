#include "MYheaders.h"

bool ispalindrome(string text)
{
    int n = text.length();
    for(int i=0; i<text.length()/2; i++)
    {
        
        if(text[i]!=text[n-i-1]) return false;
        
    }
    return true;
}

int main()
{
    string s ;
    getline(cin,s) ;

    cout << ispalindrome(s);
    
}