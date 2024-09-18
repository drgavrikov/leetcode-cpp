#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/largest-number/solutions/5786699/solution-with-number-rearranging/
 */

class Problem179 {
public:
    static std::string largestNumber(std::vector<int> &nums) {

        std::vector<std::string> stringNums;
        stringNums.reserve(nums.size());
        std::transform(nums.begin(), nums.end(), std::back_inserter(stringNums),
                       [](int num) {
                           return std::to_string(num);
                       }
        );

        std::sort(stringNums.begin(), stringNums.end(), [](const std::string &s1, const std::string &s2) {
            return s1 + s2 > s2 + s1;
        });

        if (stringNums[0] == "0") {
            return "0";
        }

        std::string result;
        result.reserve(
                std::accumulate(stringNums.begin(), stringNums.end(), 0,
                                [](size_t acc, const std::string &num) {
                                    return acc + num.length();
                                }
                )
        );
        return std::accumulate(stringNums.begin(), stringNums.end(), std::move(result),
                               [](const std::string &acc, const std::string &num) {
                                   return acc + num;
                               }
        );
    }
};

int main() {

    Problem179 problem;
    std::vector<int> nums = {3, 30, 34, 5, 9};
    assert(problem.largestNumber(nums) == "9534330");

    return 0;
}