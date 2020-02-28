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


void TowerOfHanoi(int n, char src, char des, char aux){
	if(n == 0)return;

	TowerOfHanoi(n-1, src, aux, des);

	cout << "Move " << n <<" disk from "<<src <<" to "<<des <<"\n";

	TowerOfHanoi(n-1, src, des, aux);
}

void merge(int *a, int s, int e){
	int mid = (s+e)/2;

	int j = s;
	int k = mid +1;
	int te = s;
	
	int temp[100];

	while(j <= mid && k <= e){
		if(a[j] < a[k])
			temp[te++] = a[j++];
		else temp[te++] = a[k++];
	}
	while(j <= mid){
		temp[te++] = a[j++];
	}
	while(k <= e){
		temp[te++] = a[k++];
	}


	for(int i = s; i <= e; i++)
		a[i] = temp[i];
}

void mergeSort(int *a, int s, int e){
	// base case when there are 1 or 0 elements
	if(s >= e)return;

	// Now dividing
	int mid = (s+e)/2;


	mergeSort(a, s, mid);
	mergeSort(a, mid+1, e);

	//now to merge

	merge(a, s, e);



}




int main() {

	return 0;
}
