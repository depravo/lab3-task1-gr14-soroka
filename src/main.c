#include <stdio.h>
#include <math.h>

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

int main (void)
{
  
  
  return 0;
}
