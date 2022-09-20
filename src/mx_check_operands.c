#include <stdbool.h>

bool mx_isdigit(int);
int mx_strlen(const char*);
void mx_print_error(const char*, const char*);

void mx_check_operands(char **argv, char *operand1, char *operand2, char *operation, char *result) {
	if (mx_strlen(operand1) < 1)
		mx_print_error("Invalid operand: ", argv[1]);
	if (mx_strlen(operation) != 1)
		mx_print_error("Invalid operation: ", argv[2]);
	if (mx_strlen(operand2) < 1)
		mx_print_error("Invalid operand: ", argv[3]);
	if (mx_strlen(result) < 1)
		mx_print_error("Invalid result: ", argv[4]);
	for (int i = (*operand1 == '-') ? 1 : 0; i < mx_strlen(operand1); i++)
		if (operand1[i] != '?' && mx_isdigit(operand1[i]) == 0)
			mx_print_error("Invalid operand: ", argv[1]);
	if (*operation != '+' && *operation != '-'
	&& *operation != '*' && *operation != '/'
	&& *operation != '?')
		mx_print_error("Invalid operation: ", argv[2]);
	for (int i = (*operand2 == '-') ? 1 : 0; i < mx_strlen(operand2); i++)
		if (operand2[i] != '?' && !mx_isdigit(operand2[i]))
			mx_print_error("Invalid operand: ", argv[3]);
	for (int i = (*result == '-') ? 1 : 0; i < mx_strlen(result); i++)
		if (result[i] != '?' && !mx_isdigit(result[i]))
			mx_print_error("Invalid operand: ", argv[4]);
}

