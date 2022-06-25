class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>res;
        sort(begin(folder),end(folder));
        for(auto i:folder)
        {
            if(res.size())
            {
                string prev=res[res.size()-1]+'/';
                if(i.size()>=prev.size() && i.substr(0,prev.size())==prev)
                {
                    continue;
                }
                else
                {
                    res.push_back(i);
                }
            }
            else
            {
                res.push_back(i);
            }
            
        }
        return res;
    }
};