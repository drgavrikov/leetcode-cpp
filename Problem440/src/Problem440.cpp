#include <cassert>
#include <numeric>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/solutions/5821842/ounting-tree/
 */
class Problem440 {

public:
    static long countStepsInSubtree(long n, long current) {
        long steps = 0;
        long next = current + 1;
        while (current <= n) {
            steps += std::min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return steps;
    }

    static long findKthNumber(long n, long k) {
        long current = 1;
        k--;
        while (k > 0) {
            long steps = countStepsInSubtree(n, current);
            if (steps <= k) {
                k -= steps;
                current++;
            } else {
                k--;
                current *= 10;
            }
        }
        return current;
    }
};

int main() {
    Problem440 problem;
    assert(problem.findKthNumber(13, 2) == 10);
    return 0;
}
