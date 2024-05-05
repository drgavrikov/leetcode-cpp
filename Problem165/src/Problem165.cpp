#include <string>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/compare-version-numbers/solutions/5106641/solution-without-additional-memory/
 */
class Problem165 {
public:

    static int readNextDigit(std::string::const_iterator &iterator, const std::string::const_iterator &endIterator) {
        int digit = 0;
        while (iterator != endIterator && *iterator != '.') {
            digit = digit * 10 + (*iterator++ - '0');
        }
        if (iterator != endIterator) {
            iterator++;
        }
        return digit;
    }

    int compareVersion(const std::string &version1, const std::string &version2) {
        auto iterator1 = version1.begin();
        auto iterator2 = version2.begin();

        while (iterator1 != version1.cend() || iterator2 != version2.cend()) {
            int digit1 = readNextDigit(iterator1, version1.cend());
            int digit2 = readNextDigit(iterator2, version2.cend());

            if (digit1 < digit2) {
                return -1;
            }
            if (digit1 > digit2) {
                return 1;
            }
        }
        return 0;
    }
};

int main() {
    Problem165 problem;
    assert(problem.compareVersion("1.01", "1.001") == 0);
    assert(problem.compareVersion("0.1", "1.1") == -1);
    return 0;
}