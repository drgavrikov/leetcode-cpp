#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 */

class Problem215 {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        for (int num: nums) {
            queue.push(num);
            if (queue.size() > k) {
                queue.pop();
            }
        }
        return queue.top();
    }
};

int main() {

    Problem215 problem;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    assert(problem.findKthLargest(nums, 2) == 5);

    return 0;
}
