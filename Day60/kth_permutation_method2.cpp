class Solution {
public:
    string getPermutation(int n, int k) {

        int fact = 1;
        string op = "";     //contains output string
        vector<int> inp;

        for(int i=1;i<n;i++)
        {   
            //we calculate the factorial as it gives number of combinations possible
            fact = fact*i;

            //adding to input array
            inp.push_back(i);
        }
        //in the above for loop only 1-n-1 is added so to add n
        inp.push_back(n);

        //we are indexing from 0 so k should k-1
        k = k-1;        //k=3 will be k = 2, 0,1,2 instead of 1,2,3

        while(true)
        {

            op += to_string(inp[k/fact]);
            //we remove the added element from inp array
            inp.erase(inp.begin() + k/fact);

            if(!inp.size())
            {
                break;
            }

            //update k value and fact as number of combinations are shrinked now
            k = k%fact;
            fact = fact/inp.size();

        }
        return op;
    }
};
