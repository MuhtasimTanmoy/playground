struct Row {
    vector<string> words;
    int actual_len = 0;
};

class Solution {
    vector<Row> preprocess(vector<string>& words, int maxWidth) {
        vector<Row> holder;
        int occupied = 0;
        Row temp;
        
        for (auto i = 0; i < words.size(); i++) {
            auto word = words[i];
            occupied += word.size();
            if (occupied < maxWidth) occupied++;
            if (occupied <= maxWidth)
                temp.words.push_back(word), temp.actual_len += word.size();
            else 
                holder.push_back(temp),
                temp.words.resize(0),
                temp.actual_len = 0,
                occupied = 0, i--;
        }
        
        if (temp.actual_len) holder.push_back(temp);
        return holder;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto holder = preprocess(words, maxWidth);
        
        auto process = [](Row& row, int maxWidth) {
            int space = maxWidth - row.actual_len, count = row.words.size() - 1;
            string res = "";
            for (int i = row.words.size() - 1; i >= 0; i--) {
                auto now = count ? space / count: 0;
                space -= now, count--;
                string space(now, ' ');
                res = space + row.words[i] + res;
            }
            while (res.size() < maxWidth) res.push_back(' ');
            return res;
        };
        
        auto last_line_process = [](Row& row, int maxWidth) {
            string res = "";
            for (auto term: row.words) res += term + " ";
            res.pop_back();
            while (res.size() < maxWidth) res.push_back(' ');
            return res;
        };
        
        vector<string> ans;
        int len = holder.size();
        for (auto i = 0; i < len; i++) {
            string res = "";
            if (i == len - 1) res = last_line_process(holder[i], maxWidth);
            else res = process(holder[i], maxWidth);
            ans.push_back(res);
        }
        return ans;
    }
};