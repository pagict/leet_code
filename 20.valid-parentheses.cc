#include <stack>
#include <string>

bool isValid(std::string s) {
  std::stack<int> brackets;
  for (auto i = 0u; i < s.size(); ++i) {
    auto c = s[i];
    switch (c) {
    case '{':
      brackets.push(1);
      break;
    case '}':
      if (brackets.empty() || brackets.top() - 1) {
        return false;
      } else {
        brackets.pop();
      }
      break;
    case '(':
      brackets.push(2);
      break;
    case ')':
      if (brackets.empty() || brackets.top() - 2) {
        return false;
      } else {
        brackets.pop();
      }
      break;
    case '[':
      brackets.push(3);
      break;
    case ']':
      if (brackets.empty() || brackets.top() - 3) {
        return false;
      } else {
        brackets.pop();
      }
      break;
    default:
      break;
    }
  }
  return brackets.empty();
}