#include <string>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

/**
 * @author Aleksandr Gavrikov
 * @url https://leetcode.com/problems/longest-ideal-subsequence/solutions/5083170/dynamic-programming-with-linear-complexity-beats-90-0-of-users-with-c/
 */
class Problem2115 {
public:
    std::vector<std::string>
    findAllRecipes(std::vector<std::string> &recipes, std::vector<std::vector<std::string>> &ingredients,
                   std::vector<std::string> &supplies) {
        std::unordered_map<std::string, size_t> recipe_index;
        for (size_t i = 0; i < recipes.size(); ++i) {
            recipe_index[recipes[i]] = i;
        }

        std::unordered_map<std::string, bool> cookable;
        for (auto supply: supplies) {
            cookable[supply] = true;
        }

        std::vector<std::string> result;

        std::function<bool(std::string)> dfs = [&](std::string item) {
            if (cookable.contains(item)) {
                return cookable[item];
            }

            cookable[item] = false;
            if (recipe_index.contains(item)) {
                for (auto ingredient: ingredients[recipe_index[item]]) {
                    if (!dfs(ingredient)) {
                        return false;
                    }
                }

                cookable[item] = true;
                return true;
            }

            return false;
        };

        for (auto recipe: recipes) {
            if (dfs(recipe)) {
                result.push_back(recipe);
            }
        }

        return result;
    }
};


int main() {
    Problem2115 solution;

    std::vector<std::string> recipes1 = {"bread"};
    std::vector<std::vector<std::string>> ingredients1 = {{"yeast", "flour"}};
    std::vector<std::string> supplies1 = {"yeast", "flour", "corn"};

    std::vector<std::string> result1 = solution.findAllRecipes(recipes1, ingredients1, supplies1);
    std::cout << "Recipes we can make (Example 1):\n";
    for (const auto& recipe : result1) {
        std::cout << recipe << std::endl;
    }

    // Пример 2
    std::vector<std::string> recipes2 = {"bread", "sandwich"};
    std::vector<std::vector<std::string>> ingredients2 = {{"yeast", "flour"}, {"bread", "meat"}};
    std::vector<std::string> supplies2 = {"yeast", "flour", "meat"};

    std::vector<std::string> result2 = solution.findAllRecipes(recipes2, ingredients2, supplies2);
    std::cout << "\nRecipes we can make (Example 2):\n";
    for (const auto& recipe : result2) {
        std::cout << recipe << std::endl;
    }

    // Пример 3
    std::vector<std::string> recipes3 = {"bread", "sandwich", "burger"};
    std::vector<std::vector<std::string>> ingredients3 = {{"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
    std::vector<std::string> supplies3 = {"yeast", "flour", "meat"};

    std::vector<std::string> result3 = solution.findAllRecipes(recipes3, ingredients3, supplies3);
    std::cout << "\nRecipes we can make (Example 3):\n";
    for (const auto& recipe : result3) {
        std::cout << recipe << std::endl;
    }

    return 0;
}