class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {      
        unordered_map<int, int> m;
        for(const int n : arr)
            m[n]++;
        set<int> s;

        for(const auto& [n , freq]: m){
            if(s.insert(freq).second == false)
                return false;
        }

        return true;

    }
};