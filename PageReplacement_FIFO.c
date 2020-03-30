#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	  int hit=0;
      int i=0;
      int j=0;
      int count = 0;
      int len = 0;
      int faults = 0;
      int fn =0;
      int pn = 0;
     
      printf("\nEnter the number of pages from 0-9 : ");
      scanf("%d",&pn);
      
      printf("\nEnter the number of frames from 1-7 : ");
      scanf("%d",&fn);
      
      int frames[fn];
      int pages[pn];
	     
      for(i=0; i<fn; i++) 
      {
        frames[i] = -1;
      }
      printf("\n\nGenerating Random Pages...");
      printf("\n Pages are : ");
	  for(i=0;i<pn;i++)
      {
      	pages[i]=rand()%9;
      	printf("%d",pages[i]);
	  }
	  printf("\n\n");	  
	  for(i=0;i<pn;i++)
	  {
	  	printf("\nProcess started...\n");
	  	
	  	for(j=0;j<fn;j++)
	  	{
	  		printf("\nInitialized Checking");
	  		
	  		if(pages[i]==frames[j])
	  		{
	  			printf("\nChecking For Same Frame and Pages...",j);
	  			count++;
	  			printf("\nThis can be Hit\n");
			}
			else
			{
			printf("\n Nothing Matched\n");	
			}
		}
		if(count!=0)
		{
			printf("\nCalculating Hits...",j);
			hit++;
			count = 0;
		}
		else
		{
			if(len>= fn)
			{
				printf("\n\nChecking Length...");
				len = 0;
				printf("\nResetting...", len);
					
			}
			    printf("\nMoving page(s) to frame...");
				frames[len] = pages [i];
				printf("\n Moved page %d to frame %d",i+1,len+1);
		    	len++;
			    faults++;
						
		}
		printf("\n\nDone!\n\n");
		printf("\n\n\n***********************");
		printf("  Faults : %d --",faults);
		printf("-- Hits :%d  ",hit);
		printf("*********************\n\n");
	  }
}

