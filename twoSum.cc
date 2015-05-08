#include "iostream"
#include "vector"
#include "map"
using namespace std;

bool comp(const int &a,const int &b)
{
    return a<b;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> *result = new vector<int>;
    sort(nums.begin(), nums.end(), comp);
    vector<int>::iterator first, last;
    first = nums.begin();
    last = nums.end() - 1;
    while(first < last)
    {
        if((*first + *last) > target)
            --last;
        else if((*first + *last) < target)
            ++first;
        else
        {
            (*result).push_back(first-nums.begin() + 1);
            (*result).push_back(last-nums.begin() + 1);
            break;
        }
    }
    return *result;
}

int main()
{
    int a;
    vector<int> input;
    while(cin>>a)
    {
        if(a == -999)
            break;
        input.push_back(a);
    }

    vector<int> output = twoSum(input, 8);
    cout<<output[0]<<" "<<output[1]<<endl;

    return 0;
}

