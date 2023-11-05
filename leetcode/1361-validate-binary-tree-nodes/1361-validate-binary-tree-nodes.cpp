/*
Ordering problem

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        queue<int> q; q.push(0);
        int now = 0;
        while (q.size()) {
            auto top = q.front(); q.pop();
            if (abs(now - top) > 1) return false;
            now++;
            
            if (l[top] != -1) q.push(l[top]);
            if (r[top] != -1) q.push(r[top]);
        }
        return now == n;
    }
};
*/

// class Solution {
// public:
//     bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
//         unordered_map<int, pair<int, int>> g;
//         vector<int> indegree(n, 0);
//         for (int i = 0; i < n; i++) {
//             if(l[i] != -1) if (++indegree[l[i]] > 1) return false;
//             if(l[i] != -1) if(++indegree[r[i]] > 1) return false;
//             g[i] = {l[i], r[i]};
//         }
        
//         int parent = -1;
//         for (int i = 0; i < n; i++) if (indegree[i] == 0) parent = i;
            
//         queue<int> q; q.push(parent);
//         unordered_set<int> bag;
//         while (q.size()) {
//             auto top = q.front(); q.pop();
            
//             if (bag.count(top)) return false;
//             bag.insert(top);
            
//             if (g[top].first != -1) q.push(g[top].first);
//             if (g[top].second != -1) q.push(g[top].second);
//         }
//         return bag.size() == n;
//     }
    
    // bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    //     vector<int> parents(n);
    //     for (int i = 0; i < n; ++i) {
    //         if (leftChild[i] != -1 && ++parents[leftChild[i]] > 1)
    //             return false;
    //         if (rightChild[i] != -1 && ++parents[rightChild[i]] > 1)
    //             return false;
    //     }
    //     return count_if(begin(parents), end(parents), [](int i) { return i == 0; }) == 1;
    // }
    
    class Solution {
public:
   int countNodes(vector<int> &l,vector<int> &r,int root)   // DFS from root to validate that all nodes are visited.
    {
        if(root==-1)
            return 0;
        return 1+countNodes(l,r,l[root])+countNodes(l,r,r[root]);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int> inDegree(n,0);
        int root=-1;
        for(int i=0;i<leftChild.size();i++)
            if(leftChild[i]!=-1&&inDegree[leftChild[i]]++==1)  //If in-degree exceeds 1 return false.
                return false;
            else if(rightChild[i]!=-1&&inDegree[rightChild[i]]++==1)  //If in-degree exceeds 1 return false.
                return false;
        for(int i=0;i<leftChild.size();i++)    //Find root and also check for multiple roots.
            if(inDegree[i]==0)  //If in-degree = 0 and has children it's a root.
                if(root==-1)   //Store the root.
                    root=i;
                else    //We have multiple roots, return false
                    return false;
        if(root==-1)
            return false;
        return countNodes(leftChild,rightChild,root)==n;
    }
};