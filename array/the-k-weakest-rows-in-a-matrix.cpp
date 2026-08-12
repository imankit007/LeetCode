class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> arr;
        for(int i= 0 ; i<mat.size(); i++){
            int s = 0;
            for(const int& n: mat[i])
                s+=n;
            arr.push_back(make_pair(i, s));
        }
        sort(arr.begin(), arr.end(), compare);
        vector<int> ans(k);
        for(int i =0; i<k; i++){
            ans[i] = arr[i].first;
        }
    return ans;
    }
private:
    static bool compare(const pair<int, int>& a,const pair<int, int>& b){
        return a.second==b.second ? a.first< b.first : a.second< b.second;
    }

};