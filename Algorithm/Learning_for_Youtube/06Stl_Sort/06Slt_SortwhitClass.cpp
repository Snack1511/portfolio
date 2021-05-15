#include<iostream>
#include<algorithm>

using namespace std;

/*
	template<typename T>
	sort(T start, T end)
	template<typename T>
	sort(T start, T end, Compare comp)
	
	<algorithm>헤더에 속해있다.
	 start ~ end 범위의 인자를 Compare를 적용해 정렬
	 Compare greater<자료형>() --> 내림차순 Compare
	 Compare less<자료형>() -----> 오름차순 Compare  --> default
	 Compare는 사용자정의 함수 적용 가능 

*/

class MyData{
	private:
		int l;
		int m;
		int n;
		
	public:
		MyData(int _l, int _m, int _n){
			this -> l = _l;
			this -> m = _m;
			this -> n = _n;
			
		}
		int sum(){
			return(this -> l + this -> m + this -> n);
		}
		
		operator < (MyData &data){
			return (this->sum() < data.sum());
		}
		
		void print(){
			cout << this -> l << " " << this -> m << " " << this -> n << " ---> sum : " << this -> sum() <<endl;
		} 
};

/*
	위와 같이 클래스를 정의 해서 정렬하는 경우는 실무에 적합한 방식이라고 한다.
	코딩 테스트 같은 급박한 시간 및 한정적인 환경에서는 pair라는 라이브러리 함수를 사용하는 것이 더 적절하다고 한다.
*/

bool compare_Desc (int a, int b){
	return (a > b);
}

bool compare_Asc (int a, int b){
	return (a < b);
}
// 이런식으로도 정의 후 적용 가능 

int main(){
	int arr[10] = {2, 3, 5, 6, 9, 10, 7, 8, 1, 4};
	sort(arr, arr+10, compare_Asc);
	for(int i = 0; i < 10; i++){
		cout << arr[i]<< " ";
	}
	cout  << endl;
	
	
	MyData DataArr[5] = {
		MyData(1, 5, 9),
		MyData(5, 3, 2),
		MyData(6, 8, 7),
		MyData(9, 2, 1),
		MyData(5, 4, 3)
	};
	
	sort(DataArr, DataArr+5);
	
	
	
	for(int i = 0; i < 5; i++){
		DataArr[i].print();
	}
	
	return 0;
}
