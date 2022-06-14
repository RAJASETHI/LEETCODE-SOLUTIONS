class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return (a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]));
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>>res;
        sort(people.begin(),people.end(),cmp);
        
        for(auto p:people)
        {
            res.insert(res.begin()+p[1],p);
        }
        return res;
    }
};