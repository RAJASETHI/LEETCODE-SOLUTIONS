class Solution {
public:
    int consecutiveNumbersSum(int n) {
        if(n==1)return 1;
        int cnt=0;
        for(int i=1;i*(i+1)<2*n;i++)
        {
            double a=(1.0*n-(i)*(i+1)/2)/(i+1);
            if(a-(int)a==0.0)cnt++;
        }
        return cnt+1;
    }
};