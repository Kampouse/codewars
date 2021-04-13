#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
void putcar(int nbr)
{
write(1,&nbr,1);
}
int toi(const char *str)
{
 int result; 
  result = 0;
  while( (*str >= '0') &&  (*str <= '9'))
  {
    result = (result * 10) + ((*str) - '0');
      str++;
  }  
  if(result == 27)
    return result + 6; 
  else  if(result == 28)
    return result + 35; 
  else if(result == 29)
    return result + 3; 

  return 96 + result;
}


int inversing(int value)
{
  if(value >= 32 && value <= 63)
    return value;
return  (97 + ( 'z' - value ));
}
char *switchder(const char **code,size_t nbr)
{
char *str;
size_t len;
len = 0;
str = malloc(sizeof(char)* nbr);
while(len != nbr)
{

  str[len] =  (char)inversing(toi(code[len]));
  len++;
}
return str;
}
int main(void)
{
char *dog;
  const char *codes[] = { "26", "12", "23", "22", "4", "26", "9", "8" };

dog = switchder(codes,8);
printf("%s",dog);
}
