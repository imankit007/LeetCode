class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        const int n = words.size();

        unordered_map<string, int> freq;

        for (const string& word : words) {
            freq[word]++;
        }

        vector<vector<string>> bucket(n + 1);

        for (const auto& [word, count] : freq) {
            bucket[count].push_back(word);
        }

        vector<string> ans;

        for (int i = n; i > 0 && k > 0; --i ) {
            ranges::sort(bucket[i].begin(), bucket[i].end());
            int c = bucket[i].size();
            cout<<c<<endl;
            int j = 0;
            for (; k > 0 &&  j < c;) {
                ans.push_back(bucket[i][j]);
                j++;
                k--;
            }
        }

        return ans;
    }
};