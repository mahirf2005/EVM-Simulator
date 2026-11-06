#include<stdio.h>
#include<string.h>
struct code1
{
    char name1[50];
};

int main()
{
    int i,j,n;
    char name[50];
    char code[12]; 
    FILE *f1;
    FILE *f2;
  char pass[] = "evm205";
  char pass1[7];
  printf("Enter the 6 digit password: ");
  scanf("%s",pass1);
  if(strcmp(pass,pass1)==0)
    {
    printf("Enter the number of candidates: ");
    scanf("%d",&n);
     struct code1 e[n+1];
     while(getchar() != '\n'); 
    f1=fopen("cand.txt","w");
    f2=fopen("cancode.txt","w");
    for(i=0;i<n;i++)
    {
        int count=0;
        printf("Enter %d th candidates's name: ",i+1);
         gets(name);
        printf("Enter the %d th candidates's code (3 digit): ",i+1);
        gets(code);
        if (strlen(code) == 3)
        {
        for(j=0;j<i;j++)
        {  
            if(strcmp(e[j].name1,code)==0)
            count++;
        }
        if(count==0)
        {
          strcpy(e[i].name1,code);    
        fprintf(f1,"%s  \n",name);
        fprintf(f2,"%s  \n",code);
        }
        else
        {
         printf("The code has already taken.Please enter another unique code\n");
         i--;
         continue;
        }
        }
        else
        {
         printf("Your code  must contain 3 digits.Please try again.\n");
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