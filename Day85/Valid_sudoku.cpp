class Solution {
public:

    bool isInvalid(vector<vector<char>> board)
    {
        for(int i=0;i<9;i++)
        {
            //checking for i rows
            map<char, int> mp;
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    mp[board[i][j]]++;
                    if(mp[board[i][j]] > 1)
                    {
                        return true;
                    }
                }
            }

            //checking for columns
            mp.clear();
            for(int j=0;j<9;j++)
            {
                if(board[j][i] != '.')
                {
                    mp[board[j][i]]++;
                    if(mp[board[j][i]] > 1)
                    {
                        return true;
                    }
                }
            }

            //checking for ith subarrays boxes
            mp.clear();
            int row = (i/3)*3;
            int col = (i%3)*3;
            for(int r=row; r<row+3; r++)
            {
                for(int c=col;c<col+3; c++)
                {
                    if(board[r][c] != '.')
                    {
                        mp[board[r][c]]++;
                    }

                    if(mp[board[r][c]] > 1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(isInvalid(board))
        {
            return false;
        }

        return true;
    }
};
