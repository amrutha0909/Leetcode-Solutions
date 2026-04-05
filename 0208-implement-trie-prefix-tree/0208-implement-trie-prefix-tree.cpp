class Trie {
public:
    bool isLeaf;
    Trie*children[26];
    Trie() {
        isLeaf=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
    
    void insert(string word) {
        Trie*node=this;
        for(char c:word){
            if(node->children[c-'a']==nullptr){
                Trie*newNode=new Trie();
                node->children[c-'a']=newNode;
            }
            node=node->children[c-'a'];
        }
        node->isLeaf=true;
    }
    
    bool search(string word) {
        Trie*node=this;
        if(node==nullptr)return false;
        for(char c:word){
            if(node->children[c-'a']==nullptr)return false;
            node=node->children[c-'a'];
        }
        return (node->isLeaf);
    }
    
    bool startsWith(string prefix) {
        Trie*node=this;
        if(node==nullptr)return false;
        for(char c:prefix){
            if(node->children[c-'a']==nullptr)return false;
            node=node->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */