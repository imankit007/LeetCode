class Spreadsheet {
public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) { sheet[cell] = value; }

    void resetCell(string cell) { sheet[cell] = 0; }

    int getValue(string expr) {
        const int i = expr.find('+');
        return evaluate(expr.substr(1, i - 1)) + evaluate(expr.substr(i + 1));
    }

private:
    unordered_map<string, int> sheet;

    int evaluate(string str) {
        return isalpha(str[0]) ? sheet[str] : stoi(str);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */