#include<stdio.h>
#include<string.h>
struct candidates
{
  char name[20];
  int vcode;
};
void vcast(int vlist[],int v,int n,int a[],char pass[]);
void catalogue(char pass[]); 
void result(int a[],int n,int vlist[],int v,struct candidates e[]);
int main()
{
  char pass[] = "evm205";
  char pass1[7];
  printf("Enter the 6 digit password: ");
  scanf("%s",pass1);
  if(strcmp(pass,pass1)==0)
    {
     catalogue(pass);
    }
  else
   printf("Your password is wrong . Please try again");   
}
// Catalouge candidate name and vote code
void catalogue(char pass[])
{
 int n,i,j,v,code;
 char name[20];
 FILE *f1;
 FILE *f2;
 printf("Enter the number of candidates: ");
 scanf("%d",&n);
 printf("Enter the number of voters: ");
 scanf("%d",&v);
 int a[n];
 int vlist[v];
 struct candidates e[n];
 f1=fopen("cand.txt","r");
 f2=fopen("cancode.txt","r");
 for(i=0;fgets(name,sizeof(name),f1)!=NULL;i++)
 {
  name[strcspn(name, "\n")] = '\0';
  strcpy(e[i].name, name);
 }
  for(i=0;fscanf(f2," %d",&code)!=EOF;i++)
 {
  e[i].vcode=code;
  a[i]=e[i].vcode;
 }
 fclose(f1);
 fclose(f2);
 for(i=0;i<n;i++)
 {
  printf("To vote %d th candidate '%s' enter the code: %d\n ",i+1,e[i].name,e[i].vcode);
 }
 vcast(vlist,v,n,a,pass);
 result(a,n,vlist,v,e);
}    
//Vote casting
struct vinfo
{
  char name[20];
  char id[11];
  char c[11];
};
void vcast(int vlist[],int v,int n,int a[],char pass[])
{ 
  int j;
  char name1[50];
  char id1[11];
  char id2[11];
  struct vinfo r[v+2];
  FILE *f3;
  FILE *f4;
   f3=fopen("vinfo.txt","r");
    f4=fopen("vname.txt","r");
 for(j=0;fgets(name1,sizeof(name1),f4)!=NULL;j++)
 {
    name1[strcspn(name1, "\n")] = '\0';
  strcpy(r[j].name, name1);
 }
  for(j=0;fscanf(f3,"%s ",id1)!=EOF;j++)
 {
  strcpy(r[j].id,id1); 
 }
 fclose(f3);
 fclose(f4);
 int i,y,b;
  for(j=0;j<=v;j++)
   {
  printf("Enter your 10 digits NID: ");
  scanf("%s",id2);
  if(strcmp(id2,pass)==0)
   break;
  int count=0;
  int count1=0;
  int count2=0;
  if(strlen(id2)==10)
  {  
    for(i=0;i<=v;i++)
    {
    if(strcmp(r[i].id,id2)==0)
    {
     count1++;
     b=i;
    }
   }
    if (count1==1)
    {
    strcpy(r[j].c,id2);
    for(i=0;i<=v;i++)
    {
    if(strcmp(r[i].c,id2)==0)
    {
     count++;
    }
    }
   if(count==1) 
   {
     printf("'%s' please,enter code to vote your favorite candidate: ",r[b].name);
     scanf("%d",&y);
     for(i=0;i<=n;i++)
     {
      if(a[i]==y)
      count2++;
     }
     if(count2==1)
     {
      vlist[j]=y;
     printf("\n");
     }
     else
     {
      printf("%s please enter the right vote code. \n",r[b].name);
       j--;
       continue;
     }
   }   
   else
   {
    printf("%s You have already given your vote.So, get out. \n",r[b].name);
    j--;
    continue;
   }
  }
  else
  {
  printf("You are not a voter.\n");
  j--;
  continue;
  }
}
else
  {
    printf("Your ID must contain 10 digits.Please try again.\n");
    j--;
    continue;
  }
}
}
//Result
void result(int a[],int n,int vlist[],int v,struct candidates e[])
{  
  int b[n];
   printf("-----------------Result-----------------\n ");
  int i,j;
  for(i=0;i<n;i++)
  {
    int count=0;
    for(j=0;j<v;j++)
     {
      if(a[i]==vlist[j])
      {
        count++;
      }
     }
    b[i]=count; 
  }  
    int sum=0;
      for(j=0;j<n;j++)
     {
      sum=sum+b[j];
     }
  printf("Total vote casted: %d  (%.2f)\n ",sum,(float)sum/v*100); 
  int max=0;
  int d;
  int count1=0;
  for(i=0;i<n;i++)
  {
    if(max<b[i])
    { 
      max=b[i];
      d=i;
    }
  }
  for(i=0;i<n;i++)
  {
    if(max==b[i])
    count1++;
  }
  for(i = 0; i < n; i++)
  {
    printf("%d th candidate '%s' got %d vote(s) (%.2f percent) \n", i + 1, e[i].name, b[i],(float)b[i]/sum*100);
  }
  printf("\n");
  if(count1==1)
  {
    printf("%d th candidate %s is Elected with %.2f percent majority\n",d+1,e[d].name,(float)b[d]/sum*100);
  }
  else
  {
    printf("Tie between: \n \n");
    for(i=0;i<n;i++)
    {
      if(max==b[i])
      {
        printf("%d th candidate '%s' \n",i+1,e[i].name);
      }
    }
  }
}