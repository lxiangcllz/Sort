//选择排序
//思路与交换排序相同，
//差异在于每轮比较时，有一个变量 minIndex 记录该轮比较中的最小元素的下标，
//最后将minIndex记录的下标值对应的元素与待排序位置上的元素交换。以此类推。

#include <istream>
#include <string>

using namespace std;

class illegalParameterValue { //异常参数类
public:
	illegalParameterValue() : message("Illegal parameter value") {}
	illegalParameterValue(char * theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		cout << message << endl;
	}
private:
	string message;
};

template<class T>
void swapNumber(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
int indexOfMax(T a[], int n) {
	if (n <= 0) {
		throw illegalParameterValue("n must be > 0");
	}

	int indexOfMax = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[indexOfMax]) indexOfMax = i;
	}
	return indexOfMax;
}

// template<class T>
// void selectionSort(T a[], int n) {
// 	for(int size = n; size > 1; size--) {
// 		int j = indexOfMax(a, size);
// 		swapNumber(a[j], a[size-1]);
// 	}
// }

template<class T>
void selectionSort(T a[], int n) { //如果数组已经有序，就及时终止迭代
	bool sorted = false;
	for(int size = n; !sorted && (size > 1); size--) {
		int indexOfMax = 0;
		sorted = true;

		for(int i = 1; i < size; i++) {
			if(a[indexOfMax] <= a[i]) indexOfMax = i;
			else sorted = false;
		}
		swapNumber(a[indexOfMax], a[size-1]);
	}
}

int main() {
	double a[] = {1.2, 2.3, 3.4, 3.2, 2.11, 0.99, 1.23};
	int number = sizeof(a) / sizeof(a[0]);
	cout << "Number is :" << number << endl;

	selectionSort(a, number);

	cout << "After the rearrangement, the array a is : ";
	for(int i = 0; i < number; i++) {
		cout << a[i] << '\t';
	}

	return 0;
}
