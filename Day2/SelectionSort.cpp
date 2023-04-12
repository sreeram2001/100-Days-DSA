#include <iostream>
#include<vector>
using namespace std;

/* SELECTION SORT - DIVIDE INTO SORTED AND UNSORTED PART IN AN ARRAY, fIND minimum
INDEX AND SWAP IT WITH LEFTMOST ELEMENT.*/


//returns minimum index to swap
int MinIndex(vector<int> v, int ind)
{
    int min_i = ind;                //stores index
    for(int i=ind;i<v.size();i++)
    {
        if(v[min_i] > v[i])
        {
            min_i = i;
        }
    }
    
    return min_i;
}

int main()
{
    vector<int> v = {9,6,7,3,1,4};
    cout<<"unsorted array : ";
    
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    
    //selection sort
    for(int i=0;i<v.size();i++)
    {
        int mini = MinIndex(v, i);      //get index of min element
        
        if(mini != i)
        {
            swap(v[i],v[mini]);     //swap the elements if diff index
        }
        
    }
    
    //print sorted array
    cout<<"\n"<<"sorted array : ";
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    return 0;
}
