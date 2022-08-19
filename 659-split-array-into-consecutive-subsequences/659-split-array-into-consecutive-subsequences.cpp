class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>left,end;
        for(auto i:nums)
        {
            left[i]++;
        }
        for(auto i:nums)
        {
            if(left[i]==0)continue;
            left[i]--;
            if(end[i-1]>0)
            {
                end[i-1]--;
                end[i]++;
            }
            else if(left[i+1]>0 && left[i+2]>0)
            {
                left[i+1]--;
                left[i+2]--;
                end[i+2]++;
            }
            
            else
            {
                cout<<i<<"\n";
                return false;
            }
        }
        return true;
    }
};