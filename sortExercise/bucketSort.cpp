#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(std::vector<int> &nums) {
    int n = nums.size();
    int mx = *(std::max_element(nums.begin(), nums.end()));
    std::vector<int> bucket(mx + 1, 0);
    for (auto num : nums) {
        ++bucket[num];
    }
    nums.clear();
    for (int i = 0; i < mx + 1; ++i) {
        while (bucket[i]-- > 0) {
            nums.push_back(i);
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
    bucketSort(nums);
    std::cout << "Sorted Nums is" << std::endl;
    for (auto num : nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    return 0;
}