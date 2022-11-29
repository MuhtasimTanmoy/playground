class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(!st.count(val))                                           // if val is not present in the set then put it into the set and then return true
        {
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) 
    {
        if(st.count(val))                                            // if val is present in set then erase it from set and return true
        {
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() 
    {
        if(st.size()!=0)                                             // when stack is not empty only then we can return something
        {
            return *next(st.begin(),rand()%st.size());               // it will select randomly next element from set
        }
        return 0;
    }
};