class Solution {
public:

    int findMinFibonacciNumbers(int k) {

        //filling up of fibonacci
        vector<int> fibo = {1,1};
        int i = 2;
        int sumi = 2;
        int cnt = 0;

        while(sumi <= k)
        {
            sumi  = fibo[i-1] + fibo[i-2];

            if(sumi > k)
            {
                break;
            }
            fibo.push_back(sumi);
            i += 1;
        }

        for(int i=fibo.size()-1;i>=0;i--)
        {
            if(k == 0)
            {
                break;
            }
            if(fibo[i] <= k)
            {
                k = k - fibo[i];
                cnt++;
            }
        }
        return cnt;
    }
};
