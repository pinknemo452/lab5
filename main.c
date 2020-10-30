#include<stdio.h>
int findsize(char* array) {
	int stringsize = 0;
	while ((*(array + stringsize) != '\n') || (*(array + stringsize) != 10)) {
		stringsize++;
	}
	return stringsize;
}
int main() {
	char firstword[1000] = { 0 };
	char secondword[1000] = { 0 };
	printf("enter first string: ");
	fgets(firstword, 1000, stdin);
	printf("enter second string: ");
	fgets(secondword, 1000, stdin);
	printf("enter string: ");
	char string[1000];
	fgets(string, 1000, stdin);
	int firstwordsize = findsize(firstword);
	//printf("firstword size: %d", firstwordsize);
	int secondwordsize = findsize(secondword);
	int stringsize = findsize(string);
	int wordsdifference = firstwordsize - secondwordsize;
	//printf("words difference %d", wordsdifference);
	//printf("%d", wordsdifference);
	//char* temp = (char*)malloc(firstwordsize * sizeof(char));
	int co = 0;
	int k = 0;
	int g = 0;
	for (int i = 0; i < 1000; i++) {
		if (string[i] == firstword[co]) {
			co++;
			
		}
		else co = 0;
		if (co == firstwordsize) {
			//printf("\nco %d", co);
			//printf("\nstring - co: %d\n",i-co);
			if (wordsdifference > 0) {
				for (int j = i; j < stringsize; j++) {
					
						//printf("\nj - wordsdifference %d", j - wordsdifference);
						string[j - wordsdifference] = string[j];
						string[j] = 0;
					
				}
			}
			else if (wordsdifference < 0) {
				for (int j = stringsize; j >= i; j--) {
					//printf("\nj - wordsdifference %d", j - wordsdifference);
					string[j - wordsdifference] = string[j];
					string[j] = 0;
				}
			}
			for (int j = i - firstwordsize+1; j < i - firstwordsize + secondwordsize+1; j++) {
				string[j] = secondword[k];
				k++;
			}
			co = 0;
			k = 0;
			g++;
			i -= wordsdifference;
		}
	}
	printf("sorted string: \"");
	for (int i = 0; i < stringsize -g*wordsdifference; i++) {
			printf("%c", string[i]);
	}
	printf("\"");
	return 0;
}