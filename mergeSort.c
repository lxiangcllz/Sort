//归并排序：
//将一个待排序数列一分二位，然后分别排序这两个子数列，最后把它们合并成一个有序数列。
//这个过程可以对两个子数列继续执行下去，直至分成两个分别只有一个元素的子数列为止。
//1，对左、右半边排序 
//2，把左右子数列合并成一个有序数列
//3，递归退出条件，如果 left >= right ,则已经排好数列 
//4，总共递归n次，每次的时间复杂度为log2(n)，所以总的时间复杂度为log2(n)*n

void merge(int *a, int left, int right) { //合并 
    int mid = (left + right)/2; 
    int len = right - left + 1;//数列元素个数 
    //int len = sizeof(a)/sizeof(a[0]); 
    int i = left;//遍历左边子数列 
    int j = mid + 1;//遍历右边子数列 
    int *buff = (int *)malloc(sizeof(int)*len); //辅助空间 
    int k = 0;//遍历辅助空间
    while(i<=mid && j<=right) { //当这个循环退出时说明左右两个子数列中必有一个已经遍历完
        if(a[i] < a[j]) {
            buff[k++] = a[i++];
        } else {
            buff[k++] = a[j++];
        }
    }
    if(i > mid) { //左边子数列已遍历完，则将右边子数列中的剩余元素全部拷贝到辅助空间中
        while(j <= right) {
            buff[k++] = a[j++];
        }
    } else { //右边子数列已遍历完，则将左边子数列中的剩余元素全部拷贝到辅助空间中
        while(i <= mid) {
            buff[k++] = a[i++];
        }
    }
    //将辅助空间中的元素全部搬移到原数组中，并将辅助空间free掉
    for(i=0; i<len; i++) { 
        a[left + i] = buff[i];
    }
    free(buff); //良好的编程习惯是在调用malloc函数申请辅助空间时就立即写上该free语句，以防最后忘记
}

void mergeSort(int *array, int left, int right) { //合并排序 
    if(left >= right) {
        return;
    }
    int mid = (left + right)/2;
    mergeSort(array, left, mid); //递归排序左边子数列 
    mergeSort(array, mid+1, right); //递归排序右边子数列 
    merge(array, left, right); //合并
} 

//在主函数中测试。也可单独写成一个测试函数void test()，然后在main函数中调用该test 函数
int main(int argc, char *argv[]) {
    int array[] = {1, 3, 2, 44, 32, 99, 103, 83, 1024, 15};
    int len = sizeof(array)/sizeof(array[0]);
    //swapSort(array, len); 
    //bubbleSort(array, len);
    mergeSort(array, 0, len-1);
    printf("array:\n");
    for(int i=0; i<len; i++) { //输出的是原排好序后的有序数组
        printf(" %d", array[i]);    
    }
    printf("\n");
    return 0;
}
