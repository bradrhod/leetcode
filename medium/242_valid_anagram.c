#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram( char* s, char* t)
{
    int n = strlen(s);
    if (n != (int)strlen(t))
        return false;

    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return false;

    return true;
}


int main()
{
    char word1[] = "anagram";
    char ana1[] = "nagaram";
    bool res = isAnagram(word1, ana1);
    printf( "%d", res);
    return 0;
}
