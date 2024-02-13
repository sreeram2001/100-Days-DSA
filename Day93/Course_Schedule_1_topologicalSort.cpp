//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    //create adjacency list
	    vector<int> adj[N];
	    
	    for(auto it:prerequisites)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    //indegree array - counts total incoming nodes
	    int indegree[N] = {0};
	    
	    for(int i=0;i<N;i++)
	    {
	        for(auto it:adj[i])
	        {
	            //fill the total incoming nodes to a vertice
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    //initialise queue
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    int counter = 0;    //counter variable to check total vertices
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        //increment counter
	        counter++;
	        q.pop();
	        
	        for(auto it:adj[node])
	        {
	            //decrement the indegree count
	            indegree[it]--;
	            
	            if(indegree[it] == 0)
	            {
	                q.push(it);
	            }
	        }
	        
	    }
	    
	    
	    if(counter == N)
	    {
	        return true;
	    }
	    
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
