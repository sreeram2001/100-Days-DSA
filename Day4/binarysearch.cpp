
#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> v, int tar)
{
        //binary search
    int low = 0, high = v.size()-1;
    
    while(low <= high)
    {
        int mid = (low+high)/2;     //mid element index
        
        //if mid is target return index
        if(v[mid] == tar)
        {
            return mid;
        }
        
        //if target lies in left half
        if(v[mid] > tar)
        {
            high = mid - 1;
        }
        
        //if target lies in right half of mid
        else
        {
            low = mid + 1;
        }
    }
    
    return -1;
}

int main()
{
    vector<int> v = {2,3,7,11,15,18};
    int target = 7;
    int op = binarySearch(v, target);
    cout<<"Index of Element "<<target<<" Is : "<<op;

    return 0;
}
