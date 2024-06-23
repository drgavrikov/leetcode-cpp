#include <cassert>
#include <vector>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/solutions/5035977/greedy-linear-solution-without-additional-memory/
 */
class Problem1493 {
public:
    int longestSubarray(std::vector<int>& nums) {
        int result = 0;

        int currentCount = 0;
        int prevCount = 0;
        bool isZeros = false;
        for (auto num: nums) {
            if (num == 0) {
                result = std::max(result, currentCount + prevCount);
                prevCount = currentCount;
                currentCount = 0;
                isZeros = true;
            } else {
                currentCount++;
            }
        }
        result = std::max(result, currentCount + prevCount);
        if (!isZeros) return static_cast<int>(nums.size()) - 1;
        return result;
    }
};


int main() {
    Problem1493 problem;
    std::vector<int> nums = {1, 1, 1, 0, 1};
    assert(problem.longestSubarray(nums) == 5);
    return 0;
}
