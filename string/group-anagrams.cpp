class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> keyToAnagrams;

        for(const string str: strs){
            string hash = hashing(str);
            if(!keyToAnagrams.contains(hash)){
                keyToAnagrams.emplace(hash, vector<string>({str}));
            }else{
                keyToAnagrams[hash].push_back(str);
            }
        }

        for(auto &ent : keyToAnagrams){
            ans.push_back(ent.second);
        }
        
        return ans;
    }

private:

    string hashing(string s){

        string hash = "";

        vector<int> freq(26);

        for(const char c: s){
            freq[c - 'a']++;
        }

        for(int i : freq){
            hash+=i;
        }
        return hash;
    }

};