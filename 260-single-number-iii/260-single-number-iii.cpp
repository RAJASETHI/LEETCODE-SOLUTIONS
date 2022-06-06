class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res;
        int x=0;
        for(auto i:nums)x^=i;
        int idx=0;
        for(int i=0;i<32;i++)
        {
            int num=1<<i;
            if((x&num))
            {
                idx=i;
                break;
            }
        }
        idx=1<<idx;
        int a=0,b=0;
        for(auto i:nums)
        {
            if((i&idx))
            {
                a=a^i;
            }
            else
            {
                b=b^i;
            }
        }
        return {a,b};
    }
};