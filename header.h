#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct student
{
int rollno;
char name[30];
float marks;
struct student *next;
}SLL;

extern void add_end(SLL**);
extern void print(SLL*);
extern void delete_data(SLL**);
extern void modify_data(SLL**);
extern void stud_save(SLL*);
extern void read_file(SLL**);
extern void delete_all(SLL**);
extern void sort_data(SLL*);
extern void reverse_links(SLL**);
extern void add_middle(SLL**);
#define pf printf
#define sf scanf
