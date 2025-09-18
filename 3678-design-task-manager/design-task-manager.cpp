class TaskManager {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        }
    };
    unordered_map<int,unordered_map<int,int>> userTasks; // user -> {taskID -> priority}
    unordered_map<int,int> taskToUser; // taskID -> user
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> taskOrder; 
    // {priority, taskID}
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task:tasks){
            int user=task[0],taskID=task[1],priority=task[2];
            userTasks[user][taskID]=priority;
            taskToUser[taskID]=user;
            taskOrder.push({priority,taskID});
        }
    }
    
    void add(int user, int taskID, int priority) {
        userTasks[user][taskID]=priority;
        taskToUser[taskID]=user;
        taskOrder.push({priority,taskID});
    }
    
    void edit(int taskId, int newPriority) {
        int user=taskToUser[taskId];
        userTasks[user][taskId]=newPriority;
        taskOrder.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        int user=taskToUser[taskId];
        userTasks[user].erase(taskId);
        taskToUser.erase(taskId);
    }
    
    int execTop() {
        while(!taskOrder.empty()){
            auto [pri,task]=taskOrder.top();
            taskOrder.pop();
            auto it = taskToUser.find(task);
            if(it==taskToUser.end()) continue;
            int user = it->second;
            auto uit = userTasks.find(user);
            if (uit == userTasks.end()) continue;
            auto tit = uit->second.find(task);
            if (tit == uit->second.end()) continue;
            if (tit->second == pri) {
                uit->second.erase(tit);
                taskToUser.erase(it);
                return user;
            }
            
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */