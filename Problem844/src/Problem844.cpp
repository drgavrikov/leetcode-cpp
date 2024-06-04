#include <string>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/backspace-string-compare/solutions/5028946/linear-solution-without-additional-memory/
 */
class Problem844 {
public:
    int nextIndex(const std::string& s, int index) {
        int nextIndex = index;
        int count = 0;
        while (nextIndex >= 0) {
            if (s[nextIndex] == '#') ++count;
            else if (count == 0) break;
            else --count;
            --nextIndex;
        }
        return nextIndex;
    }

    bool backspaceCompare(std::string s, std::string t) {
        int sIndex = nextIndex(s, static_cast<int>(s.length()) - 1);
        int tIndex = nextIndex(t, static_cast<int>(t.length()) - 1);
        while (sIndex >= 0 && tIndex >= 0 && s[sIndex] == t[tIndex]) {
            sIndex = nextIndex(s, sIndex - 1);
            tIndex = nextIndex(t, tIndex - 1);
        }
        return sIndex == -1 && tIndex == -1;
    }
};

int main() {
    Problem844 problem;
    assert(problem.backspaceCompare("ab#c", "ad#c"));
    return 0;
}
