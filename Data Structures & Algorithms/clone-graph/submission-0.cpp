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
    Node* dfs(Node* head,unordered_map<Node*,Node*>&mp)
    {
        if(head==nullptr) return head;
        Node* node=new Node(head->val);
        mp[head]=node;
        for(auto it:head->neighbors){
            if(!mp.count(it)){
                node->neighbors.push_back(dfs(it,mp));
            }
            else{
                node->neighbors.push_back(mp[it]);
            }
        }
        return node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        return dfs(node,mp);
    }
};
