class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int low = 0;
        int high = r*c - 1;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            int mid_r = mid/c;
            int mid_c = mid%c;
            
            if(matrix[mid_r][mid_c] == target)
            {
                return true;
            }
            
            if(matrix[mid_r][mid_c] < target)
            {
                low = mid + 1;
            }
            
            else
            {
                high = mid - 1;
            }
        }
        
        return false;
    }
};
