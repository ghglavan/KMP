#include <stdio.h>
#include <string.h>

#define MAX 2000005

int suf[MAX];
int poz[1001];
int curr;


void gaseste_suf(char* s, int ls){
	int j = 0;
	int i;
	for(i = 1; i < ls;){
		if(s[j] == s[i]){
			suf[i] = j+1;
			i++;
			j++;

		}else if(j!=0){
			j = suf[j-1];
		}else{
			suf[i] = 0;
			i++;
		}
	}

}

void KMP(char* s1, int ls1, char* s2, int ls2){
	gaseste_suf(s1,ls1);
	int i = 0;
	int j = 0;
	while(i < ls1 && j < ls2){
		if(s1[i] == s2[j]){
			i++;
			j++;
		}else{
			if(i!=0){
				i = suf[i-1];
			}else{
				j++;
			}
		}
		if(i == ls1){
			curr++;
			if(curr <= 1000)
				poz[curr-1] = j - ls1;
			i = suf[i-1];
		}
	}
}

int main(){

	int n,m;
	char* s1 = "ABA";
  char* s2 = "CABBCABABAB";




	n = strlen(s1);
	m = strlen(s2);

	KMP(s1,n,s2,m);

	printf("%d\n",curr);

	int i = 0;

	curr = curr > 1000 ? 1000 : curr;

	for(;i < curr; i++){
		printf("%d ",poz[i]);
	}

}
