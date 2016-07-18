#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define	MIN_INPUT 0x20
#define	MAX_INPUT 0x7e
int pppp=0;
typedef struct userdata
{
    char name[20];
    char phonenumber[20];
    char qq[20];
    char address[20];
    char relation[20];
    int no;
    struct userdata *next;
    struct userdata *nextnext;
} userdata;
userdata *tttt=NULL;
int  denglujiemiancaidan();
int zhuce();
int shouxinxi(char name[]);
int faxinxi(char *name);
void chakan(char name[]);
int tianjia(char name[]);
userdata * shanchu(char name[]);
userdata * genggai(char name[]);
int fenxiang(char name[]);
void chakan(char name[]);
int tianjia(char name[]);
userdata * shanchu(char name[]);
userdata * genggai(char name[]);
int fenxiang(char name[]);
userdata *chazhao(char name[]);
int gaimima();
int dadianhua();
int dianhuajiemian(char a);
int check_password(char password[]);
int check_name(char name[]);
int panduan(char *a,char *name);
int getdata( char* ps);
int GetPassword(char * ps);
char * jiemi(char mima[]);
char * jiami(char mima[]);
char * jiami(char mima[])
{
    int n,i;
    n=strlen(mima);
    for(i=0; i<=n-1; i++)
        mima[i]=mima[i]+i;
    return mima;
}
char * jiemi(char mima[])
{
    int n;
    n=strlen(mima);
    for(n=n-1; n>=0; n--)
        mima[n]=mima[n]-n;
    return mima;
}
int GetPassword(char * ps)
{
    int MaxSize=80;
    unsigned char ch;
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
    printf("\n");
    return TRUE;
}
int getdata(char* ps)
{
    int MaxSize=80;
    signed char ch;
    int i=0;
    int bIsEcho=TRUE;
    while( ( ch = (signed char)getch() ) && i < MaxSize )
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
        else if(ch<0)
        {
            putchar(ch);
            ps[i++]=ch;
            ch=getch();
            ps[i++]=ch;
        }
        else if ( ch == 8 && i> 0 )	/*退格键*/
        {
            if(ps[i-1]<0)
            {
                ps[i--] = 0;
                ps[i--] = 0;
                bIsEcho = FALSE;
                putchar( ch );
                putchar( ch );
                putchar( ' ' );
                putchar( ch );
                goto Z;
            }
            ps[i--] = 0;
            bIsEcho = FALSE;
            putchar( ch );
            putchar( ' ' );
            putchar( ch );
        }
        else if(ch==8&&i==0)return 0;
        else
            bIsEcho = FALSE;
Z:
        if(bIsEcho)
            putchar(ch);
    }
    ps[i]=0;
    i=0;
    while(ps[i]!=0)
    {
        if(ps[i]==' ') return 2;
        i++;
    }//存在空格的情况下，返回2
    printf("\n");
    return 1;
}
int panduan(char *a,char *name)
{
    int i,j,l,m,k,t=0;
    i=strlen(a);
    j=strlen(name);
    for(l=0; l<i; l++)
        for(m=0; m<j; m++)
        {
            for(k=0; k<l; k++)if(a[l]==a[k])
                {
                    l++;
                    break;
                }
            if(l>=i) break;
            if(a[l]==name[m]) t++;
        }
    if(t>=i) return 1;
    else return 0;
}
int check_name(char name[])//判断用户名长度，若超过12个字符，则错误，只能是数字，字母的组合
{
    int n;
    n=strlen(name);
    if(n<3||n>12) return 0;
    while(n)
    {
        if(!isalnum(name[n-1])) break;
        n--;
    }
    if(!n) return 1;
    else return 0;
}
int check_password(char password[])//判断密码合法性，长度不超过15个字符，不少于6个字符，只能是数字，字母，符合的组合
{
    int n;
    n=strlen(password);
    if(n>15||n<6) return 0;
    while(n)
    {
        if(!(isalnum(password[n-1])||ispunct(password[n-1]))) break;
        n--;
    }
    if(!n) return 1;
    else return 0;
}
int dianhuajiemian(char a)
{
    if(a=='1')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|               |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='2')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |                 |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='3')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='4')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|               |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");

    }
    if(a=='5')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |                 |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='6')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='7')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|               |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='8')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |                 |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='9')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='*')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|               |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='0')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |                 |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    if(a=='#')
    {
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |                   |\n");
        printf("|_______________|_________________|___________________|\n");
        Sleep(100);
        system("CLS");
        printf(" _____________________________________________________\n");
        printf("|               |                 |                   |\n");
        printf("|       1       |        2        |          3        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       4       |        5        |          6        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       7       |        8        |          9        |\n");
        printf("|_______________|_________________|___________________|\n");
        printf("|               |                 |                   |\n");
        printf("|       *       |        0        |          #        |\n");
        printf("|_______________|_________________|___________________|\n");
    }
    return 0;
}
int dadianhua()
{
    char a,dianhua[100];
    int i=0,j=1;
    system("CLS");
    printf(" _____________________________________________________\n");
    printf("|               |                 |                   |\n");
    printf("|       1       |        2        |          3        |\n");
    printf("|_______________|_________________|___________________|\n");
    printf("|               |                 |                   |\n");
    printf("|       4       |        5        |          6        |\n");
    printf("|_______________|_________________|___________________|\n");
    printf("|               |                 |                   |\n");
    printf("|       7       |        8        |          9        |\n");
    printf("|_______________|_________________|___________________|\n");
    printf("|               |                 |                   |\n");
    printf("|       *       |        0        |          #        |\n");
    printf("|_______________|_________________|___________________|\n");
    while(a!=13)
    {
        a=getch();
        fflush(stdin);
        // if(a==8) {dianhua[i++]=0;putchar(a);putchar(' ');putchar(a);goto i;}
        dianhua[i++]=a;
        dianhua[i]=0;

        if(a=='1')
        {
            Beep(1209,80);
            dianhuajiemian('1');
            printf("%s",dianhua);
        }
        if(a=='2')
        {
            Beep(1336,80);
            dianhuajiemian('2');
            printf("%s",dianhua);
        }
        if(a=='3')
        {
            Beep(1477,80);
            dianhuajiemian('3');
            printf("%s",dianhua);
        }
        if(a=='4')
        {
            Beep(1290,80);
            dianhuajiemian('4');
            printf("%s",dianhua);
        }
        if(a=='5')
        {
            Beep(1336,80);
            dianhuajiemian('5');
            printf("%s",dianhua);
        }
        if(a=='6')
        {
            Beep(1477,80);
            dianhuajiemian('6');
            printf("%s",dianhua);
        }
        if(a=='7')
        {
            Beep(1209,80);
            dianhuajiemian('7');
            printf("%s",dianhua);
        }
        if(a=='8')
        {
            Beep(1336,80);
            dianhuajiemian('8');
            printf("%s",dianhua);
        }
        if(a=='9')
        {
            Beep(1477,80);
            dianhuajiemian('9');
            printf("%s",dianhua);
        }
        if(a=='*')
        {
            Beep(1209,80);
            dianhuajiemian('*');
            printf("%s",dianhua);
        }
        if(a=='0')
        {
            Beep(1336,80);
            dianhuajiemian('0');
            printf("%s",dianhua);
        }
        if(a=='#')
        {
            Beep(1477,80);
            dianhuajiemian('#');
            printf("%s",dianhua);
        }
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                        正在拨打");
    while(j!=5)
    {
        j++;
        Beep(500,1200);
        printf(".");
        Sleep(800);
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                        您拨打的用户正忙，请稍后再拨");
    printf("\n按任意键返回...");
    a=getch();
    return 0;
}
int gaimima()
{
    fflush(stdin);
    char name1[20],name2[20],password1[20],password2[20],password3[20];
    char data[500][20],choicee[100];
    int i=0,j;
    FILE *fp;
AAA:
    system("CLS");
    printf("                                          Max通讯录\n\n");
    printf("  更改密码\n");
    printf("    用户名:");
    gets(name1);
    strcat(name1,".txt");
    fp=fopen(name1,"r");
    if(fp==NULL)
    {
        printf("无此用户\a，1.放弃修改 2.重新输入：");
        fclose(fp);
DDD:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"1")==0) return 1;
        else if(strcmp(choicee,"2")==0) goto AAA;
        else
        {
            printf("输入错误，请重新输入:\a");
            goto DDD;
        }
    }
    printf("  旧的密码:");
BBB:
    GetPassword(password1);
    if(strlen(password1)>20)
    {
        printf("输入错误，请重新输入:\a");
        goto BBB;
    }
    fp=fopen(name1,"r");
    fscanf(fp,"%s%s",name2,password2);
    fclose(fp);
    if(strcmp(password1,jiemi(password2)))
    {
        printf("密码错误，\a1.放弃修改 2.重新输入:");
CCC:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"1")==0) return 9;
        else if(strcmp(choicee,"2")==0)
        {
            system("CLS");
            printf("                                          Max通讯录\n\n");
            printf("  更改密码\n");
            printf("    用户名:");
            printf("%s\n",name2);
            printf("  旧的密码:");
            goto BBB;
        }

        else
        {
            printf("输入错误，请重新输入:\a");
            goto CCC;
        }
    }
    if(!strcmp(name2,"001"))
    {
        printf("该用户为公共通讯录用户，若要更改密码请先输入二级密码:\a");
        GetPassword(password3);
        if(strcmp(password3,"8868431"))
        {
            printf("输入错误，将返回主菜单\a");
            Sleep(1500);
            return 2;
        }
        else printf("验证成功\n");
    }
    printf("(密码不能多于15个字符或少于6 个字符，且只能由数字，字母和符号组成)\n");
    printf("  新的密码:");
