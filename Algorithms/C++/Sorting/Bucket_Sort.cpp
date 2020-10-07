/*  ALGORITHM :-
bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.
*/

// C++ program to sort an array using bucket sort 
#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 

// Function to sort arr[] of size n using bucket sort 
void bucketSort(float arr[], int n) 
{ 
	// 1) Create n empty buckets 
	vector<float> b[n]; 

	// 2) Put array elements in different buckets 
	for (int i = 0; i < n; i++) { 
		int bi = n * arr[i]; // Index in bucket 
		b[bi].push_back(arr[i]); 
	} 

	// 3) Sort individual buckets 
	for (int i = 0; i < n; i++) 
		sort(b[i].begin(), b[i].end()); 

	// 4) Concatenate all buckets into arr[] 
	int index = 0; 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < b[i].size(); j++) 
			arr[index++] = b[i][j]; 
} 

// Driver program : 
int main() 
{ 
	int n;
  cin >> n;
  float arr[n];
  for (int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
	bucketSort(arr, n); 

	cout << "Sorted array is \n"; 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 
