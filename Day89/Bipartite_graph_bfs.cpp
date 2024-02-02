class Solution {
public:
    //bfs
    bool bfs(int startnode, vector<vector<int>>& graph, int color[])
    {
        queue<int> q;
        q.push(startnode);
        //start with color 0
        color[startnode] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            //traverse thru adjacenecy list
            for(auto it:graph[node])
            {
                if(color[it] == -1)
                {   
                    //keep opposite colors to adjacent nodes
                    color[it] = !color[node];
                    q.push(it);
                }
                else
                {   
                    //if adjacent sides encounter same color return false;
                    if(color[it] == color[node])
                    {
                        return false;
                    }
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
                if(bfs(i, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
