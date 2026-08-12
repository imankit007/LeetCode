struct Task {
  int userId;
  int taskId;
  int priority;

  Task() = default;
  Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}

  bool operator<(const Task& other) const {
    return priority == other.priority ? taskId > other.taskId
                                      : priority > other.priority;
  }
};

class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const vector<int>& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        const Task task(userId, taskId, priority);
        idToTask[taskId] = task;
        bucket.insert(task);
    }

    void edit(int taskId, int newPriority) {
        Task task = idToTask[taskId];
        Task newTask(task.userId, taskId, newPriority);
        bucket.erase(task);
        idToTask[taskId] = newTask;
        bucket.insert(newTask);
    }

    void rmv(int taskId) {
        Task task = idToTask[taskId];
        bucket.erase(task);
        idToTask.erase(taskId);
    }

    int execTop() {

        if(bucket.empty()){
            return -1;
        }

        Task task = *bucket.begin();
        bucket.erase(task);
        idToTask.erase(task.taskId);
        return task.userId;
    }

private:
    unordered_map<int, Task> idToTask;
    set<Task> bucket;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */