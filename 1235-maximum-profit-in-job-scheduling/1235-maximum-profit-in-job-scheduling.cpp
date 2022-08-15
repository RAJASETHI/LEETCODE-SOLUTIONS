class Solution {
public:
    // static bool cmp(vector<int>&a,vector<int>&b)
    // {
    //     if(a[1]==b[1])return 
    // }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            res.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(res.begin(),res.end());
        map<int,int>dp={{0,0}};
        for(auto &job:res)
        {
            int curr=prev(dp.upper_bound(job[1]))->second+job[2];
            if(curr>dp.rbegin()->second)
            {
                dp[job[0]]=curr;
            }
        }
        return dp.rbegin()->second;
    }
};