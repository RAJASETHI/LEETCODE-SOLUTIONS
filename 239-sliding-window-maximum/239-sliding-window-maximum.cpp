class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>lt;
        for(int i=0;i<k;i++)
        {
            while(lt.size() && lt.back()<nums[i] )lt.pop_back();
            lt.push_back(nums[i]);
        }
        vector<int>res;
        int n=nums.size();
        res.push_back(lt.front());
        for(int i=k;i<n;i++)
        {
            if(lt.size() && lt.front()==nums[i-k])lt.pop_front();
            while(lt.size() && lt.back()<nums[i] )lt.pop_back();
            lt.push_back(nums[i]);
            res.push_back(lt.front());
        }
        return res;
    }
};