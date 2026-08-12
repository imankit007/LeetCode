class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int size = intervals.size();
        if(size<0){
            return 0;
        }
    int count = 0;
    sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b)
                    { return a[0] < b[0]; });
    int temp = intervals[0][1];
    for(int i=1; i<size; ++i){    
        if(intervals[i][0]< temp){
            count++;
            temp = min(intervals[i][1], temp);
        }else{
            temp = intervals[i][1];
        }
    }
    return count;
    }
};