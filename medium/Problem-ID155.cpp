class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class MinStack {
public:
Node*pot;
    MinStack() {
        pot=nullptr;
    }
    
    void push(int val) {
        Node*node=new Node(val);
        node->next=pot;
        pot=node;
    }
    
    void pop() {
        if(pot==nullptr){
            return;
        }
        Node*temp=pot;
        pot=pot->next;
        delete temp;
    }
    
    int top() {
        if(pot!=nullptr){
            return pot->data;
        }
        return -1;
    }
    
    int getMin() {
        int min=INT_MAX;
        Node*temp=pot;
        while(temp!=NULL){
            if(temp->data<min){
                min=temp->data;
            }
            temp=temp->next;
        }
        return min;
    }
};
