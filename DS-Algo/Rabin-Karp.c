 #include<stdio.h>
#include<string.h>

int hash(char *str, int low, int high) {
  // High is exclusive means len not index
  int hash = 0;
  for(;low<high; low++) {
    hash += (int) str[low]; 
  }
  return hash;
}

int main() {
  char *str = "aaaaabb";
  int str_len = strlen(str);
  char *pattern = "aab";
  int pattern_len = strlen(pattern);

  int p_hash = hash(pattern, 0, pattern_len);

  for(int i=0; i<str_len; i++) {
    if(hash(str, i, i+pattern_len) == p_hash) {
      int isMatchReallyFound = 0;
      for(int j=0; j<pattern_len; j++) {
        if(pattern[j] == str[i+j])
          isMatchReallyFound = 1;
        else {
          isMatchReallyFound = 0;
          break;
        }
      }
      if(isMatchReallyFound == 1) {
        printf("Match found at %d\n", i);
        break;
      }
    } 
  }
}
