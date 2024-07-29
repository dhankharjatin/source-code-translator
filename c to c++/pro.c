#include<stdio.h>
#include <string.h>
void main()
{
    FILE *r = fopen("c.txt","r");
    FILE *w = fopen("c++.txt","w");
    char c,b;
    int i=0;
    int j=0;
    int l=0;
    int x=0;
    int y=0;
    int count = 0;
    int comm;
    int z=0;
    int k;
    int num=1;
    char a[200][200];
    char space[100][100];
    char var[100][100];
    int s_comm;
    int last=0;
    int first=0;
    int br;
    
    
    while(c!=EOF )
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
        
        if(a[i][0]=='#')                                                                                              // HEADER FILES
        {
            if(strstr(a[i],"#include<stdio.h>")!=NULL)
            {
                
                printf("%s#include<iostream>\n",space[i]);
            }
            else
            {
                
                for(j=0;j<=strlen(a[i]);j++)
                {
                    if(a[i][j]!='.' && a[i][j]!='h')
                    {
                        printf("%s%c",space[i],a[i][j]);
                    }
                }
            }
            
        } 
        else if(strstr(a[i],"void main()")!=NULL)                                                                       // FUNCTIONS
        {
            
            printf("using namespace std;\n");
            printf("%sint main()\n",space[i]);
        }
        

        else if(strstr(a[i],"printf")!=NULL)                                                                            //PRINTF                                                                           
        {
            for(x=0;x<20;x++)
            {
                for(y=0;y<20;y++)
                {
                    var[x][y]='\0';
                }
            }
            z=0;
            count=0;
            x=0;
            y=0;
            last=0;
            first=0;
            //calculating the first occurance of ,
            for(comm=8;comm<=strlen(a[i]);comm++)
            {
                if((a[i][comm]==',' && (a[i][comm-1]=='\"' || a[i][comm-2]=='\"')) || a[i][comm]==')' )
                {
                        break;
                }
               
            }
            for(br=8;br<=strlen(a[i]);br++)
            {
                if(a[i][br]==')' )
                {
                        break;
                }
               
            }
            
            //storing variables after , in array
            for(j=0;j<br;j++)
            {
                if(a[i][j]==',' && (a[i][j-1]=='\"' || a[i][j-2]=='\"'))
                {
                    for(k=j+1;k<br;k++)
                    {
                        if(a[i][k]==',')
                        {
                            
                            x++;
                            y=0;
                        }
                        else
                        {   
                            var[x][y]=a[i][k];
                            y++;
                        }
                            
                    }
                }

                //calculating no. of format specifiers
                else if((a[i][j]=='%' && a[i][j+1]=='d') || (a[i][j]=='%' && a[i][j+1]=='f')|| (a[i][j]=='%' && a[i][j+1]=='c') ) 
                {
                    count++;
                    //checking if format specifier is the first thing in print statement
                    if(a[i][j-2]=='(' || a[i][j-3]=='(')
                    {
                        first=1;
                    }
                }
                 
                
                
            }            
            
            printf("%s cout<<",space[i]);
            if(first!=1)
            {
               printf("\"");
            }
            for(j=8;j<comm;j++)
            {
                // printing char by char
                if(a[i][j]!='%' && a[i][j-1]!='%' && a[i][j]!='\"'  )  
                {
                
                    printf("%c",a[i][j]);
                    
                }
                // when format specifier is encountered
                else if((a[i][j]=='%' && a[i][j+1]=='d') || (a[i][j]=='%' && a[i][j+1]=='f')|| (a[i][j]=='%' && a[i][j+1]=='c')) 
                {
                    
                    if(a[i][j-2]=='(' || a[i][j-3]=='(')
                    {
                        printf("%s<<\"",var[z]);   
                        z++;
                    }
                    else if(a[i][j+2]=='\"' || a[i][j+3]=='\"')
                    {
                        printf("\"<<%s",var[z]);
                        last=1;
                        
                    }
                    else
                    {
                        printf("\"<<%s<<\"",var[z]);
                        z++;
                    }
                    
                }
                
            }
            // printing " when format specifer is not present at the end in printf statement 
            if(last!=1)
            {
                printf("\"");
            }
            printf(";\n");
            

        }
        
        else if(strstr(a[i],"scanf")!=NULL)                                                                                  // SCANF
        {
            
            printf("%s cin>>",space[i]);
            for(s_comm=0;s_comm<=strlen(a[i]);s_comm++)
            {
                if(a[i][s_comm]==',')
                {
                    break;
                }
            }

            for(j=s_comm+1;j<=strlen(a[i]);j++)
            {
                if(a[i][j]!='&' && a[i][j]!=',' && a[i][j]!=')' )
                {
                    printf("%c",a[i][j]);

                }
                else if(a[i][j]==',')
                {
                    printf(">>");
                }
            }
            
                    

        }
        else                                                                                            //INITIALIZATION AND BRACKETS
        {
            
           printf("%s %s",space[i],a[i]);
        }
    }
    fclose(r);
    fclose(w);
    
}