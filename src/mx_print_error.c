#include <stdlib.h>

void mx_printerr(const char*);

void mx_print_error(const char* error_type, const char* str) {
	mx_printerr(error_type);
	mx_printerr(str);
	mx_printerr("\n");
	exit(-1);
}

