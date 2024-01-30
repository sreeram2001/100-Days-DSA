class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> indices;

        int l = 0;
        int r = numbers.size()-1;

        while(l <= r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                indices.push_back(l+1);
                indices.push_back(r+1);
                return indices;
            }

            else if(numbers[l] + numbers[r] < target)
            {
                l++;
            }

            else if(numbers[l] + numbers[r] > target)
            {
                r--;
            }
        }
        
        return indices;
    }
};
