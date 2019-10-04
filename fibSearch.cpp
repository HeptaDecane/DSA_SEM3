// C program for Fibonacci Search 
#include <stdio.h> 

// Utility function to find minimum of two elements 
int min(int x, int y) { return (x<=y)? x : y; } 

/* Returns index of x if present, else returns -1 */
int fib0onaccianSearch(int arr[], int x, int n) 
{ 
	/* Initialize fibonacci numbers */
	int fib2 = 0; // (m-2)'th Fibonacci No. 
	int fib1 = 1; // (m-1)'th Fibonacci No. 
	int fib0 = fib2 + fib1; // m'th Fibonacci 

	/* fib0 is going to store the smallest Fibonacci 
	Number greater than or equal to n */
	while (fib0 < n) 
	{ 
		fib2 = fib1; 
		fib1 = fib0; 
		fib0 = fib2 + fib1; 
	} 

	// Marks the eliminated range from front 
	int offset = -1; 

	/* while there are elements to be inspected. Note that 
	we compare arr[fib0m2] with x. When fib0 becomes 1, 
	fib0m2 becomes 0 */
	while (fib0 > 1) 
	{ 
		// Check if fib0m2 is a valid location 
		int i = min(offset+fib2, n-1); 

		/* If x is greater than the value at index fib0m2, 
		cut the subarray array from offset to i */
		if (arr[i] < x) 
		{ 
			fib0 = fib1; 
			fib1 = fib2; 
			fib2 = fib0 - fib1; 
			offset = i; 
		} 

		/* If x is greater than the value at index fib0m2, 
		cut the subarray after i+1 */
		else if (arr[i] > x) 
		{ 
			fib0 = fib2; 
			fib1 = fib1 - fib2; 
			fib2 = fib0 - fib1; 
		} 

		/* element found. return index */
		else return i; 
	} 

	/* comparing the last element with x */
	if(fib1 && arr[offset+1]==x)return offset+1; 

	/*element not found. return -1 */
	return -1; 
} 

/* driver function */
int main(void) 
{ 
	int arr[] = {10, 22, 35, 39,40, 45, 50, 80, 82, 
				85, 90, 100}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int x = 85; 
	printf("Found at index: %d", 
			fib0onaccianSearch(arr, x, n)); 
	return 0; 
} 

