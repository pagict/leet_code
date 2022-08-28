#include <string>
#include <vector>
int longestValidParentheses(std::string s) {
  int max = 0;
  int length = 0;
  int last_len = 0;
  std::vector<char> brackets;
  for (char c : s) {
    if (c == '(') {
      brackets.push_back(c);
      ++length;
    } else {
      if (brackets.empty()) {
        if (length > max) {
          max = length;
        }
        last_len = length;
        length = 0;
        continue;
      } else {
        ++length;
        brackets.pop_back();
      }
    }
  }
  //   length = length - brackets.size();
  if (ensured > max) {
    return ensured;
  }
  return max;
}

int main(int argc, char **argv) {
  std::string s = ")()";

  printf("longestValidParentheses(\"%s\")=%u\n", s.c_str(),
         longestValidParentheses(s));

  s = "())(())";
  printf("longestValidParentheses(\"%s\")=%u\n", s.c_str(),
         longestValidParentheses(s));

  s = "(()";
  printf("longestValidParentheses(\"%s\")=%u\n", s.c_str(),
         longestValidParentheses(s));

  s = ")()())";
  printf("longestValidParentheses(\"%s\")=%u\n", s.c_str(),
         longestValidParentheses(s));

  s = "";
  printf("longestValidParentheses(\"%s\")=%u\n", s.c_str(),
         longestValidParentheses(s));

  s = "()(()";
  printf("longestValidParentheses(\"%s\")=%u\n", s.c_str(),
         longestValidParentheses(s));
}