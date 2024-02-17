class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int indegree[graph.size()];
        for(int i=0;i<graph.size();i++)
        {
            indegree[i] = 0;
        }

        //reverse adjacency list
        vector<vector<int>> revAdj(graph.size());
        //reverse the adjacency list, to get nodes which are connected to safe nodes
        for(int i=0;i<graph.size();i++)
        {   
            //i -> it, to reverse it -> i
            for(auto it:graph[i])
            {
                revAdj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> topo;
        for(int i=0;i<graph.size();i++)
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

            for(auto it:revAdj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};
