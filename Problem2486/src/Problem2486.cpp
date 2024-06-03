#include <string>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/solutions/5254944/two-pointer-solution/
 */
class Problem2486 {
public:
    int appendCharacters(std::string s, std::string t) {
        size_t sIndex = 0;
        size_t tIndex = 0;
        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] == t[tIndex]) ++tIndex;
            ++sIndex;
        }
        return static_cast<int>(t.length() - tIndex);
    }
};

int main() {
    Problem2486 problem;
    assert(problem.appendCharacters("coaching", "coding") == 4);
    return 0;
}
