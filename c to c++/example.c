#include<stdio.h>
#include <string.h>
void replaceSubstring(char [],char[],char[]);
void main()
{
    FILE *r = fopen("c.txt","r");
    char c,b;
    char a[100][100];
    int i=0;
    int j=0;
    int loop_var; 
    char final_prog[100][100];
        
    
    while(c!=EOF)
    {
        c = fgetc(r);
        if(c=='<' || b=='>' || c=='\n')
        {
           
           i++;
           j=0;
           
        }
        a[i][j] = c;
        j++;
        b=c;
    }


    for(loop_var=0;loop_var<i;loop_var++)
    {
    
        if(strstr(a[loop_var],"void")!=NULL)
        {
            replaceSubstring(a[loop_var],"void","int");
        }
         printf("\n %d string is %s",loop_var,a[loop_var]);
    }
}



void replaceSubstring(char string[],char sub[],char new_str[])
{
int stringLen,subLen,newLen;
int i=0,j,k;
int flag=0,start,end;
stringLen=strlen(string);
subLen=strlen(sub);
newLen=strlen(new_str);

for(i=0;i<stringLen;i++)
{
flag=0;
start=i;
for(j=0;string[i]==sub[j];j++,i++)
if(j==subLen-1)
flag=1;
end=i;
if(flag==0)
i-=j;
else
{
for(j=start;j<end;j++)
{
for(k=start;k<stringLen;k++)
string[k]=string[k+1];
stringLen--;
i--;
}

for(j=start;j<start+newLen;j++)
{
for(k=stringLen;k>=j;k--)
string[k+1]=string[k];
string[j]=new_str[j-start];
stringLen++;
i++;
}
}
}
}


    

