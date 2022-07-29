#ifndef MAIN_H
#define MAIN_H

/**
 * struct long_num - A data structure for storing large positive numbers
 * @len: Number of digits
 * @size: Number of numbers in num
 * @num: Array of numbers
 */
struct long_num
{
	unsigned int len;
	unsigned int size;
	unsigned int *num;
};

/**
 * long_num - Typedef for struct long_num
 */
typedef struct long_num longnum;

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void print(char *str);
unsigned int unsigned_atoi(char *num, unsigned int n);
int _isdigit(char c);
void print_uint(unsigned int x, unsigned int n);
unsigned int _strlen(char *s);
longnum readnum(char *s);
void printnum(longnum n);
unsigned int modulo(unsigned int a, unsigned int b);
longnum mulnum(longnum a, longnum b);
void print_start(unsigned int a);
void carry_over(longnum a);

#endif
