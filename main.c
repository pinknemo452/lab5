#include<stdio.h>
#include<stdlib.h>
struct WordsArray_s {
	char** words;
	int wordsLength[1000];
};
int findsize(char* array) {
	int stringsize = 0;
	while ((array[stringsize] != '\n')) {
		stringsize++;
	}
	return stringsize;
}
int onlychars(char* word, int size) {
	for (int i = 0; i < size; i++) {
		if ((word[i] < 'A') || ((word[i] > 'Z') && (word[i] < 'a')) || (word[i] > 'z')) {
			return 0;
		}
	}
	if (size != 0) {
		return 1;
	}
	else return 0;
}
 struct WordsArray_s formArray(char* string,int* wordCount) {
	
	int stringsize = findsize(string);
	//printf("\nstringsize: %d", stringsize); printf("\n");
	int wordsize = 0;
	*wordCount = 0;
	int g = 0;
	struct WordsArray_s array;
	array.words = (char**)malloc(stringsize * sizeof(char*));
	for (int i = 0; i < stringsize+1; i++) {
		if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')) {
			wordsize++;
			//printf("okok %d ",wordsize);
		}
		else if(wordsize != 0 ) {
			array.words[*wordCount] = (char*)malloc(wordsize * sizeof(char));
			for (int k = i - wordsize ; k < i; k++) {
				//printf("string[k] %c", string[k]);
				array.words[*wordCount][g] = string[k];
				g++;
			}
			g = 0;
			//printf("word Count: %d", *wordCount); printf("\n");
			array.wordsLength[(*wordCount)] = wordsize;
			(*wordCount)+=1;
			wordsize = 0;
		}	
	}
	//printf("word Count: %d", *wordCount); printf("\n");
	/*for (int l = 0; l < *wordCount; l++) {
		//printf("f");
		for (int j = 0; j < array.wordsLength[l]; j++) {
			printf("%c", array.words[l][j]);
		}
		printf("\n");
	}*/
	return array;
}
 void sort(char* string, char* firstword, char* secondword, int stringsize ) {
	 int firstwordsize = findsize(firstword);
	 int secondwordsize = findsize(secondword);
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
	 
	 for (int i = 0; i < stringsize - g * wordsdifference; i++) {
		// printf("g");
		 printf("%c", string[i]);
	 }
	 
 }
int main() {
	char first[1000] = { 0 };
	char secondword[1000] = { 0 };
	printf("enter first word: ");
	fgets(first, 1000, stdin);
	int firstwordsize = findsize(first);
	while (onlychars(first, firstwordsize) == 0) {
		for (int i = 0; i < 1000; i++) {
			first[i] = 0;
		}
		printf("enter first word: ");
		fgets(first, 1000, stdin);
		firstwordsize = findsize(first);
	}
	printf("enter second word: ");
	fgets(secondword, 1000, stdin);
	int secondsize = findsize(secondword);
	while (onlychars(secondword, secondsize) == 0) {
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
	int wordsCount;
	struct WordsArray_s WordList = formArray(string,&wordsCount);
	
	/*for (int l = 0; l < wordsCount; l++) {
		//printf("f");
		for (int j = 0; j < WordList.wordsLength[l]; j++) {
			printf("%c", WordList.words[l][j]);
		}
		printf("\n");
	}*/
	printf("sorted string: \" ");
	for (int i = 0; i < wordsCount; i++) {
		//printf("peredano %d ", i);
		sort(WordList.words[i], first, secondword,WordList.wordsLength[i]);
		printf(" ");
	}
	printf("\"");
	return 0;
}