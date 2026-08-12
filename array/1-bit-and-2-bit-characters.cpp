class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool isLastOneBit = false;
        for( int i =0; i < bits.size(); i++){
            if(bits[i] == 0 ){
                isLastOneBit = true;
            }else{
                isLastOneBit = false;
                ++i;
            }

        }

        return isLastOneBit;

    }
};