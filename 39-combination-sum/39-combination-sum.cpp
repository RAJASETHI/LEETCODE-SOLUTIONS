class Solution {
public:
    vector<vector<int>>res;
    void f(int idx,vector<int>&c,int target,vector<int>ans)
    {
        if(idx>=c.size() || target<=0)
        {
            if(target==0)
            {
                res.push_back(ans);
            }
            return;
        }
        if(target>=c[idx])
        {
            ans.push_back(c[idx]);
            f(idx,c,target-c[idx],ans);
            ans.pop_back();
        }
        f(idx+1,c,target,ans);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        res.clear();
         f(0,c,target,{});
        return res;
    }
};