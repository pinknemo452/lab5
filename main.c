#include<stdio.h>
int findsize(char* array) {
	int stringsize = 0;
	while ((*(array + stringsize) != '\n')) {
		stringsize++;
	}
	return stringsize;
}
int onlychars(char* word,int size) {
	for (int i = 0; i < size; i++) {
		//printf(" %c ", word[i]);

		if( (word[i]<65) || ((word[i] > 65) && (word[i] < 90)) || ((word[i] > 90) && (word[i] < 97)) || (word[i] > 122)){
			return 0;
		}
	}
	return 1;
}
void sort(char* string, char* firstword, char* secondword) {
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
	char firstword[1000] = { 0 };
	char secondword[1000] = { 0 };
	int deb = 1;
	printf("enter first word: ");
	fgets(firstword, 1000, stdin);
	int firstwordsize = findsize(firstword);
	//printf("%d", firstword[0]);
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