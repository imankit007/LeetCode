class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        const int m = languages.size();

        unordered_set<int> candidate;

        for(const vector<int> friendship: friendships){
            const int a = friendship[0];
            const int b = friendship[1];
            if(!check(a, b, languages)){
                candidate.insert(a);
                candidate.insert(b);
            }
        }
        
        if(candidate.size()== 0){
            return 0;
        }


        int ans = INT_MIN;

        unordered_map<int, int> languagesCount;

        for(const int u : candidate){
            for(const int l : languages[u - 1])
                ++languagesCount[l-1];
        }

        for(const auto &[_, freq]: languagesCount){
            ans = max(ans, freq);
        }
        
        return candidate.size() - ans;


}

private:
    bool check(const int a, const int b,  vector<vector<int>>& languages ){

        for(const int l1 : languages[a - 1]){
            for(const int l2 : languages[b - 1]){
                if(l1 == l2){
                    return true;
                }
            }
        }
        return false;
    }

};