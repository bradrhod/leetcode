#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int start = 0;
    int sumGas = 0;
    int sumCost = 0;
    // if sum gas is less than sum cost we cannot make int
    int gasTank = 0;
    for(int i = 0; i < gasSize; i++ )
    {
        sumGas = sumGas + gas[i];
        sumCost = sumCost + cost[i];
        gasTank = gasTank + gas[i] - cost[i];
        if(gasTank < 0)
        {
            //we ran out, start at this the next state.
            start = i+1;
            gasTank = 0;
        }
    }
    if(sumGas >= sumCost)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int gas[] = { 1, 2, 3, 4, 5};
    int gasSize = 5;
    int cost[] = {3, 4, 5, 1, 2};
    int costSize = 5;
    int result = canCompleteCircuit( gas, gasSize, cost, costSize);
    printf("result: %i", result);
    return 0;
}
