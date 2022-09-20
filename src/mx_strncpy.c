char *mx_strncpy(char *dst, const char *scr, int len){
	int lenth = 0;
	for(int i = 0; i < len; i++){
		dst[i] = scr[i];
		lenth++;
	}
	dst[lenth] = '\0';
	return dst;
}




