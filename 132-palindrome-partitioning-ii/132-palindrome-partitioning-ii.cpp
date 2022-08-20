class Solution {
public:
    vector<int>dp;
    vector<vector<int>>isBool;
    bool isPalindrome(int l,int r)
    {
       return isBool[l][r];
    }
    int f(int idx,string s)
    {
        if(idx>=s.size())
        {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        string tmp;
        int mn=1e6;
        for(int i=idx;i<s.size();i++)
        {
            tmp+=s[i];
            if(isPalindrome(idx,i))
            {
                mn=min(mn,f(i+1,s)+1);
            }
        }
        return dp[idx]=mn;
    }
    int minCut(string s) {
        isBool.resize(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=s.size()-1;i>=0;i--)
        {
            for(int j=s.size()-1;j>=i;j--)
            {
                if(j==i)
                {
                    isBool[i][j]=1;
                }
                else if(j-i==1)
                {
                    isBool[i][j]=s[j]==s[i];
                }
                else
                {
                    isBool[i][j]=(s[j]==s[i] && isBool[i+1][j-1]);
                }
            }
        }
        dp.resize(s.size()+1,-1);
        return f(0,s)-1;
    }
};