class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int n=matrix.size(),m=matrix[0].size();
        int cnt=m*n;
        int r1=0,r2=n-1,c1=0,c2=m-1;
        while(cnt>0)
        {
            for(int j=c1;j<=c2 && (cnt--)>0;j++)
            {
                res.push_back(matrix[r1][j]);
            }
            r1++;
            for(int i=r1;i<=r2 && (cnt--)>0;i++)
            {
                res.push_back(matrix[i][c2]);
            }
            c2--;
            for(int j=c2;j>=c1 && (cnt--)>0;j--)
            {
                res.push_back(matrix[r2][j]);
            }
            r2--;
            for(int i=r2;i>=r1 && (cnt--)>0;i--)
            {
                res.push_back(matrix[i][c1]);
            }
            c1++;
        }
        return res;
    }
};