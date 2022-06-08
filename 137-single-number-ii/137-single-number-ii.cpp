class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>freq(32,0);
        for(auto i:nums)
        {
            for(int q=0;q<32;q++)
            {
                freq[q]+=(i&1);
                i>>=1;
                if(i==0)break;
            }
        }
        int res=0;
        for(int i=31;i>=0;i--)
        {
            if(freq[i]%3)
            {
                cout<<i<<" ";
                res+=1<<i;
            }
        }
        return res;
    }
};