#include <cassert>
#include <unordered_set>
#include <vector>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/solutions/5100296/hash-table-solution/
 */
class Problem2441 {
public:
    int findMaxK(std::vector<int>& nums) {
        int result = 0;
        std::unordered_set<int> set;
        for (const auto& num: nums) {
            if (set.find(-num) != set.end() && abs(num) > result) {
                result = abs(num);
            }
            set.insert(num);
        }
        return result;
    }
};

int main() {
    Problem2441 problem;
    std::vector<int> nums = {-1,2,-3,3};
    assert(problem.findMaxK(nums) == 3);
    return 0;
}