class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>res;
        for(int i=0;i<m;i++)
        {
            vector<int>tmp;
            for(int j=0;j<n;j++)
            {
                tmp.push_back(matrix[j][i]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};