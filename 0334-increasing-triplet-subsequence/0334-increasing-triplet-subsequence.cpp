class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;
        int left,mid;
        left=mid=INT_MAX;
        for(auto num:nums)
        {
            if(mid<num)return true;
            if(mid>num && num>left)mid=num;
            else if(num<left)left=num;
        }
        return false;
    }
};