class Solution {
public:
//     vector<int>dp;
//     int f(int idx,vector<int>&stone)
//     {
//         if(idx>=stone.size())return 0;
//         int sm=0,mn=INT_MIN;
//         if(dp[idx]!=-1)return dp[idx];
        
//         return dp[idx]=mn;
//     }
    // string stoneGameIII(vector<int>& stoneValue) {
    //     string res="Tie";
    //     int n=stoneValue.size();
    //     dp.resize(n,-1);
    //     int val=f(0,stoneValue);
    //     if(val>0)res="Alice";
    //     else if(val<0)res="Bob";
    //     return res;
    // }
    string stoneGameIII(vector<int>& stone) {
        string res="Tie";
        int n=stone.size();
        vector<int>dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            int sm=0,mn=INT_MIN;
            for(int i=idx;i<min(idx+3,(int)stone.size());i++)
            {
                sm+=stone[i];
                mn=max(mn,sm-dp[i+1]);
            }
            dp[idx]=mn;
        }
        int val=dp[0];
        if(val>0)res="Alice";
        else if(val<0)res="Bob";
        return res;
    }
};