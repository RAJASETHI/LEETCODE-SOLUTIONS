class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        int n=tr.size();
        int mx=INT_MAX;
        if(tr.size()==1)
        {
            mx=tr[0][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    tr[i][j]+=tr[i-1][j];
                }
                else if(j==i)
                {
                    tr[i][j]+=tr[i-1][j-1];
                }
                else
                {
                    tr[i][j]+=min(tr[i-1][j-1],tr[i-1][j]);
                }
                if(i==n-1)
                {
                    mx=min(mx,tr[i][j]);
                }
            }
        }
        return mx;
        
    }
};