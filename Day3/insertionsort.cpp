#include <iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> nums = {4,6,3,2,1,9,7};
    
    //insertion sort
    for(int i=1;i<nums.size();i++)
    {
        int curr = nums[i];
        int j = i-1;
        
        while(j >= 0  && curr < nums[j])
        {
            nums[j+1] = nums[j];
            j--;
        }
        
        nums[j+1] = curr;
    }


    cout<<"sorted : ";
    for(auto i:nums)
    {   
        cout<<i;
    }
    return 0;
}
