#include <stdio.h>
#include <stdlib.h>


//A[low...mid]和A[mid+1...high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    int *B = (int *) malloc (10*sizeof(int));//辅助数组B
    for (k = low; k <= high; k++)
        B[k] = A[k]; //将A中的元素复制到B
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high;k++){
        if(B[i] <= B[j]) //两个元素相等时优先使用靠前那个（稳定性）
            A[k] = B[i++];  //将较小值复制到A中
        else
            A[k] = B[j++];
    }
    //一边已经合并完，直接遍历另一边剩下的序列
    while(i<=mid)
        A[k++] = B[i++];
    while(j<=high)
        A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high)
{
    if(low < high){
        int mid = (low + high) / 2;//从中间划分
        MergeSort(A, low, mid);//对左半部分排序
        MergeSort(A, mid + 1, high);//对右半部分排序
        Merge(A, low, mid, high);//归并
    }
}
int main(void)
{
    int A[] = {0 ,1 , 2, 3, 4, 2, 6, 3, 8, 9, 10};
    int len = (int) sizeof(A) / sizeof(*A);
    MergeSort(A, 0, len-1);
    for (int i = 0; i < len;i++){
        printf("%d ",A[i]);
    }
}
