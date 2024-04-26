#include <string>
#include <cassert>

using namespace std;

class Problem32 {
public:
    int longestValidParentheses(string s) {
        int result = 0;

        int openedCount = 0;
        int closedCount = 0;
        int reversedOpenedCount = 0;
        int reversedClosedCount = 0;
        for (int index = 0; index < s.length(); ++index) {
            if (s[index] == '(') openedCount++;
            else closedCount++;
            if (openedCount == closedCount)
                result = max(result, 2 * openedCount);
            if (closedCount > openedCount) {
                openedCount = 0;
                closedCount = 0;
            }

            if (s[s.length() - index - 1] == '(') reversedOpenedCount++;
            else reversedClosedCount++;
            if (reversedOpenedCount == reversedClosedCount)
                result = max(result, 2 * reversedOpenedCount);
            if (reversedOpenedCount > reversedClosedCount) {
                reversedOpenedCount = 0;
                reversedClosedCount = 0;
            }
        }
        return result;
    }
};

int main() {
    Problem32 problem;
    assert(2 == problem.longestValidParentheses("(()"));
    assert(4 == problem.longestValidParentheses(")()())"));
    return 0;
}