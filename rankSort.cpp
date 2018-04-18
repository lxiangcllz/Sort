//排列排序

#include <iostream>

using namespace std;

template<class T>
void swapNumber(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
void rankArray(T a[], int n, int r[]) {
	for(int k = 0; k < n; k++) {
		r[k] = 0;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(a[j] <= a[i]) r[i]++;
			else r[j]++;
		}
	}
}

// template<class T>
// void rearrange(T a[], int n, int r[]) {
// 	T *u = new T[n];
// 	for(int i = 0; i < n; i++) {
// 		u[r[i]] = a[i];
// 	}


// 	for(int i = 0; i < n; i++) {
// 		a[i] = u[i];
// 	}

// 	delete [] u;
// }

template<class T> 
void rearrange(T a[], int n, int r[]) { //原地重排
	for(int i = 0; i < n; i++) {
		while(r[i] != i) {
			int t = r[i];
			swapNumber(a[i], a[t]);
			swapNumber(r[i], r[t]);
		}
	}
}

int main() {
	double a[] = {1.2, 2.3, 3.4, 3.2, 2.11, 0.99, 1.13};
	int number = sizeof(a) / sizeof(a[0]);
	cout << "Number is :" << number << endl;

	int r[number] = {0};

	rankArray(a, number, r);
	rearrange(a, number, r);

	cout << "After the rearrangement, the array a is : ";
	for(int i = 0; i < number; i++) {
		cout << a[i] << '\t';
	}

	return 0;
}
