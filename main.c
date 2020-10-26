#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hexaValidation(char *inputString, int start){	
	int counter = 0;
	int i = start;
	if(inputString[start] != '0'){
		return 0;
	}
	i++;

	if((tolower(inputString[start+1])!='x')){
		return 0;
	}
	i++;

	while((isdigit((int)inputString[i])) || (tolower(inputString[i]) == 'a')
		|| (tolower(inputString[i]) == 'b') || (tolower(inputString[i]) == 'c')
		|| (tolower(inputString[i]) == 'd') || (tolower(inputString[i]) == 'e')){
		if(i==2){
			counter = 3;
			i++;
		}
		else{
			counter++;
			i++;
		}
	}
	return counter;
}

int octalValidation(char *inputString, int start){
	int counter = 0;
	int i = start;

	if(inputString[start] != '0'){
		return 0;
	}
	i++;

	while(isdigit(inputString[i])){
		if((inputString[i])=='8' || (inputString[i])=='9'){
			return 0;
		}
		else{
			if(i==1){
				counter = 2;
				i++;
			}
			else{
				counter++;
				i++;
			}
		}
	}
	return counter;
}

int decimalValidation(char *inputString, int start){
	int counter = 0;
	int i = start;
	/*if(inputString[start] == '0'){
		return 0;
	}*/

	while(isdigit((int)inputString[i])){
		if(inputString[i+1] == '.'){
		    return 0;
		}
		counter++;
		i++;
	}
	return counter;
}

int floatValidation(char *inputString, int start){
	int counter = 0;
	int i = start;
	int dot = 0;
	int sign = 0;
	int exp_simbol = 0;
	int int_value  = 0;
	
	if(inputString[start] == '.'){
		return 0;
	}

	if(inputString[start] == '0' && inputString[start+1] != '.'){
		return 0;
	}

	while( isdigit(inputString[i]) || inputString[i] == '.' || tolower(inputString[i]) == 'e' || inputString[i] == '-' || inputString[i] == '+'){
		
		if(isdigit(inputString[i]))
		{
			int_value++;
		}
		if (inputString[i]== '.')
		{
			dot++;
		}
	    if (inputString[i]== 'e')
		{
			exp_simbol++;
		}
		if (inputString[i]== '-' || inputString[i]== '+')
		{
			sign++;
		}
		
		counter++;
		i++;
		
		if ( dot == 2 || exp_simbol == 2 || sign == 2){
			break;
		}

		if ( dot < exp_simbol || dot < sign || exp_simbol < sign){
			break;
		}


	}

	if(counter == int_value){
		return 0;
	}
	return counter;
}

int wordValidation(char *inputString, int start){
	int counter;
	int i = start;

	if(isalpha(inputString[start]) != 0){
		i++;
	}

	while(isalpha(inputString[i]) != 0  || isdigit(inputString[i]) != 0){
		if(i == (start+1)){
			// check
			counter = 2;
		}
		counter++;
		i++;
	}
	counter = counter -1;
	return counter;

}

int simbCounter(char *inputString, int start){
	int i = start;
	int counter;

	while(isalpha(inputString[i]) == 0  && isdigit(inputString[i]) == 0  && inputString[i] != '\0'){
		i++;
		counter++;
	}
	return counter;
}

