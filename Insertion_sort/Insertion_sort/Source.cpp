#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#define LENGTH 10000
using namespace std;

void createRandFile() {
	ofstream mfile("unsortedFile.txt");
	srand(time(0));

	for (int i = 0; i < LENGTH; i++) {
		mfile << ((rand() % LENGTH) + 1) << endl;
	}
}

void readFile(int arr[], int l) {
	ifstream mfile("unsortedFile.txt");
	for (int i = 0; i < l; i++) {
		mfile >> arr[i];
	}
}

int insertionSort(int arr[], int len) {
	int step = 0;
	for (int i = 1; i < len; i++) {
		int key = arr[i];
		step++;
		int j = i - 1;
		step++;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			step++;
			j--;
			step++;
		}
		arr[j + 1] = key;
		step++;
	}
	return step;
}

void createSortedFile(int arr[]) {
	ofstream mfile("sortedFile.txt");

	for (int i = 0; i < LENGTH; i++) {
		mfile << arr[i] << endl;
	}
}

bool testSortedFile() {
	int arr[LENGTH];
	ifstream mfile("sortedFile.txt");
	for (int i = 0; i < LENGTH; i++) {
		mfile >> arr[i];
	}
	for (int i = 0; i < LENGTH - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

int main() {
	int arr[LENGTH];
	createRandFile();
	readFile(arr, LENGTH);

	ofstream sFile("stepFile.txt");
	int x[LENGTH];

	for (int i = 10; i < 10000; i += 50) {
		for (int j = 0; j < i; j++) {
			x[j] = arr[j];
		}
		sFile << i << ',' << insertionSort(x, i) << endl;
	}

	sFile << 10000 << ',' << insertionSort(arr, 10000) << endl;

	createSortedFile(arr);
	if (testSortedFile())
		cout << "Test for sort is succesful" << endl;
	else
		cout << "Test for sort is not succesful" << endl;

	system("pause");
	return 0;
}

