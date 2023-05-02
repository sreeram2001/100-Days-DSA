class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> stac;
        map<int, int> mp;   //used to store next greater number for each num
        vector<int> op;     //output array

        stac.push(nums2[0]);   //push 1st element from full array to stack

        //traverse the complete array
        for(int i=1;i<nums2.size();i++)
        {
            //if curr num is greater than top element in stack, add it to map pair.
            while(stac.size() > 0 && stac.top() < nums2[i])
            {
                mp[stac.top()] = nums2[i];      //map the pairs number and its greater one
                stac.pop();                     //remove the old element which got a pair
            }

            stac.push(nums2[i]);                //push numbers to stack
        }
        
        //assign -1 to leftover elements in stack as there is no greater num for them
        while(stac.size() > 0)
        {
            mp[stac.top()] = -1;
            stac.pop();
        }

        //iterate over nums1 array and get the output filled with its corres. pair
        for(int i=0;i<nums1.size();i++)
        {
            op.push_back(mp[nums1[i]]);
        }

        return op;

    }
};
