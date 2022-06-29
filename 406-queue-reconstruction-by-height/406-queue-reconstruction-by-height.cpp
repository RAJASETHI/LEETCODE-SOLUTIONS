class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1])return a[0]>b[0];
        return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
       vector<vector<int>>res;
        sort(begin(people),end(people),cmp);
        for(auto p:people)
        {
            // cout<<p[0]<<" "<<p[1]<<"\n";
            int idx=0;
            int cnt=0;
            while(cnt<p[1] && idx<res.size())
            {
                
                if(cnt==p[1])break;
                if(res[idx][0]>=p[0])cnt++;
                
                idx++;
            }
            if(idx==res.size())res.push_back(p);
            else
            res.insert(res.begin()+idx,p);
        }
        return res;
    }
};