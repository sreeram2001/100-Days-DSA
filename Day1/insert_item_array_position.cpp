
#include<iostream>
#include<vector>
using namespace std;

int main()
{   
    int val,pos;
    vector v = {22,72,88,91,30};
    int l = v.size();
    
    cout<<"Enter Value to Be Inserted : ";
    cin>>val;
    cout<<"Enter position to be Inserted : ";
    cin>>pos;
    
    for(int i=l;i>=pos;i--)
    {
        v[i+1] = v[i];
    }
    
    v[pos] = val;
    l++;
    
    //print values
    for(int i=0;i<l;i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}
