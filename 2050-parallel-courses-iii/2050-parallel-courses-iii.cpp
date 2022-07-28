class Solution {
public:
    void dfs(vector<int>adj[],vector<int>&t,vector<int>&res,int idx,int time)
    {
        if(res[idx]>time+t[idx])
        {
            return;
        }
        else
        {
            res[idx]=time+t[idx];
        }
        for(auto i:adj[idx])
        {
            dfs(adj,t,res,i,res[idx]);
        }
    }
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& t) {
        vector<int>adj[n];
        vector<int>in(n,0);
        for(int i=0;i<r.size();i++)
        {
            r[i][0]--;
            r[i][1]--;
            // cout<<r[i][0]<<" "<<r[i][1]<<"\n";
            adj[r[i][0]].push_back(r[i][1]);
            in[r[i][1]]++;
        }
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                dfs(adj,t,res,i,0);
            }
        }
        int mx=0;
        for(auto i:res)mx=max(mx,i);
        return mx;
    }
};