C:
    GetPassword(password1);
    if(!check_password(password1))
    {
        printf("新密码不合法,请重新输入:\a");
        goto C;
    }
    strcat(name2,".txt");
    fp=fopen(name2,"r");
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    i--;
    strcpy(data[1],jiami(password1));
    fp=fopen(name2,"w");
    fprintf(fp,"%s %s\n",data[0],data[1]);
    for(j=2; j<=i; j=j+5)
        fprintf(fp,"%s %s %s %s %s\n",data[j],data[j+1],data[j+2],data[j+3],data[j+4]);
    fclose(fp);
    printf("更改成功...");
    Sleep(1000);
    return 0;
}
userdata *chazhao(char name[])
{
    system("CLS");
    printf("                                          Max通讯录\n\n");
    FILE *fp;
    char data[7][20],a[80],abc[9][30],choicee[100];
    int i=0,j=0,k,l=0,m,t,n=1,z=0,w=0,dd;
    strcat(name,".txt");
    userdata *head,*headhead,*p,*q,*r;
    fp=fopen(name,"r");
    while(fscanf(fp,"%s",abc[z++])!=EOF)if(z>=10)break;
    fclose(fp);
    if(z==8)
    {
        printf("暂无联系人");
        return 0;//无联系人
    }
    fp=fopen(name,"r");
    while(i!=7) fscanf(fp,"%s",data[i++]);
    head=( userdata*)malloc(sizeof( userdata));
    p=( userdata*)malloc(sizeof( userdata));
    head->next=p;
    p->next=NULL;
    p->nextnext=NULL;
    while(fscanf(fp,"%s%s%s%s%s",p->name,p->phonenumber,p->qq,p->address,p->relation)!=EOF)
    {
        q=p;
        p=(userdata*)malloc(sizeof( userdata));
        p->next=NULL;
        p->nextnext=NULL;
        q->next=p;
    }
    fclose(fp);
    q->next=NULL;
    q->nextnext=NULL;
    free(p);
    printf("可通过这些方法查找：1.姓名 2.手机/短号 3.QQ 4.住址 5.群组 6.返回上一层\n");
m:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"2")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"3")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"4")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"5")==0)i=choicee[0]-'0';
    else if(strcmp(choicee,"6")==0)
    {
        pppp=1;
        return (userdata *)6;//返回
    }
    else
    {
        printf("输入错误，请重新输入:\a");
        goto m;
    }
    if(i==5) goto A;
    printf("请输入关键字,注意不超过20个字符(直接按回车可查找到全部):");
    fflush(stdin);
    gets(a);
    j=strlen(a);
    while(j>20)
    {
        fflush(stdin);
        printf("输入错误请重新输入:\a");
        gets(a);
        j=strlen(a);
    }
    p=head->next;
    printf("        %10s%17s%14s%15s%10s\n","姓名","手机/短号","QQ","住址","群组");
    if(i==1)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->name);
                if(j>t) break;
                for(m=0; m<t; m++)
                    if(p->name[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->name))
            {
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else  if(i==2)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->phonenumber);
                if(j>t) break;

                for(m=0; m<t; m++)
                    if(p->phonenumber[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->phonenumber))
            {
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else  if(i==3)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->qq);
                if(j>t) break;
                for(m=0; m<t; m++)
                    if(p->qq[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->qq))
            {
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else if(i==4)
    {
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        while(p)
        {
            k=1;
            for(l=0; l<j; l++)
            {
                t=strlen(p->address);
                if(j>t) break;
                for(m=0; m<t; m++)
                    if(p->address[m]==a[l]) break;
                if(m>=t) k=0;
                else k=1;
                if(k==0) break;
            }
            if(l>=j&&panduan(a,p->address))
            {
                //p->no=n++;
                r->nextnext=p;
                r=r->nextnext;
            }
            p=p->next;
        }
    }
    else if(i==5)
    {
A:
        p=head->next;
        headhead=( userdata*)malloc(sizeof(userdata));
        headhead->nextnext=NULL;
        r=headhead;
        printf("您可通过这些群组查找:1.家庭 2.朋友 3.同学 4.同事 5.其他\n");
        printf("请输入您的选择:");
C:
        scanf("%s",a);
        fflush(stdin);
        if(strcmp(a,"1")==0) strcpy(a,"家庭");
        else if(strcmp(a,"2")==0) strcpy(a,"朋友");
        else if(strcmp(a,"3")==0) strcpy(a,"同学");
        else if(strcmp(a,"4")==0) strcpy(a,"同事");
        else if(strcmp(a,"5")==0) strcpy(a,"其他");
        else
        {
            printf("\n");
            printf("输入错误，请重新输入:\a");
            goto C;
        }
        dd=5;
        while (p)
        {
            if(strcmp(p->relation,a)==0)
            {
                r->nextnext=p;
                r=p;
            }
            p=p->next;
        }
    }
    n=1;
    if(dd==5)
    {
        w=0;
        r=headhead->nextnext;
        printf("家庭：");
        while(r)
        {
            w++;
            r->no=n++;
            if(w!=1)printf("      ");
            printf("%2d:%10s%17s %14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
            r=r->nextnext;
        }
        dd=0;
    }
    else
        for(i=1; i<=5; i++)
        {
            w=0;
            r=headhead->nextnext;
            if(i==1)printf("家庭：");
            if(i==2)printf("朋友：");
            if(i==3)printf("同学：");
            if(i==4)printf("同事：");
            if(i==5)printf("其他：");
            while(r)
            {
                if(i==1)
                {
                    if(strcmp(r->relation,"家庭")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==2)
                {
                    if(strcmp(r->relation,"朋友")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==3)
                {
                    if(strcmp(r->relation,"同学")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==4)
                {
                    if(strcmp(r->relation,"同事")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                else if(i==5)
                {
                    if(strcmp(r->relation,"其他")==0)
                    {
                        w++;
                        r->no=n++;
                        if(w!=1)printf("      ");
                        printf("%2d:%10s%17s%14s%15s%10s\n",r->no,r->name,r->phonenumber,r->qq,r->address,r->relation);
                    }
                }
                r=r->nextnext;
            }
            if(w==0) printf("暂无\n");
        }
    tttt=headhead;
    return head;
}
int fenxiang(char name[])
{
    FILE *fp;
    char name2[30],a,data[100][20],choicee[100];
    userdata *headhead,*head,*q;
    int choice,i=0,j=0,t;
    system("CLS");
    printf("                                          Max通讯录\n\n");
    printf("您可以通过此功能，向其他用户分享您的联系人信息，现在先查找您要分享的联系人\n\n按任意键继续...");
    a=getch();
    printf("%c",a);
    strcpy(name2,name);
    head=chazhao(name2);
    headhead=tttt;
    if(head==( userdata *)0)
    {
        Sleep(1500);
        return 2;
    }
    if(head==( userdata *)6) return 6;
    if(!headhead->nextnext)
    {
        printf("抱歉，没有找到\n");
        Sleep(1000);
        return 2;
    }
    q=headhead->nextnext;
    i=1;
    while(q)
    {
        i++;
        q=q->nextnext;
    }
    i=i-1;
    printf("请输入您要分享的是第几位联系人:");
A:
    scanf("%d",&choice);
    fflush(stdin);
    if(choice<=0||choice>i)
    {
        printf("输入错误，请重新输入:");
        goto A;
    }
    q=headhead->nextnext;
    while(q)
    {
        if(choice==q->no) break;
        q=q->nextnext;
    }
    fp=fopen("datadatadata.txt","r");
    i=0;
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    system("CLS");
    printf("您可以将您刚才选择的联系人分享给下列用户：\n");
    j=0;
    i=i-1;
    while(j<=i-1)
    {
        printf("%2d:%s\n",j+1,data[j]);
        j++;
    }
    t=i;//i为用户个数
    printf("您要向哪位用户分享联系人:");
    if(i>=10&&i<=99)
    {
p:
        scanf("%s",choicee);
        fflush(stdin);
        if(strlen(choicee)==1)
        {
            choicee[1]='0';
            choicee[2]=0;
        }
        i=choicee[0]-'0'+(choicee[1]-'0')*10-1;
        if(strlen(choicee)<=0||strlen(choicee)>2||i<=0||i>t)
        {
            printf("输入错误，请重新输入:\a");
            goto p;
        }
    }
    else if(i<=9&&i>=0)
    {
q:
        scanf("%s",choicee);
        fflush(stdin);
        i=choicee[0]-'0';
        if(strlen(choicee)!=1||i<=0||i>t)
        {
            printf("输入错误，请重新输入:\a");
            goto q;
        }
    }
    strcat(data[i-1],"share.txt");
    fp=fopen(data[i-1],"a");
    fprintf(fp,"%s %s %s %s %s\n",q->name,q->phonenumber,q->qq,q->address,q->relation);
    fclose(fp);
    printf("分享成功");
    Sleep(1500);
    return 2;
}
userdata * genggai(char name[])
{
    char data[10][22],name2[80],name3[80],choicee[100],dd[100];
    strcpy(name2,name);
    strcpy(name3,name);
    userdata *headhead,*head,*q;
    FILE *fp;
    int i=1,n,j;
    int choice;
    char aa[80];
CC:
    strcpy(name,name3);
    strcpy(name2,name3);
    printf("现在请查找您要更改的项目");
    Sleep(1500);
    system("CLS");
    head=chazhao(name);
    if(head==(userdata *)0)
    {
        Sleep(1500);
        return (userdata *)2;
    }
    if(head==(userdata *)6) return (userdata *)6;
    headhead=tttt;
    if(!headhead->nextnext)
    {
        printf("抱歉，没有找到\n");
        Sleep(1000);
        return (userdata *)2;
    }
    q=headhead->nextnext;
    i=1;
    while(q)
    {
        i++;
        q=q->nextnext;
    }
    i=i-1;//i为搜索到的个数
    if(i==1)
    {
        q=headhead->nextnext;
        goto BB;
    }
    printf("您要更改的是上面第几位联系人:");
AA:
    fflush(stdin);
    choice=0;
    scanf("%d",&choice);
    if(!choice||choice<1||choice>i)
    {
        printf("输入错误，请重新输入:\a");
        goto AA;
    }
    fflush(stdin);
    i=1;
    q=headhead->nextnext;
    while(q)
    {
        if(choice==q->no) break;
        q=q->nextnext;
    }

BB:
    printf("可更改项目：1.姓名 2.手机/短号 3.QQ 4.住址 5.群组 6.放弃更改\n请输入您要更改的项目:");
j:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) printf("(不超过10个字符，不可含空格)新姓名:");
    else if(strcmp(choicee,"2")==0) printf("(不超过17个字符，不可含空格和汉字)新手机/短号:");
    else if(strcmp(choicee,"3")==0) printf("(不超过14个字符，不可含空格和汉字)新QQ:");
    else if(strcmp(choicee,"4")==0) printf("(不超过15个字符，不可含空格)新住址:");
    else if(strcmp(choicee,"5")==0)
    {
        printf("可更改为的群组: 1.家庭 2.朋友 3.同学 4.同事 5. 其他\n");
        printf("请输入您的选择:");
cc:
        scanf("%s",dd);
        fflush(stdin);
        if(strcmp(dd,"1")==0) strcpy(aa,"家庭");
        else if(strcmp(dd,"2")==0) strcpy(aa,"朋友");
        else if(strcmp(dd,"3")==0) strcpy(aa,"同学");
        else if(strcmp(dd,"4")==0) strcpy(aa,"同事");
        else if(strcmp(dd,"5")==0) strcpy(aa,"其他");
        else
        {
            printf("输入错误，请重新输入:");
            goto cc;
        }
        strcpy(q->relation,aa);
        goto ff;

    }
    else if(strcmp(choicee,"6")==0) return (userdata *)6;
    else
    {
        printf("输入错误，请重新输入:\a");
        goto j;
    }
    choice=choicee[0]-'0';
d:
    gets(aa);
    fflush(stdin);
    n=strlen(aa);
    for(j=0; j<=n-1; j++)if(aa[j]==' ') break;
    if(j<=n-1)
    {
        printf("输入错误，请重新输入:\a");
        goto d;
    }
    while(n>20)
    {
        printf("输入错误，请重新输入:\a");
        gets(aa);
        fflush(stdin);
    }
    if(choice==2||choice==3)
    {
        for(j=0; j<=n-1; j++)if(aa[j]<0) break;
        if(j<=n-1)
        {
            printf("输入错误，请重新输入:\a");
            goto d;
        }
    }
    if(choice==1) strcpy(q->name,aa);
    else if(choice==2) strcpy(q->phonenumber,aa);
    else if(choice==3) strcpy(q->qq,aa);
    else if(choice==4) strcpy(q->address,aa);
    else if(choice==5) strcpy(q->relation,aa);
ff:
    strcat(name2,".txt");
    fp=fopen(name2,"r");
    i=0;
    while(i!=7) fscanf(fp,"%s",data[i++]);
    fclose(fp);
    fp=fopen(name2,"w");
    for(i=0; i<=6; i++) fprintf(fp,"%s ",data[i]);
    fprintf(fp,"\n");
    q=head->next;
    while(q)
    {
        fprintf(fp,"%s %s %s %s %s\n",q->name,q->phonenumber,q->qq,q->address,q->relation);
        q=q->next;
    }
    printf("更改已保存，1.继续更改 2.返回上一层\n");
II:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)
    {
        fclose(fp);
        system("CLS");
        goto CC;
    }
    else if(strcmp(choicee,"2")==0);
    else
    {
        printf("输入错误，请重新输入:\a");
        goto II;
    }
    fclose(fp);
    return head;
}
userdata * shanchu(char name[])
{
    char data[10][22],name2[80],name3[80],choicee[100];
    strcpy(name2,name);
    strcpy(name3,name);
    userdata *headhead,*head,*q,*r,*s;
    FILE *fp;
    int i=1;
    int choice;
C:
    strcpy(name,name3);
    strcpy(name2,name3);
    printf("请先查找您要删除的联系人");
    Sleep(1500);
    head=chazhao(name);
    if(head==(userdata *)0)
    {
        Sleep(1500);
        return (userdata *)2;
    }
    if(head==(userdata *)6) return (userdata *)6;
    headhead=tttt;
    if(!headhead->nextnext)
    {
        printf("抱歉，没有找到\n");
        Sleep(1000);
        return (userdata *)2;
    }
    q=headhead->nextnext;
    while(q->nextnext)
    {
        q=q->nextnext;
        i++;
    }//i为搜索到的个数
    printf("您要删除的是上面第几位联系人:");
A:
    scanf("%d",&choice);
    fflush(stdin);
    if(!choice||choice<1||choice>i)
    {
        printf("输入错误，请重新输入:\a");
        goto A;
    }


    printf("确定删除：1.是2.否\n");
K:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) ;
    else if(strcmp(choicee,"2")==0)
    {
        printf("1.继续删除 2.返回上一层\n");
        goto I;
    }
    else
    {
        printf("输入错误，请重新输入：\a");
        goto K;
    }
    fflush(stdin);
    i=1;
    r=headhead;
    q=headhead->nextnext;
    while(q)
    {
        if(choice==q->no) break;
        r=q;
        q=q->nextnext;
    }
    r->nextnext=r->nextnext->nextnext;
    s=head;
    while(s->next!=q)s=s->next;
    s->next=s->next->next;
    free(q);
    strcat(name2,".txt");
    fp=fopen(name2,"r");
    i=0;
    while(i!=7) fscanf(fp,"%s",data[i++]);
    fclose(fp);
    fp=fopen(name2,"w");
    fprintf(fp,"%s %s\n",data[0],data[1]);
    for(i=2; i<=6; i++) fprintf(fp,"%s ",data[i]);
    fprintf(fp,"\n");
    q=head->next;
    while(q)
    {
        fprintf(fp,"%s %s %s %s %s\n",q->name,q->phonenumber,q->qq,q->address,q->relation);
        q=q->next;
    }
    printf("删除成功，1.继续删除 2.返回上一层请输入2\n");
    fclose(fp);
I:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)
    {
        system("CLS");
        printf("                                          Max通讯录\n\n");
        goto C;
    }
    else if(strcmp(choicee,"2")==0) return head;
    else
    {
        printf("输入错误，请重新输入:\a");
        goto I;
    }
    return head;
}
int tianjia(char name[])
{
    system("CLS");
    fflush(stdin);
    FILE *fp;
    char data[500][30],choicee[100];
    int i=0,d,j;
A:
    printf("                                          Max通讯录\n\n");
    printf("                                  添加新的联系人到通讯录\n");
    printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
    printf("     (不多于10个字符，不含空格)请输入联系人姓名：");
    d=getdata(data[i]);
    fflush(stdin);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        goto A;
    }
    if(d==2)
    {
        printf("\n");
        goto Y;
    }
    if(strlen(data[i])>10)
    {
Y:
        printf("输入错误，请重新输入\a");
        Sleep(1000);
        system("CLS");
        goto A;
    }
B:
    printf("(不多于17个字符，不含空格)请输入联系人手机/短号：");
    d=getdata(data[i+1]);
    fflush(stdin);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        goto A;
    }
    if(d==2)
    {
        printf("\n");
        goto X;
    }
    if(strlen(data[i+1])>17)
    {
X:
        printf("输入错误，请重新输入\a");
        Sleep(1000);
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        goto B;
    }
C:
    printf("       (不多于14个字符，不含空格)请输入联系人QQ：");
    d=getdata(data[i+2]);
    fflush(stdin);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        goto B;
    }
    if(d==2)
    {
        printf("\n");
        goto W;
    }
    if(strlen(data[i+2])>14)
    {
W:
        printf("输入错误，请重新输入\a");
        Sleep(1000);
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        printf("(不多于17个字符，不含空格)请输入联系人手机/短号：%s\n",data[i+1]);
        goto C;
    }
