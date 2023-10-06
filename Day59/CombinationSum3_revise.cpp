class Solution {
public:

    vector<vector<int>> op;

    void recCombSum3(vector<int> arr, int index, int target, vector<int>& curr, int k)
    {
        //base-case
        if(target == 0 && curr.size() == k)
        {
            op.push_back(curr);
            return;
        }

        if(index >= arr.size())
        {
            return;
        }

        if(target < 0)
        {
            return;
        }

        //not include part
        recCombSum3(arr, index+1, target, curr, k);

        //includin the element
        if(arr[index] <= target)
        {
            curr.push_back(arr[index]);
            recCombSum3(arr, index+1, target - arr[index], curr, k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if(n < k)
        {
            return op;
        }

        //create input array from 1-9
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> curr;
        
        recCombSum3(arr, 0, n, curr, k);
        return op;
    }
};
