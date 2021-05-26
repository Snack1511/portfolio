#include "random.h"

int Random::nextInt(int min, int max) {
	return rand() % max + min;
}

char nextAlphabet() {
	char a = 0;
	int r = rand() % 122 + 65;
	if (r < 91 && r>96) {
		a = r;
	}
	else {
		nextAlphabet();
	}
	return a;
}

double Random::nextDouble() {
	return (double)rand() / 32767;
}