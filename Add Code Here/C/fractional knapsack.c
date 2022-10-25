// Write down the code for the fractional knapsack problem, using the Greedy Approach.

#include <stdio.h>

int main()
{
	int itemnos,cap=0;
	printf("Enter the number of items: ");
	scanf("%d", &itemnos);
	printf("Enter the capacity of knapsack:");
	scanf("%d", &cap);
	int currweight, item;
	float totprofit;
	int weight[10];
	int value[10];
	int used[10];
	printf("Enter the weight and value of %d item:\n", itemnos);
    for (int i = 0; i < itemnos; i++)
    {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }
    
    for(int i=0;i<itemnos;i++)
    {
    	used[i]=0;
    }
    
    currweight=cap;
    
    while(currweight > 0)
    {
    	item=-1;
    	for(int i=0; i<itemnos; ++i)
    	{
    		if ((used[i] == 0) && ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;
        
        used[item] =1;
        currweight -= weight[item];
        totprofit += value[item];
        
        if(currweight >= 0)
        
        	printf("Added object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], currweight);
        else
        {
            int itemPercent = (int)((1 + (float)currweight / weight[item]) * 100);
            printf("Added %d%% (%d Rs., %dKg) of object %d in the bag.\n", itemPercent, value[item], weight[item], item + 1);
            totprofit -= value[item];
            totprofit += (1 + (float)currweight / weight[item]) * value[item];
        }
    }

    printf("Filled the bag with objects worth %.2f Rs.\n", totprofit);
}
	
}
