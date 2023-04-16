class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //using fast and slow pointer method
        int slow = nums[0], fast = nums[0];     //set slow, fast to index 0 item

        while(true)
        {
            slow = nums[slow];          //same as slow.next
            fast = nums[nums[fast]];    //same as fast.next.next

            if(fast == slow)        //when both meet break the point
            {
                break;
            }
        }

        //set slow back to initial value
        slow = nums[0];

        //now run the same again but at same speed to find begin of cycle
        while( slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;    //they meet again at a point return that value
    }
};
