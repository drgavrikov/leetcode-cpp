#include <cassert>
#include <vector>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/maximum-product-subarray/solutions/5737405/dynamic-programming-solution/
 */
class Problem152 {
public:
    int maxProduct(const std::vector<int> &nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];
        int prev_max = 1, prev_min = 1;

        for (auto num: nums) {
            int temp_max = std::max(num, std::max(prev_max * num, prev_min * num));
            prev_min = std::min(num, std::min(prev_min * num, prev_max * num));
            prev_max = temp_max;
            result = std::max(result, prev_max);
        }
        return result;
    }
};

int main() {
    Problem152 problem;
    std::vector<int> nums = {2, 3, -2, 4};
    assert(problem.maxProduct(nums) == 6);
    return 0;
}
