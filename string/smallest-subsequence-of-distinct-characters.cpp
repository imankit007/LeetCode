class Solution {
public:
    string smallestSubsequence(string s) {

        
        vector<int> count(128);

        vector<bool> used(128);



        for(const char c : s){
            ++count[c];
        }

        string ans = "";

        for(const char c : s){
            --count[c];

            if(used[c]){
                continue;
            }

            while(!ans.empty() && ans.back() > c && count[ans.back()] > 0){
                used[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c] = true;
        }


        return ans;
    }
};