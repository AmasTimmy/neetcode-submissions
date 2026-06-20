class Solution {
 public:
  int calPoints(vector<string>& operations) {
    std::stack<int> recordsKeeper{};

    for (auto element : operations) {
      if (element == "C") {
        recordsKeeper.pop();
      } else if (element == "D") {
        auto elementToDouble = recordsKeeper.top();
        recordsKeeper.push(elementToDouble * 2);
      } else if (element == "+") {
        auto firstOperand = recordsKeeper.top();
        recordsKeeper.pop();
        auto secondOperand = recordsKeeper.top();
        recordsKeeper.pop();
        recordsKeeper.push(secondOperand);
        recordsKeeper.push(firstOperand);
        recordsKeeper.push(firstOperand + secondOperand);
      } else {
        recordsKeeper.push(std::stoi(element));
      }
    }

    auto resultSum = 0;
    while (!recordsKeeper.empty()) {
      resultSum += recordsKeeper.top();
      recordsKeeper.pop();
    }
    return resultSum;
  }
};