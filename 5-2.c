/*将一个长整型数s的每一位数位上的偶数依次取出来，
构成一个新的数t，其高位仍在高位，低位仍在低位。
例如: s=87653142时，t中的数为8642*/
#include <stdio.h>  
#include <stdlib.h>   
int main()  
{  
    int s=0,t=0,i=1;
    printf("Please input a number:");
    scanf("%d",&s);
    int s1=s;
    while(s1>=10)//判断s的位数
    {
        s1=s1/10;
        i++;
    }
    int a[i],j=0,h=0;
    for(j=0;j<i;j++)//将s的每一位数存入数组a
    {
        if(s%10%2==0)
        {
            a[h]=s%10;
            h++;
        }
        s=s/10;
    }
    for(j=0;j<h;j++)//将数组a中的数存入t
    {
        t=t*10+a[h-j-1];
    }
    printf("The new number is %d\n",t);
    system("pause");  
    return 0;  
} 