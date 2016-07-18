#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<conio.h>
#include<malloc.h>
#include <ctype.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 1000
#define MAXN 2000
#define MAXARRAY 20000
#include <ctype.h>
#define len strlen
#define TRUE 1
#define FALSE 0
#define	MIN_INPUT 0x20
#define	MAX_INPUT 0x7e
int student_login_interface();
int admin_interface();
int main_interface();
int exit_interface();
int student_base_data_interface();
int admin_student_base_data_interface();
int main_interface();
int register_user();
int Print_from_Linklist_to_array();
int LinkDelete_student_data();
int LinkInsert_student();
void Init_student_keydata();
void Init_admin_key_data();
int InitList_student_data();
int Initi_course_data();
int Init_student_choose_course_data();
int INIT_ALL();
int Load_student_Linklist();
int Write_ALL();
int Write_admin_key();
int Write_student_data();
int Write_student_key();
int Write_student_chose_course();
int Write_course_data();
int array_delete_student_key(char *s);
int scanf_key(char *key);
int Countdown_Clock();
void main_printf();
int Init_ALL_course_count();
int Input_key(char *key);
void welcome_interface();
int student_login();
int admin_login();
int Insert_student();
int Delete_student_data();
int Delete_course();
void personal_base_information();
void student_choose_class_data();
void student_total_credit();
int Device_studentdependclass();
int Device_studentdependcourse();
int student_course_data_in_oneclasse();
int onecourse_all_student();
int modification_student_data();
int modification_student_key();
int modification_student_basic_data();
int input_student_imformation_of_course();
int input_student_grade_imformation_of_course();
int all_student_total_credit();
int rightful_key(char *s);
int R_L_K(char*s);
int scan_num(char *num);
int scan_phone(char *num);
int scan_course_num(char *num);
int scan_sex(char *s);
int scan_age(char *s);
int scan_dor(char *s);
int scan_name(char *s);
int scan_class(char *s);
int scan_credit(double &s);
int scan_score(double &s);
int right_course(char *s);
int repeat_course(char *s);
int encrypt(char *key);
int decode(char *key);
void quicksort(char s[][20],int left,int right);
int sort_data();
int sort_student_key();
int sort_admin_key();
int sort_course();
int sort_student_course();
void butterfly();
int Fly();
int I_LOVE_YOU();
int logging_grade_data_one_course();
int finish_logging_grade();
int input_grade();
int unpass();
int Total_Credit_Unpass();
int add_course();
int add_delete_course();
int modification_admin_key();
int Look_over_scores();
int SORT_ALL();
int END();
//学生所选每一门课程的结构体
typedef struct one_course{
   char num[15];//课程编号
   char name[20];
   double usual_score;
   double exam_score;
   double final_score;
   double credit;//学分
   int  IsRetake;//判断是否重修
   char Retake_semester[20];
   int Retake_count;
   int fnish;
}one_course;
typedef struct oneclass{
    char class_name[20];
    int student_num[200];
    int count;
}oneclass;
oneclass ALLCLASS[200];
//学生基本信息
typedef struct student{
    char num[15];
    char class_name[15];
    char name[10];
    char sex[5];
    char age[5];
    char dormitory[30];
    char phone[15];
    one_course All_course[50];
    double total_credit;
    int cousetotal;
    char grade[30];
    char College[30];
    struct student *next;
}*Linklist_student,student;

student student_array[MAXARRAY];//在数组中存取学生信息
Linklist_student Student_L=(Linklist_student)malloc(sizeof(student));//学生链表头结点
//课程基本信息
typedef struct course{
   char num[15];
   char name[20];
   char imformation[200];
   int  count;//该课程已选的人数
   int Choose_student_idex[2000];//已学的学生学号,初始化时，填写
   int finish;
   int unpass;
   //struct course *next;
}course;//*Linklist_course,course;
course ALL_course[1000];
int Init_ALL_course_count()//是各班级初始化时值为0
{
    for(int i=0;i<100;i++)
    {
        ALL_course[i].count=0;
       // printf("course[%d]=%d\n",i+1,ALL_course[i].count);
    }
    return OK;
}
typedef struct s{
    char num[15];
    char key[15];
}s;
s student_key_data[MAXN];//记录学生密码
typedef struct admin{
    char num[15];
    char key[15];
}admin;
admin admin_key_data[MAXN];//记录使用者密码
int student_total=0;
int student_key_total=0;
int admin_total=0;
int studenti,coursei;
int classnum;//班级总数
int course_total=0;//选修课种类总数
int de_num[100];//删除学生的学号下表
int de_total=0;//删除总数
int admini;//当前管理员的数组下标
int COUNTDOWN=5;//倒计时初始值
void Init_student_keydata()//初始化学生密码信息
{
  int i=0;
  FILE *fkey=fopen("student_key.txt","r");
    while(fscanf(fkey,"%s%s",student_key_data[i].num,student_key_data[i].key)!=EOF)
    {
        decode(student_key_data[i].key);
        i++;
    }
    student_key_total=i;
    fclose(fkey);
}

void Init_admin_key_data()//初始化管理员密码信息
{
    FILE *fkey=fopen("admin.txt","r");
    int i=0;
    while(fscanf(fkey,"%s%s",admin_key_data[i].num,admin_key_data[i].key)!=EOF)
    {
        decode(admin_key_data[i].key);//printf("%s\n",admin_key_data[i].key);
        i++;
    }
    admin_total=i;
}
int Load_student_Linklist()//初始化学生信息
{
    printf("linllist:\n");
    Linklist_student q=Student_L;
     printf("学号  姓名  性别 年龄 宿舍号码 电话号码\n");
    while(q->next){printf("%s  %s  %s   %s   %s    %s    \n",q->next->num,q->next->name,q->next->sex,q->next->age,q->next->dormitory,q->next->phone);q=q->next;}
    return 0;
}

