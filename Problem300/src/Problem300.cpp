#include <cassert>
#include <vector>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/longest-increasing-subsequence/solutions/5741657/binary-search-in-sorted-array/
 */
class Problem300 {
public:
    static int lengthOfLIS(const std::vector<int> &nums) {
        std::vector<int> lis;
        lis.reserve(nums.size());
        for (const auto &num: nums) {
            if (lis.empty() || lis.back() < num) {
                lis.emplace_back(num);
            } else {
                auto it = std::upper_bound(lis.begin(), lis.end(), num);
                if (*it != num) {
                    *it = num;
                }
            }
        }
        return (int) lis.size();
    }
};

int main() {
    Problem300 problem;
    std::cout << Problem300::lengthOfLIS({0, 1, 0, 3, 2, 3});
    return 0;
}
