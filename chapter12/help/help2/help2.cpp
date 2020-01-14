#include <iostream>
using namespace std;
#define Maxsize 100000
int LIS(int *arr, int n, int *max_ref)
{
	if (n == 1) return 1;
	int res, longest_here = 1;

	for (int i = 1; i<n; ++i)
	{
		res = LIS(arr, i, max_ref);
		if (arr[i - 1]<arr[n - 1] && res + 1>longest_here)
			longest_here = res + 1;
	}

	if (*max_ref < longest_here)
		*max_ref = longest_here;

	return longest_here;
}

int main()
{
	int arr[Maxsize];
	int num;
	int i = 0;
	while (cin >> num) {
		arr[i] = num;
		i++;
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	int max = 1;
	LIS(arr, n, &max);
	cout << max << endl;
	return 0;
}