class Solution {
public:
    
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        for(auto i:t)freq[i]++;
        int n=s.size();
        int low=0,count=0,min_len=INT_MAX,min_start=-1;
        for(int high=0;high<n;high++)
        {
            if(freq[s[high]]>0)count++;
            freq[s[high]]--;
            if(count==t.size())
            {
                while(low<high && freq[s[low]]<0)freq[s[low]]++,low++;
                if(min_len>high-low)min_len=high-(min_start=low)+1;
                freq[s[low]]++,low++;
                count--;
            }
        }
        return min_len==INT_MAX?"":s.substr(min_start,min_len);
    }
};