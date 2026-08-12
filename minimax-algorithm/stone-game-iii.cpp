class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> mem(stoneValue.size(), INT_MIN);
        
        const int score = solve(stoneValue, 0, mem);

        if(score > 0){
            return "Alice";
        }else if(score == 0){
            return "Tie";
        }else{
            return "Bob";
        }

    }

    int solve(vector<int>& stoneValue, int i , vector<int> &mem){

        if(i >= stoneValue.size()){
            return 0;
        }

        if(mem[i] != INT_MIN){
            return mem[i];
        }


        int sum = 0; 
        for(int j = i ; j < i + 3 && j < stoneValue.size() ; ++j){
            sum += stoneValue[j];
            mem[i] = max(mem[i], sum - solve(stoneValue, j + 1, mem));
        }
        
        return mem[i];

    }

};