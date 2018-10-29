#include <stdio.h>
#include <stdlib.h>
#define nMAX 5000000
#define m 8

typedef struct {
	int info;
	int infof;
} SDATA;

SDATA a[nMAX];
int seed;
int seed2;
int n;

int main(int argc,char* argv[])
{
  int i;
  int option;
  seed2=1027;
  if (argc>1)
  {
	  sscanf( argv[1],"%d",&n);
  }
  else n=3000000;
  if (argc>2)
    {
	    
	  sscanf( argv[2],"%d",&option);
    }	    
  else option=0;
  printf("%d \n",option);
  printf("%d \n",n);
  switch (option)
  {
	  case 1:
		  {
                   for (i=0;i<n;i++)
                      {
	               a[i].info=i+1;
		       a[i].infof=0;
		      } 
		   break;
		  }
	  case 2:
		  {
                   for (i=0;i<n;i++)
	              {
	               a[i].info=n+1-i;
	               a[i].infof=0;
	              } 
		   break;
		  }
	  case 3:
		  {
			  for (i=n/2;i>=0;i--)
                             {
                              a[2*i+1].info=2*i+2;
                              a[2*i+1].infof=0;
		              a[2*i+2].info=2*i+1;	  
		              a[2*i+2].infof=0;	  
			     } 
			  break;
		  }
	  case 4:
		  {
			  for (i=n-1;i>=0;i--)
                             {
                              if (i% m)
			        { 
				  a[i].info=i;
				  a[i].infof=0;
				}
		              else 
			       {
			        a[i].info=m+m/(i+1); 
			        a[i].infof=0; 
			       }
			     } 
			  break;
		  }
	  case 5:
		  {
			  for (i=0;i<n;i+=2)
                             {
                              if ((i% m)) 
			        {
				 a[i].info=i;
				 a[i].infof=0;
				 a[i+1].info=i+1;
				 a[i+1].infof=0;
				} 
		              else 
			        {
				  a[i].info=i+1;
				  a[i].infof=0;
				  a[i+1].info=i;
				  a[i+1].infof=0;
				} 
			     } 
			  break;
		  }
          case 6:{
			  srand(seed2);
		   for (i=0;i<n;i++)
		   {
			   a[i].info=i/10;
			   a[i].infof=rand()%20;
		   }
		   break;
                 }			 

	  default:
		  {
			  srand(seed);
                   for (i=0;i<n;i++)
                      {
	               a[i].info=rand();
	               a[i].infof=0;
	              } 
		   break;
		  }
  }

  for(i=0;i<n;i++)
	  printf("(%d,%d) ",a[i].info,a[i].infof);
	return 0;

}
