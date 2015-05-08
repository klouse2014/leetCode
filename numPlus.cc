#include "iostream"
#include "string.h"
using namespace std;

#define MAXLEN 1001

char first[MAXLEN], second[MAXLEN], result[MAXLEN+1];

void strPlus()
{
    int index = max(strlen(first), strlen(second));
    int i = strlen(first) - 1;
    int j = strlen(second) - 1;
    if(i < 0 || j < 0)
        return;
    int pre = 0;
    int total = 0;
    while(i >= 0 && j >= 0)
    {
        total = first[i--] - '0' + second[j--] - '0' + pre;
        pre = total / 10;
        result[index--] = total % 10 + '0';
    }
    while(i >= 0)
    {
        total = first[i--] - '0' + pre;
        pre = total / 10;
        result[index--] = total % 10 + '0';
    }
    while(j >= 0)
    {
        total = second[j--] - '0' + pre;
        pre = total / 10;
        result[index--] = total % 10 + '0';
    }
    if(pre > 0)
        result[0] = pre + '0';
    else
        memmove(result, result + 1, MAXLEN);
}

int main()
{
    int times = 0, i = 1;
    cin >> times;
    while(i <= times)
    {
        memset(first, '\0', sizeof(first));
        memset(second, '\0', sizeof(second));
        memset(result, '\0', sizeof(result));
        cin >> first >> second;
        strPlus();
        cout << "Case "<< i++ << ":" << endl;
        cout << first << " + " << second << " = " << result << endl;
    }

    return 0;
}
