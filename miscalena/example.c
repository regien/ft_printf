#include <stdlib.h>
#include <stdio.h>

/*
int main(void)
{
	char		*str = "qweasdzxcasdqwe";
	long		vaina;
	long long	vaina2;
	int			ila;

	ila = 2147483648;
	vaina = 4294967296;
	vaina2 = 4294967296;


	printf("string: |%s|\n", str);
	printf("int = |%i| , long = |%l| long long = |%ll|", ila, vaina, vaina2);
	printf("pointer address: |%p|\n", str);
}
*/


int main(void)
{
    char ch = 'h', *string = "computer";
    int count = 234, hex = 0x10, oct = 010, dec = 10;
    double fp = 251.7366;
    wchar_t wc = (wchar_t)0x0058;
    wchar_t ws[4];

    printf("1234567890123%n4567890123456789\n\n", &count);
    printf("Value of count should be 13; count = %d\n\n", count);
    printf("%10c%5c\n", ch, ch);
    printf("%25s\n%25.4s\n\n", string, string);
    printf("%f    %.2f    %e    %E\n\n", fp, fp, fp, fp);
    printf("%i    %i     %i\n\n", hex, oct, dec);
}
