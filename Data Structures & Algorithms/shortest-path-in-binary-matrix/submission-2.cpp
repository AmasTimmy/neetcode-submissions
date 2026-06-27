class Solution {
  using Element = std::pair<int, int>;
  std::vector<Element> getAdjacents(int sr, int sc, int nbRow, int nbCol) {
    std::vector<Element> adjacents{};
    std::array<int, 8> deltaRow{-1, -1, 0, 1, 1, 1, 0, -1};
    std::array<int, 8> deltaCol{0, 1, 1, 1, 0, -1, -1, -1};

    for (int index = 0; index < 8; index++) {
      int row = sr + deltaRow[index];
      int col = sc + deltaCol[index];

      if (row >= 0 && row < nbRow && col >= 0 && col < nbCol) adjacents.push_back({row, col});
    }
    return adjacents;
  }

  int bfs(std::vector<std::vector<int>> const& grid, int nbRow, int nbCol) {
    int length = 0;
    std::queue<Element> listOfCurrentElement{};
    std::vector<std::vector<bool>> visited(nbRow, std::vector<bool>(nbCol, false));
    listOfCurrentElement.push({0, 0});
    visited[0][0] = true;

    while (!listOfCurrentElement.empty()) {
      int size = listOfCurrentElement.size();
      for (int index = 0; index < size; index++) {
        auto element = listOfCurrentElement.front();
        listOfCurrentElement.pop();

        if (element.first == nbRow - 1 && element.second == nbCol - 1) return length+1;

        for (auto adjacent : getAdjacents(element.first, element.second, nbRow, nbCol)) {
          if (grid[adjacent.first][adjacent.second] == 1) continue;
          if (visited[adjacent.first][adjacent.second]) continue;
          listOfCurrentElement.push({adjacent.first, adjacent.second});
          visited[adjacent.first][adjacent.second] = true;
        }
      }
      length++;
    }
    return -1;
  }

 public:
  int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
    auto const NB_ROW = grid.size();
    auto const NB_COL = grid[0].size();
    if (grid[0][0] == 1 || grid[NB_ROW - 1][NB_COL - 1] == 1) return -1;
    return bfs(grid, NB_ROW, NB_COL);
  }
};
