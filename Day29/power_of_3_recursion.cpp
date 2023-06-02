class Solution {
public:

    bool recur(int n)
    {
        if(n<=0)
        {
            return false;
        }

        else if(n == 1)
        {
            return true;
        }
        return n%3==0 && recur(n/3);
    }

    bool isPowerOfThree(int n) {

        return recur(n);        
    }
};
