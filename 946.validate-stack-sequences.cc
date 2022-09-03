#include <vector>

// Runtime: 21 ms, faster than 21.93% of C++ online submissions for Validate
// Stack Sequences.
// Memory Usage: 15.4 MB, less than 17.04% of C++ online submissions for
// Validate Stack Sequences.

bool validateStackSequences(const std::vector<int> &pushed,
                            const std::vector<int> &popped) {
  std::vector<int> stack;
  stack.reserve(pushed.size());

  auto pop_idx = 0;
  auto push_idx = 0;
  while (true) {
    if (!stack.empty() && popped[pop_idx] == stack.back()) {
      stack.pop_back();
      if (++pop_idx >= popped.size()) {
        break;
      }
    } else if (stack.empty()) {
      stack.push_back(pushed[push_idx++]);
    } else {
      if (push_idx >= pushed.size()) {
        return false;
      }
      stack.push_back(pushed[push_idx++]);
    }
  }
  return stack.empty();
}

int main(int argc, char **argv) {
  std::vector<int> pushed;
  std::vector<int> popped;
  if (argc > 1 && (argc - 1) % 2 != 0) {
    return -1;
  }

  for (auto i = 1; i < (argc - 1) / 2 + 1; ++i) {
    pushed.push_back(std::atoi(argv[i]));
  }
  for (auto i = (argc - 1) / 2 + 1; i < argc; ++i) {
    popped.push_back(std::atoi(argv[i]));
  }

  printf("%d\n", validateStackSequences(pushed, popped) ? 1 : 0);
}