D:
    printf("     (不多于15个字符，不含空格)请输入联系人地址：");
    d=getdata(data[i+3]);
    if(d==0)
    {
        printf("\n");
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        printf("(不多于17个字符，不含空格)请输入联系人手机/短号：%s\n",data[i+1]);
        goto C;
    }
    if(d==2)
    {
        printf("\n");
        goto V;
    }
    if(strlen(data[i+3])>14)
    {
V:
        printf("输入错误，请重新输入\a");
        Sleep(1000);
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        printf("(不多于17个字符，不含空格)请输入联系人手机/短号：%s\n",data[i+1]);
        printf("       (不多于14个字符，不含空格)请输入联系人QQ：%s\n",data[i+1]);
        goto D;
    }
E:
    printf("可选的联系人群组：1.家庭 2.朋友 3.同学 4.同事 5.其他\n");
    printf("请输入您的选择:");
    d=getdata(data[i+4]);
    fflush(stdin);

    if(d==0)//按了backspace键
    {
        printf("\n");
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        printf("(不多于17个字符，不含空格)请输入联系人手机/短号：%s\n",data[i+1]);
        printf("       (不多于14个字符，不含空格)请输入联系人QQ：%s\n",data[i+2]);
        goto D;
    }
    if(strcmp(data[i+4],"1")==0) strcpy(data[i+4],"家庭");
    else if(strcmp(data[i+4],"2")==0) strcpy(data[i+4],"朋友");
    else if(strcmp(data[i+4],"3")==0) strcpy(data[i+4],"同学");
    else if(strcmp(data[i+4],"4")==0) strcpy(data[i+4],"同事");
    else if(strcmp(data[i+4],"5")==0) strcpy(data[i+4],"其他");
    else if(!strlen(data[i+4])) strcpy(data[i+4],"无");
    else
    {
        printf("\n");
        goto S;
    }
    if(strlen(data[i+4])>14)
    {
S:
        printf("输入错误，请重新输入\a");
        Sleep(1000);
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                  添加新的联系人到通讯录\n");
        printf("按 Backspace 键可返回上个信息项目,若无信息输入，可直接回车进入下一项\n");
        printf("     (不多于10个字符，不含空格)请输入联系人姓名：%s\n",data[i]);
        printf("(不多于17个字符，不含空格)请输入联系人手机/短号：%s\n",data[i+1]);
        printf("       (不多于14个字符，不含空格)请输入联系人QQ：%s\n",data[i+2]);
        printf("     (不多于15个字符，不含空格)请输入联系人地址：%s\n",data[i+3]);
        goto E;
    }
    if(!strlen(data[i])) strcpy(data[i],"无");
    if(!strlen(data[i+1])) strcpy(data[i+1],"无");
    if(!strlen(data[i+2])) strcpy(data[i+2],"无");
    if(!strlen(data[i+3])) strcpy(data[i+3],"无");
    if(!strlen(data[i+4])) strcpy(data[i+4],"无");
    printf("1.确认添加 2.放弃添加\n");
a:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) ;
    else if(strcmp(choicee,"2")==0) return 2;
    else
    {
        printf("输入错误，请重新输入:\a");
        goto a;
    }
    printf("添加成功,1.继续添加 2.返回上一层\n");
b:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0)
    {
        i=i+5;
        system("CLS");
        goto A;
    }
    else if(strcmp(choicee,"2")==0)
    {
        j=i+5;
        strcat(name,".txt");
        fp=fopen(name,"a");
        i=0;
        while(i!=j)
        {
            fprintf(fp,"%s %s %s %s %s\n",data[i],data[i+1],data[i+2],data[i+3],data[i+4]);
            i=i+5;
        }
        fclose(fp);
        return 2 ;
    }
    else
    {
        printf("输入错误，请重新输入:\a");
        goto b;
    }
}
void chakan(char name[])
{
    system("CLS");
    printf("                                          Max通讯录\n\n");
    FILE *fp;
    char data[500][40];
    int i=0,j,t,w;
    strcat(name,".txt");
    fp=fopen(name,"r");
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    t=i-2;
    printf("           %10s%17s%14s%15s\n","姓名","手机/短号","QQ","地址");
    for(i=1; i<=5; i++)
    {
        w=0;
        if(i==1)printf("     家庭：");
        if(i==2)printf("     朋友：");
        if(i==3)printf("     同学：");
        if(i==4)printf("     同事：");
        if(i==5)printf("     其他：");
        for(j=2; j<=t; j++)
        {
            if(i==1)
            {
                if(strcmp(data[j],"家庭")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==2)
            {
                if(strcmp(data[j],"朋友")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==3)
            {
                if(strcmp(data[j],"同学")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==4)
            {
                if(strcmp(data[j],"同事")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
            if(i==5)
            {
                if(strcmp(data[j],"其他")==0)
                {
                    w++;
                    if(w!=1)printf("           ");
                    printf("%10s%17s%14s%15s\n",data[j-4],data[j-3],data[j-2],data[j-1]);
                }
            }
        }
        if(w==0) printf("无\n");
    }

    if(t==8) printf("             暂无联系人\n");
    system("pause");
    return;
}
int faxinxi(char *name)
{
    FILE *fp;
    char user[100][20],text[1000],a[30],data[10][1050],choicee[100];
    int i=0,j,n,k,t;
    system("CLS");
    printf("                                 信息\n");
    printf("您可以向其他用户发送消息，使用此软件的用户有\n");
    fp=fopen("datadatadata.txt","r");
    while(fscanf(fp,"%s",user[i++])!=EOF);
    i--;
    for(j=0; j<=i-1; j++)
    {
        printf("%d:%s\n",j+1,user[j]);
    }
    printf("您要向第几位用户发送消息:");
    t=i;
    if(i>=10&&i<=99)
    {
p:
        scanf("%s",choicee);
        fflush(stdin);
        if(strlen(choicee)==1)
        {
            choicee[1]='0';
            choicee[2]=0;
        }
        i=choicee[0]-'0'+(choicee[1]-'0')*10-1;

        if(strlen(choicee)<=0||strlen(choicee)>2||i<=0||i>t)
        {
            printf("输入错误，请重新输入:\a");
            goto p;
        }
    }
    else if(i<=9&&i>=0)
    {
q:
        scanf("%s",choicee);
        fflush(stdin);
        i=choicee[0]-'0';
        if(strlen(choicee)!=1||i<=0||i>t)
        {
            printf("输入错误，请重新输入:\a");
            goto q;
        }
    }
    strcpy(a,user[i-1]);
    printf("您将进入编辑信息界面，1.放弃编辑 2.继续编辑\n");
B:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) return 2;
    else if(strcmp(choicee,"2")==0) ;
    else
    {
        printf("输入错误，请重新输入:\a");
        goto B;
    }
    system("CLS");
    printf("信息:\n");
    printf("(信息内不能包含空格，字数不超过1000字符)\n    ");
C:
    fflush(stdin);
    gets(text);
    n=strlen(text);
    if(n>1000)
    {
        printf("信息量过大，请重新输入:\a\n");
        goto C;
    }
    for(j=0; j<=n-1; j++)
    {
        if(text[j]==' ') break;
    }
    if(j<=n-1)
    {
        printf("该信息含非法字符，请重新输入:\a\n");
        goto C;
    }
    strcat(text,"——来自用户");
    strcat(text,name);
    strcat(a,"message.txt");
    fp=fopen(a,"r");
    k=0;
    if(fp)
    {
        while(fscanf(fp,"%s",data[k++])!=EOF);
        fclose(fp);
    }
    if(data[0][0]=='0')
    {
        //fclose(fp);
        fp=fopen(a,"w");
        fprintf(fp,"1\n%s\n ",text);
        fclose(fp);
    }
    else
    {
        data[0][0]=data[0][0]+1;
        fclose(fp);
        fp=fopen(a,"w");
        for(j=0; j<=k-1; j++)
        {
            fprintf(fp,"%s\n",data[j]);
        }
        fprintf(fp,"%s\n",text);
        fclose(fp);
    }
    printf("发送成功");
    Sleep(1000);
    return 2;
}
int shouxinxi(char name[])
{
    system("CLS");
    FILE *fp;
    char name2[30],data[10][1080],a;
    int i=0,j=1;
    strcpy(name2,name);
    strcat(name2,"message.txt");
    fp=fopen(name2,"r");
    while(fscanf(fp,"%s",data[i++])!=EOF);
    i--;
    fclose(fp);
    if(data[0][0]=='0') printf("无收到信息");
    if(strcmp(data[1],"欢迎使用Max通讯录系统")==0)
    {
        printf("收到1条信息:\n\n");
        printf("欢迎使用Max通讯录！--来自Max\n\n");
        printf("按任意键返回...");
        a=getch();
        printf("%c",a);
        goto g;
    }
    else
    {
        printf("收到%c条信息：\n",data[0][0]);
        printf("\n");
        for(; j<=i-1; j++)
            printf("%s\n\n",data[j]);
    }
    printf("按任意键返回...");
    a=getch();
g:
    fp=fopen(name2,"w");
    fprintf(fp,"0\n无\n");
    fclose(fp);
    return 2;
}
int zhuce()
{
    void signin();
    FILE *fp;
    char name1[80],name2[80],password1[80],password2[80],choicee[100];
    system("CLS");
    printf("(用户名只能由3到12个字符组成，且只能由数字和字母组成成)\n");
    printf("(密码不能多于15个字符或少于6 个字符，且只能由数字，字母和符号组成)\n");
    printf("          用户名:");
    scanf("%s",name1);
    fflush(stdin);
    strcpy(name2,name1);
    strcat(name1,".txt");
    fp=fopen(name1,"r");
    if(fp)
    {
        printf("该用户名已被注册,请重新注册\a");
        Sleep(1500);
        fclose(fp);
        zhuce();
        return 1;
    }
    if(!check_name(name2))
    {
        printf("用户名不合法,请重新注册\a");
        Sleep(1500);
        zhuce();
        return 1;
    }
    printf("\n            密码:");
    GetPassword(password1);
    if(!check_password(password1))
    {
        printf("密码不合法,请重新注册\a");
        Sleep(1500);
        zhuce();
        return 17;
    }
    printf("\n请再输入一次密码:");
    GetPassword(password2);
    while(strcmp(password1,password2))
    {
        printf("密码不正确，1.放弃注册 2.继续注册\n\a");
h:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"1")==0) return 2;
        else if(strcmp(choicee,"2")==0) ;
        else
        {
            printf("输入错误，请重新输入:");
            goto h;
        }
        printf("\n            密码:");
        GetPassword(password1);
        if(!check_password(password1))
        {
            printf("密码不合法,请重新注册\a");
            Sleep(1500);
            zhuce();
            return 17;
        }
        printf("\n请再输入一次密码:");
        GetPassword(password2);
    }
    printf("注册成功,请重新登陆\n");
    Sleep(1500);
    fp=fopen(name1,"w");
    fprintf(fp,"%s %s\n",name2,jiami(password1));
    fprintf(fp,"姓名 手机/短号 QQ 住址 群组");
    fclose(fp);
    fp=fopen("datadatadata.txt","a");
    fprintf(fp," %s",name2);
    fclose(fp);
    strcat(name2,"message.txt");
    fp=fopen(name2,"w");
    fprintf(fp,"1\n欢迎使用Max通讯录系统\n");
    fclose(fp);
    signin();
    return 0;
}
int  denglujiemiancaidan()//登陆界面菜单
{
    void signin();
A:
    printf("1.重新登陆 2.注册新用户 3.返回上一层\n");
    char choicee[100];
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"1")==0) signin();
    else if(strcmp(choicee,"2")==0) zhuce();
    else if(strcmp(choicee,"3")==0) return 3;
    else
    {
        printf("输入错误，请重新输入:\a\n");
        goto A;
    }
    return 1;
}
int yonghujiemian(char name[])//用户界面
{
    char name4[30],name5[30],a,choicee[100],share[500][20];
    FILE *fp;
    int y,j;
    strcpy(name4,name);
    strcpy(name5,name);
    strcat(name4,"message.txt");
    fp=fopen(name4,"r");
    //信息量为0
    a=fgetc(fp);
    if(a=='0')
    {
        fclose(fp);
        goto GG;
    }
    if(fp)
    {
        fclose(fp);
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("\n\n\n\n\n\n                           \a您有新信息，是否查看: 1是 2.否\n");
B:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"2")==0) goto GG;
        else if(strcmp(choicee,"1")==0) shouxinxi(name5);
        else
        {
            printf("输入错误，请重新输入:");
            goto B;
        }
    }
