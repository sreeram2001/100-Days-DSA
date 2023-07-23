class Solution {
public:

    //this method returns pivot index
    //it also swaps the elements to its right position
    int pivotIndex(vector<int>& nums, int low, int high)
    {   
        //taking first element as pivot
        int pivot = nums[low];
        //set i and j pointers to move left and right of arr
        int i = low;
        int j = high;

        //as long as i and do not cross, keep swapping
        while(i < j)
        {
            //condition to move i towards right, stop i pointer only when
            //you find element greater than pivot element to swap to back side
            while(nums[i] <= pivot && i <= high-1)
            {
                i++;
            }

            //condition to move j towards left, stop j pointer only when
            //you find element lesser than pivot element, to swap to front side
            while(nums[j] > pivot && j >= low+1)
            {
                j--;
            }

            //if i and j has crossed, it means pivot is in right zone/ position
            //so swap only if i and j pointer have not crossed each other
            if(i < j)
            {
                swap(nums[i], nums[j]);
            }
        }

        //finally swap j pointer item with pivot element
        //our pivot element is basically first element
        swap(nums[low], nums[j]);
        //return index of pivot element
        return j;
    }   

    //for recursive calls, divide&conquer approach
    void quicksort(vector<int>& nums, int low, int high)
    {
        if(low < high)
        {
            //find the pivot Index
            int pivotInd = pivotIndex(nums, low, high);
            //quicksort for left of pivot
            quicksort(nums, low, pivotInd-1);
            //quicksort for right of pivot
            quicksort(nums, pivotInd+1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return nums;
        }

        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};
