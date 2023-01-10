struct Node
{
    Node(int val, shared_ptr<Node> right, shared_ptr<Node> down)
        : val(val), right(right), down(down) {}
    
    int val;
    shared_ptr<Node> right;
    shared_ptr<Node> down;
};

class Skiplist 
{
public:
    Skiplist() : node(new Node(-1, shared_ptr<Node>(), shared_ptr<Node>()))
    {}
    
    bool search(int target) 
    {
        for (auto ptr = node; ptr; ptr = ptr->down)
        {
            while (ptr->right && ptr->right->val < target)
                ptr = ptr->right;
            
            if (ptr->right && ptr->right->val == target)
                return true;
        }
        
        return false;
    }
    
    void add(int num) 
    {
        stack<shared_ptr<Node>> stack;
        shared_ptr<Node> down;
        auto insert = true;
        
        for (auto ptr = node; ptr; ptr = ptr->down)
        {
            while (ptr->right && ptr->right->val < num)
                ptr = ptr->right;
            
            stack.push(ptr);
        }
        
        while (insert && !stack.empty())
        {
            auto cur = stack.top();
            stack.pop();
            
            cur->right = make_shared<Node>(num, cur->right, down);
            down = cur->right;
            
            insert = rand() & 1;
        }
       
        if (insert)
            node = make_shared<Node>(-1, shared_ptr<Node>(), node);
    }
    
    bool erase(int num) 
    {
        auto seen = false;
        
        for (auto ptr = node; ptr; ptr = ptr->down)
        {
            while (ptr->right && ptr->right->val < num)
                ptr = ptr->right;
            
            if (ptr->right && ptr->right->val == num)
                seen = true, ptr->right = ptr->right->right;
        }
        
        return seen;
    }
    
private:
    shared_ptr<Node> node;
};
/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */