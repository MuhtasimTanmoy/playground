class Node {
    public:
    set<int> routes;

    Node(vector<int>& li) {
        routes = set<int>(li.begin(), li.end());
    }

    bool has(int i) {
        return routes.count(i);
    }

    static Node* build(vector<int>& li) {
        return new Node(li);
    }
};

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& R, int s, int t) {
        if (s == t) return 0;
        
        vector<Node*> li, q;
        unordered_set<int> visited;
        for (auto i = 0; i < R.size(); i++) {
            auto r = R[i];
            li.push_back(Node::build(r));
            if (li.back()->has(s)) {
                q.push_back(li.back()), visited.insert(i);
                if (li.back()->has(t)) return 1;
            }
        }

        auto res = q.size() ? 1: 0;
        while (q.size()) {
            res++;
            vector<Node*> updated;
            auto n = q.size();
            while (n--) {
                auto now = q.back(); q.pop_back();
                for (auto i = 0; i < li.size(); i++) {
                    if (visited.count(i)) continue;
                    bool found  = false;
                    for (auto elem: now->routes) {
                        if (found == true) break;
                        if (li[i]->has(elem)) {
                            updated.push_back(li[i]);
                            visited.insert(i);
                            if (li[i]->has(t)) return res;
                            found = true;
                            break;
                        }
                    }
                }
            }
            q = updated;
        }
        return -1;
    }
};