// struct Node
// {
//     Node(int val, shared_ptr<Node> right, shared_ptr<Node> down)
//         : val(val), right(right), down(down) {}
    
//     int val;
//     shared_ptr<Node> right;
//     shared_ptr<Node> down;
// };

// class Skiplist 
// {
// public:
//     Skiplist() : node(new Node(-1, shared_ptr<Node>(), shared_ptr<Node>()))
//     {}
    
//     bool search(int target) 
//     {
//         for (auto ptr = node; ptr; ptr = ptr->down)
//         {
//             while (ptr->right && ptr->right->val < target)
//                 ptr = ptr->right;
            
//             if (ptr->right && ptr->right->val == target)
//                 return true;
//         }
        
//         return false;
//     }
    
//     void add(int num) 
//     {
//         stack<shared_ptr<Node>> stack;
//         shared_ptr<Node> down;
//         auto insert = true;
        
//         for (auto ptr = node; ptr; ptr = ptr->down)
//         {
//             while (ptr->right && ptr->right->val < num)
//                 ptr = ptr->right;
            
//             stack.push(ptr);
//         }
        
//         while (insert && !stack.empty())
//         {
//             auto cur = stack.top();
//             stack.pop();
            
//             cur->right = make_shared<Node>(num, cur->right, down);
//             down = cur->right;
            
//             insert = rand() & 1;
//         }
       
//         if (insert)
//             node = make_shared<Node>(-1, shared_ptr<Node>(), node);
//     }
    
//     bool erase(int num) 
//     {
//         auto seen = false;
        
//         for (auto ptr = node; ptr; ptr = ptr->down)
//         {
//             while (ptr->right && ptr->right->val < num)
//                 ptr = ptr->right;
            
//             if (ptr->right && ptr->right->val == num)
//                 seen = true, ptr->right = ptr->right->right;
//         }
        
//         return seen;
//     }
    
// private:
//     shared_ptr<Node> node;
// };


class Skiplist {
private:
    const int kMaxHeight = 8;
    
    struct Node {
        int val;
        int height;
        Node** next;
        
        Node(int v, int h) {
            val = v;
            height = h;
            next = new Node*[h];
            while (--h >= 0) next[h] = nullptr;
        }
        
        ~Node() {
           delete [] next;
        }
    };
    
    int getRandomHeight() {
        int h = 1;
        while (h < kMaxHeight && rand() % 4 == 1) ++h;
        
        return h;
    }
    
    
    Node* findGreaterOrEqual(int target, Node** prev) {
        Node* it = head;
        int level = kMaxHeight-1;
        while (true) {
            Node* next = it->next[level];
            if (next && next->val < target) {
                it = next;
            } else {
                if (prev)  prev[level] = it;
                
                if (level == 0) {
                    return next;
                } else {
                    --level;
                }
            }
        }
    }
    
    
    Node* head;
public:
    Skiplist() {
        head = new Node(0, kMaxHeight);
    }
    
    bool search(int target) {
        Node* node = findGreaterOrEqual(target, nullptr);
        return node != nullptr && node->val == target;
    }
    
    void add(int num) {
        Node* prev[kMaxHeight];
        findGreaterOrEqual(num, prev);
        
        Node* node = new Node(num, getRandomHeight());  
        for (int i = 0; i < node->height; ++i) {
            node->next[i] = prev[i]->next[i];
            prev[i]->next[i] = node;
        }
    }
    
    bool erase(int num) {
        Node* prev[kMaxHeight];
        Node* to_del = findGreaterOrEqual(num, prev);
        if (to_del == nullptr || to_del->val != num) {
            return false;
        }
        
        for (int i = 0; i < to_del->height; ++i) {
            prev[i]->next[i] = to_del->next[i];
        }
        
        delete to_del;
        return true;
    }
};
/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */