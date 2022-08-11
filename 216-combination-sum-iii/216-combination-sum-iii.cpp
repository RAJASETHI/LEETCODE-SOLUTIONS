class Solution {
public:
    vector<vector<int>>res;
    void solve(int k, int n,int i=1,int sum=0,vector<int> v={})
    {
        if(v.size()==k || i==10)
        {
            if(sum==n && v.size()==k)
            {
                res.push_back(v);
            }
            return;
        }
        v.push_back(i);
        solve(k,n,i+1,sum+i,v);
        v.pop_back();
        solve(k,n,i+1,sum,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        solve(k,n,1,0,{});
        
        return res;
    }
};