#include<iostream>

using namespace std;

int findMedian(int a[], int n);

int findMedian(int a[], int n, int x);

int findMedian(int a[], int n, int x, int y);

int main()
{
	int a[] = { 0,10,20,30,40,50,60,70,80,90,100 };
	int n = 11;
	cout << "배열의 중앙값: " << findMedian(a, n) << endl;
	cout << "배열 0에서 6사이의 중앙값: " << findMedian(a, n, 10) << endl;
	cout << "배열 1에서 7사이의 중앙값: " << findMedian(a, n, 3, 4) << endl;
	return 0;
}

int findMedian(int a[], int n) {
	int m ;
	m = n / 2;
	return a[m+1];
}

int findMedian(int a[], int n, int x) {
	int m = 0;
	m = x / 2;
	return a[m];
}

int findMedian(int a[], int n, int x, int y) {
	int m = 0;
	m = (y - x)/2 + x;
	return a[m];
}