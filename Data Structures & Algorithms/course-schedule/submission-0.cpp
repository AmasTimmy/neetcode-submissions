class Solution {
  std::unordered_map<int, std::vector<int>>
  getAdjacentList(std::vector<std::vector<int>> &prerequisites) {
    std::unordered_map<int, std::vector<int>> list{};
    for (auto const &element : prerequisites) {
      list[element[0]].push_back(element[1]);
    }
    return list;
  }

  bool dfs(std::unordered_map<int, std::vector<int>> &list, int element,
           std::unordered_set<int> visited) {
    auto &adjacentList = list[element];
    if (adjacentList.empty()) {
      return true;
    }
    if (visited.count(element))
      return false;
    visited.insert(element);
    for (auto newElement : adjacentList) {
      if (!dfs(list, newElement, visited))
        return false;
    }
    visited.erase(element);
    list[element] = {};
    return true;
  }

public:
  bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    auto list = getAdjacentList(prerequisites);
    std::unordered_set<int> visited{};
    for (int index = 0; index < numCourses; index++) {
      if (!dfs(list, index, visited))
        return false;
    }
    return true;
  }
};

