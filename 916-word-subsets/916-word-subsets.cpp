class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        vector<int>freq(26,0);
        for(auto w:words2)
        {
            vector<int>f(26,0);
            for(auto i:w)f[i-'a']++;
            for(int i=0;i<26;i++)freq[i]=max(freq[i],f[i]);
        }
        
        for(auto word:words1)
        {
            vector<int>f(26,0);
            for(auto i:word)
            {
                f[i-'a']++;
            }
            int flag=1;
            for(int i=0;i<26;i++)
            {
                if(f[i]<freq[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)res.push_back(word);
        }
        return res;
    }
};