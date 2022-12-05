#ifndef MYSTR
# define MYSTR


char *get_line(const char *prompt);
int str_len(const char *s);
void *mem_cpy(void *dest, const void *src, int n);
void *myrealloc(void *p, int  new_size);

#endif