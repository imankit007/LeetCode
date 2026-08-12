class Solution {
public:
    int romanToInt(string s) {
        
        int res=0;
        vector<string> roman({"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"});
        vector<int> value({1,4,5,9,10,40,50,90,100,400,500,900,1000});
        
        
        int index  = value.size()-1;
        int j = 0;
        int i=1;
        while(j<s.size()&& index>=0){
            
            if(s.substr(j,1)==roman[index]) {
                res +=value[index];
                j++;
            }
             else if(s.substr(j,2)== roman[index]){
                res +=value[index];
                 j=j+2; 
            }
            if(i%3==0){
                index--;
            }
            i++;
        }
        
        return res;
    }
};