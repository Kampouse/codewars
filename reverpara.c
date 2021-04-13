#include  "stdio.h"
#include  "stdlib.h"

int isalapha(char str)
{
  if((str >= 'a' &&  str <= 'z')||(str >= 'A' && str <= 'Z'))
        return 0;

return 1;
}

int ft_strlen(char *str)
{
  int len;
    len  = 0;
  while(*str)
  {
  str++;
  len++;
  }
return len;
}
int ft_isspace(char str)
{
if((str >= 9 && str <= 13 ) || str == 32)
return 1;

return 0;


}

int ft_goodpara(char str)
{
    if(str == ')')
      return -1;
    if(str == '(')
      return 1;
return 0;
}

char  *ft_nesting(char *str,int len)
{
  int lenght;
  char *cat;
  char *copy;

copy = malloc(sizeof(char) * len);
cat = copy;
while(*str != '\0')
{
  lenght += ft_goodpara(*str);
 if((!isalapha(*str) || (ft_isspace(*str)))  &&  lenght % 2  == 0 )
 {

    *copy = *str;
    copy++;
 }
str++;
}
*copy = '\0';
return cat;
}

int main(void)
{
//how to insert elem into the string at the place it suppose to...
char *str  = "a (bac (d e))";

int len = 0;
  len = ft_strlen(str);


//ft_nesting("one (ruof ((rht)ee) owt)");
char *test = ft_nesting(str,len);
printf("%s",test);
free(test);

printf("%lu",sizeof(test));

//ft_nesting(" one (two (three) four)");

}
