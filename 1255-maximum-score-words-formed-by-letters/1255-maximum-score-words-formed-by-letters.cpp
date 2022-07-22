class Solution {
public:
    
        map<int,map<vector<int>,int>>dp;
    int f(int idx,vector<string>&words,vector<int>freq,vector<int>&score)
    {
        if(idx==words.size())return 0;
        int mn=0;
        int flag=1; 
        if(dp.find(idx)!=dp.end() && dp[idx].find(freq)!=dp[idx].end())return dp[idx][freq];
        for(auto i:words[idx])
        {
            if(freq[i-'a'])
            {
                freq[i-'a']--;
                mn+=score[i-'a'];
            }
            else
            {
                flag=0;
                freq[i-'a']--;
            }
        }
        if(flag)
        {
            mn+=f(idx+1,words,freq,score);
        }
        if(!flag)
            mn=0;
            for(auto i:words[idx])
            {
                freq[i-'a']++;
            }
            mn=max(mn,f(idx+1,words,freq,score));
        return dp[idx][freq]=mn;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        dp.clear();
        for(auto i:letters)freq[i-'a']++;
        return f(0,words,freq,score);
    }
};