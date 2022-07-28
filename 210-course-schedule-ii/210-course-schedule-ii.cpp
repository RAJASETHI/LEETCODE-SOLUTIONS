class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
       vector<int>adj[n];
        vector<int>in(n,0);
        for(auto i:pre)
        {
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)q.push(i);
        }
        vector<int>res;
        while(q.size())
        {
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto x:adj[node])
            {
                in[x]--;
                if(!in[x])
                {
                    q.push(x);
                }
            }
        }
        if(res.size()==n)return res;
        return {};
    }
};