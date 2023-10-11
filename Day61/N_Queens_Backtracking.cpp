class Solution {
public:

    vector<vector<string>> op;

    bool noAttack(int Origrow, int Origcol, vector<string>& chessBoard, int n)
    {   
        //we have to checks for attack from left up-diagonal, left side and //left downward diagonal
        
        //checking in left upward diagonal
        int row = Origrow, col = Origcol;
        while(row >= 0 && col >= 0)
        {
            if(chessBoard[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }

        //checking in left downward diagonal
        row = Origrow;
        col = Origcol;
        while(row < n && col >= 0)
        {
            if(chessBoard[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }

        //checking in left side
        row = Origrow;
        col = Origcol;
        while(col >= 0)
        {
            if(chessBoard[row][col] == 'Q')
            {
                return false;
            }
            col--;
        }
        return true;
    }

    void fillBoard(vector<string> chessBoard, int n, int col)
    {
        if(col == n)
        {
            op.push_back(chessBoard);
            return;
        }
        //iterating each row to place Queen
        for(int row=0;row<n;row++)
        {   
            //calling noAttack function to check if Queen can be placed safely
            //function checks if there is no Attack
            if(noAttack(row, col, chessBoard, n))
            {
                chessBoard[row][col] = 'Q';
                fillBoard(chessBoard, n, col+1);     //move to next col for next recursion
                chessBoard[row][col] = '.';            //backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n);
        string row(n, '.');  //each row is a stirng of '.' initially

        //filling input into chessboard
        for(int i=0;i<n;i++)
        {
            chessBoard[i] = row;
        }
        fillBoard(chessBoard, n, 0);
        return op;
    }
};
