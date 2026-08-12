
struct Robot {
    int position;
    int health;
    char direction;

    Robot(int p, int h, char d) : position(p), health(h), direction(d) {}
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        const int n = positions.size();

        map<int, int> positionToHealth;
        vector<Robot> robotList;
        for (int i = 0; i < n; i++) {
            robotList.emplace_back(positions[i], healths[i], directions[i]);
            positionToHealth[positions[i]] = healths[i];
        }

        sort(robotList.begin(), robotList.end(),
             [](const Robot& a, const Robot& b) {
                 return a.position < b.position;
             });
        stack<int> st;

        for (int i = 0; i < n; i++) {
            Robot& curr = robotList[i];

            while (!st.empty() && curr.health > 0 &&
                   robotList[st.top()].direction == 'R' &&
                   curr.direction == 'L') {
                Robot& prev = robotList[st.top()];
                if (curr.health == prev.health) {
                    curr.health = 0;
                    prev.health = 0;
                    st.pop();
                    positionToHealth[prev.position] = prev.health;
                    positionToHealth[curr.position] = curr.health;
                    break;
                } else if (curr.health < prev.health) {
                    curr.health = 0;
                    positionToHealth[curr.position] = 0;

                    prev.health--;
                    positionToHealth[prev.position] = prev.health;
                    break;
                } else {
                    st.pop();
                    positionToHealth[prev.position] = 0;
                    curr.health--;
                    positionToHealth[curr.position] = curr.health;
                }
            }

            if (curr.health > 0) {
                st.push(i);
            }
        }

        vector<int> ans;
        for (const int p : positions) {
            if (positionToHealth[p] > 0) {
                ans.push_back(positionToHealth[p]);
            }
        }

        return ans;
    }
};