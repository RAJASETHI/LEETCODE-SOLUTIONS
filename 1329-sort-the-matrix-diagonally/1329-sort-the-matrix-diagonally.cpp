class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>idx;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &i:mp)
        {
            sort(i.second.begin(),i.second.end());
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=mp[i-j][idx[i-j]];
                idx[i-j]++;
            }
        }
        return mat;
        
    }
};