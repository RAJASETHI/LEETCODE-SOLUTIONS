class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res;
        for(auto i:nums)
        {
            if(!res.size())
            {
                res.push_back(i);
            }
            else
            {
                res.push_back(res[res.size()-1]+i);
            }
        }
        return res;
    }
};