#include <vector>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/solutions/5218366/counting-and-prefix-sum-techniques/
 */
class Problem1608 {
public:
    int specialArray(std::vector<int>& nums) {
        size_t n = nums.size();
        std::vector<int> freq(n + 1, 0);
        for (int num: nums) {
            freq[static_cast<size_t>(fmin(num, n))]++;
        }
        int sum = 0;
        for (int num = static_cast<int>(n); num >= 0; --num) {
            sum += freq[static_cast<size_t>(num)];
            if (sum == num) return num;
        }
        return -1;
    }
};

int main() {
    Problem1608 problem1608;
    std::vector<int> nums = {3, 5};
    assert(problem1608.specialArray(nums) == 2);
    return 0;
}
