class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>idx;
        h.push_back(0);
        int mx=0;
        for(int i=0;i<=n;i++)
        {
            while(idx.size() && h[i]<=h[idx.back()])
            {
                int val=h[idx.back()];
                idx.pop_back();
                int par_idx=-1;
                if(idx.size())
                {
                    par_idx=idx.back();
                }
                mx=max(mx,(i-1-(par_idx+1)+1)*val);
            }
            idx.push_back(i);
        }
        return mx;
    }
};