#include <stdio.h>
#include <stdlib.h>


void *myrealloc(void *p, int  new_size){
	void *new_p = malloc(new_size);
	for(int i; i<new_size; i++){
		new_p[i] = p[i];
	}
	free(p);
	return new_p;
}


int strlen(char *s){
	int len = 0;
	while(*(*s+len)!='\0'){
		len+=1;
	}
	return len;
}


void strcat(char **s1, char *s2){
	int len1 = strlen(*s1);
	int len2 = strlen(s2);
	int new_len = len1 + len2;
	int i=0;
	while (i<len2){
		*(*s1+len1) = s2[i];
		i+=1;
		len1+=1;
	}
}



char *get_line(void){
	int n, len = 0
	int L = 80;
	char buf[L+1];
	int n;
	char *ptr = (char*)malloc(siziof(char));
	//*ptr = '\0'
	do{
		n = scanf("%80[^\n]%", buf)
		if (n<0){
			free(ptr);
			ptr = NULL;
			continue;
		}
		if (n==0){
			scanf("%*c")
		}
		else{
			len += strlen(buf);
			ptr = (char*)realloc(ptr,(len+1)*sizeof(char));
			strcat(&ptr, buf)
		}
	}
	while(n>0);
	return 0;
}

