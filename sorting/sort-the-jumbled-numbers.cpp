
struct T{
    int num;
    int idx;
    int newNum;
};


class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        

        vector<T> arr;


        for(int i =0; i< nums.size(); ++i){
            int mappedNum = getMapNum(mapping, nums[i]);
            arr.push_back(T(nums[i], i, mappedNum));
        }

        sort(arr.begin(), arr.end(), [](const T &a, const T &b){
            return a.newNum == b.newNum ? a.idx < b.idx : a.newNum < b.newNum;
        });

        vector<int> ans;

        for(const auto &t: arr){
            ans.push_back(t.num);
        }

        return ans;

    }

    int getMapNum(vector<int>& mapping, int num){
        string s = to_string(num);
        for(char &c : s){
            c = (char)(mapping[c - '0'] + '0');
        }
        return stoi(s);
    }

};