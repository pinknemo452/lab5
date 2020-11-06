#include<stdio.h>

int findsize(char* array) {
	int stringsize = 0;
	while ((array[stringsize] != '\n')) {
		stringsize++;
	}
	return stringsize;
}
int onlychars(char* word,int size) {
	for (int i = 0; i < size; i++) {
		if( (word[i]<'A') || ((word[i] > 'Z') && (word[i] < 'a')) || (word[i] > 'z')  ){
			return 0;
		}
	}
	if (size != 0) {
		return 1;
	}
	else return 0;
}
void sort(char* string, char* firstword, char* secondword) {
	int firstwordsize = findsize(firstword);
	int secondwordsize = findsize(secondword);
	int stringsize = findsize(string);
	int wordsdifference = firstwordsize - secondwordsize;
	int co = 0;
	int k = 0;
	int g = 0;
	for (int i = 0; i < 1000; i++) {
		if (string[i] == firstword[co]) {
			co++;
		}
		else co = 0;
		if (co == firstwordsize) {
			if (wordsdifference > 0) {
				for (int j = i; j < stringsize; j++) {
					string[j - wordsdifference] = string[j];
					string[j] = 0;
				}
			}
			else if (wordsdifference < 0) {
				for (int j = stringsize; j >= i; j--) {
					string[j - wordsdifference] = string[j];
					string[j] = 0;
				}
			}
			for (int j = i - firstwordsize + 1; j < i - firstwordsize + secondwordsize + 1; j++) {
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
	for (int i = 0; i < stringsize - g * wordsdifference; i++) {
		printf("%c", string[i]);
	}
	printf("\"");
}
int main() {
	char g[1000];
	char firstword[1000] = { 0 };
	char secondword[1000] = { 0 };
	int deb = 1;
	printf("enter first word: ");
	fgets(firstword, 1000, stdin);
	//printf("%d", firstword[0]);
	int firstwordsize = findsize(firstword);
	//printf("%d", firstword[1]);
	while (onlychars(firstword,firstwordsize) == 0) {
		for (int i = 0; i < 1000; i++) {
			firstword[i] = 0;
		}
		printf("enter first word: ");
		fgets(firstword, 1000, stdin);
		firstwordsize = findsize(firstword);
	}
	printf("enter second word: ");
	fgets(secondword, 1000, stdin);
	int secondsize = findsize(secondword);
	while (onlychars(secondword,secondsize) == 0) {
		for (int i = 0; i < 1000; i++) {
			secondword[i] = 0;
		}
		printf("enter second word: ");
		fgets(secondword, 1000, stdin);
		secondsize = findsize(secondword);
	}
	printf("enter string: ");
	char string[1000];
	fgets(string, 1000, stdin);
	sort(string, firstword, secondword);
	return 0;
}