int InitList_student_data()//把文件的数据存入链表还有数组中
{
    FILE *fdata=fopen("student_data.txt","r");
    Linklist_student q=(Linklist_student)malloc(sizeof(student));
    Linklist_student p=Student_L;
    Student_L->next=NULL;
    //int i=0;
       while(fscanf(fdata,"%s%s%s%s%s%s%s",q->num,q->class_name,q->name,q->sex,q->age,q->dormitory,q->phone)!=EOF)
     {
         q->next=p->next; p->next=q;p=q;
         q=(Linklist_student)malloc(sizeof(student));
      //   i++;
}
Print_from_Linklist_to_array();
//Load_student_Linklist();
fclose(fdata);
return 0;
}
int Initi_course_data()//初始化课程信息
{
    int i=0;
    FILE *fp=fopen("course.txt","r");
    while(fscanf(fp,"%s%s%s%d%d",ALL_course[i].num,ALL_course[i].name,ALL_course[i].imformation,&ALL_course[i].unpass,&ALL_course[i].finish)!=EOF)
    {
       // printf("%s\n",ALL_course[i].num);
      i++;
    }

    fclose(fp);course_total=i;
    return 0;

}
int Device_studentdependclass()//初始化时将学生按班级不同分类
{
    classnum=0;int j;
    for(int i=0;i<student_total;i++)
    {
        for(j=0;j<=classnum;j++)
            {
                if(!strcmp(ALLCLASS[j].class_name,student_array[i].class_name)){ALLCLASS[j].student_num[ALLCLASS[j].count++]=i;break;}
           }
        if(j>classnum){ALLCLASS[classnum].count=0;strcpy(ALLCLASS[classnum].class_name,student_array[i].class_name);ALLCLASS[classnum].student_num[ALLCLASS[classnum].count++]=i;classnum++;}
    }
    //printf("classnum=%d\n",classnum);
    return 0;
}
int student_course_data_in_oneclasse()//查看一个班级的学生考试成绩
{
    for(int i=0;i<classnum;i++)
    {
        printf("                            %s\n",ALLCLASS[i].class_name);
        for(int j=0;j<ALLCLASS[i].count;j++)
        {
        int studenti=ALLCLASS[i].student_num[j];printf("学生学号%s\n",student_array[studenti].num);
        printf("   编号  名称  平时成绩  期末成绩  平均成绩  学分 \n");
         printf("--------------------------------------------------------------\n");
        for(int j=0;j<student_array[studenti].cousetotal;j++){
    printf(" %s%7s%8.1lf%10.1lf%10.1lf%8.1lf     \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[0].All_course[0].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);
        }
         printf("--------------------------------------------------------------\n");

        }
    printf("\n\n\n");


}
return 0;
}

int Device_studentdependcourse()//初始化时将学生按课程信息分类
{
    int j;
      for(j=0;j<=course_total;j++)
    {
        ALL_course[j].count=0;
       for(int i=0;i<student_total;i++)
            {   for(int k=0;k<student_array[i].cousetotal;k++)
                if(!strcmp(ALL_course[j].num,student_array[i].All_course[k].num)){
                    ALL_course[j].Choose_student_idex[ALL_course[j].count++]=i;break;}
            }
        }
    return 0;

}
int onecourse_all_student()//输出一种科目中的所有学生考试情况
{

   // printf("输入课程编号\n");//查询方法
   // gets(num);
     for(int i=0;i<course_total;i++)//if(!strcmp(num,ALL_course[i].num))
        {   //printf("%s\n",ALL_course[i].name);
            //printf("姓名     平时成绩   期末成绩   平均成绩  学分 \n");
            for(int j=0;j<ALL_course[i].count;j++)
            {
                int k,idex=ALL_course[i].Choose_student_idex[j];
                for( k=0;k<student_array[idex].cousetotal;k++)if(!strcmp(student_array[idex].All_course[k].name,ALL_course[i].name))break;
                //printf("%s%8.1lf%10.1lf%10.1lf%8.1lf\n",student_array[idex].name,student_array[idex].All_course[k].usual_score,student_array[idex].All_course[k].exam_score,student_array[idex].All_course[k].final_score,student_array[idex].All_course[k].credit);
            }
            //printf("\n");
        }
        return 0;
}
int Write_student_data()//将学生信息写入文件
{
    FILE *fp=fopen("student_data.txt","w");int flag=0;
    for(int i=0;i<student_total;i++){
            flag=0;
    for(int j=0;j<de_total;j++)
        if(i==de_num[j]){flag=1;break;}
       if(!flag){
        fprintf(fp,"%s %s %s %s %s %s %s\n",student_array[i].num,student_array[i].class_name,student_array[i].name,student_array[i].sex,student_array[i].age,student_array[i].dormitory,student_array[i].phone);}
    }
    fclose(fp);
    return 0;
}

int Write_student_key()//将学生密码写入文件
{
    FILE *fkey=fopen("student_key.txt","w");
    for(int i=0;i<=student_key_total;i++)
   {
     encrypt(student_key_data[i].key);
     fprintf(fkey,"%s  %s\n",student_key_data[i].num,student_key_data[i].key);
   }
    fclose(fkey);
    return 0;
}

int Write_admin_key()//将管理员密码写入文件
{
    FILE *fkey=fopen("admin.txt","w");
    for(int i=0;i<=admin_total;i++)
   {
     encrypt(admin_key_data[i].key);//printf("\n%s\n",admin_key_data[i].key);
     fprintf(fkey,"%s  %s\n",admin_key_data[i].num,admin_key_data[i].key);
   }
    fclose(fkey);
    return 0;
}
int Write_student_chose_course()//将每个学生选课信息分别写入文件
{
    int flag;FILE *fp;char s[20];
    for(studenti=0;studenti<student_key_total;studenti++)
     {flag=0;sort_student_course();
     for(int k=0;k<de_total;k++)if(studenti==de_num[k]){flag=1;break;}
       strcpy(s,student_array[studenti].num);fp=fopen(strcat(s,".txt"),"w");if(flag)continue;
       for(int i=0;i<student_array[studenti].cousetotal;i++){
            fprintf(fp,"%s  %12s %8.1lf %10.1lf%10.1lf%8.1lf",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name,student_array[studenti].All_course[i].usual_score,student_array[studenti].All_course[i].exam_score,student_array[studenti].All_course[i].final_score,student_array[studenti].All_course[i].credit);
       if(student_array[studenti].All_course[i].IsRetake)fprintf(fp,"   %d       %s    %d",1,student_array[studenti].All_course[i].Retake_semester,student_array[studenti].All_course[i].Retake_count);
       else fprintf(fp,"     %d     %s    %d",0,"无",0);
       fprintf(fp,"     %d\n",student_array[studenti].All_course[i].fnish);
       }

        fclose(fp);
    }
    return 0;
}
int Write_course_data()
{
    FILE *fp=fopen("course.txt","w");
    for(int i=0;i<course_total;i++)
    {
        fprintf(fp,"%s   %s\n\n%s\n\n%d\t%d\n\n",ALL_course[i].num,ALL_course[i].name,ALL_course[i].imformation,ALL_course[i].unpass,ALL_course[i].finish);
    }
    fclose(fp);
    return 0;
}
int Insert_student()
{
  int flag=0,ff;
  char new_num[25],key1[15],key2[15];
  while(1){
      flag=0;ff=1;
  printf("请输入您要注册学生号\n");
  if(!scan_num(new_num))break;system("CLS");
  for(int i=0;i<=student_key_total;i++)
        if(strcmp(new_num,student_key_data[i].num)==0){flag=1;break;}
        if(flag){printf("对不起，该学生号已被注册，请换另一用户名\n");
        continue;
        }
   while(1)
   {
    printf("请输入您要注册的密码\n");
    ff=scanf_key(key1);
    if(!ff)break;
    system("CLS");
    printf("请再输入您要注册的密码\n");
    if(!scanf_key(key2))continue;
    system("CLS");
    if(strcmp(key1,key2)!=0){printf("两次注册密码不一致,请重新输入密码\n");continue;}
    else {
        flag=1;
        Linklist_student q,p=Student_L;
    q=(Linklist_student)malloc(sizeof(student));
    printf("请填好新学生的有关信息\n");//printf("------若有些信息暂时未需要填写，请在输入栏中输入#（其中带有* *信息为必填信息）\n");
    strcpy(q->num,new_num);
    int fg=0;
    for(;!fg;)
    {
        if(!scan_class(q->class_name)){system("CLS");break;}
        else for(;!fg;)
            if(!(scan_name(q->name))){system("CLS");break;}
        else for(;!fg;)
            if(!(scan_sex(q->sex))){system("CLS");break;}
        else for(;!fg;)
            if(!(scan_age(q->age))){system("CLS");break;}
        else for(;!fg;)
             if(!(scan_dor(q->dormitory))){system("CLS");break;}
        else for(;!fg;)
             {system("CLS");if(!(scan_phone(q->phone))){system("CLS");break;}
        else fg=1;}
    }
    if(!fg)continue;
     while(p->next){
        p=p->next;
    }int fflag=0;
    while(1)
    {
    printf("您即将注册的学生信息如下\n\n\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n    学生号       班级       姓名     性别     年龄      宿舍    电话号码\n\n");
             printf("%10s%12s%9s%7s%9s%10s%14s\n",q->num,q->class_name,q->name,q->sex,q->age,q->dormitory,q->phone);
    printf("-----------------------------------------------------------------------\n");

    printf("\n\nY:注册学生\nN:放弃注册\n\n\n\n输入您的选择   ");
    char cho;
    {
    while(1){fflush(stdin);scanf("%c",&cho);
    if(cho=='Y'||cho=='y'||cho=='N'||cho=='n'||cho=='X'||cho=='x')break;
    else printf("该输入无效，请重新输入\n");
    }
    if(cho=='Y'||cho=='y'){q->next=p->next;p->next=q;
    strcpy(student_key_data[student_key_total].num,new_num);
    strcpy(student_key_data[student_key_total].key,key1);
    student_key_total=student_key_total+1;
    strcpy(student_array[student_total].num,q->num);
    strcpy(student_array[student_total].class_name,q->class_name);
    strcpy(student_array[student_total].name,q->name);
    strcpy(student_array[student_total].sex,q->sex);
    strcpy(student_array[student_total].age,q->age);
    strcpy(student_array[student_total].dormitory,q->dormitory);
    strcpy(student_array[student_total].phone,q->phone);
    printf("注册成功！\n");
    student_total++;fflag=1;
        break;
        }if(fflag)break;
        }
        if(cho=='N'||cho=='n'){fflag=1;printf("未成功注册\n"); break;}

        }if(fflag)break;

    }
    system("CLS");
  }
  if(!ff)continue;
  printf("你想继续注册新用户\n是请输入Y 否请输入N\n");char ch;
  while(1){
      fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("输入无效\n");
      }
if(ch=='n'||ch=='N')break;
  }

   // Write_student_key();
    return OK;
}

int Delete_student_data()
{
    Linklist_student q,p=Student_L;
    char denum[15];
    while(1){printf("请输入要删除学生的学号\n");
    if(!scan_num(denum))return 0;
    while(p->next)
    {
        if(strcmp(p->next->num,denum)==0)break;
        p=p->next;
    }
    if(!p->next){printf("无此学生相关信息\n");continue;}
    printf("以下是清除该学生相关信息\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\n    学生号       班级       姓名     性别     年龄      宿舍    电话号码\n\n");
    printf("%10s%12s%9s%7s%9s%10s%14s\n\n",p->next->num,p->next->class_name,p->next->name,p->next->sex,p->next->age,p->next->dormitory,p->next->phone);
    printf("--------------------------------------------------------------------------\n\n");
    printf("Y:删除  N:放弃删除\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("输入无效\n");}
    if(ch=='Y'||ch=='y')
    {   array_delete_student_key(denum);
        q=p->next;p->next=q->next;
    free(q);
    for(int i=0;i<student_total;i++)
        if(!strcmp(denum,student_array[i].num)){de_num[de_total++]=i;break;}
    printf("删除成功！\n");
    }
    else printf("未删除该学生\n");
    printf("继续删除 Y 结束 N\n");
    {
     char ch;
     while(1){fflush(stdin);printf("请输入您的选择\n");
     scanf("%c",&ch);
     if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("输入无效\n");}
     if(ch=='N'||ch=='n')break;
    }
    }
    return ERROR;
}
int array_delete_student_key(char *s)
{
    int i;
    for(i=0;i<student_key_total;i++)
    {
        if(strcmp(student_key_data[i].num,s)==0)break;
    }
    for(int j=i;j<student_key_total;j++)
        {
            strcpy(student_key_data[j].num,student_key_data[j+1].num);
            strcpy(student_key_data[j].key,student_key_data[j+1].key);
        }
    student_key_total-=1;
    return OK;
}

int Print_from_Linklist_to_array()
{
    Linklist_student q=Student_L->next;
    int i=0;
       while(q)
     {
         strcpy(student_array[i].num,q->num);
         strcpy(student_array[i].class_name,q->class_name);
         strcpy(student_array[i].name,q->name);
         strcpy(student_array[i].sex,q->sex);
         strcpy(student_array[i].age,q->age);
         strcpy(student_array[i].dormitory,q->dormitory);
         strcpy(student_array[i].phone,q->phone);
         q=q->next;
         i++;

}
    student_total=i;
    //printf("S_T=%d\n",student_total);
   // for(int i=0;i<student_total;i++)
   // printf("from array:%s %s %s %s %s %s\n",student_array[i].num,student_array[i].name,student_array[i].sex,student_array[i].age,student_array[i].dormitory,student_array[i].phone);
    return 0;
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

int Countdown_Clock()
{
	clock_t start, finish, clsfinish;
	double time_used_in_cls = 0;
	start = clock();
	system("CLS");
	clsfinish = clock();
	time_used_in_cls = double(clsfinish - start);

	int i=COUNTDOWN;
	while(i >= 0)
	{
		start = finish = clock();
		if(i ==COUNTDOWN)
			finish += time_used_in_cls;
		while(finish-start < CLOCKS_PER_SEC - time_used_in_cls)
			finish = clock();
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("                                ");
		printf("请在 <%d> 秒后重新输入密码\n", i--);
	}
    system("CLS");
	return 1;
}
void main_printf()
{
    //printf_sin();
    printf("\n\n\n\n\n\n\n\n\n");
    printf("                                     ********************\n");
    printf("                                     ***正在初始化数据***\n");
    printf("                                     ********************\n\n\n\n\n\n\n\n");
    for(int j=0;j<89;j++)
    {
        for(int i=0;i<10000000;i++);printf("<");
    }
     INIT_ALL();
     printf("<");
    system("CLS");
}
int INIT_ALL()
{
     Initi_course_data();
     Init_ALL_course_count();
     Init_student_keydata();
     Init_admin_key_data();
     InitList_student_data();
     Init_student_choose_course_data();
     Device_studentdependclass();
     Device_studentdependcourse();
     onecourse_all_student();
     //student_course_data_in_oneclasse;
     return 0;
}
int Init_student_choose_course_data()//读取每名学生选修课程的数据
{
    int i,studenti=0,n=student_total-1;
    char s[20];
    FILE *fp;
    while(strcpy(s,student_array[n].num),fp=fopen(strcat(s,".txt"),"r"))
    //while(fscanf(fp,"%s",student_array[0].All_course[0].num)!=EOF);
    //printf("%s",student_array[0].All_course[0].num);
    {
   // printf("student[%d]num=%s\n",n,student_array[n].num);
    student_array[n].cousetotal=0;i=0;studenti=n;student_array[n].total_credit=0;
    while(fscanf(fp,"%s%s%lf%lf%lf%lf%d%s%d%d",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name,&student_array[studenti].All_course[i].usual_score,&student_array[studenti].All_course[i].exam_score,&student_array[studenti].All_course[i].final_score,&student_array[studenti].All_course[i].credit,&student_array[studenti].All_course[i].IsRetake,student_array[studenti].All_course[i].Retake_semester,&student_array[studenti].All_course[i].Retake_count,&student_array[studenti].All_course[i].fnish)!=EOF)
    {student_array[n].total_credit+=student_array[n].All_course[i].credit;i++;}student_array[n].cousetotal=i;
    //printf("n=%d\n",n);
    //printf("i=%d\n",i);
    n--;if(n<0)break;
    //printf("i=%d\n",i);

   // printf(" student_array[student_total].cousetotal=%d\n" student_array[student_total].cousetotal);
    fclose(fp);
    }
    //for(int j=0;j<i;j++)printf("%s    %s   %.1lf   %.1lf   %.1lf   %.1lf   %d   %s   %d    %d\n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count,student_array[studenti].All_course[j].fnish);
return 0;
}

int Write_ALL()
{
   Write_admin_key();
   Write_student_data();
   Write_student_key();
   Write_student_chose_course();
   Write_course_data();
   return 1;
}

int main()
{
     main_printf();
     main_interface();
     SORT_ALL();
     //Write_ALL();
     END();
     exit_interface();
}


int main_interface()
{
    char chose;int y=28;
    if(!admin_total){
            printf("\n\n\n\n\n");
             for(int i=0;i<y;i++)printf(" ");printf("---------------------------------\n");
             for(int i=0;i<y;i++)printf(" ");printf("首次使用系统,请输入管理员相关信息\n");
             for(int i=0;i<y;i++)printf(" ");printf("---------------------------------\n");
    char num[20],key1[20],key2[20];
    printf("\n\n请输入管理员账号\n");
    fflush(stdin);
    if(!scan_num(num)){printf("未完成注册!\n");return 0;}
    while(1){
            system("CLS");
    printf("请输入管理员密码\n");
    if(!scanf_key(key1)){printf("未完成注册!\n");return 0;}
    system("CLS");
    printf("\n请再次输入管理员密码\n");
    if(!scanf_key(key2))continue;
    if(!strcmp(key1,key2))break;
    printf("\n两次输入密码不同，请确认后再重新输入\n");
    }
    printf("\n您现在注册的管理员账号为%s   密码为  %s\n确认请按Y   放弃请按N\n",num,key1);char ch;
    while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("输入无效\n");}
    if(ch=='Y'||ch=='y'){
        strcpy(admin_key_data[admin_total].num,num);
        strcpy(admin_key_data[admin_total++].key,key2);
        system("CLS");printf("\n\n\n\n");
        if(!course_total||!student_total)
        {
                           for(int i=0;i<44;i++)printf(" ");printf("-----------------------------------\n");
        if(!student_total){for(int i=0;i<44;i++)printf(" ");printf("现在系统暂无学生，快去注册吧！\n");}
        if(!course_total){ for(int i=0;i<44;i++)printf(" ");printf("现在系统中暂无选修课，快去完善它吧！\n");}
                           for(int i=0;i<44;i++)printf(" ");printf("-----------------------------------");
        }
    }
    else return 0;
    }
    while(1)
    {

        printf("\n\n\n\n\n");
        for(int i=0;i<y;i++)printf(" ");printf("-----------------------------------\n");
        for(int i=0;i<y;i++)printf(" ");printf("---          1:学生登陆         ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---          2:管理员登陆       ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---          *:退出系统         ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("-----------------------------------\n");
        printf("\n\n\n\n\n\n\n\n");
        {
        while(1){char ch;printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='2')||ch=='*'){chose=ch;break;}
        else printf("该输入无效\n");}
        }
        switch(chose)
        {
           case '1':if(student_total){system("CLS");int y=35;
                  printf("\n");
                  for(int i=0;i<y;i++)printf(" "); printf("******************\n");
                  for(int i=0;i<y;i++)printf(" "); printf("***  学生登陆  ***\n");
                  for(int i=0;i<y;i++)printf(" "); printf("******************\n\n\n");
                   if(!student_login()){system("CLS");break;}
                  if(!student_login_interface())
                  {return 1;}
           }else {
           printf("对不起，系统正在维修中，暂不可用！\n");
           }
                  break;

           case '2':system("CLS");int y1;
                  printf("\n");y1=37;
                  for(int i=0;i<y1;i++)printf(" "); printf("********************\n");
                  for(int i=0;i<y1;i++)printf(" "); printf("***  管理员登陆  ***\n");
                  for(int i=0;i<y1;i++)printf(" "); printf("********************\n\n\n");
                  if(!admin_login()){system("CLS");break;}
                  if(!admin_interface())
                  {return 1;}
                  break;
           case '*':return 1;
        }
    }
}
int student_login_interface()
{
    int flag=0;char chose;int y=17;
    welcome_interface();
    while(1)
    {
        for(int i=0;i<7;i++)printf("\n");
        if(flag){system("CLS");printf("该输入不合法，请重新输入\n");flag=0;}
        for(int i=0;i<y;i++)printf(" ");printf("---------------------------------------------------------\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               1:个人基本信息的查看和修改          ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               2:选修课及考试情况                  ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               3:查看全班同学的考试情况            ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               4:查看所选选修课全班考试情况        ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               0:返回登录界面                      ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               *:退出系统                          ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---------------------------------------------------------\n\n\n\n");
        {
        while(1){char ch;printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='4')||ch=='*'){chose=ch;break;}
        else printf("该输入无效\n");}
        }
        switch(chose)
        {
           case '1':system("CLS");
                  printf("个人基本信息的查看和修改\n");
                  if(!student_base_data_interface()){system("CLS");return 0;}
                  system("CLS");break;
           case '2':system("CLS");
                  //printf("选修课及考试情况\n");
                  printf("                     %s     %s   同学所有选修课的考试情况\n",student_array[studenti].class_name,student_array[studenti].name);
                  printf("   -----------------------------------------------------------------------------------");
                  student_choose_class_data();student_total_credit();system("pause");system("CLS");break;
           case '3':system("CLS");
                  printf("查看全班同学的考试情况\n");
                   for(int i=0;i<classnum;i++)if(!strcmp(ALLCLASS[i].class_name,student_array[studenti].class_name))
       {
        printf("                            %s\n",ALLCLASS[i].class_name);
        for(int j=0;j<ALLCLASS[i].count;j++)
        {
        int studenti=ALLCLASS[i].student_num[j];//if(!student_array[studenti].cousetotal)continue;
        printf("学生号:%s\n",student_array[studenti].num);
        printf("   编号    名称   平时成绩   期末成绩   平均成绩   学分 \n");
        printf("--------------------------------------------------------------\n");
        for(int j=0;j<student_array[studenti].cousetotal;j++){
                if(!student_array[studenti].All_course[j].fnish)continue;
    printf(" %s%8s%9.1lf%12.1lf%10.1lf%9.1lf     \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);
        }
         printf("--------------------------------------------------------------\n\n");

        }
    printf("\n");}system("pause");system("CLS");
                  break;
           case '4':system("CLS");int i;
                  printf("查看所选选修课全班考试情况\n");
                  while(1){
                  printf("你现在所选的所有选修课如下\n");
                  printf("----------------\n");
                  for( i=0;i<student_array[studenti].cousetotal;i++)
                  {printf("%s      %s ",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);
                  if(!student_array[studenti].All_course[i].fnish)printf("(未有成绩信息)\n");
                  else printf("\n");
                  }
                  printf("----------------\n");
                  printf("请输入你想查找的课程编号\n");
                  char s[20];fflush(stdin);if(!scan_course_num(s))break;
                  for( i=0;i<student_array[studenti].cousetotal;i++)
                  if(!strcmp(s,student_array[studenti].All_course[i].num))break;
                  if(i>=student_array[studenti].cousetotal){printf("对不起，未找到该课程!\n");}
                  else{
                      int m;
                      for(m=0;m<course_total;m++)
                        if(!strcmp(ALL_course[m].num,s))break;
                      if(!ALL_course[m].finish)
                    if(!student_array[studenti].All_course[i].fnish)
                    {printf("对不起该科目暂未有考试成绩信息或者未完全录入完毕，暂不可查询\n");
                      printf("继续查找其它科目：Y  结束：N\n");
                    {char cho;while(1){fflush(stdin);scanf("%c",&cho);
                if(cho=='Y'||cho=='y'||cho=='N'||cho=='n'||cho=='X'||cho=='x')break;
                else printf("该输入无效，请重新输入\n");}
                if(cho=='Y'||cho=='y'){system("CLS");continue;}
                else break;
                    }
                      }system("CLS");
                  printf("\n\n  课程名称: %s      已选人数: %d\n",ALL_course[i].name,ALL_course[i].count);
                  printf("----------------------------------------------------\n");
                  printf("   姓名     平时成绩   期末成绩   平均成绩   学分 \n");
                  for(int j=0;j<ALL_course[i].count;j++)
                {
                int k,idex=ALL_course[i].Choose_student_idex[j];
                for( k=0;k<student_array[idex].cousetotal;k++)if(!strcmp(student_array[idex].All_course[k].name,ALL_course[i].name))break;
                  printf(" %8s%10.1lf%10.1lf%10.1lf%9.1lf\n",student_array[idex].name,student_array[idex].All_course[k].usual_score,student_array[idex].All_course[k].exam_score,student_array[idex].All_course[k].final_score,student_array[idex].All_course[k].credit);
                }
                  printf("----------------------------------------------------\n");
                printf("\n");}
                printf("继续查找其它科目：Y  结束：N\n");
                char cho;while(1){fflush(stdin);scanf("%c",&cho);
                if(cho=='Y'||cho=='y'||cho=='N'||cho=='n'||cho=='X'||cho=='x')break;
                else printf("该输入无效，请重新输入\n");}
                if(cho=='Y'||cho=='y'){system("CLS");continue;}
                else break;
                }system("pause");system("CLS");
                break;
           case '*':return 0;
           case '0':system("CLS");return 1;
           default :flag=1;break;//printf("该输入不合法，请重新输入\n");
        }
    }
}
void personal_base_information()
{
    int i=studenti;
    printf("\n    学生号       班级       姓名     性别     年龄      宿舍    电话号码\n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("%10s%12s%9s%7s%9s%10s%14s\n",student_array[i].num,student_array[i].class_name,student_array[i].name,student_array[i].sex,student_array[i].age,student_array[i].dormitory,student_array[i].phone);
    printf("--------------------------------------------------------------------------\n\n\n");
}
void student_choose_class_data()
{
printf("\n\n\n\n   编号      名称    平时成绩  期末成绩  平均成绩  学分   是否重修   重修学期   重修次数\n");
    for(int j=0;j<student_array[studenti].cousetotal;j++){
    if(!student_array[studenti].All_course[j].fnish)continue;
    printf("----------------------------------------------------------------------------------------\n");
    printf(" %s %8s  %8.1lf%10.1lf%10.1lf%8.1lf     ",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);

      if(student_array[studenti].All_course[j].IsRetake)
    {
        printf("是     %s      %d\n",student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);}
        else printf("否         无         无\n");

    }
    printf("---------------------------------------------------------------------------------------\n");

//  printf("%s    %s   %.1lf   %.1lf   %.1lf   %.1lf \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[0].All_course[0].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);

    //printf("tatatt=%d\n",student_array[studenti].cousetotal);
}
void student_total_credit()
{
    printf("\n\n                                                               总修学分: ");
    printf("%.2lf\n",student_array[studenti].total_credit);
    printf("---------------------------------------------------------------------------------------\n");
    printf("不及格的选修课\n课程编号        课程名称     综合成绩\n");
    for(int i=0;i<student_array[studenti].cousetotal;i++)
        if(!student_array[studenti].All_course[i].fnish)continue;
        else if(student_array[studenti].All_course[i].final_score<60)
    {               printf("-------------------------------------\n");
         printf("%s\t\t%s\t\t%.1lf   \n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name,student_array[studenti].All_course[i].final_score);
    }
                    printf("-------------------------------------\n");
         printf("\n\n\n");

            printf("暂无成绩的选修课\n");
            printf(" 课程编号        课程名称\n");
    for(int i=0;i<student_array[studenti].cousetotal;i++)
        if(!student_array[studenti].All_course[i].fnish)
        {   printf("---------------------------\n");
            printf(" %s            %s\n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);
        }
            printf("---------------------------\n");
printf("\n\n");

}
int student_base_data_interface()
{
   // printf("个人基本信息的查看和修改\n");
    //personal_base_information();
    int keyflag;char news1[20],news2[20],s[20];
    while(1)
    {
        system("CLS");personal_base_information();
        char ch;fflush(stdin);
        printf("1:密码修改   2:修改手机号码   0:返回上个界面   *:退出系统\n\n\n");
        while(1){
                fflush(stdin);printf("请输入您的选择\n");
        scanf("%c",&ch);if(ch>='1'||ch<='2'||ch=='*')break;
        else printf("输入无效\n");}

        switch(ch)
        {
           case '1':system("CLS");
                  while(1){keyflag=0;
                  printf("请输入原密码\n");
                  fflush(stdin);
                  int p=Input_key(student_key_data[studenti].key);
                  if(p==2)break;
                  if(p==1)
                  while(1)
                  {system("CLS");
                  printf("请输入新密码\n");
                  scanf_key(news1);system("CLS");
                  printf("请再次输入新密码\n");
                  scanf_key(news2);system("CLS");
                  if(!strcmp(news1,news2)){strcpy(student_key_data[studenti].key,news1);printf("修改密码成功\n");keyflag=1;system("pause"); break;}
                  else {printf("两次输入密码不同，请再次输入\n");continue;}
                  }
                  if(keyflag)break;
                  else {system("CLS");printf("原密码不正确，请确认后再次输入\n");continue;}
                  }
                  break;
           case '2':while(1){//int pchose=0;if(pchose!=0||pchose!=1)printf("该输入无效,请重新输入\n");
                  system("CLS");printf("原手机号码为：%s\n",student_array[studenti].phone);
                  printf("请输入新手机号码\n");
                  fflush(stdin);if(!scan_phone(s))break;system("CLS");
                  printf("确认将原来的手机号：%s\n改为新手机号:%s\n是则输入Y，否则输入N\n",student_array[studenti].phone,s);
                while(1){
                fflush(stdin);printf("请输入您的选择\n");
                scanf("%c",&ch);if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
                else printf("输入无效\n");}
                  if(ch=='Y'||ch=='y'){strcpy(student_array[studenti].phone,s);printf("修改手机号码成功\n");break;}
                  else {printf("手机号码未修改成功\n");break;}
                  }system("pause");
                  break;
          // case 3:printf("邮箱\n");break;
           case '*':return 0;
           case '0':system("CLS");return 1;
        }
    }
}
int admin_interface()
{
    welcome_interface();
    char  chose;int flag=0;
    while(1)
    {if(!course_total||!student_total)
        {
                 for(int i=0;i<35;i++)printf(" ");printf("温馨提示:-----------------------------------\n");
        if(!student_total){for(int i=0;i<44;i++)printf(" ");printf("现在系统暂无学生，快去注册吧！\n");}
        if(!course_total){ for(int i=0;i<44;i++)printf(" ");printf("现在系统中暂无选修课，快去完善它吧！\n");}
                           for(int i=0;i<44;i++)printf(" ");printf("-----------------------------------");
        }
    else {
for(int i=0;i<52;i++)printf(" ");printf("系统信息-----------------\n");
        for(int i=0;i<60;i++)printf(" ");printf("已注册学生总数 %d \n",student_total);
        for(int i=0;i<60;i++)printf(" ");printf("已有的选修课程 %d \n",course_total);
        for(int i=0;i<60;i++)printf(" ");printf("已有的班级总数 %d \n",classnum);
        for(int i=0;i<60;i++)printf(" ");printf("-----------------\n");
    }
        printf("\n\n\n");int y=15;
        if(flag){system("CLS");printf("该输入不合法，请重新输入\n");flag=0;}
        for(int i=0;i<y;i++)printf(" ");printf("-------------------------------------------------------------\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               1:学生注册与录入学生基本信息            ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               2:给学生录入选课信息                    ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               3:录入课程基本信息和考试情况            ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               4:查看与修改学生基本信息                ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               5:查看学生已修学分和各课程不及格学生名单---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               6:查看学生考试情况                      ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               7:修改管理员密码                        ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               8:增加或删除某门选修课                  ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               9:删除学生                              ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               0:返回登陆界面                          ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("---               *:退出系统                              ---\n");
        for(int i=0;i<y;i++)printf(" ");printf("-------------------------------------------------------------\n");
        //printf("9:注销某学生账号及信息\n0:返回主界面\n9:退出系统\n");
         {
        while(1){char ch;printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='9')||ch=='*'){chose=ch;break;}
        else printf("该输入无效\n");}
        }
        switch(chose)
        {
           case '1':system("CLS");
                  for(int i=0;i<32;i++)printf(" ");printf("学生注册与录入学生基本信息\n");
            printf("    ---------------------------------------------------------------------------------\n");
                  Insert_student();
                  break;
           case '2':system("CLS");if(!student_total){printf("现在系统还没有学生信息，快去注册吧！\n");break;}
              if(!course_total){printf("现在系统中暂无选修课，快去完善它吧！\n");break;}
           printf("                                    给学生录入选课信息\n");
           printf("    ---------------------------------------------------------------------------------\n");
           input_student_imformation_of_course();break;
           case '3': if(!course_total){system("CLS");printf("现在系统中暂无选修课，快去完善它吧！\n");break;}
                    input_grade();
                    break;

           case '4':system("CLS");if(!student_total){printf("现在系统还没有学生信息，快去注册吧！\n");break;}

           modification_student_data();system("CLS");
           break;
           case '5':system("CLS");if(!student_total){printf("现在系统还没有学生信息，快去注册吧！\n");break;}
           Total_Credit_Unpass();system("CLS");break;
           case '6':Look_over_scores();break;

           case '7':modification_admin_key();break;
           case '8':add_delete_course(); system("CLS"); break;
           case '9':system("CLS");for(int i=0;i<28;i++)printf(" ");printf("       删除学生信息\n");
           printf("    -------------------------------------------------------------------------\n");
           Delete_student_data();break;
           case '*':return 0;
           case '0':system("CLS");return 1;
           default :flag=1;break;//printf("该输入不合法，请重新输入\n");

        }
    }
}
int admin_student_base_data_interface()
{
     char  chose;int flag=0;
     char s[20];
     printf("请输入修改学生的学生号或名字\n");
     gets(s);gets(s);
     system("CLS");
    while(1)
    {
        if(flag){system("CLS");printf("该输入不合法，请重新输入\n");flag=0;}
        printf("1:修改姓名\n2:修改性别\n3:修改学号\n4:修改年龄\n5:修改宿舍号\n6:修改电话号码\n0:返回上界面\n*:退出系统\n");
        {
        while(1){char ch;printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if((ch>='0'&&ch<='6')||ch=='*'){chose=ch;break;}
        else printf("该输入无效\n");}
        }
        switch(chose)
        {
           case '1':system("CLS");
                  printf("请输入新姓名\n");
                  gets(s);gets(s);printf("修改成功\n");break;
           case '2':system("CLS");
                  printf("请输入性别\n");
                  gets(s);gets(s);printf("修改成功\n");break;
           case '3':system("CLS");
                  printf("请输入学号\n");
                  gets(s);gets(s);printf("修改成功\n");break;
           case '4':system("CLS");
                  printf("请输入新年龄\n");
                  gets(s);gets(s);printf("修改成功\n");break;
           case '5':system("CLS");
                  printf("请输入新宿舍号\n");
                  gets(s);gets(s);printf("修改成功\n");break;
           case '6':system("CLS");
                 printf("请输入新电话号\n");
                 gets(s);gets(s);printf("修改成功\n");break;
           case '*':return 0;
           case '0':system("CLS");return 1;
           default :flag=1;break;//printf("该输入不合法，请重新输入\n");
        }
    }
}
int exit_interface()
{
    int i,j;
    system("CLS");char s[100]="Designed By Chen M L";
    char a[100]="<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<感谢使用教务系统>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    printf("\n\n\n\n\n\n\n\n\n\n");
    int x=strlen(a),b=strlen(s);
    for(i=0;i<x;i++)
    {
        for(int j=0;j<10000000;j++);
        putchar(a[i]);
    }
    printf("\n\n\n\n\n\n\n");
                            printf("                                                             ");
    for(i=0;i<b;i++)
    {
        for(j=0;j<20131400;j++);
        putchar(s[i]);
    }
    printf("\n\n");
    return 0;

}


int student_login()
{
    int flag=0;
    char key[15],num[15];int count=4;
while(1){
    while(1)
{   printf("请输入你的证件号码\n");
    if(!scan_num(num))return 0;
    system("CLS");
    flag=0;
    for(int i=0;i<student_key_total;i++)
    if(strcmp(num,student_key_data[i].num)==0){strcpy(key,student_key_data[i].key);flag=1;studenti=i;break;}
    if(!flag)printf("该学号无效，请确认后再输入学号\n");
    else break;
}
int p;
while(1){
printf("请输入密码：\n");
 while(1)
 {
     p=Input_key(key);
     if(!p){
     system("CLS");
     printf("密码错误！\n你还有%d次机会输入密码,请再次确认后再输入您的密码\n",--count);
     if(!count){
            if(COUNTDOWN>20){system("CLS");p=3;printf("\n\n\n\n\n\n\n\n                           请到教务处找回密码现返回登陆界面\n");for(int i=0;i<2000000000;i++);break;}
            printf("对不起，请你在  %d 后再输入密码\n",COUNTDOWN);Countdown_Clock();COUNTDOWN+=5;count=4;break;}
 }

 if(p==2)break;
    if(p==1) {system("CLS");COUNTDOWN=5;return 1;}
 }system("CLS");if(p==2||p==3)break;
}if(p==2){system("CLS");continue;}
if(p==3)break;
}
return 0;
}

int admin_login()
{
    int flag=0;
    char key[15],num[15];int count=4;
while(1){
    while(1)
{   printf("请输入你的证件号码\n");
    if(!scan_num(num))return 0;
    system("CLS");
    flag=0;
    for(int i=0;i<admin_total;i++)
    if(strcmp(num,admin_key_data[i].num)==0){strcpy(key,admin_key_data[i].key);admini=i;flag=1;break;}
    if(!flag)printf("该证件号无效，请确认后再输入证件号\n");
    else break;
}int p;
while(1){
printf("请输入密码：\n");
 while(1)
 {  p=Input_key(key);
     if(!p){
     system("CLS");
     printf("密码错误！\n你还有%d次机会输入密码,请再次确认后再输入您的密码\n",--count);
     if(!count){printf("对不起，请你在  %d 后再输入密码\n",COUNTDOWN);Countdown_Clock();COUNTDOWN=2*COUNTDOWN;count=4;break;}
 }
 if(p==2)break;
 if(p==1){system("CLS");COUNTDOWN=5;return 1;}

 }if(p==2)break;
 system("CLS");
}if(p==2){system("CLS");continue;}
}
}

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
  if(!strcmp(ps,"*"))return 2;
  if(strcmp(key,ps)==0)return 1;
  return 0;
  printf("\n");
  }
}
void welcome_interface()
{int y;
for(int i=1;i<12;i++) printf("\n");
char s[100]="<<<<<<<<<<<<<<<<<<<欢迎登陆教务系统>>>>>>>>>>>>>>>>>>>\n";
y=strlen(s);
 printf("                  ");
 for(int i=0;i<y;i++){for(int j=0;j<=10000000;j++);printf("%c",s[i]);}
  for(int i=1;i<12;i++) printf("\n");
 for(int j=0;j<=300000000;j++);
 system("CLS");
}

