// struct Node{
//     Node* children[26];
//     int isEnd=0;   
// }
// class Trie{
//     private:
//         Node *root;
//     public:
//         Trie()
//         {
//             root=new Node();
//         }
//         void insert(string word)
//         {
//             Node* tmp=root;
//             for(auto i:word)
//             {
//                 if(tmp->children[i-'a']==NULL)
//                 {
//                     tmp->children[i-'a']=new Node();
//                 }
//                 tmp=tmp->children[i-'a'];
//             }
//             tmp->isEnd=1;
//         }
//         vector<string> search(string word)
//         {
//             Node* tmp=root;
//             vector<string>res;
            
//         }
//         string find(Node* root)
//         {
//             if(!root)return "";
//             string s;
//             for(int i=0;i<26;i++)
//             {
                
//             }
//         }
// }
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(auto i:products)
        {
            string s;
            for(auto j:i)
            {
                s+=j;
                mp[s].push_back(i);
            }
        }
        for(auto &x:mp)
        {
            sort(x.second.begin(),x.second.end());
        }
        string t;
        for(auto i:searchWord)
        {
            t+=i;
            vector<string>v;
            for(int x=0;x<min((int)mp[t].size(),3);x++)
            {
                v.push_back(mp[t][x]);
            }
            res.push_back(v);
        }
        return res;
    }
};