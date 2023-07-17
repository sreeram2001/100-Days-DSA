// to print the first occurence of the combination sum
// we use bool true and false end the further future recursive calls

#include <iostream>
#include <vector>
using namespace std;

bool recurseSubs(vector<int> &op, vector<int> arr, int ind, int sumi, int target)
{
    if (ind >= arr.size())
    {
        if (sumi == target)
        {
            for (auto it : op)
            {
                cout << it;
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // include the element
    // add the element first
    op.push_back(arr[ind]);
    sumi += arr[ind];
    if (recurseSubs(op, arr, ind + 1, sumi, target) == true)
    {
        return true;
    }              // make next recursive call after adding that element
    op.pop_back(); // now remove the element
    sumi -= arr[ind];

    // this recursive call is for non-included element
    if (recurseSubs(op, arr, ind + 1, sumi, target) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> v;
    int k = 2;

    recurseSubs(v, arr, 0, 0, k);
}
