class LFUCache {
public:
    class Node{
        public:
        Node*next;
        Node*prev;
        int key,val,freq;
        Node(int k,int v){
            key=k;
            val=v;
            freq=1;
            next=prev=nullptr;
        }
    };
    
    class List{
        public:
        Node*head;
        Node*tail;
        int size;
        List(){
            size=0;
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
            size++;
        }
        void remove(Node*node){
            Node*prevNode=node->prev;
            Node*nextNode=node->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;
            size--;
        }
        Node*removeLRU(){
            if (size == 0) return nullptr;
            Node* lru = tail->prev;
            remove(lru);
            return lru;
        }

    };
    int capacity;
    unordered_map<int,List*>freqList;
    unordered_map<int,Node*>mpp;
    int minFreq;
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    void updateFreq(Node*node){
        int freq=node->freq;
        freqList[freq]->remove(node);
        if(freq==minFreq&&freqList[freq]->size==0)minFreq++;
        node->freq++;
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new List();
        }

        freqList[node->freq]->insert(node);
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        Node*node=mpp[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity==0)return;
        if(mpp.find(key)!=mpp.end()){
            Node*existing=mpp[key];
            existing->val=value;
            updateFreq(existing);
            return;
        }
        if(mpp.size()==capacity){
            List*list=freqList[minFreq];
            Node*lru=list->removeLRU();
            mpp.erase(lru->key);
        }
        Node*node=new Node(key,value);
        minFreq = 1;
        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }
        freqList[1]->insert(node);
        mpp[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */