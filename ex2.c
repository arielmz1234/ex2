/******************
Name: Ariel Mizrahi
ID: 
Assignment: ex2
*******************/

#include <stdio.h>
#define LOGICAL_TEN 10 //LOGICAL_TEN will be used for logical action we want to do with the number 10
#define ALL_HAPPY 1 //ALL_HAPPY will be used in case 5 as the number all happy number eventually reach
#define ALL_UNHAPPY 4 //ALL_UNHAPPY will be used in case 5 as the number that all the not happy number eventually reach
int main() {
	int cases = 0;
	while (cases != 7){ //creating a loop so while the user didn't choose 7(exit), the program continues
	printf("Choose an option: \n     1. Happy Face\n     2. Balanced Number\n     3. Generous Number\n     4. Circle Of Joy\n     5. Happy Numbers\n     6. Festival Of Laughter\n     7. Exit\n");
	scanf("%d", &cases);
		switch (cases) {
			case 1: {
				char eyes, nose, mouth;//eyes, nose, mouth will hold the characters the user inputs
				int faceSize;//faceSize will hold the number the user inputs
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				scanf(" %d", &faceSize);
				while (faceSize % 2 == 0 || faceSize < 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &faceSize);
				}/*while loop that checks if the face size is odd and positive,
				if not the loop continues and the user tries again*/
				printf("%c",eyes);//print the left eye
				for (int i = 1; i <= faceSize; i++) {
					printf(" ");
				}//a for loop that runs until it reaches facesize and prints spaces each time
				printf("%c\n", eyes);//print the right eye
					for (int i = 1; i <= (faceSize/2)+1; i++) {
						printf(" ");
					}//a for loop that prints spaces until it reaches the middle of the face size +1
				printf("%c\n",nose);
				printf("\\");// print this left edge of the mouth
				for (int i = 1; i <= faceSize; i++) {
					printf("%c", mouth);
				}// for loop to print each mouth character face size times
				printf("/\n");//print the right edge of the mouth
				break;
			}
			case 2: {
				int number;//number will hold the number the user inputs
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {\
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}//while loop that keeps getting numbers from the user until he enters a positive number
				int numSize = 1;//numSize will hold how many digits the number contains, initialized at 1
				int number1 = number;
				int number2 = number;
				int number3 = number;
				/*number1,2,3 are clones of the number I want to check if balanced, every time I work on the number it changes
				and if I need to use the number again I can't so I created clones*/
				int leftDigits = 0;//leftDigits will hold sum of the digits left to the middle digit
				int rightDigits = 0;//rightDigits will hold sum of the digits right to the middle digit
				while (number1 >= LOGICAL_TEN) {
					number1 /= LOGICAL_TEN;
					numSize++;
				}/*this while loop gets how many digits the number
				contain by adding 1 to the numSize each the number is divided by 10 and each*/
				int numSizePow = 1;/*numSizePow will give me 10 to the power of numSize, (1234 will give 1000),
				initialized at 1 because we are going to multiply him*/
				for (int i = 1; i < numSize; i++) {
					numSizePow *= LOGICAL_TEN;
				}//this for loop runs until numSize and each time takes numSizePow and multiply him by 10
				int loopLength = numSize/2;//instead of writing numSize/2 in each for loop, loopLength will hold this value
				for (int i = 1; i <= loopLength; i++) {
					rightDigits += (number2 % LOGICAL_TEN);
					number2 /= LOGICAL_TEN;
				}/*this loop runs until loopLength and each time takes the number and adds
				  his rightmost digit to rightDigit, after that
				  the number is divided by 10 which "deletes" the current rightmost digit*/
				for (int i = 1; i <= loopLength; i++) {
					leftDigits += (number3 / numSizePow);
					number3 = (number3 - (numSizePow * (number3 / numSizePow)));
					numSizePow /= LOGICAL_TEN;
				}/*this loop runs until loopLength and each time takes the number dived him by numSizePow which gives the leftmost digit
				  and add it to leftDigits, the number is subtracted by the leftmost digit times numSizePow, doing that to the number
				  "deletes" his leftmost digit, now in order for numSizePow to be the same digit size with the new number we got we divide
				  numSizePow by 10.*/
				if (rightDigits == leftDigits) {
					printf("This number is balanced and brings harmony!\n");
				}
				else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}
			case 3: {
				int number;//number will hold the number the user inputs
				int divSum = 0;//divSum will hold the sum of all the number's proper dividers
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {//while loop that keeps getting numbers from the user until he enters a positive number
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}
				for (int i = 2; i < number; i++) {
					if(number % i == 0) {
						divSum += i;
					}
				}/*this loops runs from 2 to the number(no including) and checks if the index i is a divider of number,
				if its true the number is added to divSum */
				if (divSum > number) {
					printf("This number is generous!\n");
				}
				else
					printf("This number does not share.\n");
				break;
			}
			case 4: {
				int number;//number will hold the number the user inputs
				int revNum = 0;//revNum will hold the number the user inputs with its digits places reversed, initialized to 0
				int isPrime = 1;/*isPrime will hold 1 if the number is prime and 0 if not,
				in the code we will check if the number has divided is so isPrime will be set to 0
				so in any other case the number is prime so isPrime is initialized at 1*/
				int isRevPrime = 1;//same as isPrime but for the revNum
				int numSize = 1;//numSize will hold how many digits the number contain for later use, initialized to 1
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}//while loop that keeps getting numbers from the user until he enters a positive number
				int number1 = number;
				int number2 = number;
				/*number1,2 are clones of the number I want to check if balanced, every time I work on the number it changes
				and if I need to use the number again I can't so I created clones*/
				while (number1 >= LOGICAL_TEN) {
					number1 /= LOGICAL_TEN;
					numSize++;
				}/*this while loop gets how many digits the number
				contain by adding 1 to the numSize each the number is divided by 10 and each*/
				int numSizePow = 1;/*numSizePow will give me 10 to the power of numSize, (1234 will give 1000),
				initialized at 1 because we are going to multiply him*/
				for (int i = 1; i < numSize; i++) {
					numSizePow *= LOGICAL_TEN;
				}//this for loop runs until numSize and each time takes numSizePow and multiply him by 10
				while (number2 != 0) {
					revNum += (number2 % LOGICAL_TEN) * numSizePow;
					number2 /= LOGICAL_TEN;
					numSizePow /= LOGICAL_TEN;
				}/*in this while loop we take the rightmost digit of the number and multiply it by numSizePow and adding it to revNum,
				after that we divide the number by 10 and divide numSizePow by 10,
				by doing that we are adding the rightmost digits of the original number to the leftmost place in revNum*/
				for (int i = 2; i < number; i++) {
					if(number % i == 0) {
						isPrime = 0;
						break;
					}
				}/*this for loop runs from 2 to number(not included) and checks each time if the index i is a divider of the number,
				if this is true then the number isn't a prime number and isPrime = 0
				and because there is no need to check other number we break out of the loop*/
				for (int i = 2; i < revNum; i++) {
					if(revNum % i == 0) {
						isRevPrime = 0;
						break;
					}
				}// the same goes for this for loop just for revNum
				if(isPrime && isRevPrime) {//if both are prime
					printf("This number completes the circle of joy!\n");
				}
				else {
					printf("The circle remains incomplete.\n");
				}
				break;
			}
			case 5: {
				int number;//number will hold the number the user inputs
				int runner = 1;// the runner will be the number between 1-the input number, that we want to check if happy
				printf("Enter a number:\n");
				scanf("%d", &number);
				while (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}//while loop that keeps getting numbers from the user until he enters a positive number
				printf("Between 1 and %d only these numbers bring happiness:", number);
				while (runner <= number) {//this while loop ensures that we stop checking the runner number once he gets to the input number
					int digit, powSum;//digit will hold the current digit we want to power
					int number1 = runner;//clone of runner, so I can change him without changing runner
					while(number1 != ALL_HAPPY && number1 != ALL_UNHAPPY) {/*if the number that we want to check is happy or not, eventually every happy number reaches to 1,
						and every unhappy number reaches 4, so we want to break out of the loop if one of those condition happens*/
						powSum = 0;//powSum will hold the sum of each digit squared
						while(number1 > 0) {
							digit = number1 % LOGICAL_TEN;
							powSum += digit*digit;
							number1 /= LOGICAL_TEN;
						}/*in this while loop we take the rightmost digit of the number that we are checking if is happy or not,
							entering the value into digit, adding to powSum the digit squared and dividing the number by 10 which "deletes"
							the rightmost number and then enter the loop again, when the number/10 equals 0 it means
							we finished adding each digit squared of the number, and we leave this loop*/
						number1 = powSum;/*here we want to check again if the powSum of the number we entered the previous while loop is happy or not,
						to do that we give number1 the value of powSum and enter the loop again*/
					}
					if(number1 == 1) {/*now that we are out of the first while loop it means we either got that
						number1 = 1 or 4, if he equals 4 that means we the number isn't happy but if he equals 1 that means he is
						and that is what we check here, and print the number*/
						printf(" %d", runner);
					}
					runner++;/*we add 1 to the runner that was initialized at 1 so
					that we continue going through all the numbers leading to the input number*/
				}
				printf("\n");
				break;
			}
			case 6: {
				int smileNumber = 0, cheerNumber = 0;//smileNumber will hold the smile number and cheerNumber will hold the cheer number
				printf("Enter a smile and cheer number:\n");
				scanf("%*[^\n]");//this skips all the characters in the buffer except "\n"
				scanf("%*c");//this takes the the \n character out and clears the buffer
				while(1) {//this while loop continues to happen until it breaks inside the loop
					if((scanf("smile : %d, cheer :  %d", &smileNumber, &cheerNumber) ==2) && smileNumber > 0 && cheerNumber > 0 && smileNumber != cheerNumber){
							break;
					}
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					scanf("%*[^\n]");
					scanf("%*c");
				}/*in this if we are checking a few things:
					 1. that the input the user entered matches the format: "smile : %d, cheer :  %d", to check this
					 we need to understand that scanf returns a value of the number of successfully matched and assigned input items
					 when we give scanf a format it will only assign the input items if the format matches, so only when the format matches
					 scanf will return 2 for 2 successfully matched and assigned input items
					 2. we also want to ensure that both smileNumber and cheerNumber are positive
					 3. we also want to ensure that SmileNumber and cheerNumber are not equal
					 after all those conditions are true we can break out of the loop, if not the user is prompted to try again and to make sure that
					 the scanf works properly we clear the buffer again.
					 */
				int maxNum;//maxNum will hold the maximum number the user inputs
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &maxNum);
				while (maxNum <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &maxNum);
				}//while loop that keeps getting numbers from the user until he enters a positive number
				for (int i = 1; i <= maxNum; i++) {//this for loop runs from 1 until maxNum(included)
					if(i % smileNumber == 0) {//we check if smileNumber is a divider of the index i
						if(i % cheerNumber == 0) {/*if smileNumber is a divider of the index i then we need to check if cheerNumber
							is also a divider of i if so print Festival!*/
							printf("Festival!\n");
							continue;/*if we got here that means that smileNumber and cheerNumber are both dividers of i,
							in that case we can move on to the next index by using continue*/
						}
						printf("Smile!\n");//if smileNumber is a divider of the index i but cheerNumber isn't print cheer
						continue;//if we got here that means that only smileNumber is a divider of i so we can move on to the next index by using continue
					}
					if(i % cheerNumber == 0) {//we check if cheerNumber is a divider of the index i
						if(i % smileNumber == 0) {/*if cheerNumber is a divider of the index i then we need to check if smileNumber
							is also a divider of i if so print Festival!*/
							printf("Festival!\n");
							continue;/*if we got here that means that smileNumber and cheerNumber are both dividers of i,
							in that case we can move on to the next index so we use continue*/
						}
						printf("Cheer!\n");//if cheerNumber is a divider of the index i but smileNumber isn't print cheer
						continue;//if we got here that means that only cheerNumber is a divider of i so we can move on to the next index by using continue
					}
					printf("%d\n", i);//if smileNumber and cheerNumber are not dividers of i we just print i
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
