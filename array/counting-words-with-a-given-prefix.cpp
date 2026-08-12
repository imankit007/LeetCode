class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int count=0;
        int s=pref.size();
        
        for(int i=0; i<words.size();i++){
            string str = words[i].substr(0,s);
            
            if(str==pref){
                count++;
            }
        }
        return count;
    }
};