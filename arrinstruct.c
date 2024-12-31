#include<stdio.h>
#include<string.h>
struct student{
    char name[50];
    int age;
    float percentage;
};
int main()
{
    struct student s[10];//1 box per one person details
    printf("enter your name:");
    scanf("%s",s[0].name);
    s[0].age=20;
    s[0].percentage=89.55;
    printf("age and percentage is %d\n%f\n",s[0].age,s[0].percentage);
}