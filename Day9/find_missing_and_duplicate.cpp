
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v= {2, 3, 1, 5, 1};
    int i=0;
    
    while(i<v.size())
    {
        if(v[i] == v[v[i]-1])
        {
            i++;
        }
        else
        {
            swap(v[i],v[v[i]-1]);
        }
    }
    
    int dupli=0, missing=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i] != i+1)
        {
            dupli = v[i];
            missing = i+1;
        }
    }
    
    cout<<" MIssing : "<<missing;
    cout<<" DUplicate : "<<dupli;
    return 0;
}
