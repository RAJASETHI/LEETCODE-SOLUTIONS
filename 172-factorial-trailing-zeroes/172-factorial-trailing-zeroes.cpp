class Solution {
public:
    int trailingZeroes(int n) {
        int five=0,two=0;
        for(int i=1;i<=n;i++)
        {
            int num=i;
            while(num)
            {
                if(num%5==0)
                {
                    five++;
                    num/=5;
                }
                else if(num%2==0)
                {
                    two++;
                    num/=2;
                }
                else break;
            }
        }
        return min(five,two);
    }
};