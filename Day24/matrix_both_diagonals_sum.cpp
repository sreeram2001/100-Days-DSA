class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sumi = 0;
        int i=0, j=0;

        //primary diagonal
        while(i < mat.size() || j < mat.size())
        {
            sumi = sumi + mat[i][j];
            mat[i][j] = 0;
            i++;
            j++;
        }

        //secondary diagonal
        i = 0;
        j = mat.size()-1;

        while(i < mat.size() || j > 0)
        {
            sumi = sumi + mat[i][j];
            mat[i][j] = 0;
            i++;
            j--;
        }

        return sumi;
    }
};
