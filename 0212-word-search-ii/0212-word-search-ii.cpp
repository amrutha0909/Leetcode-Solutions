class Solution {
public:
    vector<string>result;
    int m,n;
    struct Trie{
        bool isLeaf;
        Trie*children[26];
        string word;
    };
    Trie*getNode(){
        Trie*node=new Trie();
        node->isLeaf=false;
        node->word="";
        for(int i=0;i<26;i++){
            node->children[i]=nullptr;
        }
        return node;
    }
    void insert(Trie*root,string word){
        Trie*node=root;
        for(char c:word){
            if(node->children[c-'a']==nullptr){
                Trie*newNode=new Trie();
                node->children[c-'a']=newNode;
            }
            node=node->children[c-'a'];
        }
        node->isLeaf=true;
        node->word=word;
    }
    vector<int>dX={-1,0,1,0};
    vector<int>dY={0,1,0,-1};
    void dfs(int i,int j,vector<vector<char>>&board,Trie*root){
        if(i<0||i>=n||j<0||j>=m)return;
        if(board[i][j]=='$'||root->children[board[i][j]-'a']==nullptr)return;
        root=root->children[board[i][j]-'a'];
        if(root->isLeaf){
            result.push_back(root->word);
            root->isLeaf=false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(int k=0;k<4;k++){
            int nx=i+dX[k];
            int ny=j+dY[k];
            dfs(nx,ny,board,root);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) { 
        Trie*root=getNode();
        for(string word:words){
            insert(root,word);
        }  
        n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=nullptr){
                    dfs(i,j,board,root);
                }
            }
        }
        return result;
    }
};