class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int diff=accumulate(begin(a),end(a),0)-accumulate(begin(b),end(b),0);
        diff/=2;
        set<int>st(a.begin(),a.end());
        for(auto i:b)
        {
            if(st.count(i+diff))return {i+diff,i};
        }
        return {};
    }
};