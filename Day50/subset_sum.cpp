// print subsequences equal to sum K
#include <iostream>
#include <vector>
using namespace std;

void recurseSubs(vector<int> &op, vector<int> arr, int ind, int sumi)
{
    if (ind == arr.size())
    {
        op.push_back(sumi);
        return;
    }

    // include the element
    sumi += arr[ind];
    recurseSubs(op, arr, ind + 1, sumi); // make next recursive call after adding that element
    // now remove the element
    sumi -= arr[ind];

    // this recursive call is for non-included element
    recurseSubs(op, arr, ind + 1, sumi);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> op;

    recurseSubs(op, arr, 0, 0);
    
    for(auto it:op)
    {
        std::cout<<it<<endl;
    }
}
