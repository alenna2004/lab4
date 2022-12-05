#include <stdio.h>
#include <stdlib.h>
#include "mystr.h"


void *myrealloc(void *p, int new_size){
	char *new_p = (char *)malloc(new_size);
	memcpy(new_p, p, new_size);
	free(p);
	return new_p;
}

void *memcpy(void *dest, const void *src,unsigned long int n){
	char *cdest = (char*)dest;
	char *csrc = (char*)src;
	for (int i = 0; i<n; i++){
		*(cdest+i)= csrc[i];
	};
	return (void*)cdest;
}

unsigned long int strlen(const char *s){
	unsigned long int len = 0;
	while(*(s+len)!='\0'){
		len+=1;
	}
	return len;
}


char *strcat(char *dest, const char *app){
	int len1 = strlen(dest);
	int len2 = strlen(app);
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



char *readline(const char *prompt){
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
			printf("\n");
			ptr = NULL;
			continue;
		}
		if (n==0){
			scanf("%*c");
		}
		else{
			len += strlen(buf);
			ptr = (char*)myrealloc(ptr,(len+1)*sizeof(char));
			strcat(ptr, buf);
		}
	}
	while(n>0);
	return ptr;
}
