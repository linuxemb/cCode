#include <stdio.h>

//  Sort arraqy usng one arrya  based on select 

int main ()
{
//unsigned int x = 0x76543210;
unsigned int x = 0x1;

char *c = (char*) &x;
printf("%c", *c);
printf ("*c is: 0x%x\n", *c);
// if (*c == 0x10)
if (*c == 0x1)
{
printf("Underlying architecture is little endian");
}
else
{
printf ("Underlying architecture is big endian.");
}

return 0;
}

 