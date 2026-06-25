class Solution {
 public:
  bool isValid(string s) {
    if (s.size() == 1) return false;
    std::stack<char> openParent{};
    for (auto element : s) {
      if (element == '(' || element == '{' || element == '[')
        openParent.push(element);
      else {
        if (openParent.empty()) return false;
        auto lastElement = openParent.top();
        if (lastElement == '(' && element != ')')
          return false;
        else if (lastElement == '{' && element != '}')
          return false;
        else if (lastElement == '[' && element != ']')
          return false;
        openParent.pop();
      }
    }
    return openParent.empty();
  }
};
