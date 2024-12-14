#include <string>
#include <cassert>
#include <vector>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/submissions/1478728787/
 */
class Problem2593 {
public:
    static long long findScore(std::vector<int>& nums) {
        size_t size = nums.size();
        std::vector<std::pair<int, size_t>> pairs(size);
        std::transform(nums.begin(), nums.end(), pairs.begin(), [idx = 0](int num) mutable {
            return std::make_pair(num, idx++);
        });
        std::sort(pairs.begin(), pairs.end());

        long long result = 0;
        std::vector<bool> marked(size);
        for (const auto& [num, index]: pairs) {
            if (!marked[index]) {
                marked[index] = true;
                if (index > 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < size) {
                    marked[index + 1] = true;
                }
                result += num;
            }
        }
        return result;
    }
};


int main() {
    // Test case 1
    std::vector<int> test1 = {2, 1, 3, 4, 5, 2};
    long long result1 = Problem2593::findScore(test1);
    std::cout << "Test 1 result: " << result1 << " (expected: 7)" << std::endl;
    assert(result1 == 7);

    // Test case 2
    std::vector<int> test2 = {2, 3, 5, 1, 3, 2};
    long long result2 = Problem2593::findScore(test2);
    std::cout << "Test 5 result: " << result2 << " (expected: 5)" << std::endl;
    assert(result2 == 5);
    return 0;
}