int modification_student_data()
{
    char num[20];int i,aa;
    while(1){
             for(int j=0;j<33;j++)printf(" ");
           printf("修改学生基本信息\n");
           printf("    -----------------------------------------------------------------------------\n");
            aa=0;
            printf("输入学生学号\n");
    fflush(stdin);if(!scan_num(num))break;
    for(studenti=0;studenti<student_total;studenti++)
        if(!strcmp(num,student_array[studenti].num))break;
        if(studenti>=student_total){system("CLS");printf("未找到该学生,请重新输入学号\n");continue;}
        system("CLS");
    while(1)
    {   printf("\n\n 您正在为  %s      %s  同学修改相关信息\n\n\n\n",student_array[studenti].num,student_array[studenti].name);
        printf("\n1:修改密码     2:修改其他基本信息    *:返回上一界面\n\n\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);
    if(ch=='1'||ch=='2'||ch=='*')break;
    else printf("该输入无效，请重新输入\n");
    }
    if(ch=='*'){aa=1;break;}
    switch(ch)
    {
        case '1':system("CLS");
            for(i=0;i<student_key_total;i++)
            if(!strcmp(num,student_key_data[i].num))break;
                studenti=i;if(!modification_student_key()){continue;}
                break;
        case '2':system("CLS");
               for(i=0;i<student_total;i++)
                if(!strcmp(num,student_array[i].num))break;
                studenti=i;if(!modification_student_basic_data())continue;
                break;
    }
printf("继续修改 Y  结束修改 N\n");
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
        else printf("该输入无效\n");}
        if(ch=='N'||ch=='n')break;
    }if(aa){system("CLS");continue;}
    printf("\n\n是否继续修改其他学生信息\n");
   printf("继续修改 Y  结束修改 N\n");
    {   char ch;
        while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
        else printf("该输入无效\n");}
        if(ch=='N'||ch=='n')break;
    }
    }
    return 0;
}
int modification_student_basic_data()
{

    char name[20],clas[20],num[20],dor[20],phone[20],age[20],sex[20];
     while(1){int ff;int fflag=0;
    printf("要修改的学生信息如下\n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n    学生号       班级       姓名     性别     年龄      宿舍    电话号码\n\n");
    printf("%10s%12s%9s%7s%9s%10s%14s\n",student_array[studenti].num,student_array[studenti].class_name,student_array[studenti].name,student_array[studenti].sex,student_array[studenti].age,student_array[studenti].dormitory,student_array[studenti].phone);
    printf("-----------------------------------------------------------------------\n");
        printf("\n1:修改学号       2:修改名字       3:修改班别     4:修改性别\n5:修改年龄       6:修改宿舍号     7:修改电话号   *:返回上一界面 \n");
        char ch;fflush(stdin);while(1){fflush(stdin);printf("请输入您的选择\n");scanf("%c",&ch);if(ch>='1'||ch<='7')break;else printf("输入无效\n");}
        switch(ch)
        {
            case '1':while(1){ff=0;printf("请输入新学号\n");
                scan_num(num);
        for(int i=0;i<=student_key_total;i++)
        if(strcmp(num,student_key_data[i].num)==0){ff=1;break;}
        if(ff){printf("对不起，该学生号已被注册，请换另一用户名\n");continue;}
        else {strcpy(student_array[studenti].num,num);printf("修改成功\n");break;}
        }break;
            case '2':printf("请输入新名字\n");scanf("%s",name);strcpy(student_array[studenti].name,name);printf("修改成功\n");break;
            case '3':printf("请输入新班别\n");scanf("%s",clas);strcpy(student_array[studenti].class_name,clas);printf("修改成功\n");break;
            case '4':printf("请输入性别\n");scanf("%s",sex);strcpy(student_array[studenti].sex,sex);printf("修改成功\n");break;
            case '5':printf("请输入年龄\n");scanf("%s",age);strcpy(student_array[studenti].age,age);printf("修改成功\n");break;
            case '6':printf("请输入新宿舍号\n");scanf("%s",dor);strcpy(student_array[studenti].dormitory,dor);printf("修改成功\n");break;
            case '7':printf("请输入新电话号\n");scan_num(phone);strcpy(student_array[studenti].phone,phone);printf("修改成功\n");break;
            case '*':{system("CLS");return 0;}
        }
        printf("-----------------------------------------------------------------------\n");
        printf("\n    学生号       班级       姓名     性别     年龄      宿舍    电话号码\n\n");
        printf("%10s%12s%9s%7s%9s%10s%14s\n",student_array[studenti].num,student_array[studenti].class_name,student_array[studenti].name,student_array[studenti].sex,student_array[studenti].age,student_array[studenti].dormitory,student_array[studenti].phone);
        printf("-----------------------------------------------------------------------\n");
        printf("继续修改:Y\n退出修改:N\n请输入您的选择");
        {
        while(1){char ch;printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y')break;
        if(ch=='N'||ch=='n'){fflag=1;break;}
        else printf("输入无效\n");}

        }
        if(fflag)break;
        }
        return 1;
}
int modification_student_key()
{
    char key1[20],key2[20];
    int flag=0;
    while(1)
    {
        printf("请输入您的新密码\n");
        fflush(stdin);if(!scanf_key(key1))return 0;
        fflush(stdin);printf("\n请再次输入您的新密码\n");if(!scanf_key(key2))continue;
        if(strcmp(key1,key2)){printf("\n两次输入密码不一样,请重新输入\n");flag=0;}
        else flag=1;
        if(flag){strcpy(student_key_data[studenti].key,key1);break;}
    }
     printf("\n请保存好您的密码！\n您的新密码为 ");
    printf("%s\n",key1);
    return 1;
}

