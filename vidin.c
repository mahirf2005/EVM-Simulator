#include<stdio.h>
#include<string.h>
struct vid
{
    char id1[15];
};
int main()
{
    int i,j,n;
    char name[50];
    char id[15];
    FILE *f1;
    FILE *f2;
  char pass[] = "evm205";
  char pass1[7];
  printf("Enter the 6 digit password: ");
  scanf("%s",pass1);
  if(strcmp(pass,pass1)==0)
    {
    printf("Enter the number of votars: ");
    scanf("%d",&n);
    struct vid e[n];
     while(getchar() != '\n'); 
    f1=fopen("vinfo.txt","w");
    f2=fopen("vname.txt","w");
    for(i=0;i<n;i++)
    {
        int count=0;
        printf("Enter %d th voters's name: ",i+1);
         gets(name);
        printf("Enter the %d th voters's id (10 digit): ",i+1);
        gets(id);
        if (strlen(id) == 10)
        {
         for(j=0;j<i;j++)
        {  
            if(strcmp(e[j].id1,id)==0)
            count++;
        }
        if(count==0)
        {
         strcpy(e[i].id1,id); 
        fprintf(f1,"%s  \n",id);
        fprintf(f2,"%s  \n",name);
        }
        else
        {
         printf("The NID has already taken.Please enter another unic ID number\n");
         i--;
         continue;
        }
        }
        else
        {
         printf("Your ID must contain 10 digits.Please try again.\n");
         i--;
         continue;
        }
    }
    fclose(f1);
    fclose(f2);
    printf("Data entry successfull");
     }
  else
   printf("Your password is wrong . Please try again");  
    return 0;
} 