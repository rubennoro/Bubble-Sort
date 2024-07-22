#include <stdio.h>
#include <time.h>

//Value of array size
#define SIZE 5000

//Function to measure run time
double CLOCK() {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC,  &t);
  return (t.tv_sec * 1000)+(t.tv_nsec*1e-6);
}

//Merge function
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

//Function that prints array
void printArray(int arr[], int size){
  int i;
  for(i = 0; i < size; i++){
    printf("%d\n", arr[i]);
  }
}

int main(){

  double start, end, t;
  int array[SIZE];
  int size = SIZE;

  srand(time(NULL)); //random # generation
  int random = rand();

  int i;
  for(i = 0; i < size; i++){ //loop generates random numbers
    array[i] = random;
    random = rand();
    //printf(" %d\n", array[i]);
  }

  start = CLOCK();

  mergeSort(array, 0, size-1);

  end = CLOCK();

  t = end - start;
  printf("%f ms\n", t);
  //int j;
  //for(j = 0; j < size; j++){ //loop generates random numbers
    //printf(" %d\n", array[j]);
  //}


  return 0;

}











