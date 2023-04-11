
#include <iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& v)
{
    for(int i=0;i<v.size()/2;i++)
    {
        int temp = v[i];
        v[i] = v[v.size()-i-1];
        v[v.size()-i-1] = temp;
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    reverseArray(v);
    
    //print it
    for(auto i:v)
    {
        cout<<i;
    }
    return 0;
}
