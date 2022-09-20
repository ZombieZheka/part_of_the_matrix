
int mx_strncmp(const char *s1, const char *s2, int n){
	for(int i = 0; i < n; i++){
		char a = s1[i];
		char b = s2[i];
		
		if(a > b){
			return 1;
		}
		else if (a < b){
			return -1;
		}
	}
	return 0;
}




