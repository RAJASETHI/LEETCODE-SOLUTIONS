class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>freq1(101,0),freq2(101,0),freq3(101,0);
        for(auto i:nums1)
            if(freq1[i]==0)freq1[i]=1;
        for(auto i:nums2)
            if(freq2[i]==0)freq2[i]=1;
        for(auto i:nums3)
            if(freq3[i]==0)freq3[i]=1;
        vector<int>res;
        for(int i=0;i<=100;i++)
        {
            if(freq1[i]+freq2[i]+freq3[i]>=2)res.push_back(i);
        }
        return res;
    }
};