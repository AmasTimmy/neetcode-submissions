class Solution {
  std::vector<std::pair<int, int>> getAdjacents(vector<vector<int>> const& grid, int sr, int sc) {
    std::vector<std::pair<int, int>> adjacents{};

    std::array<int, 4> deltaRow{-1, 0, 1, 0};
    std::array<int, 4> deltaCol{0, 1, 0, -1};

    for (int index = 0; index < 4; index++) {
      int row = sr + deltaRow[index];
      int col = sc + deltaCol[index];
      if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()) {
        adjacents.push_back({row, col});
      }
    }
    return adjacents;
  }

  int dfs(vector<vector<int>> const& grid, int sr, int sc,
           std::vector<std::vector<bool>>& visited) {
    visited[sr][sc] = true;
    int island = 1;
    for (auto pair : getAdjacents(grid, sr, sc)) {
      if (grid[pair.first][pair.second] == 0) continue;
      if (visited[pair.first][pair.second]) continue;
      island += dfs(grid, pair.first, pair.second, visited);
    }
    return island;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    const int rows = grid.size(), cols = grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 0) continue;
        if (visited[r][c]) continue;
        maxArea=std::max(maxArea, dfs(grid, r, c, visited));
      }
    }
    return maxArea;
  }
};
