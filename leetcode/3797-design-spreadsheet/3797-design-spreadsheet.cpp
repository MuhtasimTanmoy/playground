class Spreadsheet {
private:
    vector<vector<int>> sp;
public:
    Spreadsheet(int rows) {
        sp = vector<vector<int>>(rows + 1, vector<int>(26));
    }
    
    void setCell(string cell, int value) {
        auto col = cell[0] - 'A',
             row = stoi(cell.substr(1));
        sp[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int get_val(const string& cell) {
        if (isdigit(cell[0])) return stoi(cell);
        auto col = cell[0] - 'A', row = stoi(cell.substr(1)); 
        return sp[row][col];
    }

    int getValue(string formula) {
        formula = formula.substr(1);
        size_t plus = formula.find('+');
        return get_val(formula.substr(0, plus)) + get_val(formula.substr(plus + 1));
    }
};