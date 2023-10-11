class Solution {
public:

    bool recursFill(vector<vector<char>>& board)
    {
        for(int r=0;r<9;r++)
        {
            for(int c=0; c<9; c++)
            {
                //check for free/unfilled space
                if(board[r][c] == '.')
                {
                    //check if any numbers from 1-9 can be filled
                    for(char ch='1';ch<='9';ch++)
                    {
                        //check number is valid to be placed
                        if(canPlaced(r, c, ch, board))
                        {
                            //if yes then fill it in the board
                            board[r][c] = ch;

                            //make next recursive call, check if its successfull
                            if(recursFill(board))
                            {
                                return true;
                            }
                            else
                            {
                                //if not backtrack
                                board[r][c] = '.';
                            }
                        }
                    }
                    //if a number cannot be placed we return false to move to next recursion way
                    return false;
                }
            }
        }
        return true;
    }

    //function to check if num 1-9 can placed, check for each row, each col, in subarray
    bool canPlaced(int r, int c, char ch, vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            //if number present in row return false
            if(board[r][i] == ch)
            {
                return false;
            }
            //if number present in col return false
            if(board[i][c] == ch)
            {
                return false;
            }
            //if number present in any subarray 3X3 return false
            if(board[3*(r/3) + i/3][3*(c/3) + i%3] == ch)
            {
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recursFill(board);
    }
};
