#include <bits/stdc++.h>
using namespace std;

int multiply(int a, int b){
	if(b == 0)
		return 0;
	int mul = multiply(a, b-1) + a;
	return mul;
}

int StringToInt(string str){
	if(str.size() == 1)
		return (str[0]-'0');
	double y = StringToInt(str.substr(1));
	double x = str[0] - '0';
	x = x*pow(10, str.length() - 1) + y;
	return int(x);
}
int solveTiles(int n){
	if(n == 0)return 0;
	if(n<=4)
		return 1;
	int ans = solveTiles(n-1) + solveTiles(n-4);
	return ans;
}
int lin_search(int *a, int i, int key, int n){
	if(i == n)return -1;
	
	if(a[i] == key)return i; 
	
	return lin_search(a, i+1, key, n);
	
}
int bin_search(int *a, int l, int r, int key){
	int mid;
	if(r >= l){
		mid = l + ((r-l)/2);
		if(a[mid] == key)
			return mid;
		if(a[mid] > key)
			return bin_search(a, l, mid -1, key);
		return bin_search(a, mid+1, r, key);
	}
	return -1;

}

void BubbleSort(int *a, int id, int n){
	if(n == 0)return;
	for(int i = id; i < n-1; i++){
		if(a[i] > a[i+1])swap(a[i], a[i+1]);
	}
	BubbleSort(a, id, n-1);
}




int main() {
	int arr[5] = {1, 2, 12, 13, 1};
	BubbleSort(arr, 0, 5);
	for(int i = 0; i < 5; i++)cout << arr[i] <<" ";
	return 0;
}