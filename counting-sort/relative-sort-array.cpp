class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> ans;
        
        map<int, int> count;

        for(const int n: arr1)
            ++count[n];

        for(const int n: arr2){     
            for(int i =0; i<count[n]; ++i){
                ans.push_back(n);
            }
            count.erase(n);
        }

        for(const auto &[num, freq]: count){
            for(int i =0; i<count[num]; ++i){
                ans.push_back(num);
            }
        }


        return ans;
    }
};