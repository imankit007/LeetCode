class Solution {
public:
    bool closeStrings(string word1, string word2) {
        const int m = word1.size();
        const int n = word2.size();
        if(m!=n)return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        
        string s1;
        string s2;

        vector<int> freq1;
        vector<int> freq2;

        for(const char c: word1)
            m1[c]++;

        for(const char c: word2)
            m2[c]++; 

        for(const auto& [c, freq]: m1){
            s1+=c;
            freq1.push_back(freq);
        }  

        for(const auto& [c, freq]: m2){
            s2+=c;
            freq2.push_back(freq);
        }  

        ranges::sort(s1);
        ranges::sort(s2);

        if(s1!=s2)
            return false;
        
        ranges::sort(freq1);
        ranges::sort(freq2);

        return freq1==freq2;
    

        return true;
    }
};