int input_student_imformation_of_course()
{
    char num[20],counum[20];int i;int fff;

    while(1){printf("\n\n\n输入您要录入相关信息的学生学号\n");
    fflush(stdin);if(!scan_num(num))return 0;
    for(i=0;i<student_key_total;i++)
        if(!strcmp(num,student_key_data[i].num)){studenti=i;break;}
        if(i>=student_key_total){printf("未找到该学生\n");continue;}
        studenti=i;
     while(1){ fff=0; printf("您即将为 %s  同学录入选课信息\n",student_array[studenti].name);
     printf("所有选修课的编号及名称\n");
     for(int j=0;j<course_total;j++)
     printf("%s   %s\n",ALL_course[j].num,ALL_course[j].name);
     int flag=0;
     printf("请输入选修课编号\n");
     fflush(stdin);fff=scan_course_num(counum);
     if(!fff){system("CLS");break;}
     if(!repeat_course(counum)){system("CLS");printf("该学生已经注册了该课程，无需再重复注册\n");continue;}
     for(i=0;i<course_total;i++)if(!strcmp(counum,ALL_course[i].num)){flag=1;break;}
     if(flag){
     printf("确认在学生  %s   添加课程  %s     %s\n确认:Y  放弃:N\n",student_array[studenti].name,ALL_course[i].num,ALL_course[i].name);
    {char ch;
     while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
     if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
     else printf("输入无效\n");}
    if(ch=='Y'||ch=='y'){
       student_array[studenti].All_course[student_array[studenti].cousetotal].credit=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].usual_score=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].exam_score=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].final_score=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].IsRetake=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].Retake_count=0;
       student_array[studenti].All_course[student_array[studenti].cousetotal].fnish=0;
       strcpy(student_array[studenti].All_course[student_array[studenti].cousetotal].Retake_semester,"无");
       strcpy(student_array[studenti].All_course[student_array[studenti].cousetotal].num,counum);
       ALL_course[i].finish=0;
       ALL_course[i].Choose_student_idex[ALL_course[i].count++]=studenti;
       strcpy(student_array[studenti].All_course[student_array[studenti].cousetotal++].name,ALL_course[i].name);

       printf("添加成功\n");
        }
     }
     }
    else  {system("CLS");printf("不存在该课程，请重新输入课程编号\n");}
    printf("继续添加:Y  结束添加:N\n");{char ch;
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    break;else printf("输入无效\n");}
    if(ch=='N'||ch=='n')break;
     }
     }if(!fff)continue;
     printf("是否继续为其他学生录入选修课\n");
     printf("Y 继续录入  N 结束录入\n");
     {  char ch;
         while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    break;else printf("输入无效\n");}
    if(ch=='N'||ch=='n')break;
     }
     }
    //for(i=0;i<student_array[studenti].cousetotal;i++)
        //printf("%s   %s\n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);
        return 0;
}

