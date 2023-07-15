class Solution {
public:

    void recurs(vector<char>& c, int i)
    {
        //base case
        if(i >= c.size()/2)
        {
            return;
        }

        swap(c[i], c[c.size()-i-1]);
        recurs(c, i+1);
    }

    void reverseString(vector<char>& s) {

        recurs(s, 0);
    }
};
