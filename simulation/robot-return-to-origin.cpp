class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x = 0;
        int y = 0;

        if(moves.size() & 1) return false;

        for(const char &c: moves){
            if(c == 'R'){
                x++;
            }else if(c == 'L'){
                x--;
            }else if(c == 'U'){
                y--;
            }else if(c == 'D'){
                y++;
            }
        }
        return x == 0 && y == 0;


    }
};