int input_student_grade_imformation_of_course()
{
    while(1){printf("请输入录入信息的学生学号\n");
                  char num[20];int i,pp=1,fflag=0;
                  fflush(stdin);if(!scan_num(num))break;
        for(i=0;i<student_key_total;i++)
        if(!strcmp(num,student_key_data[i].num))break;
        if(i>=student_key_total){printf("未找到该学生\n");continue;}
        studenti=i;
    char counum[20],s[20];
    int flag=0,course_flag=0;
    double u,e,cre;
    while(1){fflag=0;course_flag=0;
    for(i=0;i<student_array[studenti].cousetotal;i++)
    if(!student_array[studenti].All_course[i].fnish)
    {course_flag=1;break;}
    if(!course_flag){printf("该同学所有课程成绩信息已录入完毕，无需再次录入\n");break;}
     printf("所有未录入成绩的课程编号和名字\n");
    for(i=0;i<student_array[studenti].cousetotal;i++)
    if(!student_array[studenti].All_course[i].fnish)
    {printf("%s    %s\n",student_array[studenti].All_course[i].num,student_array[studenti].All_course[i].name);}
    printf("输入要输入成绩的课程编号\n");flag=0;
    pp=scan_course_num(counum);
    if(!pp)break;
    for(i=0;i<student_array[studenti].cousetotal;i++)if(!strcmp(student_array[studenti].All_course[i].num,counum))break;
    if(i>=student_array[studenti].cousetotal){printf("对不起，该学生未有此选修课\n");return 0;}
    printf("您现在为  %s  录入   %s  科目的成绩及选修情况\n",student_array[studenti].name,student_array[studenti].All_course[i].name);
    int fg=0;
    for(;!fg;)
    {
        printf("请输入平时成绩\n");
        if(!scan_score(u))break;
        else for(;!fg;)
        {
            printf("请输入期末成绩\n");
            if(!scan_score(e))break;
            else for(;!fg;){
                printf("请输入所获学分\n");
                if(!scan_credit(cre))break;
                else fg=1;
            }
        }
    }
if(!fg){system("CLS");continue;}
    printf("请输入是否重修\n输入Y  否输入N\n");
     {char ch;
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')flag=1;break;}else printf("输入无效\n");}
    }
    if(flag)
    {
        fflush(stdin);
        printf("请输入重修学期（格式如2013~2014）\n");
        gets(s);
    }
    printf("您将为 %s 同学 %s  科目录入如下信息\n",student_array[studenti].name,student_array[studenti].All_course[i].name);
    printf("  编号  名称  平时成绩  期末成绩  平均成绩  学分   是否重修   重修学期   重修次数\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("%s%7s%8.1lf%10.1lf%10.1lf%8.1lf     ",counum,student_array[studenti].All_course[i].name,u,e,(e+u)/2,cre);
      if(flag)
    {
        printf("是     %s      %d\n",s,student_array[studenti].All_course[i].Retake_count+1);}
        else printf("否         无         无\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("确认请输入Y  放弃输入N\n");

char ch;
    {
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("输入无效\n");}
    if(ch=='N'||ch=='n')printf("课程相关信息未录入\n");
    if(ch=='Y'||ch=='y')
    {
        student_array[studenti].All_course[i].usual_score=u;
        student_array[studenti].All_course[i].exam_score=e;
        student_array[studenti].All_course[i].final_score=(u+e)/2;
         {
        int m;for(m=0;m<course_total;m++)
        if(!strcmp(ALL_course[m].num,student_array[studenti].All_course[i].num))break;
        if((u+e)/2<60)ALL_course[m].unpass=1;
        else ALL_course[m].unpass=0;}
        student_array[studenti].All_course[i].credit=cre;
        student_array[studenti].All_course[i].fnish=1;
        if(flag)
    {
        student_array[studenti].All_course[i].IsRetake=1;
        student_array[studenti].All_course[i].Retake_count++;
        strcpy(student_array[studenti].All_course[i].Retake_semester,s);
    }

       printf("录入成绩成功\n");
    }

    }

    printf("继续录入 %s 同学的其它科目成绩Y  结束录入输入N\n",student_array[studenti].name);
    {char ch;
        while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')fflag=1;break;}else printf("输入无效\n");}
    }
    if(!fflag)break;
}
if(!pp)continue;
printf("是否继续录入其他同学的成绩\n");
printf("Y 继续录入  N 结束录入\n");
{char ch;
        while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')fflag=1;break;}else printf("输入无效\n");}
   if(ch=='N'||ch=='n')break;
    }

}
return 0;
}

int searchstudentaccordingnuminkey()
{
    int i;char num[20];
    for(i=0;i<student_key_total;i++)if(!strcmp(num,student_key_data[i].num))break;studenti=i;
    return 0;
}

int all_student_total_credit()
{system("CLS");
    for(int i=0;i<32;i++)printf(" ");
    printf("所有学生已修学分\n");
    printf("    -------------------------------------------------------------------------\n\n\n");
    int i;
    printf("    学生号           姓名       已修学分\n");
    printf(" --------------------------------------\n");
    for(i=0;i<student_total;i++)
    {
    printf(" %12s%13s%12.2lf\n",student_array[i].num,student_array[i].name,student_array[i].total_credit);
    printf(" --------------------------------------\n");

    }
    return 0;
}
int unpass()
{
    system("CLS");
        for(int i=0;i<30;i++)printf(" ");printf("查看各科目不及格学生的名单\n");
    printf("   ----------------------------------------------------------------------\n\n\n");
    int idex,k;

    for(int i=0;i<course_total;i++)
    {
       if(ALL_course[i].unpass)
            {printf("课程名字: ");
             printf("%s \n\n",ALL_course[i].name);
             printf("   学号            班别          姓名\n");
             printf(" --------------------------------------\n");
            for(int j=0;j<ALL_course[i].count;j++)
            {
                idex=ALL_course[i].Choose_student_idex[j];
                for(k=0;k<student_array[idex].cousetotal;k++)
                {if(!strcmp(ALL_course[i].num,student_array[idex].All_course[k].num))break;}
                    if(student_array[idex].All_course[k].final_score<60&&(student_array[idex].All_course[k].fnish))
                printf("%s\t%s\t%s\n",student_array[idex].num,student_array[idex].class_name,student_array[idex].name);
            }
            printf("\n");
            }
    }
    return 0;
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
int R_L_K(char*s)
{
    if(strlen(s)>=6&&strlen(s)<=12)return 1;
    else return 0;
}

int scan_num(char *num)
{
    while(1){printf("         (证件号长度为 12)\n");
             printf("               输入 * 返回\n");
    char s[100];
    fflush(stdin);
    scanf("%s",s);
    //printf("s=%s\n",s);
    if(!strcmp(s,"*"))return 0;
    if(strlen(s)!=12){system("CLS");printf("输入证件号长度不合法，请重新输入\n");continue;}
    strcpy(num,s);
    return 1;
    }
}
int scan_course_num(char *num)
{
    while(1){printf("         (选修课编号长度为 6)\n");
             printf("               (输入 *  返回)\n");
    char s[100];
    fflush(stdin);
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    if(strlen(s)!=6){system("CLS");printf("输入选修课编号长度不正确，请重新输入\n");continue;}
    strcpy(num,s);
    return 1;
    }
}
int scan_phone(char *num)
{
   printf("请输入手机号码\n");
    while(1){printf("         (手机号码长度为 11或6)\n");
             printf("                (输入 * 返回)\n");
    char s[100];
    fflush(stdin);
    scanf("%s",s);
    if(!strcmp(s,"*")){system("CLS");return 0;}
    if(!(strlen(s)==11||strlen(s)==6)){system("CLS");printf("输入手机号码长度不正确，请重新输入\n");continue;}
    strcpy(num,s);
    system("CLS");return 1;
    }
}

int right_course(char *s)
{
    for(int i=0;i<course_total;i++)
        if(!strcmp(s,ALL_course[i].num))return 0;
    return 1;
}

int repeat_course(char *s)
{
    for(int i=0;i<student_array[studenti].cousetotal;i++)
        if(!strcmp(s,student_array[studenti].All_course[i].num))return 0;
    return 1;
}
int encrypt(char *key)
{
    int y=strlen(key);
    for(int i=0;i<y;i++)
        key[i]=key[i]^15;
    return 0;
}
int decode(char *key)
{
   int y=strlen(key);
   for(int i=0;i<y;i++)
   key[i]=key[i]^15;
   return 0;

}
int scan_class(char *s)
{
    //system("CLS");
    while(1){printf("请输入班别  (如:软件工程R2)  \n");
    printf("         (输入 * 返回)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;

    return 1;
    }
}
int scan_name(char *s)
{
    system("CLS");
    printf("请输入姓名\n");
    printf("         (输入 * 返回)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    return 1;
}
int scan_dor(char *s)
{
    system("CLS");
    while(1){
    printf("请输入宿舍号 (格式如 7-413 )\n");
    printf("         (输入 * 返回)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    return 1;}
}
int scan_age(char *s)
{
    int d;
    system("CLS");
   while(1){printf("请输入年龄\n");
    printf("         (输入 * 返回)\n");
    scanf("%s",s);
    if(!strcmp(s,"*"))return 0;
    sscanf(s,"%d",&d);
    if(d<0||d>=200){system("CLS");printf("输入年龄不合理,请重新输入\n");continue;}
    return 1;}
}
int scan_sex(char *s)
{   char a[100];
    system("CLS");
    while(1)
    {printf("请输入性别\n");
    printf("         (输入 * 返回)\n");
    printf(" 1:男  2:女\n");
    scanf("%s",a);
    if(!strcmp(s,"*"))return 0;
    if(!strcmp(a,"1")||!strcmp(a,"2"))break;
    system("CLS");printf("输入无效，请重新输入\n");
    }
    if(!strcmp(a,"1"))strcpy(s,"男");
    if(!strcmp(a,"2"))strcpy(s,"男");
    return 1;
}
int scan_score(double &s)
{
    while(1){printf("        (分数为百分制)\n");
    printf("              (输入-1返回)\n");
    scanf("%lf",&s);
    if(s==-1)return 0;
    if(s<0||s>100){system("CLS");printf("该输入不合法,请重新输入\n");continue;}
     system("CLS");
    return 1;
    }
}
int scan_credit(double &s)
{

    while(1){printf("        (学分的有效范围为0~4分)\n");
    printf("              (输入-1返回)\n");
    scanf("%lf",&s);
    if(s==-1)return 0;
    if(s<0||s>4){system("CLS");printf("该输入不合法,请重新输入\n");continue;}
    system("CLS");
    return 1;
    }
}
int sort_data()
{
   int i,j,flag;
   char temp[20];
    for(i=0;i<student_total;i++)
        {flag=0;
        for(j=0;j<student_total-i-1;j++)
        {
            if(strcmp(student_array[j].num,student_array[j+1].num)>0){
                    strcpy(temp,student_array[j+1].num);
            strcpy(student_array[j+1].num,student_array[j].num);
            strcpy(student_array[j].num,temp);flag=1;}
        }
        if(!flag)break;
        }
        return 0;
}
int sort_student_key()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<student_key_total;i++)
    {
        flag=0;
        for(j=0;j<student_key_total-i-1;j++)
        {
            if(strcmp(student_key_data[j].num,student_key_data[j+1].num)>0)
            {
                strcpy(temp,student_key_data[j+1].num);
                strcpy(student_key_data[j+1].num,student_key_data[j].num);
                strcpy(student_key_data[j].num,temp);
                flag=1;
            }
        }
        if(!flag)break;
    }
    return 0;
}

int sort_admin_key()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<admin_total;i++)
    {
        flag=0;
        for(j=0;j<admin_total-i-1;j++)
        {
            if(strcmp(admin_key_data[j].num,admin_key_data[j+1].num)>0)
            {
                strcpy(temp,admin_key_data[j+1].num);
                strcpy(admin_key_data[j+1].num,admin_key_data[j].num);
                strcpy(admin_key_data[j].num,temp);
                flag=1;
            }
        }
        if(!flag)break;
    }
    return 0;
}
int sort_student_course()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<student_array[studenti].cousetotal;i++)
    {
        flag=0;
        for(j=0;j<student_array[studenti].cousetotal-i-1;j++)
        {
            if(strcmp(student_array[studenti].All_course[j].num,student_array[studenti].All_course[j+1].num)>0)
            {
                strcpy(temp,student_array[studenti].All_course[j].num);
                strcpy(student_array[studenti].All_course[j].num,student_array[studenti].All_course[j+1].num);
                strcpy(student_array[studenti].All_course[j+1].num,temp);
                flag=1;
               // printf("%s\n",temp);
            }
        }
        if(!flag)break;
    }
    return 0;
}

