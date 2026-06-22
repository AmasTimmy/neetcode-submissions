class Solution {
  struct Node {
    int r{};
    int c{};

    bool operator==(const Node& other) const { return r == other.r && c == other.c; }
  };
  struct NodeHash {
    std::size_t operator()(const Node& n) const {
      return std::hash<int>()(n.r) ^ (std::hash<int>()(n.c) << 1);
    }
  };
  std::vector<Node> getAdjacent(vector<vector<int>> const& image, Node node) {
    std::vector<Node> adjacentNodes{};
    std::array<int, 4> delta_row = {-1, 0, 1, 0};
    std::array<int, 4> delta_col = {0, 1, 0, -1};
    int const COL = image[0].size();
    int const NUM = image.size();

    for (int index = 0; index < 4; index++) {
      int resultedRow = node.r + delta_row[index];
      int resultedCol = node.c + delta_col[index];
      if (resultedRow >= 0 && resultedRow < NUM && resultedCol >= 0 && resultedCol < COL) {
        adjacentNodes.push_back({resultedRow, resultedCol});
      }
    }
    return adjacentNodes;
  }

  void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor,
           std::unordered_set<Node, NodeHash>& visited) {
    image[sr][sc] = color;
    visited.insert({sr, sc});
    for (auto element : getAdjacent(image, {sr, sc})) {
      if (visited.contains(element)) continue;
      if (image[element.r][element.c] != originalColor) continue;
      dfs(image, element.r, element.c, color, originalColor, visited);
    }
  }

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int originalColor = image[sr][sc];
    if (originalColor == color) return image;
    std::unordered_set<Node, NodeHash> visited{};
    dfs(image, sr, sc, color, originalColor, visited);
    return image;
  }
};