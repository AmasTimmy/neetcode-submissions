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
  Node* bfs(Node* node) {
    std::queue<std::pair<Node*, Node*>> list{};
    std::unordered_map<int, pair<Node*, Node*>> visited{};
    Node* clone = new Node{node->val};
    list.push({node, clone});
    visited[node->val] = {node, clone};

    while (!list.empty()) {
      auto size = list.size();

      for (int index = 0; index < size; index++) {
        auto pairOfElements = list.front();
        list.pop();
        auto original = pairOfElements.first;
        auto cloned = pairOfElements.second;
        std::cout << original->val << endl;
        for (auto* adjacent : original->neighbors) {
          if (visited.contains(adjacent->val)) {
            auto elements = visited[adjacent->val];
            cloned->neighbors.push_back(elements.second);
            continue;
          }
          Node* cloneAdj = new Node(adjacent->val);
          cloned->neighbors.push_back(cloneAdj);
          list.push({adjacent, cloneAdj});
          visited[adjacent->val] = {adjacent, cloneAdj};
        }
      }
    }
    return clone;
  }

 public:
  Node* cloneGraph(Node* node) { return node ? bfs(node) : nullptr; }
};
