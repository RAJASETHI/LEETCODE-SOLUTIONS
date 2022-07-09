class Solution {
public:
    #define resp(i,a,b) for(int i=a;i<b;i++)
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n-1;
        int dp[n];
        resp(k,0,n)dp[k]=-1;
        dp[n-1]=0;
        int i=n-2;
        while(i>=0)
        {
            if(nums[i]+i>=n-1)dp[i]=1;
            else if(nums[i])
            {
                int m=n+1;
                int pos=-1;
                for(int j=i+1;j<=i+nums[i];j++)
                {
                    if(dp[j]<m && dp[j]!=-1)
                    {
                        m=dp[j];
                        pos=j;
                    }
                    // cout<<m<<" ";
                }
                // cout<<"\n";
                dp[i]=m+1;
            }
            // cout<<dp[i]<<" ";
            i--;
        }
        return dp[0];
    }
};