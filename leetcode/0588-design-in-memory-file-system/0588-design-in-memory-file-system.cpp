class FileSystem {
private:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode *> children;
        TrieNode() : isFile(false) {}
    };

    TrieNode *root;
    
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> getStrs (const string &s, char delim = '/') {
        vector<string> result;
        stringstream ss (s);
        string item;
        while (getline (ss, item, delim)) 
            if (item.size()) 
                result.push_back (item);
        return result;
    }
    
    vector<string> ls(string path) {
        vector<string> strs = getStrs(path);
        TrieNode *curr = root;
        for (string &str : strs) curr = curr->children[str];
        if (curr->isFile) return {strs.back()};
        
        vector<string> ans;
        for (auto &p: curr->children) ans.push_back(p.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> strs = getStrs(path);
        TrieNode *curr = root;
        for (string &str : strs) {
            if (!curr->children.count(str))
                curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> strs = getStrs(filePath);
        TrieNode *curr = root;
        for (string &str : strs) {
            if (!curr->children.count(str))
                curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> strs = getStrs(filePath);
        TrieNode *curr = root;
        for (string &str : strs) curr = curr->children[str];
        return curr->content;
    }
};