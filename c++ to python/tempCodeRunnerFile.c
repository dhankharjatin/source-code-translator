#include<stdio.h>
#include<string.h>
void main()
{
    FILE *r= fopen("c++.txt","r");
    char c,b;
    char a[200][200];
    char space[200][200];
    int i=0;
    int j=0;
    int l=0;
    int num=1;
    char var_cin[50][50];
    int x=0;
    int y=0;
    int cin_num=1;
    int semi=0;
    int z;
    char f_var[50][50];   
    int q=0;
    int t=0;
    int e1=0;
    int e2=0;
    char n1[10];
    char n2[10];
    int ind=0;
    char svar[10][10];
    int x1=0;
    int y1=0;
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
    for(i=0;i<=num;i++)
    {
        if(strstr(a[i],"{")!=NULL)
        {
            ind=1;
        }
        else if(strstr(a[i],"}")!=NULL)
        {
            ind=0;
        }
        else if(strstr(a[i],"int main()")!=NULL)
        {
            i++;
        }
        else if((strstr(a[i],"int")!=NULL || strstr(a[i],"char")!=NULL || strstr(a[i],"float")!=NULL || strstr(a[i],"void")!=NULL) && strstr(a[i],";")==NULL )
        {
            if(ind==1)
            {
                printf("\t");
            }
            printf("def ");
            for(j=5;j<=strlen(a[i]);j++)
            {
                printf("%c" ,a[i][j]);
                if(a[i][j]==')')
                {
                    printf(":");
                }
            }
            
        }
        else if(strstr(a[i],"switch(")!=NULL)                                           //switch
        {
            
            for(j=7;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!=')' && a[i][j]!='\n' && a[i][j]!='(')
                {
                    svar[x1][y1]=a[i][j];
                    y1++;   
                }
            }
            
        }
        else if(strstr(a[i],"case ")!=NULL)                                             //case
        {
            if(strstr(a[i-2],"switch(")!=NULL)
            {
                printf("if (%s) ==",svar[0]);
                for(j=5;j<=strlen(a[i]);j++)
                {
                    printf("%c",a[i][j]);
                }
            }
            else
            {
                printf("elif (%s) ==",svar[0]);
                for(j=5;j<=strlen(a[i]);j++)
                {
                    printf("%c",a[i][j]);
                }
            }
        }
        else if(strstr(a[i],"default :")!=NULL || strstr(a[i],"default:")!=NULL )
        {
            printf("else :\n");
        }
        else if(strstr(a[i],"int")!=NULL && strstr(a[i],"=")!=NULL)                      //initialization
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            for(j=5;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!=';')
                {
                    printf("%c",a[i][j]);
                }
            }
        }
        else if((strstr(a[i],"char")!=NULL && strstr(a[i],"=")!=NULL))
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            for(j=6;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!=';')
                {
                    printf("%c",a[i][j]);
                }
            }

        }
        else if(strstr(a[i],"cout<<")!=NULL)                                       // cout
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            printf("print(");
            for(j=6;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!=';' && a[i][j]!='<')
                {
                    printf("%c",a[i][j]);
                }
                else if(a[i][j]=='<' && a[i][j+1]=='<')
                {
                    printf(",");
                }
                else if(a[i][j]==';')
                {
                    printf(")");
                }
            }
            
        }
        else if(strstr(a[i],"cin>>")!=NULL)                                         //cin
        {
            if(ind==1)
            {
                printf("\t");
            }
            for(j=7;j<strlen(a[i])-1;j++)
            {
                if(a[i][j]!='>' && a[i][j]!=';')
                {                
                    var_cin[x][y]=a[i][j];
                    y++;
                }
                else if(a[i][j]=='>' && a[i][j+1]=='>')
                {
                    x++;
                    y=0;
                    cin_num++;
                }
            }
            for(z=0;z<cin_num;z++)
            {
                
                printf("%s =int(input())\n",var_cin[z]);   
            }        
        }
        else if(strstr(a[i],"else if(")!=NULL || strstr(a[i],"else if (")!=NULL)           //else if
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            printf("elif");
            for(j=8;j<strlen(a[i]);j++)
            {
                printf("%c",a[i][j]);
                if(a[i][j]==')')
                {
                    printf(":");
                }
            }
        }
        else if(strstr(a[i],"if(")!=NULL || strstr(a[i],"if (")!=NULL )                  //if
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            for(j=1;j<=strlen(a[i]);j++)
            {
                printf("%c",a[i][j]);
                if(a[i][j]==')')
                {
                    printf(":");
                }
            }
            
        }
        else if(strstr(a[i],"else")!=NULL || strstr(a[i],"else ")!=NULL)                     //else
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            for(j=1;j<=strlen(a[i]);j++)
            {
                printf("%c", a[i][j]);
                if(a[i][j-1]=='s')
                {
                    printf(":");
                }
            } 
        }
        else if(strstr(a[i],"while(")!=NULL || strstr(a[i],"while (")!=NULL)                //while
        {
            if(ind==1)
            {
                printf("\t");
            }
            
            for(j=1;j<=strlen(a[i]);j++)
            {
                printf("%c", a[i][j]);
                if(a[i][j]==')')
                {
                    printf(":");
                }
            }
                
        }     
        else if(strstr(a[i],"for(")!=NULL || strstr(a[i],"for (")!=NULL)                        //for
        {
            if(ind==1)
            {
                printf("\t");
            }
            printf("for");
            for(j=0;j<=strlen(a[i]);j++)
            {
                e1++;
                if(a[i][j]=='=')
                {
                    e2=e1;
                    break;
                }

            }
            for(j=e1;j<=strlen(a[i]);j++)
            {
                e2++;
                if(a[i][j]=='=')
                {
                    break;
                }

            }
            
            for(j=e1;j<=strlen(a[i]);j++)
            {
                if(a[i][j]==';')
                {
                    break;
                }
                n1[q]=a[i][j];
                q++;
            }
            for(j=e2;j<=strlen(a[i]);j++)
            {
                if(a[i][j]==';')
                {
                    break;
                }
                n2[t]=a[i][j];
                t++;
            }
            for(j=4;j<e1-1;j++)
            {
                if(a[i][j]!='(' )
                {
                    printf("%c",a[i][j]);
                }
                
            }
            printf(" in range( %s, %s) :\n",n1,n2);
            
        }
        else if(strstr(a[i],"++")!=NULL || strstr(a[i],"--")!=NULL)                             //increment and decrement operator
        {
            if(ind==1)
            {
                printf("\t");
            }
            for(j=1;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!='+' && a[i][j]!='-')
                {
                    printf("%c",a[i][j]);
                }
                else if(a[i][j]=='+' && a[i][j+1]=='+' )
                {
                    printf("+=1");
                }
                else if(a[i][j]=='-' && a[i][j+1]=='-')
                {
                    printf("-=1");
                }
            }
        }   
    }   
}