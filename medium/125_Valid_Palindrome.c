#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

bool isPalindrome(char* s)
{
    char* left = s;
    char* right = s + strlen(s) - 1;

    while(left < right)
    {
        // skip puncutation (non alpha numberic)
        while( left < right && !isalnum(*left)) left++;
        while( left < right && !isalnum(*right)) right--;

        if(tolower((unsigned char)*left) != tolower((unsigned char)*right))
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    char s[] = "A man, a plan, a canal: Panama";
    bool res = isPalindrome(s);
    printf("res: %d", res);
    char s2[] = "race a car";
    res = isPalindrome(s2);
    printf("res2: %d", res);

    return 0;
}
