class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> oper;

        for(int i=1;i<n+1;i++)
        {
            if((count(target.begin(), target.end(), i)) > 0)
            {
                oper.push_back("Push");
            }
            else
            {
                oper.push_back("Push");
                oper.push_back("Pop");
            }

            if(i == target[target.size()-1])
            {
                break;
            }
        }
        return oper;
    }
};
