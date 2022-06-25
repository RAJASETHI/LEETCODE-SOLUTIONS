struct Node{
    unordered_map<char,Node*>child;
    int isEnd=0;
};
class Trie{
    private:
    Node* root=NULL;
    public:
    Trie(vector<string>&folder)
    {
        root=new Node();
        for(auto i:folder)
        {
            insert(i);
        }
    }
    void insert(string s)
    {
        Node* tmp=root;
        for(auto i:s)
        {
            if(tmp->child[i]==NULL)
            {
                tmp->child[i]=new Node();
            }
            tmp=tmp->child[i];
        }
        tmp->isEnd=1;
    }
    string search(string s)
    {
        Node* tmp=root;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='/' && tmp->child[s[i]]->isEnd==1 && i!=s.size()-1)return "";
            tmp=tmp->child[s[i]];
        }
        return s;
    }
    
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for(auto &i:folder)i+='/';
        Trie* t=new Trie(folder);
        vector<string>res;
        for(auto i:folder)
        {
            if(t->search(i)!="")
            {
                i.pop_back();
                res.push_back(i);
            }
        }
        return res;
    }
};