#include <string>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/solutions/5254944/two-pointer-solution/
 */
class Problem2486 {
public:
    int appendCharacters(std::string s, std::string t) {
        auto sIter = s.begin();
        auto tIter = t.begin();
        while (sIter != s.end() && tIter != t.end()) {
            if (*sIter == *tIter) ++tIter;
            ++sIter;
        }
        return static_cast<int>(t.end() - tIter);
    }
};

int main() {
    Problem2486 problem;
    assert(problem.appendCharacters("coaching", "coding") == 4);
    return 0;
}
