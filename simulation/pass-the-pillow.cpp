class Solution {
public:
    int passThePillow(int n, int time) {
        
        int odd = (time / (n-1)) & 1;

        int c = time % (n-1);

        if(odd){
            return  n -c ;
        }else{
            return   1 + c;
        }
    }
};