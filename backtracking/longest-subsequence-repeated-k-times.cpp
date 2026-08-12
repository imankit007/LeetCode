class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
    
        vector<int> freq(26,0);
        vector<char> uniqueChars;
        queue<string> q ;
        q.push("");
        string ans = "";
        for(char c : s){
            ++freq[c - 'a'];
        }
        for(char c  = 'a' ; c <= 'z'; ++c){
            if(freq[c - 'a'] >= k){
                uniqueChars.push_back(c);
            }
        }
        while(q.size() > 0){
            string curr = q.front();
            q.pop();
            if(curr.length() * k > s.length()){
                return ans;
            }
            for(char c :uniqueChars ){
                string str = curr + c;
                if(isSubsequence(str, s, k)){
                    q.push(str);
                    ans = str;
                }
            }
        }
        return ans;
    }

private:
    bool isSubsequence(string sub, string s, int k){
        int i =0;
        for(const char c : s){
            if(c == sub[i]){
                if(++i == sub.length()){
                    if(--k ==0){
                        return true;
                    }
                    i = 0;
                }
            }
        }
        return false;
    }

};