#include<stdio.h>
#include<string.h>
void main()
{
    FILE *r=fopen("java.txt","r");
    FILE *w=fopen("c++.txt","w");
    char c,b;
    int l=0;
    int i=0;
    int j=0;
    char a[200][200];
    char space[100][100];
    int num=1;

    while(c!=EOF)
    {
        c=fgetc(r);
        if(c==' '&& b==' ')
        {
            space[i][l]=c;
            l++;
        }
        
        else
        {
            a[i][j]=c;
            j++;
            if(c=='\n')
            {
                i++;
                j=0;
                l=0;
                num++;
            }
        }
        b=c;
    }

    for(i=0;i<num;i++)
    {    
        if(strstr(a[i],"public class Main")!=NULL)                                              //classes
        {
            printf("#include<iostream>\n");
            printf("using namespace std;\n");
        }
        else if(strstr(a[i],"public static void main(String[] args)")!=NULL)                    //functions
        {
            printf("int main()\n");
        }
        else if(strstr(a[i],"new Scanner")!=NULL || strstr(a[i],"java.util.Scanner")!=NULL)                                               //scanner
        {

        }
        else if(strstr(a[i],"System.out.println")!=NULL)                                        //System.out.print
        {
            printf("%s\t cout<<",space[i]);
            for(j=20;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!='+' && a[i][j]!='(' && a[i][j]!=')')
                {
                    printf("%c",a[i][j]);
                }
                else if(a[i][j]=='+')
                {
                    printf("<<");
                }
            }
                

        }
        else if(strstr(a[i],"nextInt()"))                                                   //input
        {
            printf("\t");
            for(j=0;j<=strlen(a[i]);j++)
            {
                if(a[i][j]=='=')
                {
                    printf(";\n");
                    break;
                }
                printf("%c",a[i][j]);
            }
            printf("%s\t cin>>",space[i]);
            {
                for(j=5;j<=strlen(a[i]);j++)
                {
                    if(a[i][j]=='=')
                    {
                    printf(";\n");
                    break;
                    }
                    printf("%c",a[i][j]);
                }
            }
        }


        else
        {
            printf("%s",space[i]);
            printf("%s",a[i]);
            
        }
    }
    
}

