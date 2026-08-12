class Solution {
public:
    string convert(string s, int numRows) {
        
        int n=s.size();
        
        if(numRows==1)
            return s;
       
        int i = 0;
        int r = 0;
        bool zig = false;
        
        vector<string> result(numRows, "");
        
        while(i<n){
            if(r<numRows && !zig){
                result[r]+=s[i];
                i++;
                r++;
            }else{
                if(!zig){
                    zig =true;
                    r--;
                }else{
                    r--;
                    if(r>=0)
                        result[r]+=s[i];
                    i++;
                    if(r==0){
                        zig=false;
                        r++;
                    }
                }
                
            }//if-else
        }//while
        
        string res;
        for(i = 0; i< result.size() ; i++){
            for(int j = 0; j<result[i].size(); j++){
                res+=result[i][j];
            }
        }
        
        return res;
            
    }// end of convert
};