#include <stdio.h>
int main(){
 int* pc;
 int c;
 c=22;
 printf("Address of c:%ld\n",&c);
 printf("Value of c:%ld\n\n",c);
 pc=&c;
 printf("Address of pointer pc:%ld\n",pc);
 printf("Content of pointer pc:%ld\n\n",*pc);
 c=11;
 printf("Address of pointer pc:%ld\n",pc);
 printf("Content of pointer pc:%ld\n\n",*pc);
 *pc=2;
 printf("Address of c:%ld\n",&c);
 printf("Value of c:%ld\n\n",c);
 return 0;
}
