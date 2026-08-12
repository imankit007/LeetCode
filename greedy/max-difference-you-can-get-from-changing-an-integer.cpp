class Solution {
public:
    int maxDiff(int num) {

        string largest = to_string(num);
        string smallest = largest;

        for (int i = 0; i < largest.size(); ++i) {
            if (largest[i] != '9') {
                changeChars(largest, largest[i], '9');
                break;
            }
        }
        for (int i = 0; i < smallest.size(); ++i) {
            if (i == 0) {
                if (smallest[i] == '1') {
                    continue;
                } else {
                    changeChars(smallest, smallest[i], '1');
                    break;
                }
            }
            if (smallest[i] == '0' || smallest[i] == '1') {
                continue;
            }
            changeChars(smallest, smallest[i], '0');
            break;
            
        }

        cout << largest << endl;
        cout << smallest;

        return stoi(largest) - stoi(smallest);
    }

private:
    void changeChars(string& s, char from, char to) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == from) {
                s[i] = to;
            }
        }
    }
};