void simbolValid(char *inputString, int start, int simbCounter){
	int i = start;
	switch (inputString[i])
	{
	case '(':
		printf("left parenthesis");
		break;
	case ')':
		printf("right parenthesis");
		break;
	case '[':
		printf("left bracket");
		break;	
	case ']':
		printf("right bracket");
		break;	
	case ',':
		printf("comma");
		break;
	case '?':
		printf("conditional true");
		break;	
	case ':':
		printf("conditional false");
		break;	
	case '~':
		printf("1s complement");
		break;	
	case '^':
		if(simbCounter == 1){printf("bitwise XOR");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("bitwise XOR equals");}
		break;
	case '*':
		if(simbCounter == 1){printf("multiply/dereference operator");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("times equals");}
		break;
	case '!':
		if(simbCounter == 1){printf("negate");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("inequality test");}
		break;	
	case '%':
		if(simbCounter == 2 && inputString[i+1] == '='){printf("mod equals");}
		break;	
	case '|':
		if(simbCounter == 1){printf("bitwise OR");}
		else if(simbCounter == 2 && inputString[i+1] == '|'){printf("logical OR");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("bitwise OR equals");}
		break;	
	case '+':
		if(simbCounter == 1){printf("addition");}
		else if(simbCounter == 2 && inputString[i+1] == '+'){printf("increment");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("plus equals");}
		break;
	case '/':
		if(simbCounter == 1){printf("division");}
		else if(simbCounter == 2 && inputString[i+1] == '/'){printf("sizeof");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("divide equals");}
		break;
	case '<':
		if(simbCounter == 1){printf("less than test");}
		else if(simbCounter == 2 && inputString[i+1] == '<'){printf("shift left");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("less than or equal test");}
		else if(simbCounter == 3 && inputString[i+2] == '='){printf("shift left equals");}
		break;
	case '>':
		if(simbCounter == 1){printf("greater than test");}
		else if(simbCounter == 2 && inputString[i+1] == '>'){printf("shift right");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("greater than or equal test");}
		else if(simbCounter == 3 && inputString[i+2] == '='){printf("shift right equals");}
		break;		
	case '=':
		if(simbCounter == 1){printf("assignment");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("equality test");}
		break;	
	case '&':
		if(simbCounter == 1){printf("AND/address operator");}
		else if(simbCounter == 2 && inputString[i+1] == '&'){printf("logical AND");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("bitwise AND equals");}
		break;	
	case '-':
		if(simbCounter == 1){printf("minus/subtract operator");}
		else if(simbCounter == 2 && inputString[i+1] == '-'){printf("decrement");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("minus equals");}
		else if(simbCounter == 2 && inputString[i+1] == '>'){printf("structure pointer");}
		break;	
	default:
		break;
	}
}

void print_substrings(char *inputString, int start, int end){
	for(int i = start; i <= end; i++){
		printf("%c",inputString[i]);
	}
}

// Split the substrings in subtrings if these are joined
void deepReading(char *inputString){
	int counter = 0 ;
	int endString = 0;
	int len = strlen(inputString);
	while(endString <= len && inputString[endString] != '\0' ){
		if(isdigit(inputString[endString])){
			if(hexaValidation(inputString, endString)){
				printf("Hexadecimal:  ");
				counter = hexaValidation(inputString,endString);
				print_substrings(inputString, endString, counter);
				endString = endString + counter ;
			}
			else if (octalValidation(inputString,endString)){
				printf("Octal: ");
				counter = octalValidation(inputString,endString);
				print_substrings(inputString, endString, counter);
				endString = endString + counter ;
			}
			else if (decimalValidation(inputString,endString)){
				printf("Decimal: ");
				counter = decimalValidation(inputString,endString);
				print_substrings(inputString, endString, counter);
				endString = endString + counter ;
			}
			else if (floatValidation(inputString,endString)){
				printf("Float ");
				counter = floatValidation(inputString,endString);
				//printf("%d", counter);
				print_substrings(inputString, endString, counter);	
				endString = endString + counter;
			}

		}
		else if(isalpha(inputString[endString])){
			printf("Word: ");
			counter = wordValidation(inputString,endString);
			print_substrings(inputString, endString, counter);
			endString = endString + counter;
		}
		else{
			printf("Simbol: ");
			counter = simbCounter(inputString,endString);
			simbolValid(inputString, endString, counter);
			endString = endString + counter;
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
	
	// Loop for spliting subtrings 
	for (i = 0; i <numberString; i++)
	{
		deepReading(strings[i]);
	}
	free(strings);
	return 0;
}