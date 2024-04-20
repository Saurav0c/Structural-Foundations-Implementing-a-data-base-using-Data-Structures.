#include"header.h"
static int i=0,z=0,rnn,k=0;
int op1;
int main()
{
	char op;
	SLL*headptr=0;
	while(1)
	{
		pf("\033[30;4;1;7;32m\n\n\n||||||||||||||||||| STUDENT RECORD MENU |||||||||||||||||||\033[0m\n\n");
		pf("\033[1;40ma/A : Add a new record\nd/D : Delete record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\nf/F : Read from the file 'Student.dat'\033[0m\n");
		pf("\033[1;31m\nEnter your desired choice :\033[0m\t");
		sf(" %c",&op);

		switch(op)
		{
			case 'A':
			if(k==1)
			{
			add_middle(&headptr);break;
			}
			else
			{
			add_end(&headptr);break;
			}
			case 'a':
			if(k==1)
			{
			add_middle(&headptr);break;
			}
			else
			{
			add_end(&headptr);break;
			}
			case 's': print(headptr);break;
			case 'S': print(headptr);break;
			case 'e' :
			l1:
			pf("1)Save and Exit\n2)Exit\n");
			scanf("%d",&op1);
			if(op1==1)
			{
			if(headptr!=0)
			{
			stud_save(headptr);
			pf("\033[1;7;5;33mSaving.....\033[0m\n");
			sleep(3);
			system("clear");
			pf("\033[1;33mSaved!\033[0m\n");
			exit(0);
			}
			pf("\033[1;5;7;33mNO RECORDS FOUND TO SAVE\033[0m\n");
			exit(0);
			}
			if(op1==2)
			{
			exit(0);
			}
			if(op1>2)
			goto l1;
			
			case 'E':
			l2:
			pf("1)Save and Exit\n2)Exit\n");
			scanf("%d",&op1);
			if(op1==1)
			{
			if(headptr!=0)
			{
			stud_save(headptr);
			pf("\033[1;7;5;33mSaving......\033[0m\n");
			sleep(3);
			system("clear");
			pf("\033[1;33mSaved!\033[0m\n");
			exit(0);
			}
			pf("\033[1;5;7;33mNO RECORDS FOUND TO SAVE\033[0m\n");
			exit(0);
			}
			if(op1==2)
			{
			exit(0);
			}
			if(op1>2)
			goto l2;
			case 'd':delete_data(&headptr);break;
			case 'D':delete_data(&headptr);break;
			case 'm':modify_data(&headptr);break;
			case 'M':modify_data(&headptr);break;
			case 'v':stud_save(headptr);break;
			case 'V':stud_save(headptr);break;
			case 'f':
				 if(z==1)
				 {
					 pf("\033[1;5;7;33mRECORDS ALREDY LOADED\033[0m\n");
					 break;
				 }
				 read_file(&headptr);break;
			case 'F':
				 if(z==1)
				 {
					 pf("\033[1;5;7;33mRECORDS ALREDY LOADED\033[0m\n");
					 break;
				 }
				 read_file(&headptr);break;

			case 'l':delete_all(&headptr);break;
			case 'L':delete_all(&headptr);break;
			case 't':sort_data(headptr);break;
			case 'T':sort_data(headptr);break;
			case 'r':reverse_links(&headptr);break;
			case 'R':reverse_links(&headptr);break;
			default: pf("\033[1;5;7;31m\n\n You have entered a wrong choice\033[0m\n\n");break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void add_end(SLL**ptr)
{
	SLL*new,*last;
	new=malloc(sizeof(SLL));
	printf("\nEnter the name and marks : \n");
	scanf("%s %f",new->name,&new->marks);
	new->rollno=++i;
	new->next=0;
	if(*ptr==0)
	{
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while(last->next)
		{
			last=last->next;
		}
		last->next=new;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print(SLL *ptr)
{
	if(ptr==0)
	{
		pf("\033[1;5;7;33m NO RECORDS FOUND\033[0m\n");
		return;
	}
	pf("\033[1;34m\n********************************************\033[0m\n");
	while(ptr)
	{
		pf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	pf("\033[1;34m********************************************\033[0m\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delete_data(SLL **ptr)
{
	SLL *del,*prev;
	int r;
	int m;
	char op;
	if(*ptr==0)
	{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
	}
	del=*ptr;
	printf("Enter the way you want delete : \npress r/R for rollnumber wise deletion\npress n/N for name wise deletion\n");
	scanf(" %c",&op);

	if(op=='r' | op=='R')
	{
		pf("Enter the rollno to delete:\t");
		sf("%d",&r);
		//rnn=r;
		if(r==1)
		{
			rnn=r;
			*ptr=del->next;
			rnn=r;
			free(del);
		}
		else
		{
			if(r>i || r<=0)
			{
				pf("\033[1;5;7;31mINVALID INPUT\033[0m\n");
				return;
			}
			while(del)
			{
				if(del->rollno==r)
					break;


				prev=del;
				del=del->next;
			}
			prev->next=del->next;
			rnn=r;
			free(del);
		}

	}
	else if(op=='n' | op=='N')
	{

		char name[30];
		int c=0;
		pf("Enter the name:\t");
		sf("%s",name);
		while(del)
		{
			if(strcmp(name,del->name)==0)
			{
				c++;
			}
			del=del->next;
		}
		del=*ptr;
		prev=del;
		if(c==1)
		{
			while(del)
			{
				if(strcmp(name,del->name)==0)
				{
					if(del==*ptr)
					{
						*ptr=del->next;
						rnn=del->rollno;
						free(del);
						break;
					}
					prev->next=del->next;
					rnn=r;
					free(del);
					break;
				}
				prev=del;
				del=del->next;
			}

		}

		int t;


		if(c>1)
		{
			while(del)
			{
				if(strcmp(name,del->name)==0)
				{
					pf("%d %s %f\n",del->rollno,del->name,del->marks);
				}
				del=del->next;
			}
			pf("Enter the rollno to delete:\t");
			sf("%d",&r);
			//rnn=r;
			if(r>i||r<=0)
			{
				pf("\033[1;5;7;31mINVALID INPUT\033[0m\n");
				return;
			}
			del=*ptr;
			for(t=1;t<r;t++)
				del=del->next;
			if(strcmp(del->name,name)==0)
			{
				del=*ptr;
				if(r==1)
				{
					*ptr=del->next;
					rnn=r;
					free(del);
				}
				else
				{

					while(del)
					{
						if(del->rollno==r)
							break;


						prev=del;
						del=del->next;
					}
					prev->next=del->next;
					free(del);

				}
			}
			else
			{
				pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
				return;
			}
		}
	}

	//del=*ptr;
	//int j=0;
//	while(del)
//	{
//		del->rollno=++j;
//		del=del->next;
//		i=j;
//
//	}

	pf("\033[1;5;7;31mRECORD DELETED\033[0m\n");
i--;
k=1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modify_data(SLL**ptr)
{
	SLL*mod;
	char op,name[30],name1[30];
	float percent;
	int r,op1,op2,op3,op4,op5,c=0,r1,c1=0;
	if(*ptr==0)
	{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
	}
	pf("\nEnter the way you want to modify the code :\n");
	pf("\nr/R : Rollno wise\nn/N : Name wise\np/P : Percentage wise\n");
	sf(" %c",&op);
	if(op=='r' || op=='R')
	{
		pf("\nEnter the rollno of the studentdata you want to modify :\t");
		scanf("%d",&r);
		if(*ptr==0)
		{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
		}
		mod=*ptr;
		if(r>i||r<=0)
		{
			pf("\033[1;5;7;31mINVALID INPUT\033[0m\n");
		}
		while(mod)
		{
			if(mod->rollno==r)
			{
				pf("Enter what you want to modify in this data:\n");
				pf("1)Name 2)Marks\n");
				scanf("%d",&op1);
				if(op1==1)
				{
					pf("Enter the new name :\n");
					scanf("%s",mod->name);
				}
				if(op1==2)
				{
					pf("Enter the new marks :\n");
					scanf("%f",&mod->marks);
				}
			}
			mod=mod->next;
		}
	}
	else if(op=='n' || op=='N')
	{
		pf("Enter the name of the student you want to modify\n");
		scanf("%s",name1);
		if(*ptr==0)
		{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
		}
		mod=*ptr;
		while(mod)
		{
			if(strcmp(name1,mod->name)==0)
				c++;
			mod=mod->next;
		}

		if(c==0)
		{
			pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
			return;
		}
		else if(c==1)
		{
			mod=*ptr;
			while(mod)
			{
				if(strcmp(name1,mod->name)==0)
				{
					pf("Enter what you want to modify in this data:\n");
					pf("1)Name 2)Marks\n");
					sf("%d",&op2);
					if(op2==1)
					{
						pf("Enter the new name :\n");
						scanf("%s",mod->name);
					}
					if(op2==2)
					{
						pf("Enter the new marks :\n");
						scanf("%f",&mod->marks);
					}
				}
				mod=mod->next;
			}
		}

		else if(c>1)
		{
			mod=*ptr;
			while(mod)
			{
				if(strcmp(name1,mod->name)==0)
				{
					pf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
				}
				
				mod=mod->next;
			}
			mod=*ptr;
			pf("Enter the roll no you want to modify :\t");
			sf("%d",&r1);
			while(mod)
			{
				if(mod->rollno==r1)
				{
					if(strcmp(name1,mod->name)==0)
					{
						pf("Enter what you want to modify in this data:\n");
						pf("1)Name 2)Marks\n");
						scanf("%d",&op3);
						if(op3==1)
						{
							pf("Enter the new name :\n");
							sf("%[^\n]s",mod->name);
						}
						if(op3==2)
						{
							pf("Enter the new marks :\n");
							scanf("%f",&mod->marks);
						}
					}
				}
				mod=mod->next;
			}
		}
	}
	

	else if(op=='p'||op=='P')
	{
		pf("Enter the mark:\t");
		scanf("%f",&percent);
		if(*ptr==0)
		{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
		}
		mod=*ptr;
		while(mod)
		{
			if(mod->marks==percent)
				c1++;
			mod=mod->next;
		}
		if(c1==0)
		{
			pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
			return;
		}

		else if(c1==1)
		{
			mod=*ptr;
			pf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
			while(mod)
			{
				if(mod->marks==percent)
				{
					pf("Enter what you want to modify in this data:\n");
					pf("1)Name 2)Marks\n");
					scanf("%d",&op5);
					if(op5==1)
					{
						pf("Enter the new name :\n");
						scanf("%s",mod->name);
					}
					if(op5==2)
					{
						pf("Enter the new marks :\n");
						scanf("%f",&mod->marks);
					}
				}
				mod=mod->next;
			}
		}
		}
		else if(c1>1)
		{
			mod=*ptr;
			while(mod)
			{
				if(mod->marks==percent)
				{
					pf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
				}
				mod=mod->next;
			}
			mod=*ptr;
			pf("Enter the roll no you want to modify :\t");
			sf("%d",&r1);
			while(mod)
			{
				if(mod->rollno==r1)
				{
					if(mod->marks==percent)
					{
						pf("Enter what you want to modify in this data:\n");
						pf("1)Name 2)Marks\n");
						scanf("%d",&op4);
						if(op4==1)
						{
							pf("Enter the new name :\n");
							sf("%s",mod->name);
						}
						if(op4==2)
						{
							pf("Enter the new marks :\n");
							scanf("%f",&mod->marks);
						}
					}
				}
				mod=mod->next;
			}

		}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void stud_save(SLL*ptr)
{
	FILE *fp;
	fp=fopen("student.dat","w");
	if(fp==0)
	{

		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
	}
	if(ptr==0)
	{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
	}
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}

	fclose(fp);

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void read_file(SLL**ptr)
{

	FILE *fp;
	fp=fopen("student.dat","r");
	SLL*new,*last;
	if(fp==0)
	{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
	}
	while(1)
	{
		new=malloc(sizeof(SLL));
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks)==-1)
			break;
		new->rollno=++i;
		new->next=0;
		if(*ptr==0)
		{
			*ptr=new;
		}
		else
		{
			last=*ptr;
			while(last->next)
			{
				last=last->next;
			}
			last->next=new;
		}

	}
	fclose(fp);
	pf("\033[1;5;33mRecords loaded\033[0m\n");
	z=1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delete_all(SLL**ptr)
{
	SLL *del;
	if(*ptr==0)
	{
		pf("\033[1;5;7;33mNO RECORDS FOUND\033[0m\n");
		return;
	}
	else
	{
		del=*ptr;
		while(del)
		{
			*ptr=del->next;
			free(del);
			del=*ptr;
		}
		pf("\033[1;7;5;33mRECORDS ARE DELETED\033[0m\n");
		z=0;
		i=0;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort_data(SLL*ptr)
{
	char op,c=0;
	int n,m,y;
	SLL *sort=ptr,*sort1=ptr;
	SLL temp,temp1,temp2;
	pf("Enter the way you want to sort\n");
	pf("\nn/N :For sorting using name\np/P : For marks wise\n");
	scanf(" %c",&op);
	if(ptr==0)
	{	
	pf("\033[1;7;5;33mNO RECORDS FOUND TO SORT\033[0m\n");
	return;
	}
	while(sort)
	{
		c++;
		sort=sort->next;
	}
	sort=ptr;
	if(op=='n' || op=='N')
	{
		for(m=0;m<c;m++)
		{
			sort1=sort->next;
			for(n=m+1;n<c;n++)
			{
				y=(strcmp(sort->name,sort1->name));
				if(y>0)
				{
				
					
					strcpy(temp.name,sort->name);
					temp.marks=sort->marks;
					temp.rollno=sort->rollno;
					strcpy(sort->name,sort1->name);
					sort->marks=sort1->marks;
					sort->rollno=sort1->rollno;
					strcpy(sort1->name,temp.name);
					sort1->marks=temp.marks;
					sort1->rollno=temp.rollno;
				}
				sort1=sort1->next;
			}
			sort=sort->next;
		}
	}
	sort1=sort=ptr;
	if(op=='p'||op=='P')
	{
		for(m=0;m<c;m++)
		{
			sort1=sort->next;
			for(n=m+1;n<c;n++)
			{
				if(sort->marks<sort1->marks)
				{
						
					strcpy(temp.name,sort->name);
					temp.marks=sort->marks;
					temp.rollno=sort->rollno;
					strcpy(sort->name,sort1->name);
					sort->marks=sort1->marks;
					sort->rollno=sort1->rollno;
					strcpy(sort1->name,temp.name);
					sort1->marks=temp.marks;
					sort1->rollno=temp.rollno;
						
				}
				sort1=sort1->next;
			}
			sort=sort->next;		
			}

	}


	pf("\033[1;7;5;33mLIST SORTED ACCODING TO YOUR REQUIREMENTS\033[0m\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reverse_links(SLL**ptr)
{
	SLL *rev=*ptr;
	int r=0,c=0;
	if(*ptr==0)
	{
	pf("\033[1;7;5;33mNO RECORDS FOUND\033[0m\n");
	return;
	}
	while(rev)
	{
		c++;
		rev=rev->next;
	}
	rev=*ptr;
	SLL **a=malloc(sizeof(SLL*)*c);
	while(rev)
	{
		a[r++]=rev;
		rev=rev->next;
	}
	rev=*ptr;
	for(r=1;r<c;r++)
	{
		a[r]->next=a[r-1];
	}
	a[0]->next=0;
	*ptr=a[c-1];

	pf("\033[1;7;33mRECORDS ARE REVERSED\033[0m\n");
}

void add_middle(SLL**ptr)
{
	SLL*new,*last;
	new=malloc(sizeof(SLL));
	sf("%s %f",new->name,&new->marks);
	new->rollno=rnn;
	if(rnn==1)
	{
		
			new->next=*ptr;
			*ptr=new;

		
	}
	else
	{
		last=*ptr;
		while(last->next!=0 && new->rollno > last->next->rollno)
		{
			last=last->next;
		}
		new->next=last->next;
		last->next=new;
	}
	k=0;
	i++;
}
























































