int sort_course()
{
    int i,j,flag;
    char temp[20];
    for(i=0;i<course_total;i++)
    {
        flag=0;
        for(j=0;j<course_total-i-1;j++)
        {
            if(strcmp(ALL_course[j].num,ALL_course[j+1].num)>0)
            {
                strcpy(temp,ALL_course[j+1].num);
                strcpy(ALL_course[j+1].num,ALL_course[j].num);
                strcpy(ALL_course[j].num,temp);
                flag=1;
            }
        }
        if(!flag)break;
    }
    return 0;
}

int I_LOVE_YOU()
{
    int m=1,n=9,i;char s[100]="Design by　Chen M  L";int y=strlen(s);

    for(i=0;i<17;i++){
    system("CLS");
    printf("\n\n\n\n");
    if(i%2==0)printf("\n");
    if(i%3==0)printf("\n\n");
    if(i%4==0)printf("\n\n\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("* * *  *     * * * * *       * * * * *  *    * * * * * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("  *    *     *     *  *     *  *         *  *  *     * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("  *    *     *     *   *   *   * * * *     *   *     * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("  *    *     *     *    * *    *           *   *     * *    *\n");
    for(int j=0;j<m*i%n;j++)printf(" ");printf("* * *  * * * * * * *     *     * * * *     *   * * * * *  * *\n");
    for(int k=0;k<201314000;k++);
    }
     printf("\n\n\n\n\n\n\n\n");
    printf("                                                        ");
    for(int n=0;n<y;n++)
    {
        for(int j=0;j<100000000;j++);
        printf("%c",s[n]);
    }
    printf("\n\n");
   system("pause");
    system("CLS");
    return 0;
}
int logging_grade_data_one_course()
{
    char num[20],s[20];int i;int flag=0;int fg=0;
    double e,u,cre;
    while(1){
            printf("所有课程的编号和名字\n");
    for(i=0;i<course_total;i++)
    {
        printf("%s    %s",ALL_course[i].num,ALL_course[i].name);
        if(ALL_course[i].finish)printf("(已录入完毕)\n");
        else printf("\n");
    }
            printf("请输入要录入成绩的课程编号\n");
    if(!scan_course_num(num)){system("CLS");break;}

    for(i=0;i<course_total;i++)
        if(!strcmp(num,ALL_course[i].num)){coursei=i;break;}

    if(i>=course_total){
            printf("对不起，暂无此课程编号\n");
            printf("退出录入: Y 重新输入: N\n");
    }
    else {//printf("count %d  \n",ALL_course[coursei].count);
            for(i=0;i<ALL_course[coursei].count;i++)
    {
        studenti=ALL_course[coursei].Choose_student_idex[i];
        if(!finish_logging_grade()){break;}
    }
    if(ALL_course[coursei].finish){printf("该课程已完成成绩输入\n");continue;}
    if(!ALL_course[coursei].count){printf("该选修课暂无学生选修\n");continue;}
    printf("已检查到该课程上次已录入到    %s   %s  \n",student_array[studenti].num,student_array[studenti].name);
    printf("从该处继续录入:Y  重新录入: N \n");
    char ch;int ppp;
    {
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("输入无效\n");}
    }
    if(ch=='N'||ch=='n'){i=0;printf("你已选择重新输入选修课成绩\n");}
    while(i<ALL_course[coursei].count)
    {
        flag=0;studenti=ALL_course[coursei].Choose_student_idex[i];
        printf("您现在在为 %s 同学录入 %s  科目的成绩\n",student_array[ALL_course[coursei].Choose_student_idex[i]].name,ALL_course[coursei].name);
        fg=0;
        for(;!fg;)
      {
        printf("请输入平时成绩\n");
        if(ppp=scan_score(u),!ppp)break;
        else for(;!fg;)
        {
            printf("请输入期末成绩\n");
            if(!scan_score(e))break;
            else for(;!fg;){
                printf("请输入所获学分\n");
                if(!scan_credit(cre))break;
                else fg=1;
            }
        }

    }
    if(!fg){system("CLS");break;}
        printf("请输入是否重修\n输入Y  否输入N\n");
     {char ch;
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')
    {if(ch=='Y'||ch=='y')flag=1;break;}else printf("输入无效\n");}
    }
    if(flag)
    {
        fflush(stdin);
        printf("请输入重修学期（格式如2013~2014）\n");
        gets(s);
    }int sti;
    for(sti=0;sti<student_array[studenti].cousetotal;sti++)
        if(!strcmp(student_array[studenti].All_course[sti].num,ALL_course[coursei].num))break;
    printf("您将为 %s 同学 %s  科目录入如下信息\n",student_array[studenti].name,student_array[studenti].All_course[sti].name);
    printf("  编号  名称  平时成绩  期末成绩  平均成绩  学分   是否重修   重修学期   重修次数\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("%s%7s%8.1lf%10.1lf%10.1lf%8.1lf     ",ALL_course[coursei].num,student_array[studenti].All_course[sti].name,u,e,(e+u)/2,cre);
      if(flag)
    {
        printf("是     %s      %d\n",s,student_array[studenti].All_course[sti].Retake_count+1);}
        else printf("否         无         无\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("确认请输入Y  放弃输入N\n");

char ch;
    {
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("输入无效\n");}
    if(ch=='N'||ch=='n')printf("课程相关信息未录入\n");
    if(ch=='Y'||ch=='y')
    {
        student_array[studenti].All_course[sti].usual_score=u;
        student_array[studenti].All_course[sti].exam_score=e;
        student_array[studenti].All_course[sti].final_score=(u+e)/2;
        student_array[studenti].All_course[sti].credit=cre;
        if((u+e)/2<60)ALL_course[coursei].unpass=1;
        student_array[studenti].All_course[sti].fnish=1;
        if(flag)
    {
        student_array[studenti].All_course[sti].IsRetake=1;
        student_array[studenti].All_course[sti].Retake_count++;
        strcpy(student_array[studenti].All_course[sti].Retake_semester,s);
    }
       printf("录入成绩成功\n");i++;
    }
    }
    }
    if(!ppp) continue;
    {ALL_course[coursei].finish=1;
    printf(" %s  %s  录入成绩完毕\n",ALL_course[coursei].num,ALL_course[coursei].name);i=0;}
    }
     if(!fg){system("CLS");continue;}
    {char ch;
    printf("\n\n是否继续录入其它课程\n继续: Y  结束: N \n");
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;
    else printf("输入无效\n");}
    if(ch=='N'||ch=='n')break;
    else i=0;
    }
    }
    system("CLS");
    return 0;
}
int finish_logging_grade()
{
    int i;
    for(i=0;i<student_array[studenti].cousetotal;i++)
        if(!strcmp(student_array[studenti].All_course[i].num,ALL_course[coursei].num))break;
    if(student_array[studenti].All_course[i].fnish){return 1;}
    return 0;
}
int input_grade()
{
    int y=35;
   while(1){
         system("CLS");
                  for(int i=0;i<32;i++)printf(" ");
                  printf("录入课程基本信息和考试情况\n");
                  printf("    ------------------------------------------------------------------------------\n\n\n\n");
    for(int i=0;i<y;i++)printf(" ");printf("-----------------------\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  录入成绩方式   ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  1:按学生学号   ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  2:按选修课课程 ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("---  *:返回         ---\n");
    for(int i=0;i<y;i++)printf(" ");printf("-----------------------\n");
    char ch;
    {
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='1'||ch=='2'||ch=='*')break;
    else printf("输入无效\n");}
    switch(ch)
    {
        case '1':system("CLS");input_student_grade_imformation_of_course();system("CLS");break;
        case '2':system("CLS");logging_grade_data_one_course();system("CLS");break;
        case '*':system("CLS");return 0;
     }
    }
   }
}

