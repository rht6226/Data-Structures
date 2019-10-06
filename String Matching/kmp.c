#include<stdio.h>
#include<string.h>
char txt[100],pat[100];
int M ,N ,lps[100],j=0,i=0;
 // Preprocess the pattern (calculate lps[] array)
void computeLPSArray()
{
  int len = 0, i;
  lps[0] = 0;
  i = 1;
  while(i < M)
  {
   if(pat[i] == pat[len])
   {
   len++;
   lps[i] = len;
   i++;
   }
   else
   {     // mismatch after j matches
   if( len != 0 )
     len = lps[len-1];
   else
   {
     lps[i] = 0;
     i++;
   }
   }
  }
}
void KMPSearch()
{
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    // values for pattern
  M = strlen(pat);
    // create lps[] that will hold the longest prefix suffix
  N = strlen(txt);
  computeLPSArray();

    // the loop calculates lps[i] for i = 1 to N-
  while(i < N)
  {
  if(pat[j] == txt[i])
  {
    j++;
    i++;
  }

  if (j == M)
  {
    printf("Found pattern at index %d \n", i-j);
    j = lps[j-1];
  }
  else if(pat[j] != txt[i])
  {
    // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
    if(j != 0)
   j = lps[j-1];
    else
   i = i+1;
  }
  }
}

int main()
{
 printf("\n ENTER THE TEXT    : ");
 scanf("%s",txt);
 printf("\n ENTER THE PATTERN : ");
 scanf("%s",pat);
 KMPSearch();
 return 0;
}
