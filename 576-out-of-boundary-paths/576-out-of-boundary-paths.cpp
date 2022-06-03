class Solution {
public:
    int mod=pow(10,9)+7;
    vector<vector<vector<int>>>dp;
    int f(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if(startRow>=m || startRow<0 || startColumn<0 || startColumn>=n )return 1;
        if(!maxMove)return 0;
        if(dp[startRow][startColumn][maxMove]!=-1)return dp[startRow][startColumn][maxMove];
        return dp[startRow][startColumn][maxMove]=((f(m,n,maxMove-1,startRow+1,startColumn)%mod+f(m,n,maxMove-1,startRow,startColumn+1)%mod)%mod+(f(m,n,maxMove-1,startRow-1,startColumn)%mod+f(m,n,maxMove-1,startRow,startColumn-1)%mod)%mod)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return f(m,n,maxMove,startRow,startColumn);
    }
};