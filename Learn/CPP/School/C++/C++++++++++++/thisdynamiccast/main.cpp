#include "sample.h"

int main() {
	sample s(10); // 10개 정수 배열을 가진 Sample 객체 생성
	s.read(); // 키보드에서 정수 배열 읽기
	s.write(); // 정수 배열 출력
	cout << "가장 큰 수는 " << s.big() << endl; // 가장 큰 수 출력
}