GG:
    strcpy(name4,name);
    strcat(name4,"share.txt");
    fp=fopen(name4,"r");
    if(fp!=NULL)
    {
        j=0;
        while(fscanf(fp,"%s",share[j++])!=EOF);
        fclose(fp);
        if(j<=3)
        {
            goto A;
        }
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("\n\n\n\n\n\n                           \a其他用户向您分享了联系人，是否查看: 1是 2.否，下次查看\n");
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"2")==0)
        {
            goto A;
        }
        else if(strcmp(choicee,"1")==0)
        {
            system("CLS");
            printf("%10s%17s%14s%15s%10s","姓名","手机/短号","QQ","地址","群组\n");
            y=0;
            while(y<=j-1)
            {
                printf("%10s%17s%14s%15s%10s\n",share[y],share[y+1],share[y+2],share[y+3],share[y+4]);
                y=y+5;
            }
            printf("是否添加联系人: 1.是 2.否:");
            scanf("%s",choicee);
            fflush(stdin);
            if(strcmp(choicee,"2")==0)
            {
                strcpy(name4,name);
                strcat(name4,"share.txt");
                fp=fopen(name4,"w");
                fclose(fp);
                goto A;
            }
            else if(strcmp(choicee,"1")==0)
            {
                strcpy(name4,name);
                strcat(name4,".txt");
                fp=fopen(name4,"a");
                y=0;
                while(y<=j-3)
                {
                    fprintf(fp,"%s %s %s %s %s\n",share[y],share[y+1],share[y+2],share[y+3],share[y+4]);
                    y=y+5;
                }
                fclose(fp);
            }
            else
            {
                printf("输入错误，请重新输入:");
                goto B;
            }
        }
        else
        {
            printf("输入错误，请重新输入:\a");
            goto B;
        }
        strcpy(name4,name);
        strcat(name4,"share.txt");
        fp=fopen(name4,"w");
        fclose(fp);
    }
