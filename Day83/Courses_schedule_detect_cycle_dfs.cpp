class Solution {
public:

    //helper function to check for cycle using dfs
    bool isCycle(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathvisited)
    {
        visited[node] = 1;
        pathvisited[node] = 1;

        for(auto adjnode:adj[node])
        {   
            //if its not visited then recursive dfs
            if(!visited[adjnode])
            {
                if(isCycle(adjnode, adj, visited, pathvisited))
                {
                    return true;
                }
            }
            else if(visited[adjnode] && pathvisited[adjnode])
            {
                //if its visited thn check in pathvisits
                //return if cycle detected
                return true;
            }
        }

        //change path visited to default
        pathvisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //creating the adjency list
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathvisited(numCourses, 0);

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i] && isCycle(i, adj, visited, pathvisited))
            {
                return false;
            }
        }
        return true;
    }
};
