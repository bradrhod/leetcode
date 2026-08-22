#include <stdio.h>

#define MAXINT 0x7FFFFFFF

int maxProfit(int * prices, int pricesSize)
{
    // Find the minimum prices in the array.
    int minprice = MAXINT;
    int profit = 0;
    for(int i = 0; i < pricesSize; i++)
    {
        if( prices[i] < minprice)
        {
            minprice = prices[i];
        }
        int thisprofit = prices[i] - minprice;

        profit = ( profit > thisprofit ? profit : thisprofit);
    }

    return profit;
}

int main()
{
    int prices[] = { 7, 1, 5, 3, 6, 4};
    int pricesSize = 6;
    int profit = maxProfit(prices, pricesSize);
    printf("max profit %d",profit);
    return 0;
}
