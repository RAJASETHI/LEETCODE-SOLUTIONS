class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int mx=0;
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=0;i<n;i++)
        {
            int cnt=1,sm=0;
            for(int j=i;j<n;j++)
            {
                sm+=cnt*(satisfaction[j]);
                cnt++;
            }
            mx=max(mx,sm);
        }
        return mx;
    }
};