class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>freq;
        for(auto i:arr)freq[i]++;
        vector<vector<int>>ff;
        for(auto i:freq)
        {
            ff.push_back({i.first,i.second});
        }
        sort(ff.begin(),ff.end(),cmp);
        int sum=arr.size()/2,cnt=0;
        for(auto i:ff)
        {
            if(sum>0)
            {
                cnt++;
                sum-=i[1];
            }
        }
        return cnt;
    }
};