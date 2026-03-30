class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node*next;
        Node*prev;
        Node(int k,int v){
            key=k;
            val=v;
            next=nullptr;
            prev=nullptr;
        }
    };
    unordered_map<int,Node*>mpp;
    int capacity;
    Node*head;
    Node*tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insert(Node*node){
        Node*nextNode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nextNode;
        nextNode->prev=node;
    }
    void remove(Node*node){
        Node*prevNode=node->prev;
        Node*nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        Node*node=mpp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        Node*node=new Node(key,value);
        if(mpp.find(key)!=mpp.end()){
            Node*existing=mpp[key];
            remove(existing);
            mpp.erase(key);
        }
        if(capacity==mpp.size()){
            Node*lru=tail->prev;
            remove(lru);
            mpp.erase(lru->key);
        }
        insert(node);
        mpp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */