/**
 * @Author: Max
 * @Time: 9/16/21 14:21
 */

#include<iostream>
using namespace std;

/**
 * 暴力解法
 */
//int MaxSubsequenceSum(const int array[], int n)
//{
//    int tempSum, maxSum;
//    maxSum = 0;
//    for (int i = 0;i < n;i++)       // 子序列起始位置
//    {
//        for (int j = i;j < n;j++)   // 子序列终止位置
//        {
//            tempSum = 0;
//            for (int k = i;k < j;k++)   // 子序列遍历求和
//                tempSum += array[k];
//            if (tempSum > maxSum)       // 更新最大和值
//                maxSum = tempSum;
//        }
//    }
//    return maxSum;
//}
//
//int main()
//{
//    const int a[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
//    int maxSubSum = MaxSubsequenceSum(a, 8);
//    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
//    system("pause");
//    return 0;
//}

/**
* 暴力解法优化
*/
//int MaxSubsequenceSum(const int array[],int n)
//{
//    int tempSum, maxSum;
//    maxSum = 0;
//    for (int i = 0;i < n;i++)
//    {
//        tempSum = 0;
//        for (int j = i;j < n;j++)
//        {
//            tempSum += array[j];
//            if (tempSum > maxSum)
//                maxSum = tempSum;
//        }
//    }
//    return maxSum;
//}
//
//int main()
//{
//    const int a[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
//    int maxSubSum = MaxSubsequenceSum(a, 8);
//    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
//    system("pause");
//    return 0;
//}

/**
* 递归分治
*/
//int max3(int a, int b, int c)           // 求三个数的最大值
//{
//    int max = a;
//    if (b > max)
//        max = b;
//    if (c > max)
//        max = c;
//    return max;
//}
//
//int MaxSubsequenceSum(const int array[], int left, int right)
//{
//    if (left == right)          // 设置基准，即递归终止条件
//        return array[left];
//
//    int middle = (left + right) / 2;
//
//    int leftMaxSubsequenceSum = MaxSubsequenceSum(array, left, middle);     // 求左半部分最大子序列和
//    int rightMaxSubsquenceSum = MaxSubsequenceSum(array, middle + 1, right);    // 求右半部分最大子序列和
//
//    // 处理左右边界问题：最大子序列跨越中间，包含左半部分最右一个数，同时包含右半部分最左一个数
//    int maxLeftBorderSum = 0;
//    int maxRightBorderSum = 0;
//    int tempSum = 0;        // 临时求和变量
//    for (int i = middle;i >= left;i--)
//    {
//        tempSum += array[i];
//        if (tempSum > maxLeftBorderSum)
//            maxLeftBorderSum = tempSum;     // 左边包含边界最大序列和
//    }
//    tempSum = 0;
//    for (int i = middle + 1;i < right;i++)
//    {
//        tempSum += array[i];
//        if (tempSum > maxRightBorderSum)
//            maxRightBorderSum = tempSum;    // 右边包含边界最大序列和
//    }
//
//    int maxBorderSum = maxRightBorderSum + maxLeftBorderSum;        // 最大边界子序列和等于两部分边界之和
//    return max3(leftMaxSubsequenceSum, maxBorderSum, rightMaxSubsquenceSum);         // 返回三个部分的最大子序列和
//}
//
//int main() {
//    const int a[] = {4, -3, 5, -2, -1, 2, 6, -2};
//    int maxSubSum = MaxSubsequenceSum(a, 0, 7);
//    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
//    system("pause");
//    return 0;
//}

/**
* 动态规划
*/
int MaxSubsequenceSum(const int A[], int n)
{
    int tempSum = 0;
    int maxSum = 0;
    for (int j = 0;j < n;j++)   // 子问题后边界
    {
        tempSum = (tempSum + A[j]) > A[j] ? (tempSum + A[j]) : A[j];
        if (tempSum > maxSum)   // 更新最大和
            maxSum = tempSum;

    }
    return maxSum;
}

int main()
{
    const int a[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int maxSubSum = MaxSubsequenceSum(a, 8);
    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
    system("pause");
    return 0;
}
