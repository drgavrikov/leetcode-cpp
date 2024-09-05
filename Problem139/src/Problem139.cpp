#include <cassert>
#include <string>
#include <vector>

class Problem139 {
public:
    bool wordBreak(std::string s, const std::vector<std::string> &wordDict) {
        size_t length = s.length();
        std::vector<bool> dp(length + 1);
        dp[0] = true;
        for (size_t start = 0; start < length; ++start) {
            if (!dp[start]) {
                continue;
            }
            for (const auto &word: wordDict) {
                size_t wordLength = word.length();
                size_t end = start + wordLength;
                if (end < dp.size() && std::string_view(s.data() + start, wordLength) == word) {
                    dp[end] = true;
                    if (end == length) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {

    Problem139 problem;
    assert(problem.wordBreak("leetcode", {"leet", "code"}));

    return 0;
}