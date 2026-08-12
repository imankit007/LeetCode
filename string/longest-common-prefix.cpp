class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string res = "";
        
        int i=0;
        int j =0;
        int minLength=0;
       for(;i<strs.size();i++){
           if(strs[i].size()==0){
               return "";
           }
           if(minLength<strs[i].size()){
               minLength = strs[i].size();
               res = strs[i];
           }
       }
        
        
        
        for(i=0; i<strs.size();i++){
            minLength = res.size();
            for(j=0; j<minLength;j++){
                if(res[j]!=strs[i][j]){
                    res = res.substr(0,j);
                    break;
                }    
            }
        }
       return res;
        
    }
};