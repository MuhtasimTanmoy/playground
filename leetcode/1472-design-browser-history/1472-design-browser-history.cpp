class BrowserHistory {
    vector<string> history;
    int curr = 0;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr++;
    }
    
    void visit(string url) {
        if (curr == history.size()) history.push_back(url);
        else {
            history[curr] = url;
            history.resize(curr + 1);
        }
        curr++;
    }
    
    string back(int steps) {
        auto min = max(curr - steps - 1, 0);
        curr = min + 1;
        return history[min];
    }
    
    string forward(int steps) {
        auto max = min(curr + steps, (int) history.size());
        curr = max;
        return history[curr - 1];
    }
};