class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>freq;
        for(auto i:s)freq[i]++;
        int cnt=0;
        for(auto i:t)
        {
            if(freq[i])
            {
                freq[i]--;
            }
            else cnt++;
        }
        return cnt;
    }
};