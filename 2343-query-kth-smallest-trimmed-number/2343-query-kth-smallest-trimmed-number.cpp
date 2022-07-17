class Solution {
public:
    // struct cmp{
        static bool cmp(pair<string,int>&p1,pair<string,int>&p2)
        {
            if(p1.first==p2.first)return p1.second<p2.second;
            return p1.first<p2.first;
        }
    // };
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        unordered_map<int,vector<pair<string,int>>>mp;
        for(int i=0;i<=nums[0].size();i++)
        {
            int cp=0;
            for(auto x:nums)
            {
                mp[i].push_back({x.substr(x.size()-i),cp});
                cp++;
            }
            
        }
        for(auto &i:mp)
        {
            sort(i.second.begin(),i.second.end(),cmp);
        }
        for(auto i:queries)
        {
            
            // while(q.size()>k)
            // {
            //     cout<<q.top().first<<" "<<q.top().second<<"\n";
            //     q.pop();
            // }
            // cout<<"\n";
            res.push_back(mp[i[1]][i[0]-1].second);
        }
        return res;
    }
};