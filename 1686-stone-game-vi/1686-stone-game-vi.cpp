class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]>b[0];
    }
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        // vector<int>a=aliceValues;
        vector<vector<int>>a;
        int n=aliceValues.size();
        for(int i=0;i<aliceValues.size();i++)
        {
            a.push_back({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
        }
        sort(a.begin(),a.end(),cmp);
        int sm1=0,sm2=0;
        for(int i=0;i<n;i+=2)
        {
            sm1+=a[i][1];
            if(i+1<n)sm2+=a[i+1][2];
        }
        // cout<<sm1<<" "<<sm2<<"\n";
        if(sm1>sm2)return 1;
        else if(sm1==sm2)return 0;
        return -1;
    }
};