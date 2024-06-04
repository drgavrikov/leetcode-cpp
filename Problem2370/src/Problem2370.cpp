#include <string>
#include <cassert>
#include <array>

using std::string;

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/longest-ideal-subsequence/solutions/5083170/dynamic-programming-with-linear-complexity-beats-90-0-of-users-with-c/
 */
class Problem2370 {
public:
    int longestIdealString(const string& s, int k) {
        std::array<int, 26> dp{};
        std::fill(std::begin(dp), std::end(dp), 0);

        for (char ch: s) {
            int maxLength = 0;
            for (int shift = 0; shift <= k; ++shift) {
                auto shiftLeftIndex = size_t (ch - shift - 'a');
                if (ch - shift >= 'a' && ch - shift <= 'z' && maxLength < dp[shiftLeftIndex] + 1) {
                    maxLength = dp[shiftLeftIndex] + 1;
                }

                auto shiftRightIndex = size_t (ch + shift - 'a');
                if (ch + shift >= 'a' && ch + shift <= 'z' && maxLength < dp[shiftRightIndex] + 1) {
                    maxLength = dp[shiftRightIndex] + 1;
                }
            }
            dp[size_t (ch - 'a')] = maxLength;
        }
        return *std::max_element(std::begin(dp), std::end(dp));
    }
};

int main() {
    Problem2370 problem;
    assert(problem.longestIdealString("acfgbd", 2) == 4);
    assert(problem.longestIdealString("abcd", 3) == 4);
    return 0;
}