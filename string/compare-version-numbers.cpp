class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        int i = 0, j = 0;

        for (; i < v1.size() && j < v2.size(); ++i, j++) {
            int val = compare(v1[i], v2[j]);
            if (val != 0) {
                return val;
            }
        }

        while (i < v1.size()) {
            int val = compare(v1[i], "0");
            if (val != 0) {
                return val;
            }
            i++;
        }

        while (j < v2.size()) {
            int val = compare("0", v2[j]);
            if (val != 0) {
                return val;
            }
            j++;
        }
        return 0;
    }

private:
    int compare(string s1, string s2) {
        int v1 = stoi(s1);
        int v2 = stoi(s2);

        if (v1 < v2) {
            return -1;
        } else if (v1 > v2) {
            return 1;
        }
        return 0;
    }

    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        size_t start = 0, end = 0;

        while ((end = str.find(delimiter, start)) != string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(str.substr(start)); // last part
        return tokens;
    }
};