#include <stdio.h>
#include "../inc/minilibmx.h"
#include <stdbool.h>

void print(int op1, int op2, char *p, int res) {
	mx_printint(op1);
	mx_printchar(' ');
	mx_printstr(p);
	mx_printchar(' ');
	mx_printint(op2);
	mx_printstr(" = ");
	mx_printint(res);
	mx_printchar('\n');
}

int marked(int num, char* str) {
	return (*str == '-') ? -num : num;
}

int main(int argc, char *argv[]) {
	if(argc != 5) {
		mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]");
		return -1;
	}
	// delete spases
	char *operand1Str = mx_strtrim(argv[1]);
	char *operand2Str = mx_strtrim(argv[3]);
	char *operation = mx_strtrim(argv[2]);
	char *resultStr = mx_strtrim(argv[4]);
	mx_check_operands(argv, operand1Str, operand2Str, operation, resultStr);

	for (int oper_num = 0; oper_num < 4; oper_num++) {
	for(int operand1 = 0; operand1 < mx_pow(10, mx_strlen(operand1Str)); operand1++) {
		if(mx_check(operand1, operand1Str))
			continue;
		for(int operand2 = 0; operand2 < mx_pow(10, mx_strlen(operand2Str)); operand2++) {
			if(mx_check(operand2, operand2Str))
				continue;
			for(int result = 0; result < mx_pow(10, mx_strlen(resultStr)); result++) {
				if(mx_check(result, resultStr))
					continue;
				if(mx_strcmp(operation,"+") == 0
				|| (mx_strcmp(operation, "?") == 0 && oper_num == 0)) {
					if(marked(operand1, operand1Str) + marked(operand2, operand2Str) == marked(result, resultStr)) {
						print(marked(operand1, operand1Str), marked(operand2, operand2Str), "+", marked(result, resultStr));
					}
				}
				else if(mx_strcmp(operation, "-") == 0
				|| (mx_strcmp(operation, "?") == 0 && oper_num == 1)) {
					if(marked(operand1, operand1Str) - marked(operand2, operand2Str) == marked(result, resultStr)) {
						print(marked(operand1, operand1Str), marked(operand2, operand2Str), "-", marked(result, resultStr));
					}
				}
				else if(mx_strcmp(operation,"*") == 0
				|| (mx_strcmp(operation, "?") == 0 && oper_num == 2)) {
					if(marked(operand1, operand1Str) * marked(operand2, operand2Str) == marked(result, resultStr)) {
						print(marked(operand1, operand1Str), marked(operand2, operand2Str), "*", marked(result, resultStr));
					}
				}
				else if(mx_strcmp(operation,"/") == 0
				|| (mx_strcmp(operation, "?") == 0 && oper_num == 3)) {
					if(operand2 != 0
					&& marked(operand1, operand1Str) / marked(operand2, operand2Str) == marked(result, resultStr)) {
						print(marked(operand1, operand1Str), marked(operand2, operand2Str), "/", marked(result, resultStr));
					}
				}
			}
		}
	}
	if (mx_strcmp(operation, "?") != 0)
		break;
	}
	mx_strdel(&operand1Str);
	mx_strdel(&operand2Str);
	mx_strdel(&operation);
	mx_strdel(&resultStr);
}




