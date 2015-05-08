#include "iostream"
#include "vector"
using namespace std;

int countPrimes(int n)
{
    vector<int> primeList;
    primeList.push_back(2);
    int i = 3;
    while(i <= n)
    {
        //选择乘数中较小的一个测试
        bool isPrime = true;
        vector<int>::iterator iter = primeList.begin();
        for(; iter!=primeList.end() && *iter * *iter <= i; iter++)
        {
            //遍历之前的质数, 均不能被整除就是下一个质数
            if(i % *iter == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime == true)
            primeList.push_back(i);
        ++i;
    }
    for(int i=0; i<primeList.size(); i++)
        cout<<primeList[i]<<" ";
    cout<<endl;

    return primeList.size();
}

void setBitMap(char *bitmap, int pos)
{
    //将位图第pos位置为1
    bitmap[pos >> 3] |= (1 << (pos%8));
}

void resetBitMap(char *bitmap, int pos)
{
    //将位图第pos位置为0
    bitmap[pos >> 3] &= ~(1 << (pos%8));
}

bool testBitMap(char *bitmap, int pos)
{
    //测试位图第pos位置是否为1
    return bitmap[pos >> 3] & (1 << (pos%8)); 
}

int countPrimes_SOE(int n)
{
    int len = (n>>3) + 1;
    char *numList = new char[len];
    vector<int> primeList;
    for(int i=0; i<n; i++)
        setBitMap(numList, i);
    resetBitMap(numList, 0);
    int index = 1;
    while(index < n)
    {
        int temp = index+1;
        if(testBitMap(numList, index))
        {
            primeList.push_back(temp);
            for(int i=2; i*temp<=n; i++)
            {
                if(testBitMap(numList, i*temp - 1))
                    resetBitMap(numList, i*temp - 1);
            }
        }
        ++index;
    }
    for(int i=0; i<primeList.size(); i++)
        cout<<primeList[i]<<" ";
    cout<<endl;
    delete numList;
    return primeList.size();
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<countPrimes(n)<<endl;
        cout<<countPrimes_SOE(n)<<endl;
    }

    return 0;
}
