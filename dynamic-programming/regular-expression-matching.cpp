class Solution {
public:
    bool isMatch(string s, string p) {
        
        vector<vector<bool>> str(s.size() +1, vector<bool>(p.size() + 1, false));
        str[0][0] = true;
        
        for(int i = 0; i<=p.size(); i++){
            if(i>1 && p[i-1]=='*'){
                str[0][i]=str[0][i-2];
            }//if
        }//for
        
        for(int i =1; i<=s.size();i++){
            for(int j =1 ; j<=p.size(); j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    str[i][j]=str[i-1][j-1];
                }else if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2] || p[j-2]=='.'){
                        str[i][j]=str[i][j-1] || str[i][j-2] || str[i-1][j];
                    }else{
                        str[i][j]=str[i][j-2];
                    }//if
                }//if
            } //for
        }//for
        return str[s.size()][p.size()];
    }
};