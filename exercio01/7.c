#include <stdio.h>

int main (void) {
   int **r;
   int i; int *p;
   i = 1234; p = &i;
   printf ("*p = %d\n", *p);
   printf (" p = %ld\n", (long int) p);
   printf (" p = %ld\n", (long int) *p);
   printf (" p = %ld\n", (long int) &i);
   printf (" p = %p\n", (void *) p);
   printf ("&p = %p\n", (void *) &p);
   return 0;
}