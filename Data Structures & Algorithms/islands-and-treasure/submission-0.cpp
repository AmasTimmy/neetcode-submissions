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

    void bfs(std::vector<std::vector<int>>& rooms, int const nbRow,
             int const nbCol) {
        std::queue<Element> elements{};
        auto const INF = INT_MAX;
        for (auto r = 0; r < nbRow; r++) {
            for (auto c = 0; c < nbCol; c++) {
                if (rooms[r][c] == 0) {
                  
                    elements.push({r, c});
                }
            }
        }
        int layers = 0;

        while (!elements.empty()) {
            auto queueLength = elements.size();
            for (int index = 0; index < queueLength; index++) {
                auto element = elements.front();
                elements.pop();

                for (auto adjacent : getAdjacents(element.first, element.second,
                                                  nbRow, nbCol)) {
                    if (rooms[adjacent.first][adjacent.second] != INF) {
                        if (rooms[adjacent.first][adjacent.second] == -1 ||
                            rooms[adjacent.first][adjacent.second] <=
                                layers+1)
                            continue;
                    }
                    rooms[adjacent.first][adjacent.second] = layers+1;
                    elements.push(adjacent);
                }
            }
            layers++;
        }
    }

public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        int const NB_ROW = rooms.size();
        int const NB_COL = rooms[0].size();
        bfs(rooms, NB_ROW, NB_COL);
    }
};