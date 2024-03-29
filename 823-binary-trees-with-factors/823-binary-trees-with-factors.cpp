class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        unordered_map<int,long>dp;
        long cnt=0;
        for(int i=0;i<n;i++)
        {
            dp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                    dp[arr[i]]=(dp[arr[i]]+(dp[arr[j]]*(dp[arr[i]/arr[j]])))%mod;
            }
            cnt=(cnt+dp[arr[i]])%mod;
        }
        return cnt;
    }
};