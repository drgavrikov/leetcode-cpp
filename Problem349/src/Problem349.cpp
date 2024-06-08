#include <vector>
#include <unordered_set>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/intersection-of-two-arrays/solutions/5265597/set-intersection/
 */
class Problem349 {
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::unordered_set<int> unique2(nums2.begin(), nums2.end());

        std::vector<int> result;
        for (auto num: nums1) {
            if (unique2.count(num) > 0) {
                result.push_back(num);
                unique2.erase(num);
            }
        }
        return result;
    }
};

int main() {
    Problem349 problem;
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> result = {2};
    assert(problem.intersection(nums1, nums2) == result);
    return 0;
}