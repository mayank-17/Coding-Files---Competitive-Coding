#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);
    int charFrequency[26]= {0};
    int i=0;
    while(a[i] != '\0')
    {
        charFrequency[a[i]-'a']++;
        i++;
    }
    i=0;
    while(b[i] != '\0')
    {
        charFrequency[b[i]-'a']--;
        i++;
    }
    int sum=0;
    for(int k=0; k<26; k++)
    {
        sum += (0<charFrequency[k])?charFrequency[k]:(-charFrequency[k]);
    }
    printf("%d", sum);
    return 0;
}
