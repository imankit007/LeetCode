class Solution {
public:
    string generateString(string str1, string str2) {
        const int n = str1.size();
        const int m = str2.size();

        const int N = n + m - 1;

        string word(N, '$');

        vector<bool> canChange(N, false);

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != '$' && word[i + j] != str2[j]) {
                        cout<<"here0";
                        return "";
                    }
                    word[i + j] = str2[j];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                if (isSame(word, str2, i, m)) {
                    bool changed = false;
                    for (int k = i + m - 1; k >= i; k--) {
                        if (word[k] == 'a' && canChange[k]) {
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if (!changed) {
                        return "";
                    }
                }
            }
        }

        return word;
    }

private:
    bool isSame(string& word, string& str, int i, int m) {

        int j = 0;
        for (int k = i; k < i + m; k++) {
            if (word[k] != str[j]) {
                return false;
            }
            j++;
        }
        return true;
    }
};