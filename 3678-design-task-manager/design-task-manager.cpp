// class TaskManager {
// public:
//     struct cmp{
//         bool operator()(const pair<int,int>& a, const pair<int,int>& b){
//             if(a.first==b.first) return a.second<b.second;
//             return a.first<b.first;
//         }
//     };
//     unordered_map<int,unordered_map<int,int>> userTasks; // user -> {taskID -> priority}
//     unordered_map<int,int> taskToUser; // taskID -> user
//     priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> taskOrder; 
//     // {priority, taskID}
//     TaskManager(vector<vector<int>>& tasks) {
//         for(auto task:tasks){
//             int user=task[0],taskID=task[1],priority=task[2];
//             userTasks[user][taskID]=priority;
//             taskToUser[taskID]=user;
//             taskOrder.push({priority,taskID});
//         }
//     }
    
//     void add(int user, int taskID, int priority) {
//         userTasks[user][taskID]=priority;
//         taskToUser[taskID]=user;
//         taskOrder.push({priority,taskID});
//     }
    
//     void edit(int taskId, int newPriority) {
//         int user=taskToUser[taskId];
//         userTasks[user][taskId]=newPriority;
//         taskOrder.push({newPriority,taskId});
//     }
    
//     void rmv(int taskId) {
//         int user=taskToUser[taskId];
//         userTasks[user].erase(taskId);
//         taskToUser.erase(taskId);
//     }
    
//     int execTop() {
//         while(!taskOrder.empty()){
//             auto [pri,task]=taskOrder.top();
//             taskOrder.pop();
//             auto it = taskToUser.find(task);
//             if(it==taskToUser.end()) continue; // check if task exists
//             int user = it->second;
//             auto uit = userTasks.find(user);
//             if (uit == userTasks.end()) continue; // check if user exists
//             auto tit = uit->second.find(task);
//             if (tit == uit->second.end()) continue; // check if task exists
//             if (tit->second == pri) {
//                 uit->second.erase(tit);
//                 taskToUser.erase(it);
//                 return user;
//             }
            
//         }
//         return -1;
//     }
// };

// space optimised version

class TaskManager {
public:
    unordered_map<int, pair<int, int>> mpp;
    priority_queue<pair<int, int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task : tasks){
            mpp[task[1]] = {task[2], task[0]};
            pq.push({task[2], task[1]});
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId] = {priority, userId};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        mpp[taskId].first = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mpp[taskId].first = -1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId] = pq.top();

            if(mpp[taskId].first == priority){
                mpp[taskId].first = -1;
                pq.pop();
                return mpp[taskId].second;
            }
            else{
                pq.pop();
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