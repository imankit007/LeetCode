class Solution {
public:
    int minimumDistance(string word) {
        const int n = word.size();

        const int MAX = 1 << 30;

        vector<vector<vector<int>>> dp(
            27, vector<vector<int>>(27, vector<int>(n, MAX)));

        for (int i = 0; i < 26; i++) {
            dp[word[0] - 'A'][i][0] = 0;
            dp[i][word[0] - 'A'][0] = 0;
        }

        for (int i = 1; i < n; i++) {
            int prevChar = word[i - 1] - 'A';
            int currChar = word[i] - 'A';
            int moveDist = dist(prevChar, currChar);

            for (int otherFinger = 0; otherFinger < 26; otherFinger++) {
                dp[currChar][otherFinger][i] =
                    min(dp[currChar][otherFinger][i],
                       dp[prevChar][otherFinger][i - 1] + moveDist);

                dp[otherFinger][currChar][i] =
                    min(dp[otherFinger][currChar][i],
                         dp[otherFinger][prevChar][i - 1] + moveDist);

                if (otherFinger == prevChar) {
                    for (int prevOtherFinger = 0; prevOtherFinger < 26;
                         prevOtherFinger++) {
                        int otherFingerDist = dist(prevOtherFinger, currChar);

                        dp[currChar][otherFinger][i] =
                            min(dp[currChar][otherFinger][i],
                               dp[prevOtherFinger][prevChar][i - 1] +
                                    otherFingerDist);

                        dp[otherFinger][currChar][i] =
                            min(dp[otherFinger][currChar][i],
                               dp[prevChar][prevOtherFinger][i - 1] +
                                    otherFingerDist);
                    }
                }
            }
        }
        int minDistance = MAX;
        int lastChar = word[n - 1] - 'A';

        for (int otherFinger = 0; otherFinger < 26; ++otherFinger) {
            minDistance = min(minDistance, dp[lastChar][otherFinger][n-1]);
            minDistance = min(minDistance, dp[otherFinger][lastChar][n - 1]);
        }

        return minDistance;
    }

private:
    int dist(int a, int b) {
        if (a == 26)
            return 0;
        const int x1 = a / 6;
        const int y1 = a % 6;
        const int x2 = b / 6;
        const int y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
};