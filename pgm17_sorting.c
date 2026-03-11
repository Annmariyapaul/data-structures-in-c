//SORTING
#include <stdio.h>
int a[20], b[20], n, i;
void heapify(int arr[], int n, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest])
largest = left;
if (right < n && arr[right] > arr[largest])
largest = right;
if (largest != i)
{
int temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;
heapify(arr, n, largest);
}
}
void heapSort(int arr[], int n)
{
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i);
for (int i = n - 1; i >= 0; i--)
{
int temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
heapify(arr, i, 0);
}
}
void merge(int low, int mid, int high)
{
int i = low, x = low, y = mid + 1;
while (x <= mid && y <= high)
{
if (a[x] < a[y])
b[i++] = a[x++];
else
b[i++] = a[y++];
}
while (x <= mid)
b[i++] = a[x++];
while (y <= high)
b[i++] = a[y++];
for (i = low; i <= high; i++)
a[i] = b[i];
}
void mergeSort(int low, int high)
{
if (low < high)
{
int mid = (low + high) / 2;
mergeSort(low, mid);
mergeSort(mid + 1, high);
merge(low, mid, high);
}
}
int partition(int low, int high)
{
int pivot = a[low];
int i = low, j = high;
while (i < j)
{
while (i <= high && a[i] <= pivot)
i++;
while (a[j] > pivot)
j--;
if (i < j)
{
int temp = a[i];
a[i] = a[j];
a[j] = temp;
}
}
a[low] = a[j];
a[j] = pivot;
return j;
}
void quickSort(int low, int high)
{
if (low < high)
{
int p = partition(low, high);
quickSort(low, p - 1);
quickSort(p + 1, high);
}
}
void printArray()
{
for (i = 0; i < n; i++)
printf("%d ", a[i]);
printf("\n");
}
int main()
{
int choice;
printf("Enter the number of elements: ");
scanf("%d", &n);
printf("Enter the elements: ");
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
do
{
printf("\nMenu:\n");
printf("1. Heap Sort\n");
printf("2. Merge Sort\n");
printf("3. Quick Sort\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
heapSort(a, n);
printf("After Heap Sort: ");
printArray();
break;
case 2:
mergeSort(0, n - 1);
printf("After Merge Sort: ");
printArray();
break;
case 3:
quickSort(0, n - 1);
printf("After Quick Sort: ");
printArray();
break;
case 0:
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
continue;
}
} while (choice != 0);
return 0;
}

/*OUTPUT:
Enter the number of elements: 5
Enter the elements: 2 6 56 89 12

Menu:
1. Heap Sort
2. Merge Sort
3. Quick Sort
0. Exit
Enter your choice: 1
After Heap Sort: 2 6 12 56 89 

Menu:
1. Heap Sort
2. Merge Sort
3. Quick Sort
0. Exit
Enter your choice: 2
After Merge Sort: 2 6 12 56 89 

Menu:
1. Heap Sort
2. Merge Sort
3. Quick Sort
0. Exit
Enter your choice: 3
After Quick Sort: 2 6 12 56 89 

Menu:
1. Heap Sort
2. Merge Sort
3. Quick Sort
0. Exit
Enter your choice: 0
Exiting the program.



*/