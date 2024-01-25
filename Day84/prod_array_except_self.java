class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        //to get the product of array except self
        //product until item i is prefix product product after item i is suffix product.    
        //product of prefix and suffix gives result

        int n = nums.length;    //length of input array
        int pre[] = new int[n];     //prefix product
        int suff[] = new int[n];    //suffix product
        
        //initialise
        pre[0] = 1;         //product calculate from begin
        suff[n-1] = 1;      //product calculate from end

        //calculating prefix array
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1]*nums[i-1];
        }

        //calculating suffix array
        for(int i=n-2;i>=0;i--)
        {
            suff[i] = suff[i+1]*nums[i+1];
        }

        //to calculate product of every element except for current element
        int op[] = new int[n];
        for(int i=0;i<n;i++)
        {
            op[i] = pre[i]*suff[i];
        }

        return op;
    }
}
