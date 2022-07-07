class Solution {
public:
    int dfs(int idx,vector<vector<int>>& graph,vector<int>&vis,vector<int>&res)
    {
        vis[idx]=1;
        int ans=1;
        for(auto i:graph[idx])
        {
            if(res[i]==-1 && vis[i]==0)
            {
                ans=ans && dfs(i,graph,vis,res);
            }
            else if(res[i]==0 || vis[i]==1)
            {
                ans=0;
                break;
            }
        }
        res[idx]=ans;
        vis[idx]=0;
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>res(n,-1);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(res[i]==-1)
            {
                dfs(i,graph,vis,res);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(res[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};