// class BIT{
//     private:
//     vector<int>bits;
//     public:
//     BIT(int n):bits(n){}
//     void update(int num)
//     {
//         int val=1;
//         for(int i=num;i<bits.size();i+=(i&(-i)))
//         {
//             bits[i]+=val;
//         }
//     }
//     int query(int num)
//     {
//         int sm=0;
//         for(int i=num;i>0;i-=(i&(-i)))
//         {
//             sm+=bits[i];
//         }
//         return sm;
//     }
// };
class BIT{
    private:
        vector<int>bit;
    public:
        BIT(int n) : bit(n+1) { }
        void update(int idx,int val=1)
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
        int n=nums.size();
        int mx=1e4+1;
        BIT obj(2*mx);
        for(int i=0;i<n;i++)nums[i]+=mx;
        vector<int>res;
        for(int i=n-1;i>=0;i--)
        {
            res.push_back(obj.query(nums[i]-1));
            obj.update(nums[i]);
        }
        reverse(begin(res),end(res));
        return res;
    }
};