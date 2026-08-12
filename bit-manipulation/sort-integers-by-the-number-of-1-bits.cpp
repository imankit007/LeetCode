class Solution {
public:
    static int bitCount(int a){
        int count = 0;
        while(a>0){
            if(a&1)
                count++;
            a>>=1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        
        sort(arr.begin(), arr.end(), [](const int &a,const int &b){

            int counta = bitCount(a);
            int countb = bitCount(b);

            if(counta == countb)
                return a<b;
            
            return counta < countb;
        });

        return arr;
    }
};