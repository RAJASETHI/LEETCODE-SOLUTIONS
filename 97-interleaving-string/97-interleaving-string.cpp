class Solution {
public:
    bool f(int i,int j,int k,string s2, string s1, string s3,vector<vector<vector<int>>>&dp)
    {
        if(i==s1.size())
        {
            while(j<s2.size())
            {
                if(s2[j]!=s3[k])return false;
                j++;
                k++;
            }
            return true;
        }
        if(j==s2.size())
        {
            while(i<s1.size())
            {
                if(s1[i]!=s3[k])return false;
                i++;
                k++;
            }
            return true;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(s1[i]==s2[j] && s2[j]==s3[k])return dp[i][j][k]=(f(i+1,j,k+1,s2,s1,s3,dp) || f(i,j+1,k+1,s2,s1,s3,dp));
        else if(s1[i]==s3[k])return dp[i][j][k]=f(i+1,j,k+1,s2,s1,s3,dp);
        else if(s2[j]==s3[k])return dp[i][j][k]=f(i,j+1,k+1,s2,s1,s3,dp);
        return dp[i][j][k]=false;
    }
    bool isInterleave(string s2, string s1, string s3) {
        int i=0,j=0,k=0,n=s1.size(),m=s2.size(),l=s3.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,-1)));
        if(n+m!=l)return false;
        return f(0,0,0,s2,s1,s3,dp);
    }
};