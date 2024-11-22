/******************
Name: Ariel Mizrahi
ID: 213458821
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int cases = 0;
	while (cases != 7){
	printf("Choose an option: \n     1. Happy Face\n     2. Balanced Number\n     3. Generous Number\n     4. Circle Of Joy\n     5. Happy Numbers\n     6. Festival Of Laughter\n     7. Exit\n");
	scanf("%d", &cases);
		switch (cases) {
			case 1: {
				char eyes, nose, mouth;
				int faceSize;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				scanf(" %d", &faceSize);
				while (faceSize % 2 == 0 || faceSize < 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}
				printf("%c",eyes);
				for (int i = 1; i <= faceSize; i++) {
					printf(" ");
				}
				printf("%c\n", eyes);
				if (faceSize != 1) {
					for (int i = 1; i <= (faceSize/2)+1; i++) {
						printf(" ");
					}

				}
				else {
					printf(" ");
				}
				printf("%c\n",nose);
				printf("\\");
				for (int i = 1; i <= faceSize; i++) {
					printf("%c", mouth);
				}
				printf("/\n");
				break;
			}
			case 2: {
				int number;
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}
				int numSize = 1;
				int number1 = number;
				int number2 = number;
				int number3 = number;
				int leftDigits = 0;
				int rightDigits = 0;
				while (number1 >= 10) {
					number1 /= 10;
					numSize++;
				}
				int numSizePow = 1;
				for (int i = 1; i < numSize; i++) {
					numSizePow *= 10;
				}
				int loopLength = numSize/2;
				for (int i = 1; i <= loopLength; i++) {
					rightDigits += (number2 % 10);
					number2 /= 10;
				}
				for (int i = 1; i <= loopLength; i++) {
					leftDigits += (number3 / numSizePow);
					number3 = (number3 - (numSizePow * (number3 / numSizePow)));
					numSizePow /= 10;
				}
				if (rightDigits == leftDigits) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}
			case 3: {
				int number;
				int divSum = 0;
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}
				for (int i = 2; i < number; i++) {
					if(number % i == 0) {
						divSum += i;
					}
				}
				if (divSum > number) {
					printf("This number is generous!\n");
				}
				else
					printf("This number does not share.\n");
				break;
			}
			case 4: {
				int number;
				int revNum = 0;
				int isPrime = 1;
				int isRevPrime = 1;
				int numSize = 1;
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}
				int number1 = number;
				int number2 = number;
				while (number1 >= 10) {
					number1 /= 10;
					numSize++;
				}
				int numSizePow = 1;
				for (int i = 1; i < numSize; i++) {
					numSizePow *= 10;
				}
				while (number2 != 0) {
					revNum += (number2 % 10) * numSizePow;
					number2 /= 10;
					numSizePow /= 10;
				}
				for (int i = 2; i < number; i++) {
					if(number % i == 0) {
						isPrime = 0;
						break;
					}
				}
				for (int i = 2; i < revNum; i++) {
					if(revNum % i == 0) {
						isRevPrime = 0;
						break;
					}
				}
				if(isPrime && isRevPrime) {
					printf("This number completes the circle of joy!\n");
				}
				else {
					printf("The circle remains incomplete.\n");
				}
				break;
			}
			case 5: {
				int number;
				int runner = 1;
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}
				printf("Between 1 and %d only these numbers bring happiness:", number);
				while (runner <= number) {
					int digit, powSum;
					int number1 = runner;
					while(number1 != 1 && number1 != 4) {
						powSum = 0;
						while(number1 > 0) {
							digit = number1 % 10;
							powSum += digit*digit;
							number1 /= 10;
						}
						number1 = powSum;
					}
					if(number1 == 1) {
						printf(" %d", runner);
					}
					runner++;
				}
				printf("\n");
				break;
			}
			case 6: {
				int smileNumber = 0, cheerNumber = 0;
				printf("Enter a smile and cheer number:\n");
				while (getchar() != '\n'){ };
				while(1) {
					if((scanf("smile : %d, cheer :  %d", &smileNumber, &cheerNumber) ==2) && smileNumber > 0 && cheerNumber > 0 && smileNumber != cheerNumber){
							break;
					}
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					while (getchar() != '\n'){ };
				}
				int maxNum;
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &maxNum);
				while (maxNum <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &maxNum);
				}
				for (int i = 1; i <= maxNum; i++) {
					if(i % smileNumber == 0) {
						if(i % cheerNumber == 0) {
							printf("Festival!\n");
							continue;
						}
						printf("Smile!\n");
						continue;
					}
					if(i % cheerNumber == 0) {
						if(i % smileNumber == 0) {
							printf("Festival!\n");
							continue;
						}
						printf("Cheer!\n");
						continue;
					}
					printf("%d\n", i);
				}
				break;
			}
			case 7: {
				printf("Thank you for your journey through Numeria!");
				break;
			}
			default:
				printf("This option is not available, please try again.\n");
		}
	}
	return 0;
}
