// 45 / 45 test cases passed, but took too long.
/*
class TextEditor {
    string content = "";
    int cursor_index = 0;
public:
    TextEditor() {}
    
    void addText(string text) {
        content.insert(cursor_index, text);
        cursor_index += text.size();
    }
    
    int deleteText(int k) {
        auto from = max(0, cursor_index - k), 
             len = cursor_index > k ? k: cursor_index;
        cursor_index -= len;
        content.erase(from, len);
        return len;
    }
    
    string cursorLeft(int k) {
        cursor_index -= k;
        if (cursor_index < 0) cursor_index = 0;
        
        auto from = max(0, cursor_index - 10), 
             len = cursor_index > 10 ? 10: cursor_index;
        return content.substr(from, len);
    }
    
    string cursorRight(int k) {
        cursor_index += k;
        if (cursor_index > content.size()) cursor_index = content.size();
        
        auto from = max(0, cursor_index - 10), 
             len = cursor_index > 10 ? 10: cursor_index;
        return content.substr(from, len);
    }
};
*/

class TextEditor {
    string before, after;
public:
    TextEditor() {}
    
    void addText(string text) {
        before.insert(end(before), begin(text), end(text));
    }
    
    int deleteText(int k) {
        k = min(k, (int) before.size());
        before.resize(before.size() - k);
        return k;
    }
    
    string cursorLeft(int k) {
        while(k-- && !before.empty()) 
            after.push_back(before.back()),
            before.pop_back();
        return before.substr(before.size() - min((int)before.size(), 10));
    }
    
    string cursorRight(int k) {
        while(k-- && !after.empty()) 
            before.push_back(after.back()),
            after.pop_back();
        return before.substr(before.size() - min((int)before.size(), 10));
    }
};