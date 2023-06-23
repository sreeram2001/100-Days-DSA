class Solution {
public:

    int recursion(vector<int> arr, int ind, int curr, int maxi)
    {
        if(ind == arr.size())
        {
            return maxi;
        }

        maxi = max(maxi, curr);
        return recursion(arr, ind+1, curr+arr[ind], maxi);
    }

    int largestAltitude(vector<int>& gain) {
        return recursion(gain, 0, 0, 0);
    }
};
