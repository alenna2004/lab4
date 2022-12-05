#include <stdio.h>
#include <stdlib.h>
#include "mystr.h"


void *myrealloc(void *p, int new_size){
	char *new_p = (char *)malloc(new_size);
	mem_cpy(new_p, p, new_size);
	free(p);
	return new_p;
}

void *mem_cpy(void *dest, const void *src, int n){
	char *cdest = (char*)dest;
	char *csrc = (char*)src;
	for (int i = 0; i<n; i++){
		*(cdest+i)= csrc[i];
	};
	return (void*)cdest;
}

int str_len(const char *s){
	int len = 0;
	while(*(s+len)!='\0'){
		len+=1;
	}
	return len;
}


char *str_cat(char *dest, const char *app){
	int len1 = str_len(dest);
	int len2 = str_len(app);
	int new_len = len1 + len2;
	int i=0;
	while (i<len2){
		*(dest+len1) = app[i];
		i+=1;
		len1+=1;
	}
	*(dest +new_len) = '\0';
	return dest;
}



char *get_line(const char *prompt){
	printf("%s", prompt);
	int n, len = 0;
	int L = 80;
	char buf[L+1];
	char *ptr = (char*)malloc(sizeof(char));
	*ptr = '\0';
	do{
		n = scanf("%80[^\n]%", buf);
		if (n<0){
			free(ptr);
			ptr = NULL;
			continue;
		}
		if (n==0){
			scanf("%*c");
		}
		else{
			len += str_len(buf);
			ptr = (char*)myrealloc(ptr,(len+1)*sizeof(char));
			str_cat(ptr, buf);
		}
	}
	while(n>0);
	return ptr;
}
