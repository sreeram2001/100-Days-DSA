class Solution {
public:
    bool dfs(int node, vector<vector<int>> graph, int vis[], int pathVis[], int safe[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        safe[node] = 0;    //initialise node as safe check to 0

        for(auto it:graph[node])
        {
            if(!vis[it])
            {
                if( dfs(it, graph, vis, pathVis, safe) == true)
                {   
                    safe[node] = 0; 
                    return true;
                }
            }
            //if node has been previously visited
            else
            {   
                //check if pathvisited
                if(pathVis[it])
                {
                safe[node] = 0; 
                //node has been visited already in the same path, hence cycle
                return true;
                }
            }
        }

        //iterations over reached last node hence marked as safe node
        safe[node] = 1;
        pathVis[node] = 0;  //revert back to not visited path
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        //visited array check
        int vis[V];
        //since this is directed graph we make use of pathvisited array
        int pathVis[V];
        //array to update if node is in safe state
        int safe[V];
        //output array
        vector<int> op;

        for(int i=0;i<V;i++)
        {
            vis[i] = 0;
            safe[i] = 0;
        }

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i, graph, vis, pathVis, safe);   
            }
        }

        for(int i=0;i<V;i++)
        {
            if(safe[i] == 1)
            {
                op.push_back(i);
            }
        }
        return op;
    }
};
