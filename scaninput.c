#include<stdio.h>


int main() {
	char input[5];
	while(1) {
		scanf("%s", input);
		if (input[0] == 'u') printf("go in the undo routine\n");
		if (input[0] != 'u') {
			// Process this as a normal move
			printf("This is a normal move\n");
			int start_column = input[0] - 'a';
			int start_row = 8 - (input[1] - '0');
			//printf("at position (3, 4) we have (%c, %c)\n", input[2], input[3]);
			int end_column = input[2] - 'a';
			int end_row = 8 - (input[3] - '0');
			printf("We are moving row (%d %d) to (%d %d)\n", start_column, start_row, end_column, end_row);
		}
	}
	return 0;
}
