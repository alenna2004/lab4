#include <stdio.h>
#include "mystr.h"
#include <stdlib.h>


char *str_work(const char *str, int N){
	int total_len = 0;
	int word_len = 0;
	char *word = (char*)malloc((N+1)*sizeof(char));
	if(!word){
		printf("Failed to allocate memory");
		return NULL;
	}
	int s_len = str_len(str);
	char *new_line = (char*)malloc((s_len*2)*sizeof(char));
	if(!new_line){
		printf("Failed to allocate memory");
		return NULL;
	}
	int i = 0;
	while(i<=s_len){
		if (str[i]!=' ' && str[i] !='\t' && word_len<N && i!=s_len){
			word[word_len] =str[i];
			word_len +=1;
		}
		else{
			if (word_len != 0){
				word[word_len] = ' ';
				word_len+=1;
				mem_cpy(new_line+total_len, word, word_len);
				total_len +=word_len;
				word_len = 0;
				if(str[i] != ' '&&str[i] != '\t'){
					i-=1;
				}
			}
		}
		i++;
	}
	free(word);
	if(total_len){
		new_line = (char*)myrealloc(new_line,(total_len)*sizeof(char));
		new_line[total_len-1] = '\0';
	}
	else{
		new_line[total_len] = '\0';
	}
	return new_line;	
}


int main(void){
	int N = 3;
	char *line = get_line("Enter the line: ");
	while(line){
		printf("\"%s\"\n", line);
		char * new_line = str_work(line, N);
		printf("\"%s\"\n", new_line);
		free(line);
		free(new_line);
		line = get_line("Enter the line: ");
	}
	return 0;
}
