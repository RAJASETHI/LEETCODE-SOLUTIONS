class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        int max_e=*max_element(nums.begin(),nums.end());
        int min_e=*min_element(nums.begin(),nums.end());
        double gap=double(max_e-min_e)/double(n-1);
        gap=max(gap,(double)1);
        vector<int>maxA(n,INT_MIN);
        vector<int>minA(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            int idx=(nums[i]-min_e)/gap;
            maxA[idx]=max(maxA[idx],nums[i]);
            minA[idx]=min(minA[idx],nums[i]);
        }
        int prev=maxA[0],mx=0;
        for(int i=1;i<n;i++)
        {
            if(minA[i]==INT_MAX)continue;
            
            else
            {
                mx=max(mx,minA[i]-prev);
                prev=maxA[i];
            }
        }
        return mx;
    }
};