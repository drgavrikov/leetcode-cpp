#include <cassert>
#include <vector>
#include <deque>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/continuous-subarrays/submissions/1478693751/?envType=daily-question&envId=2024-12-14
 */
class Problem2762 {
public:
    static long long continuousSubarrays(std::vector<int>& nums) {
        long long result = 0LL;
        size_t lf = 0;
        std::deque<size_t> deque_min, deque_max;

        for (size_t rt = 0; rt < nums.size(); ++rt) {
            int value = nums[rt];
            while (!deque_min.empty() && nums[deque_min.back()] >= value) {
                deque_min.pop_back();
            }
            deque_min.push_back(rt);

            while (!deque_max.empty() && nums[deque_max.back()] <= value) {
                deque_max.pop_back();
            }
            deque_max.push_back(rt);

            while (nums[deque_max.front()] - nums[deque_min.front()] > 2) {
                if (lf == deque_min.front()) {
                    deque_min.pop_front();
                }
                if (lf == deque_max.front()) {
                    deque_max.pop_front();
                }
                lf++;
            }
            result += static_cast<long long>(rt - lf + 1);
        }
        return result;
    }
};

int main() {
    Problem2762 problem;
    std::vector<int> nums1 = {2, 2, 2, 2};
    assert(problem.continuousSubarrays(nums1) == 10);
    std::cout << "Test 1 passed!" << std::endl;

    std::vector<int> nums2 = {5, 4, 2, 4};
    assert(Problem2762::continuousSubarrays(nums2) == 8);
    std::cout << "Test 2 passed!" << std::endl;

    std::vector<int> nums3 = {1, 2, 3};
    assert(Problem2762::continuousSubarrays(nums3) == 6);
    std::cout << "Test 3 passed!" << std::endl;
    return 0;
}
