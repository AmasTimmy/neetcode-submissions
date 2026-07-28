class Solution {
    class SameSet {
        std::unordered_map<int, int> m_parent{};
        std::unordered_map<int, int> m_rank{};

        int find(int element) {
            if (m_parent[element] == element) return element;
            m_parent[element] = find(m_parent[element]);
            return m_parent[element];
        }

       public:
        SameSet(int n) {
            for (int index = 0; index < n; index++) {
                m_parent[index] = index;
                m_rank[index] = 0;
            }
        }

        void merge(int x, int y) {
            if (is_same(x, y)) return;

            auto rootx = find(x);
            auto rooty = find(y);
            if (m_rank[rootx] > m_rank[rooty])
                m_parent[rooty] = rootx;
            else if (m_rank[rootx] < m_rank[rooty])
                m_parent[rootx] = rooty;
            else {
                m_parent[rootx] = rooty;
                m_rank[rooty]++;
            }
        }

        bool is_same(int x, int y) {
            auto rootx = find(x);
            auto rooty = find(y);
            return rooty == rootx;
        }
        int getNbrComponent() {
            int count = 0;
            for (auto [k, v] : m_parent) {
                if (k == v) count++;
            }
            return count;
        }
    };

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        SameSet elementsSet(n);
        for (auto element : edges) {
            elementsSet.merge(element[0], element[1]);
        }
        return elementsSet.getNbrComponent();
    }
};
