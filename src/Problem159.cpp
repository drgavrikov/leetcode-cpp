#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/solutions/5095009/sliding-window-solution/
 */
class Problem159 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        std::unordered_map<char, int> chars;

        int result = 0;

        int left = 0;
        int right = 0;

        while (right < s.length()) {
            chars[s[right]]++;

            while (chars.size() > 2) {
                chars[s[left]]--;
                if (chars[s[left]] == 0) {
                    chars.erase(s[left]);
                }
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};

int main() {
    Problem159 problem;
    assert(3 == problem.lengthOfLongestSubstringTwoDistinct("eceba"));
    assert(5 == problem.lengthOfLongestSubstringTwoDistinct("ccaabbb"));
    return 0;
}