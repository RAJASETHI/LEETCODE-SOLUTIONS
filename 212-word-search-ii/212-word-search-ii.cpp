struct Node{
    Node* children[26];
    int isEnd=0;
};
class Trie{
    public:
        Node* root=NULL;
        Trie(vector<string>&word)
        {
            root=new Node();
            for(auto x:word)
            {
                addWord(x);
            }
                        
        }
        Node* getRoot(){return root;}
        void addWord(string s)
        {
            Node* tmp=root;
            for(auto x:s)
            {
                int val=x-'a';
                if(tmp->children[val]==NULL)tmp->children[val]=new Node();
                tmp=tmp->children[val];
            }
            tmp->isEnd++;
        }
        
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // unordered_set<string>result_set;
        vector<string>res;
        Trie *trie=new Trie(words);
        Node* root=trie->getRoot();
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                f("",board,i,j,root,res);
            }
        }
        // vector<string>res(result_set.begin(),result_set.end());
        return res;
    }
private:
    void f(string ans,vector<vector<char>>& board,int x,int y,Node* root,vector<string>&res)
    {
            if(root->isEnd>0){root->isEnd--;res.push_back(ans);}
            if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]==' ')return;
            if(root->children[board[x][y]-'a'])
            {
                char c=board[x][y];
                ans+=c;   
                board[x][y]=' ';
                f(ans,board,x+1,y,root->children[c-'a'],res);
                f(ans,board,x-1,y,root->children[c-'a'],res);
                f(ans,board,x,y+1,root->children[c-'a'],res);
                f(ans,board,x,y-1,root->children[c-'a'],res);
                board[x][y]=c;
            }
    }
};