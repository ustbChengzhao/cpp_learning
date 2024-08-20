#include<iostream>
using namespace std;

int randomAccess(int* nums, int size) {
    int randomIndex = rand() * size;
    int randomNum = nums[randomIndex];

    return randomNum;
}
int main() {
    /* 1.初始化数组 */
    // 存储在栈上
    int arr[5];
    int nums[5] = {1, 2, 3, 4, 5};

    // 存储在堆上
    int* arr1 = new int[5];
    int* nums1 = new int[5];


    /* 2.访问元素 */
    std::cout << randomAccess(nums, 5) << endl;;

    return 0;
}