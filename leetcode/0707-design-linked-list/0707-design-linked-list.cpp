class Node {
    public:
    int val;
    Node* next;
    
    Node(int val): val(val), next(NULL) {}
    Node(int val, Node* next): val(val), next(next) {}
};

class MyLinkedList {
    Node* head = NULL;
public:
    MyLinkedList() {}
    
    void print(Node* head) {
        auto itr = head;
        while (itr) {
            cout<<itr->val<<endl;
            itr = itr->next;
        }
    }
    
    int get(int index) {
        // print(head);
        auto itr = head;
        while(index--) {
            if (!itr) return -1;
            itr = itr->next;
        }
        return itr ? itr->val: -1;
    }
    
    void addAtHead(int val) {
        auto to_add = new Node(val, NULL);
        to_add->next = head;
        head = to_add;
    }
    
    void addAtTail(int val) {
        auto to_add = new Node(val);
        if (!head) {
            head = to_add;
            return;
        }
        auto itr = head;
        while (itr->next) itr = itr->next;
        itr->next = to_add;
    }
    
    void addAtIndex(int index, int val) {
        
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        auto itr = head;
        while (--index) {
            if (!itr) return;
            itr = itr->next;
        }
        if (!itr) return;
        auto to_add = new Node(val, itr->next);
        itr->next = to_add;
    }
    
    void deleteAtIndex(int index) {
        
        if (index == 0) {
            head = head->next;
            return;
        }
        
        auto itr = head;
        while (--index) {
            if (!itr) return;
            itr = itr->next;
        }
        if (!itr) return;
        itr->next =  itr->next ? itr->next->next: NULL;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */