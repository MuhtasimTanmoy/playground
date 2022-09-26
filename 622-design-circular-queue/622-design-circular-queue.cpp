class MyCircularQueue {
public:
    int sz = 0, front = 0, back = -1;
    vector<int> v;
    
    MyCircularQueue(int k) {
        v = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        ++back;
        ++sz;
        v[back % v.size()] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        ++front;
        --sz;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : v[front % v.size()];
    }
    
    int Rear() {
        return isEmpty() ? -1 : v[back % v.size()];
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == v.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */