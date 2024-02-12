 //set indegree - total incoming nodes to a vertice
	    int indegree[V] = {0};
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {   
	            //fill the total incoming nodes to a vertice
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    //fill initialise of q for vertices with 0 incoming nodes
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;   //stores topological sort
	    //BFS
	    while(!q.empty())
	    {
	        int node = q.front();
	        //push nodes inside output vector
	        topo.push_back(node);
	        q.pop();
	        
	        for(auto it:adj[node])
	        {
	            //now decrement the count
	            indegree[it]--;
	            //when the indegree reaches 0 push inside q;
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	    }
