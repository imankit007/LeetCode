class Solution {
public:
    string intToRoman(int num) {
        
        string result;
        vector<string> roman({"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"});
        vector<int> value({1,4,5,9,10,40,50,90,100,400,500,900,1000});
        
        int j = roman.size() -1;
        
        while(num>0){
            while(value[j]<= num){
                num = num-value[j];
                result += roman[j];
            }
            j--;
        }
        
        return result;
    }
};