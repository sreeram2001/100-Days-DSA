class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> rows;
        vector<int> cols;


        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(!(count(rows.begin(), rows.end(), i)))
                    {
                        rows.push_back(i);
                    }
                    if(!(count(cols.begin(), cols.end(), j)))
                    {
                        cols.push_back(j);
                    }
                }
            }
        }

        //make rows to zero
        for(auto i:rows)
        {
            for(int j=0;j<c;j++)
            {
                matrix[i][j] = 0;
            }
        }

        //make cols to zero
        for(int i=0;i<r;i++)
        {
            for(auto j:cols)
            {
                matrix[i][j] = 0;
            }
        }
    }
};
