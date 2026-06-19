class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    std::priority_queue<int> lastStoneStanding;

    for (auto element : stones) {
        lastStoneStanding.push(element);
    }

    while (lastStoneStanding.size() > 1) {
      auto firstElement = lastStoneStanding.top();
      lastStoneStanding.pop();
      auto secondSelement = lastStoneStanding.top();
      lastStoneStanding.pop();
      auto remaining = abs(firstElement - secondSelement);
      if (remaining != 0) lastStoneStanding.push(remaining);
    }

    return lastStoneStanding.empty() ? 0 : lastStoneStanding.top();
  }
};
