// Lab 1-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <time.h>
#include <Bits.h>
#include <iomanip>  
using namespace std;

void quicksort(int arr[], int size);
void quickleft(int arr[], int left, int right);
void quickright(int arr[], int left, int right);
int setpart(int arr[], int indexleft, int indexright, int pivot);
void swap_values(int& variable1, int& variable2);
void display(int arr[], int size);
void mergsort(int arr[], int brr[], int size);
void mergpart(int arr[], int brr[], int left, int right);
void mergging(int arr[], int brr[], int left, int mid, int right);

void main() {

	clock_t start, end, start2, end2;

	

	//create int size for size of array
	int size;
	//input size array
	cout << "Input your size of this >>" << endl;
	cin >> size;
	//create array arr and brr
	int* arr = new int[size];
	int* brr = new int[size];

	//create number in array
	cout << "Enter NUmber Here" << endl;

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	//display array
	display(arr, size);

	start = clock();
	quicksort(arr, size);
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	display(arr, size);
	cout << "Time taken by program is : " << fixed << time_taken << setprecision(7) << endl;
	start2 = clock();
	mergsort(arr, brr, size);
	end2 = clock();
	double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
	display(arr, size);
	cout << "Time taken by program is : " << fixed << time_taken2 << setprecision(7) << endl;


}
//function quick
void quicksort(int arr[], int size) {
	//create indexleft
	int indexleft = 0;
	//create indexright
	int indexright = size - 1;
	//create pivot
	int pivot = 0;
	//create indexpivot
	int indexpivot = 0;

	//check if size <1 if size = 1 not sort
	if (indexright - indexleft <= 0) {
		return;
	}
	else {
		//set pivot = indexright
		pivot = arr[size - 1];
		//find indexpivot in setpartfunction
		indexpivot = setpart(arr, indexleft, indexright, pivot);
		//quickleft
		quickleft(arr, indexleft, indexpivot - 1);
		//quickright
		quickright(arr, indexpivot + 1, indexright);

	}

}
//function quickright for recursion
void quickright(int arr[], int left, int right) {
	//create varriable look like upper
	int indexleft = left;
	int indexright = right;
	int pivot = 0;
	int indexpivot = 0;

	//check if size <1
	if (indexright - indexleft <= 0) {
		return;
	}
	else {
		//set pivot = indexright
		pivot = arr[right];
		//find indexpivot in setpartfunction
		indexpivot = setpart(arr, indexleft, indexright, pivot);
		//quickleft
		quickleft(arr, indexleft, indexpivot - 1);
		//quickright
		quickright(arr, indexpivot + 1, indexright);

	}


}
//function quickleft for recursion
void quickleft(int arr[], int left, int right) {
	//create varriable look like upper
	int indexleft = left;
	int indexright = right;
	int pivot = 0;
	int indexpivot = 0;

	//check if size <1
	if (indexright - indexleft <= 0) {
		return;
	}
	else {
		//set pivot = indexright
		pivot = arr[right];
		//find indexpivot in setpartfunction
		indexpivot = setpart(arr, indexleft, indexright, pivot);
		//quickleft
		quickleft(arr, indexleft, indexpivot - 1);
		//quickright
		quickright(arr, indexpivot + 1, indexright);

	}



}
//function setpart for indexpivot
int setpart(int arr[], int indexleft, int indexright, int pivot) {
	//setleft = index-1
	int setleft = indexleft - 1;
	//setrighr = right
	int setright = indexright;
	//loop for indexleft to indexright
	for (int i = indexleft; i < indexright; i++) {
		//if arr[i] lower than pivot
		if (arr[i] <= pivot) {
			//index setleft + 1
			setleft++;
			//then swap
			swap_values(arr[setleft], arr[i]);
		}

	}
	//swap between setleft and indexrighr
	swap_values(arr[setleft + 1], arr[indexright]);
	//return setleft + 1 that is indexpivot
	return setleft + 1;
}
//function for swap
void swap_values(int& variable1, int& variable2) {
	//create tempurary for store
	int temp;
	//temp = var1
	temp = variable1;
	//var1 = var2
	variable1 = variable2;
	//var2 = tmp
	variable2 = temp;
}
//function display
void display(int arr[], int size) {
	//display with for loop
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
//function for merge
void mergsort(int arr[], int brr[], int size) {
	//create index left, mid, and right
	int indexleft = 0;
	int indexright = size - 1;
	int indexmid = 0;
	//check if size <1
	if (indexright - indexleft <= 0) {
		return;
	}
	else {
		//define indexmid
		indexmid = (indexleft + indexright) / 2;
		//go to mergpart
		mergpart(arr, brr, indexleft, indexmid);
		//go to mergpart
		mergpart(arr, brr, indexmid + 1, indexright);
		//sum data
		mergging(arr, brr, indexleft, indexmid, indexright);


	}

}
//function to separate part
void mergpart(int arr[], int brr[], int left, int right) {
	//create mid
	int indexmid = 0;
	//check if size <1
	if (right - left <= 0) {
		return;
	}
	else {
		//define mid
		indexmid = (left + right) / 2;
		//recursion mergpart
		mergpart(arr, brr, left, indexmid);
		//recursion mergpart
		mergpart(arr, brr, indexmid + 1, right);
		//sum data
		mergging(arr, brr, left, indexmid, right);


	}

}
//function to mergging
void mergging(int arr[], int brr[], int left, int mid, int right) {
	//create n1, n2, i
	int n1, n2;
	int i;
	//loop for input brr
	for (n1 = left, n2 = mid + 1, i = left; n1 <= mid && n2 <= right; i++) {
		if (arr[n1] <= arr[n2])
			brr[i] = arr[n1++];
		else
			brr[i] = arr[n2++];
	}
	//define brr when n1 lower than mid
	while (n1 <= mid) {
		brr[i++] = arr[n1++];
	}
	//define brr when n2 lower than right
	while (n2 <= right) {
		brr[i++] = arr[n2++];
	}
	//define arr = brr
	for (i = left; i <= right; i++) {
		arr[i] = brr[i];
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
