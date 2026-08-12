class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0.0;

        const int n = classes.size();
        
        auto compare = [](const ClassReport& a,
                                                       const ClassReport& b) {
            return a.getAddRatio() < b.getAddRatio();
        };

        priority_queue<ClassReport, vector<ClassReport>, decltype(compare)>
            maxHeap(compare);

        for (const vector<int>& report : classes) {
            maxHeap.push({report[0],report[1]});
        }

        while (extraStudents) {
            ClassReport report = maxHeap.top();
            maxHeap.pop();
            report.pass += 1;
            report.total += 1;
            --extraStudents;
            maxHeap.push(report);
        }

        while (maxHeap.size() > 0) {
            ans += maxHeap.top().getRatio();
            maxHeap.pop();
        }
        return ans / n;
    }

private:
    struct ClassReport {
        int pass;
        int total;
        double getRatio() const { return (double)pass / total; }
        double getAddRatio() const {
            return (double)(pass + 1) / (total + 1) - getRatio();
        }
    };
};