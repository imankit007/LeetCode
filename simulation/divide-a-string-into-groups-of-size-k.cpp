class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        const int n = s.size();
        
        vector<string> ans;
        int curr = 0;
        while(curr<n){
           string temp = "";
            for(int i =0; i<k; i++){
                if(curr<n)
                   temp+=s[curr++];
                else
                    temp+=fill;
            }   
            ans.push_back(temp);
        }
        return ans;
    }
};