#include <bits/stdc++.h>
using namespace std;

// Unix File Search API

// Design Unix File Search API to search file with different arguments as "extension", "name", "size" ...
// The design should be maintainable to add new contraints.

enum FileType {
    DIR = 0, XML, TXT, COUNT
};

class File {

private:
    string name_;
    size_t size_;
    FileType type_;
    char* content_;

public:
    File(string name, int size, FileType type) : name_(name), size_(size), type_(type){ }
    File(string name, int size, FileType type, char* content) : name_(name), size_(size), type_(type), content_(content){ }

    string getName() {
        return name_;
    }

    size_t getSize() {
        return size_;
    }

    FileType getType() {
        return type_;
    }

    char* getFile() {
        return content_;
    }

    void printInfo() {
         cout << "File name\t" << name_ << endl;
         cout << "File size\t" << size_ << endl;
         cout << "File type\t" << type_ << endl;
    }
};

class Directory: public File {

private:
    unordered_set<File*> children_;

public:
    Directory(string name) : File(name, 0, FileType::DIR) { }

    Directory(string name, vector<File*> sub_files): File(name, 0, FileType::DIR) {
        children_= unordered_set<File*> (sub_files.begin(), sub_files.end());
    }

    void addFile(File* file) {
        children_.insert(file);
    }

    void deleteFile(File* file) {
        if (children_.find(file) != children_.end())
            children_.erase(file);
    }

    unordered_set<File*> directoryListFile() {
        return children_;
    }

    void printInfo() {
        cout << "DIR name\t" << File::getName() << endl;
        cout << "DIR children no\t" << children_.size() << endl;
        for(auto child : children_)
            child->printInfo();
        cout << "DIR print done!\t" <<  endl;
    }
};


class Rule {
public:
    virtual bool checkRulePassed(File* file) const = 0;
    virtual void printInfo() const = 0;
};

class Filter {
    vector<Rule*> rules_;
public:
    Filter(vector<Rule*>& rules) : rules_(rules) { }

    vector<File*> find_filter(Directory& dir) {
        unordered_set<File*> files = dir.directoryListFile();
        vector<File*> res;
        for (auto file : files) {
            bool valid = true;
            for (auto rule : rules_) {
                if (!rule->checkRulePassed(file)) {
                    valid = false;
                    break;
                }
            }
            if (valid) res.push_back(file);
        }
        return res;
    }

    void printInfo() {
        cout << "Filter rules:\n";
        for(auto rule: rules_) {
            rule->printInfo();
        }
    }
};

class MinSizeRule: public Rule {
private:
    size_t min_size_ = 0;
public:
    MinSizeRule(size_t size) : min_size_(size) { }
    bool checkRulePassed(File* file) const override {
        return file->getSize() >= min_size_;
    }
    void printInfo() const override{
        cout << "Check if size >= " << min_size_ << endl;
    }
};


class TypeSameRule : public Rule {
private:
    FileType target_type_ = FileType::COUNT;
public:
    TypeSameRule(FileType type) : target_type_(type){ }

    bool checkRulePassed(File* file) const override{
        return file->getType() == target_type_;
    }

    void printInfo() const override{
        cout << "Check if type == " << target_type_ << endl;
    }
};


int main() {
    Directory cur_dir{"test_dir"};
    for(size_t i = 0; i < 10; i++) {
        File* cur_file = new File("test_file" + to_string(i), i * 100, FileType(i % FileType::COUNT));
        cur_dir.addFile(cur_file);
    }

    cur_dir.printInfo();
    MinSizeRule size_rule(400);
    TypeSameRule type_rule(FileType::XML);
    Rule* r1 = &size_rule;
    Rule* r2 = &type_rule;
    vector<Rule*> filter_rules{r1, r2};
    Filter cur_filter(filter_rules);
    cur_filter.printInfo();

    vector<File*> flitering_res = cur_filter.find_filter(cur_dir);
    cout << "Filtering results:\n";
    for(auto f : flitering_res) f->printInfo();
    return 0;
}