class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;

        long long int x = 1;

        for(int i =0; i<rowIndex+1;i++){
            ans.push_back(x);
            x = x * (rowIndex-i)/(i+1);
        }

        
        return ans;  
    }
};