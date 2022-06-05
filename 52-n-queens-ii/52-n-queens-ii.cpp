class Solution {
public:
    int f(int x,vector<int>col,vector<int>d1,vector<int>d2)
    {
        int n=col.size();
        if(x==n)return 1;
        int cnt=0;
        for(int y=0;y<n;y++)
        {
            if(!col[y] && !d1[x+y] && !d2[n+x-y])
            {
                col[y]=1;
                d1[x+y]=1;
                d2[n+x-y]=1;
                cnt+=f(x+1,col,d1,d2);
                col[y]=0;
                d1[x+y]=0;
                d2[n+x-y]=0;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<int>col(n,0);
        vector<int>d1(2*n+1,0);
        vector<int>d2(2*n+1,0);
        return f(0,col,d1,d2);
    }
};