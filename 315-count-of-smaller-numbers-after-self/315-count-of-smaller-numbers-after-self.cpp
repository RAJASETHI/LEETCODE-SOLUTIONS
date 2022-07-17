class BIT{
    private:
        vector<int>bit;
    public:
        BIT(int n) : bit(n+1) { }
        void update(int idx,int val)
        {
            while(idx<bit.size())
            {
                bit[idx]+=val;
                idx+=idx&(-idx);
            }
        }
        int query(int idx)
        {
            int sm=0;
            while(idx>0)
            {
                sm+=bit[idx];
                idx-=idx&(-idx);
            }
            return sm;
        }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        int mx=1e4+1;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]+=mx;
        }
        BIT t(2*mx);
        for(int i=n-1;i>=0;i--)
        {
            t.update(nums[i],1);
            res.push_back(t.query(nums[i]-1));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};