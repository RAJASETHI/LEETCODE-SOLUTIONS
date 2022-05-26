class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n)
        {
            if(n&(n+1)==0)
            {
                cnt+=log2(n)+1;
                return cnt;
            }
            cnt+=n&1;
            n>>=1;
        }
        return cnt;
    }
};