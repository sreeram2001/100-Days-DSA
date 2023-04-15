class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //exchange rows in matrix top-bottom
        for(int i=0;i<matrix.size()/2;i++)
        {
            swap(matrix[i],matrix[matrix.size()-1-i]);
        }

        //tranpose of a mtrix
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix.size();j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};
