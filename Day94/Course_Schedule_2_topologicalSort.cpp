class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //create adjacency list
        vector<int> adj[numCourses];
        vector<int> topo;

        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        //using kahns algorithm approach
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++)
        {
            indegree[i] = 0;
        }

        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                //fill total incoming nodes to a vertex
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node])
            {
                //visit adjacent connected nodes
                //reduce indegree counter
                indegree[it]--;
                //push inside queue only when indegree count is 0
                if(indegree[it] == 0) q.push(it);
            }

        }

        //return vector only if its a topological sort
        if(topo.size() == numCourses)
        {
            return topo;
        }

        return {};
    }
};
