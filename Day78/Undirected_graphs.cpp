

#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter nodes :";
    cin>>n;
    cout<<"Enter number of EDges : ";
    cin>>m;
    vector<int> adj[n+1];
    
    cout<<"Enter nodes connections";
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        
        //undirected graphs
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //print graph connections
    for(int i=0;i<n+1;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        
        cout<<" "<<endl;
    }

    return 0;
}
