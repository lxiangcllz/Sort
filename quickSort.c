//利用递归实现快速排序：

#include <stdio.h>

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

#define N 10

int main(int argc, char *argv[]) {
    int a[N]; 
    printf("Enter %d numbers to be sorted: ", N);
    for(int i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, N-1);
    printf("In sorted order: ");

    for(int i=0; i<N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void quicksort(int a[], int low, int high) {
    int middle;

    if(low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle-1);
    quicksort(a, middle+1, high);
}

int split(int a[], int low, int high) { //找到分割元素的正确位置
    int part_num = a[low];

    for(;;) {
        while(low < high && part_num <= a[high]) {
            high--;
        }
        if(low >= high) break;
        a[low] = a[high];
        low++;

        while(low < high && a[low] <= part_num) {
            low++;
        }
        if(low >= high) break;
        a[high] = a[low];
        high--;
    }
    a[low] = part_num;
    return low; //这两句中low 换成high 亦可，因为此时它们相同
}
