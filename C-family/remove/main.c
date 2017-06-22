#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char prefix[128] = "./ws.in";
	for (int i = strlen(prefix); i < 127; i++)
		prefix[i] = rand()%26 + 'a';
	prefix[127] = '\0';
	for (int i = 0; i < 200000; i++) {
		char path[256];
		sprintf(path, "%s%02d", prefix, i);
		FILE *fout = fopen(path, "w");
		if (fout == NULL) {
			fprintf(stderr, "Write failed\n");
			exit(1);
		}
		fprintf(fout, "hello %d\n", i);
		fclose(fout);
	}
	return 0;
}
