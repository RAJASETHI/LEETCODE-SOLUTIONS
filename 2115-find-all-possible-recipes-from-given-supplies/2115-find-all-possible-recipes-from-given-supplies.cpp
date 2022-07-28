class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        int n=recipes.size();
        vector<int>in(n,0);
        unordered_map<string,int>idx;
        for(int i=0;i<n;i++)
        {
            idx[recipes[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ingredients[i].size();j++)
            {
                adj[ingredients[i][j]].push_back(recipes[i]);
                in[i]++;
            }
        }
        queue<string>q;
        for(auto i:supplies)q.push(i);
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(recipes[i]);
            }
        }
        vector<string>res;
        while(q.size())
        {
            string node=q.front();
            if(idx.find(node)!=idx.end())
            {
                res.push_back(node);
            }
            q.pop();
            for(auto i:adj[node])
            {
                in[idx[i]]--;
                if(in[idx[i]]==0)
                {
                    q.push(i);
                }
            }
        }
        return res;
    }
};