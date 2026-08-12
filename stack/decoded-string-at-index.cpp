class Solution {
public:
    

    string decodeAtIndex(string s, int k) {
      
      long size =0;
      for(char c: s){

          if(isdigit(c)){
            size = size * (c-'0');
          }else{
            size+=1;
          }
      }

      for(int i =s.size()-1; i>=0 ; i--){
          k%=size;

          if(k==0 && isalpha(s[i]))
            return (string) ""+s[i];
          
          if(isdigit(s[i]))
            size = size/ (s[i] - '0');
          else
            size-=1;
      }
    return "";
    }
};