#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;

//检测两个字符串是否同类型
//如果s中的字符被另一个字符替换后能转变为t, 则返回true否则false
bool isIsomorphic(string s, string t)
{
    vector<int> checkList;
    map<int, int> firstPosDict;
    map<int, int>::iterator iter;
    for(string::size_type i=0; i<s.size(); i++)
    {
        iter = firstPosDict.find(s[i]);
        if(iter == firstPosDict.end())
            firstPosDict[s[i]] = i;
        checkList.push_back(firstPosDict[s[i]]);
    }
    firstPosDict.clear();

    for(string::size_type i=0; i<t.size(); i++)
    {
        iter = firstPosDict.find(t[i]);
        if(iter == firstPosDict.end())
            firstPosDict[t[i]] = i;
        if(checkList[i] != firstPosDict[t[i]])
            return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    while(cin>>s1>>s2)
        cout<<isIsomorphic(s1, s2)<<endl;

    return 0;
}





