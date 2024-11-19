#include<stdio.h>
int data[20], gen[20],temp[20],dl,gl,j,k;
void xor ()
{
  for(int i=0;i<gl;i++)
  {
    temp[i]=temp[i]^gen[i];
  }
}
void leftshift()
{
 int ch=temp[0];
 for(int i=0;i<gl-1;i++)
 {
   temp[i]=temp[i+1];
 }
  temp[gl-1]=ch;
}
void generate (int data[],int gen[])
{
  for(int i=0;i<gl-1;i++)
  {
    data[dl+i]=0;
  }
  for(int i=0;i<gl;i++)
  {
    temp[i]=data[i];
  }
  int pick=gl;
  while(pick<dl+gl-1)
  {
    if(temp[0]==1)
    {
      xor();
    }
    else{
     leftshift();
    }
    temp[gl-1]=data[pick];
    pick++;
  }
  printf("Frame after appending 0's------");
  for(int i=0;i<dl+gl-1;i++)
  {
    printf("%d",data[i]);
  }
  printf("/n");
   printf(" The Remainder is----");
   for(int i=0;i<gl;i++)
  {
    printf("%d",temp[i]);
  }
  printf("\n");
  printf("Transmitting Frame----\n");
  printf("The Transmitted frame is---");
  for(int i=0;i<gl-1;i++)
  {
    data[dl+i]=temp[i];
  }
  printf("/n");
  for(int i=0;i<dl+gl-1;i++)
  {
    printf("%d",data[i]);
  }
}
void verify(int data[],int gen[])
{
 printf("frame recieved \n");
 printf("checking for errors......\n");
 printf("Recieved Frame is ......\n");
 for(int i=0;i<dl+gl-1;i++)
 {
    printf("%d",data[i]);
 }
  for(int i=0;i<gl;i++)
  {
    temp[i]=data[i];
  }
  int pick=gl;
  while(pick<dl+gl-1)
  {
    if(temp[0]==1)
    {
      xor();
    }
    else
    {
     leftshift();
    }
    temp[gl-1]=data[pick];
    pick++;
  }
  printf("Remainder is ---\n");
  int ct=0;
   for(int i=0;i<gl;i++)
  {
    printf("%d",temp[i]);
    if(temp[i]==0)
    ct++;
  }
  if(ct==gl)
  printf("Data sent Successfully");
  else
  printf("Error in the CRC code generation");
}
void main()
{
 printf("*****Cyclic redundancy check-12 (CRC12)*******\n");
 printf("Enter Frame length");
 scanf("%d",&dl);
 printf("The Frame is ---\n");
 for(int i=0;i<dl;i++)
 {
    scanf("%d",&data[i]);
 }
  printf("\n >>>>both high & low ordersbits of GENERATOR must be 1<<<<\n");
 printf("Enter generator length\n");
 scanf("%d",&gl);
 printf("Enter  the generator \n");
 for(int i=0;i<gl;i++)
 {
   scanf("%d",&gen[i]);
 }
 do
 {
   printf("Press 1 to generate CRC code OR 2 to verify CRC code");
   scanf("%d",&j);
   switch(j)
   {
    case 1: generate(data,gen);
            break;
    case 2 :verify(data,gen);
            break;
   default:printf("Invalid choice!!");
   }
   printf("--exit ");
   scanf("%d",&k);
  }while(k!=1);
}
