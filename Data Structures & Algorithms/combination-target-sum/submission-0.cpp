class Solution {
    void dfs(std::vector<int> candidates, int target, int sum, int starting,
             std::vector<int> result, std::vector<std::vector<int>>& sets) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            sets.push_back(result);
            return;
        }

        for (int index = starting; index < candidates.size(); index++) {
            auto element = candidates[index];
            result.push_back(element);
            dfs(candidates, target, sum + element, index, result, sets);
            result.pop_back();
        }
    }

   public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> sets{};
        std::sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, {}, sets);
        return sets;
    }
};