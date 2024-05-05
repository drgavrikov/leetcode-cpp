#include <string>
#include <unordered_set>
#include <cassert>

using std::string;
using std::unordered_map;

class Problem159 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> chars;

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
            result = std::max(result, right - left + 1);
            right++;
        }

        return result;
    }
};

int main() {
    Problem159 problem;
    assert(problem.lengthOfLongestSubstringTwoDistinct("eceba") == 3);
    assert(problem.lengthOfLongestSubstringTwoDistinct("ccaabbb") == 5);
    return 0;
}