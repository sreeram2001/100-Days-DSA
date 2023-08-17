
#include <iostream>
#include<deque>
using namespace std;

void WindowMax(int arr[], int n, int k)
{
    deque<int> dq{k};
    
    for(int i=0;i<k;i++)
    {   
        while(!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for(int i=k;i<n;i++)
    {   
        //print the max value in each window, i.e. front of queue
        std::cout<<"Max : "<<arr[dq.front()]<<std::endl;
        
        //remove elements out of window
        while(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }
        
        //remove elements lesser than current element from window - deque
        while(!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        
        dq.push_back(i);
    }
    
    std::cout<<"Max : "<<arr[dq.front()]<<std::endl;
}

int main()
{
    int arr[] = {9,7,2,4,6,8,2,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
 
    //call function
    WindowMax(arr, n, k);
    return 0;
}
