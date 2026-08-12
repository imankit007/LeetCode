class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int i =0;
        for(const string str:words){
            if(str.find(x)!=string::npos){
                ans.push_back(i);
            }
                i++;
            }
        return ans;
    }
};