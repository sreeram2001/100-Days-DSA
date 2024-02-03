class Solution {
public:

    //dfs call for topological sort clubbed with cycle detection
    bool dfsTOPO(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> pathVis,stack<int> &topo)
    {
        visited[node] = 1;
        pathVis[node] = 1;

        //traverse thru adjacency nodes
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                if( dfsTOPO(it, adj, visited, pathVis, topo) == true)
                {
                    return true;
                }
            }
            else if(pathVis[it])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        topo.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //adjacency list
        vector<vector<int>> adj(numCourses);
        //contains topological order output
        vector<int> op;
        //visited array
        vector<int> visited(numCourses, 0);
        //path visited array
        vector<int> pathVis(numCourses, 0);
        stack<int> topo;

        //fill up my list
        //{ arr[1] = {arr[0]} }
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        //topological sort
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if( dfsTOPO(i, adj ,visited, pathVis, topo) == true )
                {
                    return op;
                }
            }
        }

        while(!topo.empty())
        {
            op.push_back(topo.top());
            topo.pop();
        }
        return op;
    }
};
