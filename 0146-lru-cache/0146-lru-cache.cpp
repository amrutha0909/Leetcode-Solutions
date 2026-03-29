class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node*next;
        Node*prev;
        Node(int k, int v){
            key=k;
            value=v;
            prev=next=nullptr;
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
        Node*node=mpp[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node*existing=mpp[key];
            remove(existing);
            mpp.erase(key);
        }
        if(mpp.size()==capacity){
            Node*lru=tail->prev;
            remove(lru);
            mpp.erase(lru->key);
        }
        Node*newNode=new Node(key,value);
        insert(newNode);
        mpp[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */