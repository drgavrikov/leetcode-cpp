#include <string>
#include <cassert>

class Problem1702 {
public:
    std::string maximumBinaryString(std::string binary) {
        size_t firstZero = binary.find('0');
        if (firstZero == std::string::npos) return binary;

        auto countZeros = static_cast<size_t>(std::count(std::next(binary.begin(), (int) firstZero), binary.end(), '0'));
        auto countOnes = static_cast<size_t>(binary.length() - firstZero - countZeros);

        std::string result(firstZero, '1');
        result.append(countZeros - 1, '1');
        result.push_back('0');
        result.append(countOnes, '1');

        return result;
    }
};

int main() {
    Problem1702 problem1702;
    assert(problem1702.maximumBinaryString("000110") == "111011");
    return 0;
}
