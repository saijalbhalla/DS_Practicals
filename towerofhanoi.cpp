#include <iostream>
#include<string.h>
using namespace std;

void replacePi(char input[]) 
{
int len=strlen(input),i=0;
 if(len==0||len==1)
   return;
else
{  
     if(input[0]=='p'&& input[1]=='i')
     {input[0]='3';
      input[1]='.';
        for(i=len;i>1;i--)
         input[i+2]=input[i];
      input[2]='1';
      input[3]='4';
     replacePi(input); //or  replacePi(input+4);
     }     
     else
    {
     replacePi(input+1);
    }
}  
}
int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
