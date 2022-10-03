class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        char ch=colors[0];
        int mx=neededTime[0],sm=neededTime[0];
        for(int i=1;i<colors.size();i++)
        {
            if(ch==colors[i])
            {
                sm+=neededTime[i];
                mx=max(mx,neededTime[i]);
            }
            else
            {
                cost+=sm-mx;
                sm=mx=neededTime[i];
                ch=colors[i];
            }
        }
        cost+=sm-mx;
        return cost;
    }
};