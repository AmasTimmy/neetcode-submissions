class Solution {
    using Element = std::pair<int, int>;
    std::vector<Element> getAdjacents(int sr, int sc, int nbRow, int nbCol) {
        std::vector<Element> adjacents{};
        std::array<int, 4> deltaRow{-1, 0, 1, 0};
        std::array<int, 4> deltaCol{0, 1, 0, -1};

        for (int index = 0; index < 4; index++) {
            int row = sr + deltaRow[index];
            int col = sc + deltaCol[index];

            if (row >= 0 && row < nbRow && col >= 0 && col < nbCol)
                adjacents.push_back({row, col});
        }
        return adjacents;
    }

    int bfs(std::vector<std::vector<int>>& grid, int nbRow, int nbCol) {
        int length = 0;
        std::queue<Element> listOfCurrentElement{};
        int freshCount = 0;

        for (int row = 0; row < nbRow; row++) {
            for (int col = 0; col < nbCol; col++) {
                if (grid[row][col] == 2) {
                    listOfCurrentElement.push({row, col});
                } else if (grid[row][col] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        while (!listOfCurrentElement.empty()) {
            int size = listOfCurrentElement.size();
            bool rottedAny = false;
            for (int index = 0; index < size; index++) {
                auto element = listOfCurrentElement.front();
                listOfCurrentElement.pop();
                for (auto adjacent : getAdjacents(element.first, element.second,
                                                  nbRow, nbCol)) {
                    if (grid[adjacent.first][adjacent.second] == 1) {
                        grid[adjacent.first][adjacent.second] = 2;
                        listOfCurrentElement.push({adjacent.first, adjacent.second});
                        freshCount--;
                        rottedAny = true;
                    }
                }
            }
            if (rottedAny) length++;
        }
        return freshCount == 0 ? length : -1;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid, grid.size(), grid[0].size());
    }
};