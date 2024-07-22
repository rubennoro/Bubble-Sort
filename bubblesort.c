#include <stdio.h>
#include <time.h>

//Size of array 
#define SIZE 5000

//Function to measure run time
double CLOCK() {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC,  &t);
  return (t.tv_sec * 1000)+(t.tv_nsec*1e-6);
}

//Function used to swap numbers in array
void swap(int* less, int* greater){
  int n = *less;
  *less = *greater;
  *greater = n;
}

//Bubblesort function
void bubblesort(int arr[], int size){
  int i, j;
  for(i = 0; i < size-1; i++){ //iterates x-1 times
    for(j = 0; j < size-i-1; j++){ //iterates x-1-i times (starts as x-2, i starts at 1)
      if(arr[j+1] < arr[j]){
        swap(&arr[j+1], &arr[j]);
      }
    }
  }
}

//Function that prints the array
 void printArray(int arr[], int size){
   int i;
   for(i = 0; i < size; i++){
     printf("%d\n", arr[i]);
   }
 }

int main(){

  //Can change size to any desired value
  int array[SIZE];
  srand(time(NULL));
  int random = rand();
  int size = SIZE;

  double start, finish, total;
  int i;

  for(i = 0; i<size; i++){
    array[i] = random;
    random = rand();
    //  printf("%d\n", array[i]);
  }
  
  start = CLOCK()
  
  bubblesort(array, size);

  finish = CLOCK();
  
  total = finish-start;
  printf("%f milliseconds \n", total);
  //printArray(array, size);



  return 0;
}

