#include <iostream>
#include <vector>



void merge(std::vector<int> &nums, int start, int mid, int end, std::vector<int> &res);

void mergeSort(std::vector<int> &nums, int start, int end, std::vector<int> &res) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid, res);
        mergeSort(nums, mid + 1, end, res);
        merge(nums, start, mid, end, res);
    }
};

void merge(std::vector<int> &nums, int start, int mid, int end, std::vector<int> &res) {
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        res[k++] = nums[i] > nums[j] ? nums[j++] : nums[i++];
    }
    while (i <= mid) {
        res[k++] = nums[i++];
    }
    while (j <= end) {
        res[k++] = nums[j++];
    }
    for (k = start; k <= end; ++k) {
        nums[k] = res[k];
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 5, 7, 3 ,8, 3, 5, 6, 8, 11};
    int n = nums.size();
    std::cout << "Original Nums is" << std::endl;
    for (auto num : nums) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    std::vector<int> res;
    mergeSort(nums, 0, n - 1, res);
    std::cout << "Sorted Nums is" << std::endl;
    for (auto num : res) {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    return 0;
}