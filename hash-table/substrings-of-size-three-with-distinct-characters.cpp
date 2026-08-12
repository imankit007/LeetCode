class Solution {
public:
    int countGoodSubstrings(string s) {

        int count = 0;
        if(s.length()<3) return 0;
        for(int i=0; i<s.length()-2;i++){
            string r = s.substr(i ,3);
            if(r[0]!=r[1] &&r[0]!=r[2] && r[1]!=r[2]) count++;
        }

        return count;


    }
};