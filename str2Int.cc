#include "iostream"
using namespace std;

#define MAX 0x7fffffff
#define MIN 0x80000000

//字符合法性检查
bool charIsOk(char c)
{
    if(c > '9' || c < '0')
        return false;
    else
        return true;
}

//将输入字符串转化为整数输出
int StrToInt(char *str, char *errMsg)
{
    if(str == NULL)
    {
        strcpy(errMsg, "传入指针为空");
        return -1;
    }
    //字符串开头检查
    int sign = 1;
    int result = 0, i=0;
    if(str[0] == '-')
    {
        sign = -1;
        if(str[1] == '0')
        {
            strcpy(errMsg, "负号后不能跟0");
            return -1;
        }
        i++;
    }
    if(str[0] == '+')
        i++;
    if(str[0] != '+' && str[0] != '-' && !charIsOk(str[0]))
    {
        strcpy(errMsg, "字符串开头异常");
        return -1;
    }

    bool isStart = false;
    for(; i<strlen(str); i++)
    {
        if(str[i] == '0' && !isStart)
            continue;
        if(!charIsOk(str[i]))
        {
            //合法性检查
            strcpy(errMsg, "字符串内容异常");
            return -1;
        }
        if(str[i] != '0' || isStart)
        {
            isStart = true;
            //需检查是否溢出
            if(1 == sign && (int(MAX) - (str[i] - '0')) / 10 < result)
            {
                strcpy(errMsg, "字符表示数字溢出");
                return -1;
            }

            if(-1 == sign && (int(MIN) + (str[i] - '0')) / 10 > result*sign)
            {
                strcpy(errMsg, "字符串表示数据溢出");
                return -1;
            }
            result = result * 10 + str[i] - '0';
        }
    }
    if(result !=0 && sign == -1)
        result *= sign;

    return result;
}


int main()
{
    cout<<int(MAX)<<" "<<int(MIN)<<endl;
    char str[100] = {0}, err[30] = {0};
    cin >> str;
    int output = StrToInt(str, err);
    if(strlen(err) != 0)
        cout<<err<<endl;
    else
        cout<<output<<endl;
    return 0;
}
