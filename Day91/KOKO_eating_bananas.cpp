class Solution {
public:

    long long checkPossible(vector<int> piles, int h, int k)
    {
        long long count = 0;

        for(int i=0;i<piles.size();i++)
        {
            count = count + ceil(piles[i]/(double)k);
        }

        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        //the lowest k value possible
        int low = 1;    
        //the highest k value rate possible
        int high = *max_element(piles.begin(), piles.end());
        //minimum k
        int op = 0;

        while(low <= high)
        {
            int mid = (low + high)/2;

            //total hours taken
            long long hours = checkPossible(piles, h, mid);

            if(hours <= h)
            {   
                //decrease rate at eating bananas if its less than given hours
                op = mid;
                high = mid-1;
            }
            else
            {   
                //increase rate at eating bananas if it crosses total hours given
                low = mid + 1;
            }
        }

        return op;
    }
};
