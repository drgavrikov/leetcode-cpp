#include <string>
#include <cassert>

using namespace std;

class Problem1702 {
public:
    string maximumBinaryString(string binary) {
        size_t firstZero = binary.find('0');
        if (firstZero == string::npos) return binary;

        size_t countZeros = count(binary.begin() + firstZero, binary.end(), '0');
        size_t countOnes = binary.length() - firstZero - countZeros;

        string result(firstZero, '1');
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
