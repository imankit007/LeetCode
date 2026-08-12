class Solution {
public:
    int maximum69Number (int num) {
        int ans = num;
        string number = to_string(num);

        for(int i = 0; i< number.size(); ++i){
            string curr = number;
            if(curr[i] == '9'){
                curr[i] = '6';
            }else{
                curr[i] = '9';
            }

            ans = max(ans, stoi(curr));

        }
        return ans;

    }
};