/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        q.push(node);
        unordered_map<Node* , Node*> clone;
        clone[node]=new Node(node->val);
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            for(auto it:i->neighbors){
                if(!clone.count(it)) {
                    clone[it]=new Node(it->val);
                    q.push(it);
                }
                clone[i]->neighbors.push_back(clone[it]);
            }
        }
        return clone[node];
    }
};