#include "iostream"
#include "string.h"
using namespace std;

int lengthOfLastWord(char* s) 
{
    if(NULL == s || 0 == strlen(s))
        return 0;
    char *p = s + strlen(s) - 1;
    while(*p == ' ' && p >= s)
        --p;
    int lastLen = 0;
    while(p >= s)
    {
        if(*p == ' ')
            break;
        --p;
        ++lastLen;
    }
    return lastLen;
}


int main()
{
    char str[100];
    while(cin.getline(str, 100))
        cout << lengthOfLastWord(str)<<endl;

    return 0;
}
