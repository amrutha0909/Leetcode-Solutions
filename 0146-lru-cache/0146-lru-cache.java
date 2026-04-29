class LRUCache {
    static class Node{
        int key;
        int val;
        Node next;
        Node prev;
        Node(int k,int v){
            key=k;
            val=v;
        }
    }
    Node head;
    Node tail;
    int capacity;
    Map<Integer,Node>mpp;
    public LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head.next=tail;
        tail.prev=head;
        this.capacity=capacity;
        mpp=new HashMap<>();
    }
    void addNode(Node node){
        Node nextNode=head.next;
        head.next=node;
        node.prev=head;
        node.next=nextNode;
        nextNode.prev=node;
    }
    void removeNode(Node node){
        Node prevNode=node.prev;
        Node nextNode=node.next;
        prevNode.next=nextNode;
        nextNode.prev=prevNode;
    }
    public int get(int key) {
        if(!mpp.containsKey(key))return -1;
        Node existing=mpp.get(key);
        removeNode(existing);
        addNode(existing);
        return existing.val;

    }
    public void put(int key, int value) {
        if(mpp.containsKey(key)){
            Node existing=mpp.get(key);
            removeNode(existing);
            mpp.remove(key);
        }   
        if(mpp.size()>=capacity){
            Node lru=tail.prev;
            removeNode(lru);
            mpp.remove(lru.key);
        }
        Node node=new Node(key,value);
        addNode(node);
        mpp.put(key,node);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */