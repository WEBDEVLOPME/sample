#include<stdio.h> 
int absolute(int a,int b) 
 {int c; 
 c=a-b; 
 if(c<0) 
 return -c; 
 else 
 return c; 
 } 
void main() 
 {int choice,m,n,x,start,i,j,pos,min,a[15],count; 
 count=0; 
 clrscr(); 
 printf("\nEnter the number of cylinders :"); 
 scanf("%d",&m); 
 printf("\nEnter the number of requests :"); 
 scanf("%d",&n); 
 printf("\nEnter starting position :"); 
 scanf("%d",&start); 
 printf("\nEnter the request queue :"); 
 for(i=0;i<n;i++) 
 {scanf("%d",&a[i]); 
 if(a[i]>=m) 
{printf("\ninvalid input"); 
 scanf("%d",&a[i]); 
 } 
 } 
 do 
 {printf("\n\nDISK SCHEDULING ALGORITHMS\n1. FCFS\n2. SCAN"); 
printf("\nEnter choice :"); 
scanf("%d",&choice); 
count=0; 
x=start; 
switch(choice) 
 {case 1:printf("\nFCFS :\n"); 
 printf("Scheduling services the request in the order that 
follows:\n%d\t",start); 
 for(i=0;i<n;i++) 
 {x-=a[i]; 
 if(x<0) 
 x=-x; 
 count+=x; 
 x=a[i]; 
 printf("%d\t",x); 
 } 
 printf("\nTotal Head Movement :%d Cylinders",count); 
 break; 
 case 2:printf("\nSCAN :\n"); 
 printf("Scheduling services the request in the order that follows:\n"); 
 count=0; 
 pos=0; 
 for(i=0;i<n;i++) 
 for(j=0;j<n-i-1;j++) 
 if(a[j]>a[j+1]) 
 {x=a[j]; 
 a[j]=a[j+1]; 
 a[j+1]=x; 
 } 
 for(i=0;i<n;i++) 
 if(a[i]<start) 
 pos++; 
 for(i=0;i<pos;i++) 
 for(j=0;j<pos-i-1;j++) 
if(a[j]<a[j+1]) 
 {x=a[j]; 
a[j]=a[j+1]; 
a[j+1]=x; 
} 
 x=start; 
 printf("%d\t",x); 
 for(i=0;i<pos;i++) 
{count+=absolute(a[i],x); 
x=a[i]; 
printf("%d\t",x); 
} 
 count+=absolute(x,0); 
 x=0; 
 printf("%d\t",x); 
 for(i=pos;i<n;i++) 
{count+=absolute(a[i],x); 
x=a[i]; 
printf("%d\t",x); 
} 
 printf("\nTotal Head Movement: %d Cylinders",count); 
 break; 
 } 
printf("\nDo you want to continue(1 to continue) :"); 
scanf("%d",&choice); 
}while(choice==1); 
 } 
 
