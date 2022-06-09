class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j]=mat[i][j]-'0';
                    continue;
                }
                
                if(mat[i][j]-'0')
                {
                    dp[i][j]+=dp[i-1][j]+1;
                }
            }
        }
        int mx=0;
        for(int i=0;i<m;i++)
        {
            mx=max(mx,mxArea(dp[i]));
        }
        return mx;
    }
    int mxArea(vector<int>h)
    {
        int n=h.size();
        vector<int>idx;
        h.push_back(0);
        int mx=0;
        for(int i=0;i<h.size();i++)
        {
            while(idx.size() && h[i]<=h[idx.back()])
            {
                int val=h[idx.back()];
                idx.pop_back();
                int par=-1;
                if(idx.size())
                {
                    par=idx.back();
                }
                mx=max(mx,val*(i-par-1));
            }
            idx.push_back(i);
        }
        // cout<<mx<<" ";
        return mx;
    }
};