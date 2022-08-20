class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
         int n=arr.size();
        int r=0;
        int i=0,cnt=0;
        vector<int>nums(arr.begin(),arr.end());
        sort(nums.begin(),nums.end());
        unordered_map<int,list<int>>mp;
        for(int i=0;i<n;i++)
        {
            // cout<<nums[i]<<" "<<i<<"\n";
            mp[nums[i]].push_back(i);
        }
        
        while(i<n)
        {
            if(i<=r)
            {
                r=max(r,mp[arr[i]].front());
                mp[arr[i]].pop_front();
            }
            else
            {
                cnt++;
                r=mp[arr[i]].front();
                mp[arr[i]].pop_front();
            }
            // cout<<r<<" "<<cnt<<" "<<i<<"\n";
            i++;
        }
        cnt++;
        return cnt;
    }
};