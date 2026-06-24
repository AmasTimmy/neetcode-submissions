class Solution {
  std::vector<std::pair<int, int>> getAdjacents(vector<vector<char>> const& grid, int sr, int sc) {
    std::vector<std::pair<int, int>> adjacents{};

    std::array<int, 4> deltaRow{-1, 0, 1, 0};
    std::array<int, 4> deltaCol{0, 1, 0, -1};
    //std::cout << sr << "~for~~" << sc << std::endl;
    for (int index = 0; index < 4; index++) {
      int row = sr + deltaRow[index];
      int col = sc + deltaCol[index];
      if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()) {
        //std::cout << row << "~~~" << col << std::endl;
        adjacents.push_back({row, col});
      }
    }
    return adjacents;
  }

  void dfs(vector<vector<char>> const& grid, int sr, int sc,
           std::vector<std::vector<bool>>& visited) {
    visited[sr][sc] = true;
    for (auto pair : getAdjacents(grid, sr, sc)) {
      if (grid[pair.first][pair.second] == '0') continue;
      if (visited[pair.first][pair.second]) continue;
      dfs(grid, pair.first, pair.second, visited);
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int nbrIsland = 0;
    const int rows = grid.size(), cols = grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == '0') continue;
        if (visited[r][c]) continue;
        dfs(grid, r, c, visited);
        nbrIsland++;
      }
    }
    return nbrIsland;
  }
};
