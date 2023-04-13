#include <iostream>
#include<vector>
using namespace std;


    //method which finds the index of pivot element to split array
int pivot_index(vector<int>& arr, int l, int h)
{
    int pivot = l;

    for(int i=l; i<h; i++)
    {
        if(arr[i] <= arr[h])
        {
            swap(arr[i],arr[pivot]);
            pivot++;
        }
    }
    swap(arr[pivot],arr[h]);
    return pivot;
    }

//for recursive call - quicksort
void quicksort(vector<int>& nums, int l, int h)
{
    if(l < h)
    {
        //to find pivot element index
        int pivot_ind = pivot_index(nums,l,h);

        //recursive for left and right half of pivot
        quicksort(nums,l,pivot_ind-1);
        quicksort(nums,pivot_ind+1,h);
        
    }
}

int main()
{
    vector<int> nums = {5,4,2,1};
    int low = 0;
    int high = nums.size();
    quicksort(nums, low, high-1);
    
    cout<<"sorted : ";
    for(auto i:nums)
    {   
        cout<<i;
    }
    return 0;
}
