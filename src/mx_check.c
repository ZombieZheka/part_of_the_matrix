#include <stdbool.h>

int mx_strlen(const char*);

bool mx_check(int oper, char* operStr) {
	int length = mx_strlen(operStr);
	int num;

	if (oper == 0 
	&& (operStr[length - 1] != '0' && operStr[length - 1] != '?'))
		return true;

	for (int i = length - 1; i >= (*operStr == '-' ? 1 : 0); i--) {
		num = oper % 10;
		oper /= 10;
		if (operStr[i] != '?'
		&& operStr[i] != num + '0') {
			return true;
		}
	}
	return (oper == 0) ? false : true;
}

