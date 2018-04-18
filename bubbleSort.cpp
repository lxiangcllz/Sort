//冒泡排序
//每轮排序从首位置元素开始与相邻的下一元素比较，
//若比下一元素大，则二者交换位置，否则不交换，
//直至倒数第二个位置上的元素与尾元素作完比较，
//这样一轮冒泡比较下来就将最大的元素放在了最后一个位置上；
//接着进行下一轮排序，就把次最大元素放在了倒数第二个位置上；
//以此类推，直至第一个位置上的元素为最小元素。
//注意，若在若干轮的排序过程中出现某一轮排序中一次也没有发生过相邻两元素之间的交换，
//则说明所有的元素此时已经全部从头到尾按从小到大排好序，因此整个的冒泡排序过程没必要再进行下去，可以结束了。
//那么，可以声明一个变量 flag 初始化为0，
//若发生交换则置为1，在每轮冒泡比较完之后检查 flag 的值，若仍为0，则直接 break 退冒泡排序循环过程，
//否则重新置为 0，开始下一轮冒泡比较过程。
//C版本
void bubbleSort(int *a, int len) { //冒泡排序,总共最多比较1+2+...+(len-1)次，时间复杂度为o(n*n),而最理想情况下为o(n) 
    int flag = 0;
    for(int i=0; i<len-1; i++){
        flag = 0;
        for(int j=0; j<len-i-1; j++){
            if(a[j] > a[j+1]) { //此处若改为判断 a[j] < a[j+1]，则整个冒泡排序的结果为从大到小排序
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1; 
            }
        }
        if(flag = 0) { //这一趟没有交换，说明剩余元素已有序，无需再循环比较下去 
            return;
        }
    }
} 

//C++版本
#include <iostream>

using namespace std;

// template<class T>
// void bubble(T a[], int n) {
// 	for(int i = 0; i < n-1; i++) {
// 		if(a[i] > a[i+1]) swapNumber(a[i], a[i+1]);
// 	}
// }
// template<class T>
// void bubbleSort(T a[], int n) {
// 	for(int i = n; i > 1; i--) {
// 		bubble(a, i);
// 	}
// }

//优化一下：检查数组秩序，如果已有序就及时终止迭代
template<class T>
bool bubble(T a[], int n) { 
	bool swapped = false;
	for(int i = 0; i < n-1; i++) {
		if(a[i] > a[i+1]) {
			swapNumber(a[i], a[i+1]);
			swapped = true;
		}
	}
	return swapped;
}
template<class T>
void bubbleSort(T a[], int n) {
	for(int i = n; i > 1 && bubble(a, i); i--);
}


int main() {
	double a[] = {1.2, 2.3, 3.4, 3.2, 2.11, 0.99, 1.33};
	int number = sizeof(a) / sizeof(a[0]);
	cout << "Number is :" << number << endl;

	bubbleSort(a, number);

	cout << "After the rearrangement, the array a is : ";
	for(int i = 0; i < number; i++) {
		cout << a[i] << '\t';
	}

	return 0;
}
