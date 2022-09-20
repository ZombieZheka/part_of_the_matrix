#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


char *mx_strncpy(char *dst, const char *scr, int len);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
void mx_strdel(char **str);
bool mx_isspace(char c);


char *mx_strtrim(const char *str){
	if(str == NULL){
		return NULL;
	}
	int frontend = 0;
	int backend = mx_strlen(str);
	
	for(int i =0; i < mx_strlen(str); i++){
		if(mx_isspace(str[i]) == 1){
			frontend = i + 1;
			continue;
		}
		else{
			break;
		}
	}
	for(int i = mx_strlen(str) - 1; i > 0; i--){
		if(mx_isspace(str[i]) == 1){
			backend = i - 1;
			continue;
		}
		else{
			break;
		}
	}
	char *newStr = mx_strnew(backend - frontend + 1);
	newStr = mx_strncpy(newStr,&str[frontend],backend - frontend+1);
	return newStr;	
}


