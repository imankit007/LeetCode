class Solution {
public:
    string frequencySort(string s) {
        
        string ans = "";

        unordered_map<char, int> freq;

        for(const char c : s){
            ++freq[c];
        }
        
        vector<pair<int, char>> v;
        for( auto& [c,f]: freq){
           v.push_back(make_pair(f,c));
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){return a.first>b.first;});

        for(auto& [f,c]: v){
            while(f--){
                ans+=c;
            }
        }

        return ans;
    }
};