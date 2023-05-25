class Solution {
public:

    void recursion_reverse(vector<char>& ss, int start, int end)
    {
        //recursive function
        //termination condition
        if(start >= end)
        {
            return;
        }

        swap(ss[start], ss[end]); //using two pointer
        recursion_reverse(ss,start+1,end-1);
    }

    void reverseString(vector<char>& s) {
        int st = 0, ed = s.size()-1;
        return recursion_reverse(s, st, ed);
    }
};
