#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) ;
void BuildMaxHeap(int A[], int len);
void HeadAdjust(int A[], int k, int len);
void HeapSort(int A[], int len);


void swap(int* a, int* b) 
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
    
// 建立大根堆排序
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--) //从后往前调整所有非终端节点
        HeadAdjust(A, i, len);//这个函数是由上到下的，上一步调用是有下到上的
}

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k];//A[0]哨兵
    for (int i = 2 * k; i <= len;i*=2){//沿key较大的子结点筛选
        if(i<len&&A[i]<A[i+1])
            i++;//取较大的子结点的下标
        if(A[0]>=A[i])
            break;//如果满足大根堆要求，退出循环
        else{
            A[k] = A[i];//将A[i]调整到父结点上
            k = i; //修改k值向下筛选，再次进入for循环
        }
    }
    A[k] = A[0];//把哨兵中的元素放入最终位置
}

//堆排序
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);//建立初始堆
    for (int i = len; i > 1; i--){//n-1趟交换和建堆的过程
        swap(&A[i], &A[1]);//堆顶元素和堆底元素互换 最大值放在末尾
        HeadAdjust(A, 1, i - 1); // 剩余元素整理成大根堆
    }
}

int main(void)
{
    int a[] = {0 ,1 , 2, 3, 4, 2, 6, 3, 8, 9, 10};
    int len = (int) sizeof(a) / sizeof(*a);
    HeapSort(a, len - 1);
    for (int i = 1; i < len;i++){
        printf("%d ",a[i]);//返回的排序是逆序的
    }
}