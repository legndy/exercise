#include <vector>
#include <iostream>

void quickSort(std::vector<int> &nums, int l, int r) {
    if (l < r) {
        int i = l, j = r, x = nums[i];
        while (i < j) {
            while (i < j && nums[j] > x) {
                --j;
            }
            if (i < j) {
                //std::swap(nums[i++], nums[j]);
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] < x) {
                ++i;
            }
            if (i < j) {
                //std::swap(nums[i], nums[j--]);
                nums[j--] = nums[i];
            }
        }
        nums[i] = x;
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
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
    quickSort(nums, 0, n - 1);
    std::cout << "Sorted Nums is" << std::endl;
    for (auto num : nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    return 0;
}

