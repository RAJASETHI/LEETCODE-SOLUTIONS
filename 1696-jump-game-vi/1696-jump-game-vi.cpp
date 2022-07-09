class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>q;
        int curr=0;
        for(int i=n-1;i>=0;i--)
        {
            if(q.size() && i+k<q.front())q.pop_front();
            curr=nums[i]+(q.size()?nums[q.front()]:0);
            while(q.size() && nums[q.back()]<=curr)q.pop_back();
            q.push_back(i);
            nums[i]=curr;
        }
        return curr;
    }
};