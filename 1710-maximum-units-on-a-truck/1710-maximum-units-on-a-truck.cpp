class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(begin(boxTypes),end(boxTypes),cmp);
        int cnt=0;
        for(auto i:boxTypes)
        {
            if(truckSize>=i[0])
            {
                cnt+=i[0]*i[1];
                truckSize-=i[0];
            }
            else
            {
                cnt+=truckSize*i[1];
                break;
            }
        }
        return cnt;
    }
};