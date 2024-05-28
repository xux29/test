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
    
// �������������
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--) //�Ӻ���ǰ�������з��ն˽ڵ�
        HeadAdjust(A, i, len);//������������ϵ��µģ���һ�����������µ��ϵ�
}

//����kΪ������������Ϊ�����
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k];//A[0]�ڱ�
    for (int i = 2 * k; i <= len;i*=2){//��key�ϴ���ӽ��ɸѡ
        if(i<len&&A[i]<A[i+1])
            i++;//ȡ�ϴ���ӽ����±�
        if(A[0]>=A[i])
            break;//�����������Ҫ���˳�ѭ��
        else{
            A[k] = A[i];//��A[i]�������������
            k = i; //�޸�kֵ����ɸѡ���ٴν���forѭ��
        }
    }
    A[k] = A[0];//���ڱ��е�Ԫ�ط�������λ��
}

//������
void HeapSort(int A[], int len)
{
    BuildMaxHeap(A, len);//������ʼ��
    for (int i = len; i > 1; i--){//n-1�˽����ͽ��ѵĹ���
        swap(&A[i], &A[1]);//�Ѷ�Ԫ�غͶѵ�Ԫ�ػ��� ���ֵ����ĩβ
        HeadAdjust(A, 1, i - 1); // ʣ��Ԫ������ɴ����
    }
}

int main(void)
{
    int a[] = {0 ,1 , 2, 3, 4, 2, 6, 3, 8, 9, 10};
    int len = (int) sizeof(a) / sizeof(*a);
    HeapSort(a, len - 1);
    for (int i = 1; i < len;i++){
        printf("%d ",a[i]);//���ص������������
    }
}