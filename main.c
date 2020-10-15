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
	counter++;

	if((tolower(inputString[i])!='x')){
		return 0;
	}
	i++;
	counter++;

	while((isdigit((int)inputString[i])) || (tolower(inputString[i])=='a')
		|| (tolower(inputString[i])=='b') || (tolower(inputString[i])=='c')
		|| (tolower(inputString[i])=='d') || (tolower(inputString[i])=='e')){
		counter++;
		i++;
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
	counter++;
	while(isdigit((int)inputString[i])){
		if((inputString[i])=='8' || (inputString[i])=='9'){
			return 0;
		}
		else{
			counter++;
			i++;

		}
	}
	return counter;
}

int decimalValidation(char *inputString, int start){
	int counter = 0;
	int i = start;

	if(inputString[start] == '0'){
		return 0;
	}

	while(isdigit((int)inputString[i])){	
			counter++;
			i++;
	}

	return counter;
}

int floatValidation(char *inputString, int start){
	int counter;
	int i,j = start;
	int dot = 0;
	int sign = 0;
	int exp_simbol = 0;
	int int_value  = 0;
	
	if(inputString[start]=="."){
		return 0;
	}

	if(inputString[start]=="0" && inputString[start]!="."){
		return 0;
	}

	while( isdigit((int)inputString[i]) || inputString[i]== "." || 	
			tolower((int)inputString[i]) == 'e' || inputString[i]== "-" || 
			inputString[i]== "+")
	{
		
		if(isdigit(inputString[i])){
			int_value++;
		}
		if (inputString[i]== ".")
		{
			dot++;
		}
		if (inputString[i]== "e")
		{
			exp_simbol++;
		}
		if (inputString[i]== "-" || inputString[i]== "+")
		{
			sign++;
		}
		if ( dot == 2 || exp_simbol == 2 || sign == 2){
			break;
		}

		if ( dot < exp_simbol || dot < sign || exp_simbol < sign){
			break;
		}

		counter++;
		i++;
	}

	if(counter == int_value){
		return 0;
	}

	return counter;

}

int wordValidation(char *inputString, int start){
	int counter;
	int i = start;

	if(isdigit(inputString[start])){
		return 0; 
	}
	while(isalpha(inputString[i])){
		counter++;
		i++;
	}

	return counter;

}


int simbCounter(char *inputString, int start){
	int i = start;
	int counter;

	while(isdigit((int) inputString[i]) == 0  || isalpha((int) inputString[i]) == 0){
		i++;
		counter++;
	}
	return counter;
}

void oneSimbol(char *inputString, int start, int simbCounter){
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
	case '< ':
		if(simbCounter == 1){printf("less than test");}
		else if(simbCounter == 2 && inputString[i+1] == '<'){printf("shift left");}
		else if(simbCounter == 2 && inputString[i+1] == '='){printf("less than or equal test");}
		else if(simbCounter == 3 && inputString[i+2] == '='){printf("shift left equals");}
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

void deepReading(char *inputString){
	int i=0;
	char change = 0;
	int len = strlen(inputString);
	printf("\nString: %s\n", inputString);
	for (i = 0; i < len; i++){
		int j = i+1;

		if(isdigit(inputString[i])){

		}
		else if(isalpha(inputString[i])){

				
		}
		else{

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