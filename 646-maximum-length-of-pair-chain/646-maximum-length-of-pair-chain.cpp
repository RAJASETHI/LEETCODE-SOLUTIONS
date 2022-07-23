class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
        // return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs),cmp);
        int curr=-1001;
        int cnt=0;
        for(auto i:pairs)
        {
            if(curr<i[0])
            {
                cnt++;
                curr=i[1];
            }
        }
        return cnt;
        
    }
};