#include <stdio.h>
#include <stdlib.h>

int main(){
    char inputString[100];
    int leftIndex, rightIndex, length = 0;
    printf("Enter a string for palindrome check\n");
    scanf("%[^\n]s", inputString);
    while(inputString[length] != '\0')
        length++;
    printf("%d\n", length);
    if(length < 1)
        return EXIT_FAILURE;
    leftIndex = 0;
    rightIndex = length -1;
    while(leftIndex < rightIndex){
        if(inputString[leftIndex] != inputString[rightIndex]){
            printf("%s is not a Palindrome \n", inputString);
            return EXIT_SUCCESS;
        }
        leftIndex++;
        rightIndex--;
    }
    printf("%s is a Palindrome \n", inputString);
    return EXIT_SUCCESS;
}
