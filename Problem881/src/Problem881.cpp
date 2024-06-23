#include <algorithm>
#include <vector>
#include <cassert>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/boats-to-save-people/solutions/5358475/two-pointer-solution/
 */
class Problem881 {
public:
    int numRescueBoats(std::vector<int> &people, int limit) {
        std::sort(people.begin(), people.end());

        int result = 0;

        size_t begin = 0;
        size_t end = people.size() - 1;
        while (begin <= end) {
            if (people[begin] + people[end] <= limit) {
                begin++;
                end--;
            } else {
                end--;
            }
            result++;
        }
        return result;
    }
};

int main() {
    Problem881 problem;
    std::vector<int> people = {3, 2, 2, 1};
    assert(problem.numRescueBoats(people, 3) == 3);
    return 0;
}