#include <stdio.h>

// the program calculates the sum of all numbers between two given numbers
void main() {
	int firstNum;
	int secondNum;
	int sum= 0;
	prinf("Enter two numbers : \n");
	scanf("%d %d", &firstNum, &secondNum);	// gets input

	// calculate the sum
	for (int i = firstNum; i <= secondNum; i++)
		sum += i;
	printf("The total sum is : %d\n", sum);
}
