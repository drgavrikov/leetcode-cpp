#include <cassert>
#include <vector>
#include <algorithm>

class Problem75 {
public:
    void sortColors(std::vector<int>& nums) {
        auto pointer0 = nums.begin();
        auto pointer2 = nums.end() - 1;
        
        auto current = nums.begin();
        while (current <= pointer2) {
            if (*current == 0) {
                std::swap(*current++, *pointer0++);
            } else if (*current == 2) {
                std::swap(*current, *pointer2--);
            } else {
                current++;
            }
        }
    }
};

int main() {
    Problem75 problem;

    std::vector<int> test1 = {2, 0, 2, 1, 1, 0};
    std::vector<int> expected1 = {0, 0, 1, 1, 2, 2};
    problem.sortColors(test1);
    assert(test1 == expected1);
    
    std::vector<int> test2 = {2, 0, 1};
    std::vector<int> expected2 = {0, 1, 2};
    problem.sortColors(test2);
    assert(test2 == expected2);

    return 0;
}
