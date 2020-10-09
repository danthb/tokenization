#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void deepReading(char *inputString){
	int i=0;
	char change = 0;
	int len = strlen(inputString);
	printf("\nString: %s\n", inputString);
	for (i = 0; i < len; i++){
		int j = i+1;
		if(change==0){

			if(isdigit(inputString[i])){
				//printf("%d  ", i);
				//printf("numero\n");
				printf("%c", inputString[i]);
				// Float point
				if(inputString[j] == 46 ){
					change = 0;
				}
				//Hexa
				else if((inputString[j] == 88) || (inputString[j] == 120)){
					change = 0;
					
				}
				//Decimal number
				else if(isdigit(inputString[i]) == isdigit(inputString[j])){
					change=0;
				}else{
					change=1;
				}
			}
			else if(isalpha(inputString[i])){
				//printf("%d  ", i);
				//printf("letra\n");
				printf("%c", inputString[i]);
				if(isalpha(inputString[i]) == isalpha(inputString[j])){
					change=0;
				}else if(isdigit(inputString[j])){
					change=0;
				}
				//If it is necessary to separate alphanumeric and integer 
				else{
					change=1;
				}
				
			}
			else{
				//printf("simbolo\n");
				printf("%c", inputString[i]);
				if(isdigit(inputString[j])){
					change=0;
					
				}else if (isalpha(inputString[j])){
					change=1;
				}
			}
		//In order to set the separation of strings	
		}else{
			i--;
			printf("\n******change******\n");
			change = 0;

		}
	}
	printf("\n");

}

int readingString(char *inputString, char whiteBlank, char ***outputString){

	int len = strlen(inputString);
	int numberString = 1;
	char **currentString;
	int i;
	for (i = 0; i < len; i++){
    // Set the split of strings with the use of "\0"
		if (inputString[i] == whiteBlank)
		{
			inputString[i] = '\0';	
			numberString++;
		}
	}

	*outputString = malloc(numberString * sizeof(char *));

	currentString = *outputString;

	*currentString = inputString;

	// Store the strings
	for (i = 0; i < len; i++) {
		if (inputString[i] == '\0') {
			currentString++;
			*currentString = &(inputString[i+1]);
		}
	}

	return numberString; 
}

int main(int argc, char* argv[1]) {
    if (argc == 2){
        printf("TRUE\n");
    }
    printf("Number of inputs %d\n", argc);
    printf("Name file: %s\n", argv[0]);
    printf("String: %s\n", argv[1]);
    char **strings;
	int numberString;
	int i;
    numberString = readingString(argv[1], ' ', &strings);


	// Loop for deepReading when the strings are joined with each other
	for (i = 0; i <numberString; i++)
	{
		deepReading(strings[i]);
	}
	
	free(strings);
	return 0;
}