A:
    system("CLS");
    int i=0,k=0,l=0;
    char password[16],name2[30],name3[30],data[500][40],ch;
    printf("                                          Max通讯录\n\n");
    printf("用户:");
    printf("%s\n",name);
    printf("操作:1.查找 2.添加 3.删除 4.更改 5.查看全部 6.分享 7.发送信息 8.拨打电话 0.注销\n");
    strcat(name,".txt");
    fp=fopen(name,"r");
    fscanf(fp,"%s %s",name,password);
    strcpy(name2,name);
    strcpy(name3,name2);
    while(fscanf(fp,"%s",data[i++])!=EOF);
    fclose(fp);
    printf("请输入要进行的操作:");
C:
    scanf("%s",choicee);
    fflush(stdin);
    if(strcmp(choicee,"0")!=0&&strcmp(choicee,"1")!=0&&strcmp(choicee,"2")!=0&&strcmp(choicee,"3")!=0&&strcmp(choicee,"4")!=0&&strcmp(choicee,"5")!=0&&strcmp(choicee,"6")!=0&&strcmp(choicee,"7")!=0&&strcmp(choicee,"8")!=0)
    {
        printf("输入错误，请重新输入:\a");
        goto  C;
    }
    while(strcmp(choicee,"0")!=0)
    {
        strcpy(name3,name2);
        switch(choicee[0])
        {
        case '1':
            chazhao(name3);
            if(pppp==1)
            {
                pppp=0;
                goto c;
            }
            printf("\n\n输入任意键返回上一层...");
            ch=getch();
            printf("%c",ch);
c:
            goto A;
            break;
        case '2':
            tianjia(name3);
            goto A;
            break;
        case '3':
            shanchu(name3);
            goto A;
            break;
        case '4':
            genggai(name3);
            goto A;
            break;
        case '5':
            chakan(name3);
            goto A;
            break;
        case '7':
            faxinxi(name3);
            goto A;
            break;
        case '8':
            dadianhua();
            goto A;
            break;
        case '6':
            fenxiang(name3);
            goto A;
            break;
        default:
            fflush(stdin);
            printf("输入错误,请重新输入:\a");
        }
d:
        scanf("%s",choicee);
        fflush(stdin);
        if(strcmp(choicee,"0")!=0&&strcmp(choicee,"1")!=0&&strcmp(choicee,"2")!=0&&strcmp(choicee,"3")!=0&&strcmp(choicee,"4")!=0&&strcmp(choicee,"5")!=0&&strcmp(choicee,"6")!=0&&strcmp(choicee,"7")!=0&&strcmp(choicee,"8")!=0)
        {
            printf("输入错误，请重新输入:");
            goto  d;
        }
    }
    if(strcmp(choicee,"0")==0)
    {
        strcpy(name3,name2);
        strcat(name3,".txt");
        fp=fopen(name3,"r");
        while(fscanf(fp,"%s",data[k++])!=EOF);
        fclose(fp);
        jiami(data[1]);
        fp=fopen(name3,"w");
        fprintf(fp,"%s %s\n",data[0],data[1]);
        for(l=2; l<=k-2; l=l+5) fprintf(fp,"%s %s %s %s %s\n",data[l],data[l+1],data[l+2],data[l+3],data[l+4]);
        fclose(fp);
        return 1;
    }
    return 0;
}
void signin()
{
    system("CLS");
    printf("                                          Max通讯录\n\n");
    FILE *fp;
    char a[2][16];
    int i=0,g,j=0;
    char name[80],name2[80],password[80],d[2][20],data[500][20];
    fp=fopen("001.txt","r");
    fscanf(fp,"%s%s",d[0],d[1]);
    fclose(fp);
    printf("登陆\n公共通讯录用户账号为001，密码为%s\n",jiemi(d[1]));
    printf("用户名:");
    scanf("%s",name);
    fflush(stdin);
    strcpy(name2,name);
    strcat(name,".txt");
    printf("\n  密码:");
    GetPassword(password);
    fflush(stdin);
    fp=fopen(name,"r");
    if(fp==NULL)
    {
        printf("用户不存在或密码错误\a\n");
        g=denglujiemiancaidan();
        return;
    }
    else //用户名正确，开始验证密码
    {
        fp=fopen(name,"r");
        while(fscanf(fp,"%s",a[i++])!=EOF)if(i==2) break;
        if(strcmp(jiemi(a[1]),password)==0)
        {
            fp=fopen(name,"r");
            while(fscanf(fp,"%s",data[j++])!=EOF);
            fclose(fp);
            jiemi(data[1]);
            fp=fopen(name,"w");
            fprintf(fp,"%s %s\n",data[0],data[1]);
            for(i=2; i<=j-2; i=i+5) fprintf(fp,"%s %s %s %s %s\n",data[i],data[i+1],data[i+2],data[i+3],data[i+4]);
            fclose(fp);
            system("CLS");
            printf("                                          Max通讯录\n\n");
            printf("\n\n\n\n\n\n\n\n\n\n                                   正在登录,请稍等");
            printf(".");
            Sleep(300);
            printf(".");
            Sleep(300);
            printf(".");
            Sleep(300);
        }
        else
        {
            printf("用户不存在或密码错误\a\n");
            g=denglujiemiancaidan();
            if(g==3)
            {
                g=0;
                return;
            }
        }
    }
    yonghujiemian(name2);
    fflush(stdin);
    return;
}
int main()
{
    char choice[100];
    system("CLS");
    printf("                                          Max通讯录\n\n");
    printf("                                          1.登陆 \n");
    printf("                                          2.注册 \n");
    printf("                                          3.更改密码 \n");
    printf("                                          4.关于 \n");
    printf("                                          5.退出系统 \n");
    printf("请输入您要进行的操作:");
d:
    scanf("%s",choice);
    fflush(stdin);
    if(strcmp(choice,"1")!=0&&strcmp(choice,"2")!=0&&strcmp(choice,"3")!=0&&strcmp(choice,"4")!=0&&strcmp(choice,"5")!=0)
    {
        printf("输入错误，请重新输入:\a");
        goto d;
    }
    while(strcmp(choice,"5")!=0)
    {
        switch(choice[0])
        {
        case '1':
            signin();
            break;
        case '2':
            zhuce ();
            break;
        case '3':
            gaimima();
            break;
        case '4':
            system("CLS");
            printf("\n\n\n\n\n\n\n\n\n                                          Max通讯录\n");
            printf("\n                                          版本:v0.99\n");
            printf("\n                                          公司:microhard\n\n");
            system("pause");
            break;
        }
        system("CLS");
        printf("                                          Max通讯录\n\n");
        printf("                                          1.登陆 \n");
        printf("                                          2.注册 \n");
        printf("                                          3.更改密码 \n");
        printf("                                          4.关于 \n");
        printf("                                          5.退出系统 \n");
        printf("请输入您要进行的操作:");
b:
        scanf("%s",choice);
        fflush(stdin);
        if(strcmp(choice,"1")!=0&&strcmp(choice,"2")!=0&&strcmp(choice,"3")!=0&&strcmp(choice,"4")!=0&&strcmp(choice,"5")!=0)
        {
            printf("输入错误，请重新输入:\a");
            goto b;
        }
    }
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                         感谢使用\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}
