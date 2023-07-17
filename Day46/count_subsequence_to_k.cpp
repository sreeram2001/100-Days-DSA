// count the number of subsequences equal to k
// we do not need to form the subsequences here
// tc -> 2*n as every element has 2 options - 2recursive calls - pick and not pick
#include <iostream>
#include <vector>
using namespace std;

int recurseSubs(vector<int> arr, int ind, int sumi, int target)
{
    if (ind >= arr.size())
    {
        if (sumi == target)
        {
            return 1;
        }
        return 0;
    }

    // include the element
    sumi += arr[ind]; // add the element first
    // make recursive call after adding that element
    int l = recurseSubs(arr, ind + 1, sumi, target);
    sumi -= arr[ind]; // now remove the element

    // this recursive call is for non-included element
    int r = recurseSubs(arr, ind + 1, sumi, target);

    // we add the recursive function calls
    // l is for inclusion part and //r is for non-included part
    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2};
    vector<int> v;
    int k = 2;

    cout << recurseSubs(arr, 0, 0, k);
}
