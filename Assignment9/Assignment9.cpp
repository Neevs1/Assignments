// Max Heap in C++
  
   #include <iostream>
   using namespace std;
  
   void heapify(int arr[], int n, int i) {
 	// Find largest among root, left child and right child
 	int largest = i;
 	int left = 2 * i + 1;
 	int right = 2 * i + 2;
  
 	if (left < n && arr[left] > arr[largest])
   	largest = left;
  
 	if (right < n && arr[right] > arr[largest])
   	largest = right;
  
 	// Swap and continue heapifying if root is not largest
 	if (largest != i) {
   	swap(arr[i], arr[largest]);
       heapify(arr, n, largest);
 	}
   }
  
   // main function to do heap sort
   void heapSort(int arr[], int n) {
 	// Build max heap
 	for (int i = n / 2 - 1; i >= 0; i--)
   	heapify(arr, n, i);
  
 	// Heap sort
 	for (int i = n - 1; i >= 0; i--) {
   	swap(arr[0], arr[i]);
  
   	// Heapify root element to get highest element at root again
   	heapify(arr, i, 0);
 	}
   }
  
   // Print an array
   void printArray(int arr[], int n) {
 	for (int i = 0; i < n; ++i)
   	cout << arr[i] << " ";
 	cout << "\n";
   }
  
   // Driver code
   int main() {
 	int n;
	cout<<"Enter length of array: "<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 	heapSort(arr, n);
  
 	cout << "Sorted array is \n";
 	printArray(arr, n);
   }
  
/*
Output:
Enter length of array: 
5
Enter element 1: 34
Enter element 2: 23
Enter element 3: 65
Enter element 4: 76
Enter element 5: 3
Sorted array is
3 23 34 65 76

*/
