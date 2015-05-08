#include "iostream"
#include "string.h"
using namespace std;

#define max 2000

char fst[max], sec[max], result[max*2];

void bigFloatPlus()
{
    int len_fst = strlen(fst);
    int len_sec = strlen(sec);
    int dotPos1 = 0, dotPos2 = 0;
    while(dotPos1 < len_fst)
    {
        if('.' == fst[dotPos1])
            break;
        dotPos1++;
    }
    while(dotPos2 < len_sec)
    {
        if('.' == sec[dotPos2])
            break;
        dotPos2++;
    }

    //如果输入为整数, 在后面添加小数点便于循环
    if(dotPos1 == len_fst)
    {
        fst[dotPos1] = '.';
        fst[dotPos1+1] = '0';
        fst[dotPos1+2] = '\0';
        len_fst += 2;
    }
    if(dotPos2 == len_sec)
    {
        sec[dotPos2] = '.';
        sec[dotPos2+1] = '0';
        sec[dotPos2+2] = '\0';
        len_sec += 2;
    }

    //将小数点后面位数较多的部分直接复制
    int len1 = len_fst - 1 - dotPos1;
    int len2 = len_sec - 1 - dotPos2;
    int i = len_fst - 1, j = len_sec - 1;
    int index = sizeof(result) -2;
    if(len1 > len2)
    {
        memcpy(result + index - (len1 - len2 - 1), fst + i - (len1 - len2 - 1), len1 - len2);
        i -= len1 - len2;
        index -= len1 - len2;
    }
    if(len1 < len2)
    {
        memcpy(result + index - (len2 - len1 - 1), sec + j - (len2 - len1 - 1), len2 - len1);
        j -= len2 - len1;
        index -= len2 - len1;
    }

    int pre = 0, tmp = 0;
    while(i >= 0 && j >= 0)
    {
        if('.' == fst[i])
        {
            result[index--] = '.';
            i--;
            j--;
            continue;
        }
        tmp = pre + fst[i--] - '0' + sec[j--] - '0';
        pre = tmp / 10;
        result[index--] = tmp % 10 + '0';
    }
    while(i >= 0)
    {
        if('.' == fst[i])
        {
            result[index--] = '.';
            i--;
            continue;
        }
        tmp = pre + fst[i--] - '0';
        pre = tmp / 10;
        result[index--] = tmp % 10 + '0';
    }
    while(j >= 0)
    {
        if('.' == sec[j])
        {
            result[index--] = '.';
            j--;
            continue;
        }
        tmp = pre + sec[j--] - '0';
        pre = tmp / 10;
        result[index--] = tmp % 10 + '0';
    }
    if(pre > 0)
        result[index--] = pre + '0';

    int tail = sizeof(result) - 2;
    while(tail > index)
    {
        if(result[tail] != '0' && result[tail] != '.')
            break;
        else
            tail--;
    }
    result[tail+1] = '\0';

    memmove(result, result+index+1, tail-index);
}


int main()
{
    memset(fst, '\0', sizeof(fst));
    memset(sec, '\0', sizeof(sec));
    while(cin >> fst >> sec)
    {
        memset(result, '\0', sizeof(result));
        bigFloatPlus();
        cout<<result<<endl;
    }

    return 0;
}
