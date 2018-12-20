#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] > nums[j]) {
                std::swap(nums[i], nums[j]);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 5, 7, 3 ,8, 3, 5, 6, 8, 11};
    int n = nums.size();
    std::cout << "Original Nums is" << std::endl;
    for (auto num : nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    bubbleSort(nums);
    std::cout << "Sorted Nums is" << std::endl;
    for (auto num : nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    return 0;
}