#include <iostream>
#include<vector>
using namespace std;

void recurseSubs(vector<int> &op, vector<int> arr, int ind, int n)
{
    if (ind >= n)
    {
        for (auto it : op)
        {
            cout << it;
        }
        cout << endl;
        return;
    }

    // include the element
    // add the element first
    op.push_back(arr[ind]);
    recurseSubs(op, arr, ind + 1, n); // make next recursive call after adding that element
    op.pop_back();                    // now remove the element

    // this recursive call is for non-included element
    recurseSubs(op, arr, ind + 1, n);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    int n = arr.size();
    vector<int> v;

    recurseSubs(v, arr, 0, n);
}
