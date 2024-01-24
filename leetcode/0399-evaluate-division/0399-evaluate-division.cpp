class UF {
public:
    string find(string s) {
        auto is_parent_available = parents.count(s);
        if (is_parent_available) {
            auto p = parents[s], gp = find(p);
            vals[s] *= vals[p];
            parents[s] = gp;
        }
        return parents[s];
    }
    
    void join(string p, string c, double val) {
        add(p), add(c);
        auto px = find(p), py = find(c);
        parents[px] = py;
        vals[px] = val * vals[p] / vals[c];
    }
    
    bool has(string s, string c) {
        if (!parents.count(s)) return false;
        if (!parents.count(c)) return false;
        if (find(s) == find(c)) return false;
        return true;
    }
    
    double get_ans(string p, string c) {
        return vals[p] / vals[c];
    }
private:
    unordered_map<string, double> vals;
    unordered_map<string, string> parents;
    
    void add(string s) {
        if (parents.count(s)) return;
        parents[s] = s;
        vals[s] = 1.0;
    }
};

class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& eqs,
//                                 vector<double>& vals, 
//                                 vector<vector<string>>& qs) {
//         UF uf;
//         for (int i = 0; i < vals.size(); i++) {
//             auto p = eqs[i][0], c = eqs[i][1];
//             auto weight = vals[i];
//             uf.join(p, c, weight);
//         }
//         vector<double> res;
//         for (auto q: qs) {
//             auto calc = uf.has(q[0], q[1]) ? uf.get_ans(q[0], q[1]): -1;
//             res.push_back(calc);
//         }
//         return res;
//     }
public:  
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        vector<double> res(queries.size(), -1);
        
        int i = 0;
        for (auto &eq : equations)
            unite(eq[0], eq[1], values[i++]);
        
        i = 0;
        for (auto &q : queries) {
            string x = q[0], y = q[1];
            if (isNode(x) && isNode(y) && find(x) == find(y))
                res[i] = vals[x] / vals[y];
            ++i;
        }
            
        return res;
    }

    bool isNode(string x) {
        return roots.count(x) > 0;
    }
    
    void add(string x) {
        if (!isNode(x)) roots[x] = x, vals[x] = 1.0;
    }
    
    string find(string x) {
        if (x != roots[x]) {
            string rootX = roots[x];
            roots[x] = find(rootX);
            vals[x] = vals[x] * vals[rootX];
        }
        return isNode(x) ? roots[x] : x;
    }

    void unite(string x, string y, double v) {
        add(x), add(y);
        string rootX = find(x), rootY = find(y);
        roots[rootX] = rootY;
        vals[rootX] = v * vals[y] / vals[x];
    }    

private:
    unordered_map<string, string> roots;
    unordered_map<string, double> vals;
};