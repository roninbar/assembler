#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {
	// for each input file (*.as)
	//   for each line in the file
	//     while (not <eol>)
	//       get the next token
	int i;
	for (i = 1; i < argc; i++)
	{
		FILE *pFile;
		char fileName[100];
		char line[1000];
		sprintf(fileName, "%s.as", argv[i]);
		pFile = fopen(fileName, "r");
		if (pFile == NULL) {
			exit(ENOENT);
		}
		else {
			while (fgets(line, 1000, pFile)) {
				printf("%s", line);
			}
			fclose(pFile);
		}
	}
}