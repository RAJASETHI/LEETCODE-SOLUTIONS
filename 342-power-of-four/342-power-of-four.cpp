class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n==INT_MIN)return false;
        if(n<=0)return false;
        int val=n&(-n);
        if(n!=val)return false;
        val=log2(n);
        if(val%2==0)return true;
        return false;
    }
};