// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int min_idx(vector<int>&key,vector<int>&mst)
	{
	    int  mn=INT_MAX,mni=-1;
	    for(int i=0;i<key.size();i++)
	    {
	        if(mst[i]==0 && mn>key[i])
	        {
	            mn=key[i];
	            mni=i;
	        }
	    }
	    return mni;
	}
	void prims(int V, vector<vector<int>> adj[],vector<int>&key,vector<int>&mst,vector<pair<int,int>>&par)
	{
	    int u=min_idx(key,mst);
        if(u==-1)return;
        mst[u]=1;
        for(auto i:adj[u])
        {
            int node=i[0],dist=i[1];
            if(mst[node]==0 && key[node]>dist)
            {
                key[node]=dist;
                par[node]={u,dist};
            }
        } 
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>key(V,INT_MAX),mst(V,0);
        vector<pair<int,int>>par(V,{0,0});
        key[0]=0;
        par[0]={-1,0};
       for(int i=0;i<V-1;i++)
       {
           prims(V,adj,key,mst,par);
       }
       int sm=0;
       for(int i=1;i<V;i++)
       {
           sm+=par[i].second;
       }
       return sm;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends