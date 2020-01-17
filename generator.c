#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int num1, int num2){
	return num1 + num2;
}
int diff(int num1, int num2){
	return num1 - num2;
}
int prod(int num1, int num2){
	return num1 * num2;
}
int frac(int num1, int num2){
	if (num2 == 0)
		return -1;
	return num1 / num2;
}

int main(){
	
	// Open the file
	char filename[] = "calculator.py";
	FILE* myfile = fopen(filename, "w+");
	if (myfile == NULL){
		printf("Unable to open file %s.\r\n", filename);
	}
	
	// Write introduction to code
	fprintf(myfile, 
	"%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
	"# Greet user \r\n",
	"print('Welcome to my first calculator!') \r\n",
	"print('All inputs are of the form: (integer) (operator) (integer).\\r\\n') \r\n",
	"\r\n",
	"operators = ['+', '-', '*', '/'] \r\n",
	"\r\n",
	"while (True): \r\n",
	"\r\n",
	"    # Retrieve input \r\n",
	"    num_1 = input('Please input first integer (0, 1, ...): ') \r\n",
	"    oper  = input('Please input operator (+, -, *, /): ') \r\n",
	"    num_2 = input('Please input second integer (0, 1, ...): ') \r\n",
	"\r\n",
	"    # Validate input \r\n",
	"    try: \r\n",
	"        num_1 = int(num_1) \r\n",
	"    except ValueError: \r\n",
	"        print('ERROR: First number is not an integer!') \r\n",
	"        continue \r\n",
	"    if num_1 < 0 or num_1 > 200: \r\n",
	"        print('ERROR: First number must be between 0 and 200.') \r\n",
	"        continue \r\n",
	"\r\n",
	"    try: \r\n",
	"        num_2 = int(num_2) \r\n",
	"    except ValueError: \r\n",
	"        print('ERROR: Second number is not an integer!') \r\n",
	"        continue \r\n",
	"    if num_2 < 0 or num_2 > 200: \r\n",
	"        print('ERROR: Second number must be between 0 and 200.') \r\n",
	"        continue \r\n",
	"\r\n",
	"    if oper not in operators: \r\n",
	"        print('ERROR: Operator not valid, input one of {}'.format(operators)) \r\n",
	"\r\n",
	"    # Run the code! \r\n"
	);
	
	// Write all outcomes
	char operators[] = {'+', '-', '*', '/'};
	int (*funcs[4]) (int x, int y) = {sum, diff, prod, frac};
	
	for (int i = 0; i < 4; i++){
		
		// Operator filter
		fprintf(myfile, "    if oper == operators[%d]: \r\n", i);
		
		for (int num1 = 0; num1 <= 200; num1++)
			for (int num2 = 0; num2 <= 200; num2++){
				fprintf(myfile, "        if num_1 == %d and num_2 == %d: \r\n", num1, num2);
				fprintf(myfile, "            print('Answer: %d\\r\\n') \r\n", funcs[i](num1, num2));
				fprintf(myfile, "            continue \r\n");
			}
		fprintf(myfile, "\r\n");
	}
	
	// Close the file
	fclose(myfile);
	return 0;
}
