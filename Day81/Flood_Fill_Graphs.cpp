class Solution {
public:

    void dfs(int sr, int sc, int initialCol, vector<vector<int>>& op,vector<vector<int>> image, int color)
    {
        op[sr][sc] = color;

        int n = image.size();    //row size
        int m = image[0].size();  //col size

        //checking neighbours of the node
        //neighbours are - (row-1,col) (row,col+1) (row+1,col) (row,col-1)
        //i.e. (-1,0) (0,1) (1,0) (0,-1)
        //let us use an array with values -1 to 1 and iterate for neighbours
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i=0;i<=3;i++)
        {
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];

            if(nrow >= 0 && nrow<n && ncol >=0 && ncol < m && image[nrow][ncol]==initialCol
            && op[nrow][ncol] != color)
            {
                dfs(nrow, ncol, initialCol, op, image, color);
            }
        }

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        //initial color of source,
        int initialCol = image[sr][sc];

        //creating a copy of input array
        vector<vector<int>> op = image;

        //make the dfs call
        dfs(sr, sc, initialCol, op, image, color);

        return op;
    }
        

};
