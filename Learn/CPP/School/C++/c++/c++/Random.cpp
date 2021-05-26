#include "Random.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

/*void Random::Get_Random(int Rand) {
	for (int i = 0; i < Rand; i++) {
		rand();
	}
}*/

Random::Random() {
	srand((unsigned)time(NULL));
	r = 0;
}

int Random::next() {
	return rand();
}

int Random::nextlnRange(int RS, int RE) {
	int RandSum;
	RandSum = next() % RE + RS;
	return RandSum;
}