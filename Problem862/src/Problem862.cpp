#include <vector>
#include <cassert>
#include <deque>

using std::vector;
using std::deque;

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
 */
class Problem862 {
public:
    static int shortestSubarray(vector<int>& nums, int k) {
        size_t n = nums.size();
        std::vector<long> prefix_sums(n + 1, 0);

        for (size_t index = 0; index < n; ++index) {
            prefix_sums[index + 1] = prefix_sums[index] + nums[index];
        }

        std::deque<size_t> deq;
        int min_length = INT_MAX;

        for (size_t right = 0; right < n + 1; ++right) {
            long prefix_sum = prefix_sums[right];

            while (!deq.empty() && prefix_sums[deq.back()] >= prefix_sum) {
                deq.pop_back();
            }
            deq.push_back(right);

            while (!deq.empty() && prefix_sum - prefix_sums[deq.front()] >= k) {
                min_length = std::min(min_length, static_cast<int>(right - deq.front()));
                deq.pop_front();
            }
        }
        return (min_length == INT_MAX ? -1 : min_length);
    }
};

int main() {
    Problem862 solver;

    // Тест 1: Пример из задачи
    {
        std::vector<int> nums = {84, -37, 32, 40, 95};
        int k = 167;
        assert(solver.shortestSubarray(nums, k) == 3); // Ожидаемый результат: длина подмассива [32, 40, 95]
    }

    // Тест 2: Отсутствие подходящего подмассива
    {
        std::vector<int> nums = {1, 2, 3};
        int k = 7;
        assert(solver.shortestSubarray(nums, k) == -1); // Нет подмассива с суммой >= k
    }

    // Тест 3: Массив с одним элементом
    {
        std::vector<int> nums = {5};
        int k = 5;
        assert(solver.shortestSubarray(nums, k) == 1); // Единственный элемент соответствует условию
    }

    // Тест 4: Отрицательные числа
    {
        std::vector<int> nums = {-1, -1, -1, 5};
        int k = 5;
        assert(solver.shortestSubarray(nums, k) == 1); // Только последний элемент
    }

    // Тест 5: Большой массив
    {
        std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int k = 15;
        assert(solver.shortestSubarray(nums, k) == 2); // Подмассив [7, 8]
    }
    return 0;
}
