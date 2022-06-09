class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    double val(vector<int>&a,vector<int>&b)
    {
        double sm=sqrt((b[0]-a[0])*(b[0]-a[0])+(b[1]-a[1])*(b[1]-a[1]));
        return sm;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>dp={p1,p2,p3,p4};
        set<vector<int>>st={p1,p2,p3,p4};
        if(st.size()!=4)return 0;
        sort(dp.begin(),dp.end(),cmp);
        if((dp[2][1]-dp[0][1])*(dp[1][1]-dp[0][1])==(dp[1][0]-dp[0][0])*(-1)*(dp[2][0]-dp[0][0]))
        {
            if((dp[2][1]-dp[3][1])*(dp[1][1]-dp[3][1])==(dp[1][0]-dp[3][0])*(-1)*(dp[2][0]-dp[3][0]))
            {
                if(val(dp[0],dp[2])==val(dp[1],dp[3]) && val(dp[0],dp[1])==val(dp[2],dp[3]) && val(dp[0],dp[1])==val(dp[0],dp[2]))
                {
                    return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
        return true;
    }
};