#include<stdio.h>
#include<stdlib.h>

char *month_name(int n){
  static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };

  return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(){

  int n;
  scanf("%d", &n);
  while(n != 0){
    printf("%s\n", month_name(n));
    scanf("%d", &n);
  }

  return EXIT_SUCCESS;
}
