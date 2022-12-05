#ifndef MYSTR
# define MYSTR


char *readline(const char *prompt);
unsigned long int strlen(const char *s);
void *memcpy(void *dest, const void *src, unsigned long int n);
void *myrealloc(void *p, int  new_size);

#endif
