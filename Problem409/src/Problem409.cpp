#include <vector>
#include <string>
#include <numeric>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/longest-palindrome/solutions/5258509/counting-the-frequencies-solution/
 */
class Problem409 {
public:
    int longestPalindrome(const std::string& s) {
        size_t size = 'z' - 'A' + 1;
        auto letterCount = std::vector<int>(size);
        int countOdd = 0;
        for (char c: s) {
            auto charIndex = static_cast<size_t>(c - 'A');
            ++letterCount[charIndex];
            if ((letterCount[charIndex] & 1) == 1) ++countOdd;
            else --countOdd;
        }
        int result = std::accumulate(
                letterCount.begin(),
                letterCount.end(),
                0,
                [](double acc, int value) { return acc + ((value >> 1) << 1); }
        );
        return result + (countOdd > 0);
    }
};

int main() {
    Problem409 problem;
    assert(problem.longestPalindrome("abccccdd") == 7);
    return 0;
}