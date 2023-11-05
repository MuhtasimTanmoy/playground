/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<NestedInteger> list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = size(nestedList) - 1; i >= 0; i--) 
            list.push_back(nestedList[i]);
    }
    
    int next() {
        int next = list.back().getInteger();
        list.pop_back();
        return next;
    }
    
    bool hasNext() {
        while (list.size() && !list.back().isInteger()) {
            auto elemList = list.back().getList();
            list.pop_back();
            
            for (int i = size(elemList) - 1; i >= 0; i--) 
                list.push_back(elemList[i]);
        }
        return list.size();
    }
};
