#include <stdbool.h>

bool mx_isspace(char);
bool mx_isdigit(char);

int mx_atoi(const char *str) {
	int number = 0;
	bool negative = false;

	if (*str == '+'
	|| *str == '-') {
		if (*str == '-')
			negative = !negative;
		str++;
	}
	while (*str != '\0') {
		if (!mx_isdigit(*str))
			return 0;
		number *= 10;
		number += *str - '0';
		str++;
	}
	if (negative)
		number *= -1;
	return (negative) ? -number : number;
}

