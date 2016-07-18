#ifndef CONTACTPERSON_H_INCLUDED
#define CONTACTPERSON_H_INCLUDED

#include <string.h>
#include <stdio.h>

#define ALL 5         //全部
#define FAMILY 4      //家庭
#define FRIENDS 3     //朋友
#define SCHOOLMATES 2 //同学
#define OTHERS 1      //其他

class ContactPerson
{
public:
    ContactPerson();

    void setName(char str[]);

    void setPhoneNumber(char str[]);

    void setQq(char str[]);

    void setEmail(char str[]);

    void setAddress(char str[]);

    void setRelation(int rel);

    char * getName();

    char * getPhoneNumber();

    char * getQq();

    char * getEmail();

    char * getAddress();

    char * mergeStr(char str[]);

    int getRelation();


token = ' ';
private:

    char name[20];

    char phoneNumber[20];

    char qq[15];

    char email[25];

    char address[50];

    int relation;


};

typedef struct AddressBook
{
    ContactPerson person;

    AddressBook * next;//此链将全部联系人连起来

}AddressBook;



#endif // CONTACTPERSON_H_INCLUDED