int Total_Credit_Unpass()
{
    int y=35;

    while(1){ printf("                              所有学生总学分和各科目不及格名单\n");
              printf("   -----------------------------------------------------------------------------\n\n\n\n");
    for(int i=0;i<y;i++)printf(" "); printf("----------------------------\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  1:所有学生的总学分  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  2:各科目不及格名单  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  *:返回              ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("----------------------------\n\n\n\n");
    char ch;
    {
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
    if(ch=='1'||ch=='2'||ch=='*')break;
    else printf("输入无效\n");}
    switch(ch)
    {
        case '1':all_student_total_credit();system("pause");system("CLS");break;
        case '2':unpass();system("pause");system("CLS");break;
        case '*':system("CLS");return 0;
     }
    }
   }
}
int Delete_course()
{   system("CLS");
    int i;char num[20],name[20];
    printf("                                  删除某门选修课信息\n");
    printf("   ------------------------------------------------------------------------------\n\n\n");
    if(!course_total){printf("对不起，系统暂时还未有课程\n");return 0;}
    while(1){printf("输入要删除选修课编号\n");
    if(!scan_course_num(num))break;
    for(i=0;i<course_total;i++)
            if(!strcmp(num,ALL_course[i].num))break;
    if(i>=course_total){printf("对不起，系统未有该选修课\n");continue;}
    strcpy(name,ALL_course[i].name);
    printf("将要删除的选修课信息如下\n");
    printf("选修课编号   %s\n",ALL_course[i].num);
    printf("选修课名称    %s\n",ALL_course[i].name);
    printf("描述信息   %s\n",ALL_course[i].imformation);
    printf("确认删除 Y  放弃删除 N\n");
       char ch;
        while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='n'||ch=='N')break;
        else printf("该输入无效\n");}
    if(ch=='Y'||ch=='y')
    {
        for(int j=i;j<course_total;j++)
        {
            strcpy(ALL_course[j].num,ALL_course[j+1].num);
             strcpy(ALL_course[j].name,ALL_course[j+1].name);
              strcpy(ALL_course[j].imformation,ALL_course[j+1].imformation);
        }
        course_total--;
        printf("删除 %s 课程成功\n",name);
    }
    else printf("%s  课程未删除\n",name);
    printf("是否继续删除其他课程\n");
    printf("Y 继续   N 结束\n");
    {  char ch;
        while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='n'||ch=='N')break;
        else printf("该输入无效\n");}
        if(ch=='N'||ch=='n')break;
    }
    }
    system("CLS");
    return 0;
}
int add_course()
{
    {system("CLS");
            char num[20],name[20],imfo[200];
            printf("                                增加某门选修课\n\n\n\n");
            printf("    -------------------------------------------------------------------------\n");
            while(1){printf("请输入您要增加选修课的编号\n");
            fflush(stdin);if(!scan_course_num(num))break;
            if(!right_course(num)){printf("对不起，已有该选修课，请换另一编号\n");continue;}
            printf("请输入该选修课的名称\n");
            scanf("%s",name);
            printf("请输入对该课程的大概描述(不超40字)\n");
            fflush(stdin);scanf("%s",imfo);
            printf("确认添加如下选修课\n");
            printf("编号 %s  名称%s  \n描述信息\n%s\n",num,name,imfo);
            printf("确认 Y  放弃 N\n");
        {char ch;
        while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("输入无效\n");}
        if(ch=='Y'||ch=='y')
        {
            strcpy(ALL_course[course_total].num,num);
            strcpy(ALL_course[course_total].name,name);
            strcpy(ALL_course[course_total++].imformation,imfo);
            printf("添加成功！\n");
        }
        }
        printf("继续增加课程 Y  结束  N\n");
        {char ch;
        while(1){fflush(stdin);scanf("%c",&ch);if(ch=='Y'||ch=='N'||ch=='y'||ch=='n')break;else printf("输入无效\n");}
        if(ch=='N'||ch=='n')break;}
            }
    }
 system("CLS");
 return 0;
}
int add_delete_course()
{
    system("CLS");int y=35;
   while(1) {
        printf("                                    添加或删除课程\n");
        printf("   -------------------------------------------------------------------------------\n\n\n");
    for(int i=0;i<y;i++)printf(" "); printf("--------------------\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  1:添加课程  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  2:删除课程  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  *:返回      ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("--------------------\n\n\n\n");
    printf("请选择\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);
    if((ch>='1'&&ch<='2')||ch=='*')break;
    else printf("输入无效\n");}
    switch(ch)
    {
        case '1':add_course();break;
        case '2':Delete_course();break;
        case '*':system("CLS");return 0;
    }
   }
}
int modification_admin_key()
{
    system("CLS");
    char new1[100],new2[100];int p,fl;
    printf("                                   修改管理员密码\n");
    printf("   -------------------------------------------------------------------------------\n\n\n\n");
    while(1){printf("请输入原密码\n");fl=0;
    p=Input_key(admin_key_data[admini].key);
    if(p==2){ system("CLS");break;}
    if(!p){system("CLS");printf("\n输入密码不正确，请重新输入\n");continue;}
    system("CLS");
    while(1){printf("请输入新密码\n");
    if(!scanf_key(new1))break;
    system("CLS");
    printf("请再次输入新密码\n");
    if(!scanf_key(new2)){continue;}
    system("CLS");
    if(!strcmp(new1,new2)){fl=1;strcpy(admin_key_data[admini].key,new1);printf("修改密码成功!\n您的新密码为  %s  \n",new1);break;}
    printf("两次输入密码不一样，请重新输入\n");
    }
    if(fl)break;
    }
return 0;
}
int Look_over_scores()
{
    system("CLS");
    int y=28;
    while(1){printf("                                        查看学生成绩\n");
    printf("  --------------------------------------------------------------------------------------\n\n\n\n\n\n");
    for(int i=0;i<y;i++)printf(" "); printf("------------------------------------------\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  1:按班统计学生选课情况及考试成绩  ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  2:按课程统计学生名单及考试成绩    ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("---  *:返回                            ---\n");
    for(int i=0;i<y;i++)printf(" "); printf("------------------------------------------\n\n\n\n");
    printf("请选择\n");
    char ch;
    while(1){fflush(stdin);scanf("%c",&ch);
    if((ch>='1'&&ch<='2')||ch=='*')break;
    else printf("输入无效\n");}
    switch(ch)
    {
        case '1':system("CLS");if(!student_total){printf("现在系统还没有学生信息，快去注册吧！\n");break;}
          for(int i=0;i<28;i++)printf(" "); printf("按班级统计学生选修课及考试情况\n");
          printf("    -------------------------------------------------------------------------\n");
                 while(1){for(int j=0;j<classnum;j++)printf(" %s \n",ALLCLASS[j].class_name);
                printf("请输入你要查看班级的名称\n");char s[20];
                    fflush(stdin);if(!scan_class(s))break;int i;
        for(i=0;i<classnum;i++)
        if(!strcmp(ALLCLASS[i].class_name,s))break;
        if(!strcmp(ALLCLASS[i].class_name,s)){
        printf("                            %s\n",ALLCLASS[i].class_name);
        for(int j=0;j<ALLCLASS[i].count;j++)
        {
        int studenti=ALLCLASS[i].student_num[j];printf("学生学号%s\n",student_array[studenti].num);
        printf("    编号   名称   平时成绩  期末成绩  平均成绩  学分 \n");
        printf("--------------------------------------------------------------\n");
        for(int j=0;j<student_array[studenti].cousetotal;j++){
    if(student_array[studenti].All_course[j].fnish)
    printf("  %5s%8s%9.1lf%10.1lf%10.1lf%8.1lf     \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name,student_array[studenti].All_course[j].usual_score,student_array[studenti].All_course[j].exam_score,student_array[studenti].All_course[j].final_score,student_array[studenti].All_course[j].credit);//,student_array[studenti].All_course[j].IsRetake,student_array[studenti].All_course[j].Retake_semester,student_array[studenti].All_course[j].Retake_count);
    else printf("  %5s%8s     无         无       无      无 \n",student_array[studenti].All_course[j].num,student_array[studenti].All_course[j].name);
        }
         printf("--------------------------------------------------------------\n");

        }
    printf("\n\n\n");system("pause");system("CLS");
}
else printf("找不到该班级\n");
printf("是否继续查询其他班级\n");
printf("继续查询 Y  结束查询 N\n");
 char ch;
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n')break;
        else printf("该输入无效\n");}
        if(ch=='N'||ch=='n')break;
}system("CLS");
break;
        case '2':system("CLS");
                    if(!student_total){printf("现在系统还没有学生信息，快去注册吧！\n");break;}
                    if(!course_total){printf("对不起系统还没有相关选修课程，先去录入选修课程吧！\n");break;}
                    while(1){for(int i=0;i<28;i++)printf(" ");
                            printf("按课程统计学生名单及考试成绩\n");
                     printf("    -------------------------------------------------------------------------\n");
                    for(int i=0;i<course_total;i++)
                    {printf("%s    %s",ALL_course[i].num,ALL_course[i].name);
                   if(!ALL_course[i].finish)printf("(未完全录入)\n");
                    else printf("(已录入)\n");
                    }
                  printf("请输入您要查问的课程编号\n");
                  char num[20];fflush(stdin);if(!scan_course_num(num))break;
                  system("CLS");int i;
                  for(i=0;i<course_total;i++)
                    if(!strcmp(num,ALL_course[i].num))break;
            if(!strcmp(num,ALL_course[i].num)){printf("科目: %s\n",ALL_course[i].name);
            printf("     学号            班级      姓名    平时成绩  期末成绩   平均成绩  学分 \n");
            for(int j=0;j<ALL_course[i].count;j++)
            {
                int k,idex=ALL_course[i].Choose_student_idex[j];
                for(k=0;k<student_array[idex].cousetotal;k++)if(!strcmp(student_array[idex].All_course[k].name,ALL_course[i].name))break;
                printf(" %8s%14s%10s%8.1lf%10.1lf%10.1lf%8.1lf\n",student_array[idex].num,student_array[idex].class_name,student_array[idex].name,student_array[idex].All_course[k].usual_score,student_array[idex].All_course[k].exam_score,student_array[idex].All_course[k].final_score,student_array[idex].All_course[k].credit);
                }
        }
        else printf("暂无此种选修课\n");
    printf("继续查询 Y  结束查询 N\n");
    char ch;
    while(1){printf("请输入您的选择\n");fflush(stdin);scanf("%c",&ch);
        if(ch=='Y'||ch=='y'||ch=='N'||ch=='n'){system("CLS");break;}
        else printf("该输入无效\n");}
        if(ch=='N'||ch=='n')break;
        }system("CLS");break;
        case '*':system("CLS");return 0;
    }
    }
}

int SORT_ALL()
{
     sort_data();
     sort_student_key();
     sort_admin_key();
     sort_course();
     return 0;
}

int END()
{
    system("CLS");
    printf("\n\n\n\n\n\n\n");
    printf("                          ********************************************\n");
    printf("                          ***正在将有关信息写入文件，请勿关闭程序！***\n");
    printf("                          ********************************************\n\n");
    printf("写入进程\n\n");
    for(int i=0;i<89;i++)
    {for(int j=0;j<10000000;j++);printf(">");}
    if(Write_ALL()){printf(">\n\n\n");
    printf("                             ***********************************\n");
    printf("                             ***信息写入成功,现在转到离开界面***\n");
    printf("                             ***********************************\n");
    }
    for(int i=0;i<201314000;i++);
    for(int i=0;i<201314000;i++);
    for(int i=0;i<201314000;i++);
    return 0;
}



