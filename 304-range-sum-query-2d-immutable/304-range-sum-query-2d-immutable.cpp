class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        dp.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                dp[i][j]=matrix[i][j];
                if(!i && !j)
                {
                    
                }
                else if(!j)
                {
                    dp[i][j]+=dp[i-1][j];
                }
                else if(!i)
                {
                    dp[i][j]+=dp[i][j-1];
                }
                else
                    dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<"\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int val=dp[row2][col2];
        if(row1)val-=dp[row1-1][col2];
        if(col1)val-=dp[row2][col1-1];
        if(row1 && col1)val+=dp[row1-1][col1-1];
        return val;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */