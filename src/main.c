#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxnumber(int n) {
  int s[10] = { 0 };
  int result = 0;
  
  while(n) {
    s[n % 10]++;
    n /= 10;
  }
  
  for(int i = 9; i >= 0; i--) {
    for(int j = 0; j < s[i]; j++) {
      result *= 10;
      result += i;
    }  
  }
  
  return result;
}

int main (int argc, char** argv)
{
  if(argc < 2) {
    printf("Invalid number of arguments!");
    return 1;
  }

  char* ptr;
  int arr_size = strtol(argv[1], &ptr, 10);
  int* arr = malloc(arr_size * sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < arr_size; i++) {
    arr[i] = rand() % 1000;
  }

  printf("Source array:\n");
  for(int i = 0; i < arr_size; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  printf("Result array:\n");
  for(int i = 0; i < arr_size; i++) {
    arr[i] = maxnumber(arr[i]);
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  return 0;
}
