#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 10

int p, f;
int frames[MAX_FRAMES], pages[MAX_PAGES];

void printFrame()
{
	for (int i=0; i<f; i++)
	{
		if (frames[i] != -1)
			printf("%d\t", frames[i]);
		else
			printf("_\t");
	}
}

void FIFO()
{
	int Faults = 0, Hit = 0, index = 0;
	for (int i=0; i<f; i++)
		frames[i] = -1;
		
	for (int i=0; i<p; i++)
	{
		printf("\tPage: %d -> ", pages[i]);
		int found = 0;
		for (int j=0; j<f; j++)
		{
			if (frames[j] == pages[i])
			{
				found = 1;
				break;
			}
		}
		if (!found)
		{
			frames[index] = pages[i];
			index = (index + 1) % f;
			Faults++;
			printFrame(); printf("FAULT\n");
		}
		else
		{
			Hit++;
			printFrame(); printf("HIT\n");
		}
	}
	
	printf("\nTotal Faults : %d", Faults);
	printf("\nTotal Hits : %d\n", Hit);
}

void LRU()
{
	int Faults = 0, Hit = 0, time[MAX_FRAMES] = {0}, leastUsed;
	for (int i=0; i<f; i++)
	{
		frames[i] = -1;
	}
	
	for (int i=0; i<p; i++)
	{
		printf("\tPage: %d -> ", pages[i]);
		int found = 0, index = -1;
		for (int j=0; j<f; j++)
		{
			if (frames[j] == pages[i])
			{
				found = 1;
				time[j] = i;
				break;
			}
			if (frames[j] == -1)
			{
				index = j; break;
			}
		}
		if (!found)
		{
			if (index != -1)
			{
				frames[index] = pages[i];
				time[index] = i;
			}
			else
			{
				leastUsed = 0;
				for (int j=1; j<f; j++)
				{
					if (time[j] < time[leastUsed]) 
						leastUsed = j;
				}
				frames[leastUsed] = pages[i];
				time[leastUsed] = i;
			}
			Faults++;
			printFrame(); printf("FAULT\n");
		}
		else
		{
			Hit++;
			printFrame(); printf("HIT\n");
		}
	}
	
	printf("\nTotal Faults : %d", Faults);
	printf("\nTotal Hits : %d\n", Hit);
}

void LFU()
{
	int Faults = 0, Hit = 0, freq[MAX_FRAMES] = {0}, time[MAX_FRAMES] = {0};
	for (int i=0; i<f; i++)
	{
		frames[i] = -1;
	}
	
	for (int i=0; i<p; i++)
	{
		printf("\tPage: %d -> ", pages[i]);
		int found = 0, index = -1;
		for (int j=0; j<f; j++)
		{
			if (frames[j] == pages[i])
			{
				found = 1;
				freq[j] ++;
				break;
			}
			if (frames[j] == -1)
			{
				index = j; break;
			}
		}
		if (!found)
		{
			if (index != -1)
			{
				frames[index] = pages[i];
				freq[index] = 1;
				time[index] = i;
			}
			else
			{
				int leastFreq = 0;
				for (int j=1; j<f; j++)
				{
					if (freq[j] < freq[leastFreq] || (freq[j] == freq[leastFreq] && time[j] < time[leastFreq]))
						leastFreq = j;
				}
				frames[leastFreq] = pages[i];
				freq[leastFreq] = 1;
				time[leastFreq] = i;
			}
			Faults++;
			printFrame(); printf("FAULT\n");
		}
		else
		{
			Hit++;
			printFrame(); printf("HIT\n");
		}
	}
	
	printf("\nTotal Faults : %d", Faults);
	printf("\nTotal Hits : %d\n", Hit);
}

void main()
{
	printf("Enter the no: of frames : "); scanf ("%d", &f);
	printf("Enter the no: of pages : "); scanf("%d", &p);
	
	printf("Enter the page reference string : ");
	for (int i=0; i<p; i++)
	{
		scanf("%d", &pages[i]);
	}
	
	printf("\nFIFO Page Replacement : \n"); FIFO();
	printf("\nLRU Page Replacement : \n"); LRU();
	printf("\nLFU Page Replacement : \n"); LFU();
}
