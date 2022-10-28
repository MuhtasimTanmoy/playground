#include<bits/stdc++.h>

using namespace std;

class File {
  public:
    string name;
    int type;
    int size;
    vector < File * > children;
    bool isDirectory;

  File(string name, int type, int size, bool isDirectory) {
    this -> name = name;
    this -> type = type;
    this -> size = size;
    this -> isDirectory = isDirectory;
  }

  void addChildren(File * f);
};

void File::addChildren(File * f) {
  this -> children.push_back(f);
}

//
class Filter {
  public:
    virtual bool apply(File * f) = 0;
};

class minSize: public Filter {
  int size;
  public:
    minSize(int size) {
      this -> size = size;
    }
  bool apply(File * f) {
    return f -> size >= size;
  }
};

class Type: public Filter {
  int type;
  public:
    Type(int type) {
      this -> type = type;
    }
  bool apply(File * f) {
    return f -> type == type;
  }
};

class FindFiles {
  public:
    void searchFilesDFS(File f, vector < Filter > filters, vector < File * > & output) {
      if (f -> children.empty()) {
        return;
      }

      for (auto file: f -> children) {
        bool flag = true;
        if (file -> isDirectory) {
          searchFilesDFS(file, filters, output);
        } else {
          for (auto it: filters) {
            if (it -> apply(file) == false) {
              flag = false;
              break;
            }
          }
        }
        if (flag and file -> isDirectory == false) {
          output.push_back(file);
        }
      }
    }

  void searchFilesBFS(File * f, vector < Filter * > filters, vector < File * > & output) {
    if (f -> children.empty()) {
      return;
    }

    queue < File * > file_queue;
    file_queue.push(f);

    while (!file_queue.empty()) {
      auto x = file_queue.front();
      file_queue.pop();

      if (x -> isDirectory) {
        for (auto file: x -> children) {
          bool flag = true;
          if (file -> isDirectory) {
            flag = false;
            file_queue.push(file);
          } else {
            for (auto filter: filters) {
              if (filter -> apply(file) == false) {
                flag = false;
                break;
              }
            }
          }
          if (flag)
            output.push_back(file);
        }
      } else {
        bool flag = true;
        for (auto filter: filters) {
          if (filter -> apply(x) == false) {
            flag = false;
            break;
          }
        }
        if (flag)
          output.push_back(x);
      }
    }
  }
};

int main() {
  File f1("f1", 0, 20, 1);
  File f2("f2", 0, 20, 1);
  File f3("f3.txt", 0, 10, 1);
  File f4("f4.txt", 0, 10, 0);
  File f5("f5.txt", 0, 5, 0);
  File f6("f6.txt", 0, 100, 0);

  f1.addChildren( & f2);
  f1.addChildren( & f3);

  f2.addChildren( & f4);
  f2.addChildren( & f5);

  f3.addChildren( & f6);

  minSize m(10);
  Type t(0);
  vector < Filter * > filters;
  filters.push_back( & m);
  filters.push_back( & t);

  vector < File * > output;

  FindFiles f;
  f.searchFilesBFS( & f1, filters, output);
  for (auto c: output)
    cout << c -> name << " ";
}