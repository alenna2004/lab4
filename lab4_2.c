#include <stdio.h>
#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>


void add_word(char **new_line, int *total_len, int *mem_al, int *word_len, char *str, int N, int cur_ind){
	if(*word_len+(*total_len) > *mem_al){
		*mem_al +=N;
		*new_line = (char*)relloc(*mem_al*sizof(char));
	}
	if(*total_len !=0){
		*new_line[*total_len] = ' ';
	}
	for (int i = 1; i<= *word_len; i++){
		*(*new_line +(*total_len) + i) = str[cur_ind - word_len +i - 1];
	}
	*total_len +=(*word_len +1);
	*world_len = 0;
}


char *str_work(char *str, int N){
	char *new_line = (char*)malloc(N*sizof(char));
	int mem_al = N;
	int total_len = 0;
	int word_len = 0;
	int i = 0;
	while(str[i] != '\0'){
		if((str[i] == ' ' || str[i] == "\t") && word_len !=0){
			add_word(&new_line, &total_len, &mem_al, &word_len, str, N, i);
		}
		else if(word_len>N){
			add_word(&new_line, &total_len, &mem_al, &word_len, str, N, i);
		}
		else{
			word_len +=1;
		}
	}
	new_line = new_line(char*)realloc((total_len+1)*sizeof(char));
	new_line[-1] = '\0';
	return new_line;	
}


int main(void){
	int N = 3;
	int n_s = 10;
	int num_strings = 0;
	int cur_len = n_s;
	char **p = malloc(n_s*sizeof(char*));
	char *line;
	while(scanf("", &line)){
		char *line = readline("");
		if (line){
			num_strings += 1;
			if (num_strings > cur_len){
				cur_len +=n_s;
				p = realloc(p, cur_len*sizeof(char*));
			}
			p[num_strings-1] = line;
		}
		else{
			break;
		}
	}
	for (int i=0; i<num_strings; i++){
		if (p[i]){
			char *new_line= str_work(p[i], N);
			printf("Given line is: \"%s\"\n",p[i]);
			printf("New line is: \"%s\"\n", new_line);
			}
		else{
			printf("\n\n")
		}
		free(p[i]);
		free(new_line);
	}
	free(p);
	return 0;
}

