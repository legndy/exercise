#include <vector>
#include <iostream>

void quickSort(std::vector<int> &nums, int l, int r) {
    if (l < r) {
        int privot = nums[l], i = l + 1, j = r;
        while (i <= j) {
            while (i <= j && nums[j] > privot) {
                --j;
            }
            while (i <= j && nums[i] < privot) {
                ++i;
            }
            if (i >= j) {
                break;
            }
            std::swap(nums[i++], nums[j--]);
        }
        //因为right一定是停在从右到左第一个小于first的数上，交换之后，
		//依然能保证first值左边的比first小，右边的比first大
        std::swap(nums[j], nums[l]);
        quickSort(nums, l, j - 1);
        quickSort(nums, j + 1, r);
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

