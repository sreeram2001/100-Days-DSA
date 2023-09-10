class Solution {
public:
    string getPermutation(int n, int k) {
        
        //we go with factorial approach here
        //total elements if k=3, is 3, so we have a total of 3!ways - 6ways to generate permutation
        vector<int> nums;
        int fac = 1;

        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);  //input string
            fac = fac*i;
        }
        fac = fac/n;

        string op = "";     //has the output value
        k = k-1;        //since we are starting from index 0

        while(true)
        {
            op += to_string(nums[k/fac]);
            
            //now we have to remove the element we found from array, so as to reduce our permutations
            nums.erase(nums.begin() + k/fac);

            //iterate until array is empty
            if(nums.size() == 0)
            {
                return op;
            }
            
            k = k%fac;
            fac = fac/nums.size();
        }

        return op;
    }
};
