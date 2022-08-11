class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int idx=1;
        int cnt=n*n;
        int r1=0,r2=n-1,c1=0,c2=n-1;
        while(cnt>0)
        {
            for(int i=c1;i<=c2 && (cnt-->0);i++)res[r1][i]=idx++;
            r1++;
            for(int i=r1;i<=r2&& (cnt-->0);i++)res[i][c2]=idx++;
            c2--;
            for(int i=c2;i>=c1&& (cnt-->0);i--)res[r2][i]=idx++;
            r2--;
            for(int i=r2;i>=r1&& (cnt-->0);i--)res[i][c1]=idx++;
            c1++;
        }
        return res;
    }
};