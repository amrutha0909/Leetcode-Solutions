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
    Node*head;
    Node*tail;
    unordered_map<int,Node*>mpp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void remove(Node*node){
        Node*prevNode=node->prev;
        Node*nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void insert(Node*node){
        Node*nextNode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nextNode;
        nextNode->prev=node;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1; 
        Node*existing=mpp[key];
        remove(existing);
        insert(existing);
        return existing->val;
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