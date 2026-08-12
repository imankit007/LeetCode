class Solution {
public:
    bool solve(int sx, int sy, int fx, int fy, int t){
        int step = max(abs(sx-fx), abs(sy-fy));
        return step==0?t!=1:step<=t;
    }

    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        return solve(sx, sy, fx, fy, t);
    }
};