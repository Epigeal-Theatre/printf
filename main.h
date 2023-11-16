#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


#define FMINUS 1
#define FPLUS 2
#define FZERO 4
#define FHASH 8
#define FSPACE 16



#define SLONG 2
#define SSHORT 1



#define UNUSED(x) (void)(x)
#define BUFFSIZE 1024



/**
 * struct fmt - truct stop
 *
 * @fmt: our format
 *
 * @fn: format func
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - typedef stop
 *
 * @fmt: our format.
 *
 * @fm_t: format func
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int intcontenthandler(const char *fmt, int *i,
va_list list, char bf[], int fl, int wi, int pr, int sz);



/*batchfunctions*/
int printcharacter(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printstring(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printpercent(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printint(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printbinary(va_list tp, char bf[], int fl, int wd, int pr, int sz);

int printunsigned(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printoctals(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printhexadecimals(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printHEXADECIMAL(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printhexadecimallowup(va_list tp, char mpt[],
		char bf[], int fl, char flc, int wd, int pr, int sz);

int printpointer(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printnonprintable(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printinreverse(va_list tp, char bf[], int fl, int wd, int pr, int sz);
int printrot13(va_list tp, char bf[], int fl, int wd, int pr, int sz);


/*08_formathandlers(handlers of width)*/
int writehandle_char(char c, char bf[], int fl, int wd, int pr, int sz);
int numberwriter(int is_negative, int index,
		char bf[], int fl, int wd, int pr, int sz);
int numwriter(int index, char bf[], int fl, int wd,
		int pre, int leng, char pad, char extra_c);
int unsignedwriter(int is_negative, int index, char bf[],
		int fl, int wd, int pr, int sz);
int pointerwrite(char bf[], int index, int leng, int wd,
		int fl, char pad, char extra_c, int padst);


/*09_slit.c functions*/
int canweprint(char c);
int apphex(char asc, char bf[], int i);
int dowehavedigit(char c);
long int convertsznumber(long int num, int sz);
long int unsignedszconvert(unsigned long int num, int sz)
#endif
