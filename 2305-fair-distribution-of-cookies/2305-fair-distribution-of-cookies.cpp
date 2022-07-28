class Solution {
public:
    int mx=INT_MAX;
    void f(int idx,vector<int>&nums,vector<int>&cookies)
    {
        if(idx==cookies.size())
        {
            mx=min(mx,*max_element(nums.begin(),nums.end()));
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]+=cookies[idx];
            f(idx+1,nums,cookies);
            nums[i]-=cookies[idx];
            if(nums[i]==0)break;
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        mx=INT_MAX;
        vector<int>nums(k,0);
        f(0,nums,cookies);
        return mx;
    }
};