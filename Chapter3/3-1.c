#include <stdio.h>

int binsearch (int x, int v[], int n);

int main () {
	int buffer[10] = {4,5,6,7,8,9,10,11,12,13};
	int ind = binsearch(10, buffer, 10);
	printf("Index of 10 in array is %d \n", ind);

	return 0;
}

int binsearch (int x, int v[], int n){
	int low, mid, high;

	low = 0;
	high = n - 1;

	while (low <= high && x != v[low]){
		mid = (low + high)/2;
		if (x < v[mid]){
			high = mid - 1;
		}

		else low = mid; 
	}

	if (x == v[low]){
		return low;
	}

	return -1; 

}