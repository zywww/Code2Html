#include <conio.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#define	MIN_INPUT 0x20
#define	MAX_INPUT 0x7e
#include <ctype.h>

/*
* 所有功能有此函数实现：
* pszPw ： 保存密码的缓冲
* iMaxSize ：最大的密码长度，该长度必须小于缓冲区大小。
* 返回值为TRUE为成功获取密码。总是返回TRUE

*/
int R_L_K(char*s)
{
    if(strlen(s)>=6&&strlen(s)<=12)return 1;
    else return 0;
}
int rightful_key(char *s)
{
    int flag=0;
    while(*s)
    {
        if(! isalnum(*s++)){flag=1;break;}
    }
    if(flag)return 0;
    return 1;
}
int scanf_key(char* ps)
{
    int MaxSize=80;
unsigned char ch;
while(1){printf("      (密码由6~12个数字或字母构成)\n");
printf("              (返回上一界面 * )\n");
int i=0;
int bIsEcho=TRUE;
while( ( ch = (unsigned char)getch() ) && i < MaxSize )
{
bIsEcho=TRUE;
if ( ch == 13)//回车
{
ps[i++]=0;
break;
}
else if ( ch >= MIN_INPUT && ch <= MAX_INPUT) /*所有可打印字符*/
{
ps[i++]=ch;
}
else if ( ch == 8 && i> 0 )	/*退格键*/
{
ps[i--] = 0;
bIsEcho = FALSE;
putchar( ch );
putchar( ' ' );
putchar( ch );
}
else
bIsEcho = FALSE;
if(bIsEcho)
putchar('*');
}
ps[i]=0;
if(!strcmp(ps,"*")){system("CLS");return 0;}
if(!R_L_K(ps)){printf("\n密码长度不正确请重新输入\n");continue;}
if(!rightful_key(ps)){printf("\n输入含有不合法字符请重新输入密码\n");continue;}
system("CLS");return 1;
}
}
/*int scanf_key(char *key)
{
  char input[100];
  char ch;
  int i;

      while(1)
  {
      printf("      (密码由6~12个数字或字母构成)\n");
      printf("              (返回上一界面 * )\n");
  memset(input,0,10);
  i = 0;
  while((ch = getch()) != '\r')
   {
   if( ch == '\b')
    {
    putchar('\b');
    putchar(0);
    putchar('\b');
    i--;
    }
   else{
    input[i++] = ch;
    putchar('*');
     }
   }
   if(!strcmp(input,"*")){system("CLS");return 0;}
   if(!R_L_K(input)){printf("\n密码长度不正确请重新输入\n");continue;}
   if(!rightful_key(input)){printf("\n输入含有不合法字符请重新输入密码\n");continue;}
   strcpy(key,input);
 system("CLS");return 1;
  }

}*/
int Input_key(char *key)
{
   int MaxSize=80;
   unsigned char ch;
   char ps[MaxSize];
  printf("      (退出输入并返回返回上一界面  *  )\n");
  while(1)
  {

 int i=0;
int bIsEcho=TRUE;
while( ( ch = (unsigned char)getch() ) && i < MaxSize )
{
bIsEcho=TRUE;
if ( ch == 13)//回车
{
ps[i++]=0;
break;
}
else if ( ch >= MIN_INPUT && ch <= MAX_INPUT) /*所有可打印字符*/
{
ps[i++]=ch;
}
else if ( ch == 8 && i> 0 )	/*退格键*/
{
ps[i--] = 0;
bIsEcho = FALSE;
putchar( ch );
putchar( ' ' );
putchar( ch );
}
else
bIsEcho = FALSE;
if(bIsEcho)
putchar('*');
}
ps[i]=0;
  if(!#strcmp(ps,"*"))return 2;
  if(strcmp(key,ps)==0)return 1;
  return 0;
  printf("\n");
  }
}

int main()
{
    char key[20];
    while(1){
    printf("\n%d\n",Input_key("123456"));
    }
}


