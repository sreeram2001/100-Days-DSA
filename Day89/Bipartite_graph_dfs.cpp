class Solution {
public:
    //bfs
    bool dfs(int node, int col, vector<vector<int>>& graph, int color[])
    {
        //mark it as visited and colored
        color[node] = col;

        for(auto it:graph[node])
        {
            if(color[it] == -1)
            {   
                //in the dfs call pass the opposite color so adjcent sides are not same color
                if( dfs(it, !col, graph, color) == false)
                {
                    return false;
                }
            }
            else
            {
                if(color[it] == col)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();   //total number of vertices
        //array to store the bipartite color for each node
        int color[V];

        for(int i=0;i<V;i++)
        {
            color[i] = -1;
        }

        //we will run all nodes thru bfs
        //we run a for loop in case input has seperate components inside of one graph comp.
        for(int i=0;i<V;i++)
        {
            if(color[i] == -1)
            {   
                //if same colors are present in adjacent nodes return false
                if(dfs(i, 0, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
