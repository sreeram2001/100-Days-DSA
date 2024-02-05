class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = 0, c = matrix[0].size()-1;
        int rows = matrix.size()-1, cols = matrix[0].size()-1;

        while(r <= rows && c >= 0)
        {
            if(target == matrix[r][c])
            {
                return true;
            }
            else if(target < matrix[r][c])
            {
                c--;
            }
            else
            {
                r++;
            }
        }

        return false;
    }
};
