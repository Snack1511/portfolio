#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
	아래와 같이 소스코드의 길이를 짧게 하는 것을 숏코딩(short Coding)이라고 한다.
	작성된 두 소스코드의 시간 복잡도가 같다면 소스코드가 짧을 수록 더 좋은 코드일 것이다.
	
	vector
	c++stl에 있는 컨테이너로 사용자가 손쉽게 사용하기 위해 정의된 클래스이다.
	가장 큰 장점은 동적으로 원소를 추가할 수 있고 그에따라 크기도 자동으로 변한다.
	속도측면에서는 배열에 밀리지만 메모리를 효율적으로 관리할 수 있다는 점에서 굉장히 많이 사용 된다고 한다.
	
	vector는 배열과 같이 원소들이 하나의 메모리 블록에 연속하게 저장된다.
	그렇기에 원소가 추가되거나 삽입될 때 메모리 재할당으로 상당한 부하가 발생할 수 있다는 점이 단점으로서 꼽힌다.
	
	tip : size vs. capacity
	size -> 원소의 개수
	capacity -> 할당된 공간의 크기
	나눠진 이유 : 앞서 언급했듯 벡터는 원소가 추가되거나 삽입될 시 메모리 재할당이 발생할 수 있다.
				  이에 따라 원소가 추가될 경우 차후 필요할 거라 예상되는 메모리 공간을 추가적으로 할당하는 방식으로 작동하는데 
				  이를 capacity로 알수 있다.
				  추가 할당 크기는 현재 capacity의 반만큼 추가된다. 
*/

bool compair_pairinpair(pair<string, pair<int, int> > a, 
						pair<string, pair<int, int> > b){
							
	if(a.second.first == b.second.first){
		return a.second.second < b.second.second;
	}
	else{
		return a.second.first < b.second.first;
	
	}
}

int main(){
	vector<pair<int, int> > v;
	v.push_back(pair<int, int> (1, 9)); 
	v.push_back(pair<int, int> (5, 3));
	v.push_back(pair<int, int> (8, 7));
	v.push_back(pair<int, int> (6, 1));
	v.push_back(pair<int, int> (4, 3));
	

	
	for(int i = 0; i < v.size(); i++) {
		cout <<v[i].first << " " << v[i].second << endl;
	}
	cout << "-----Sort------"<<endl;
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++) {
		cout <<v[i].first << " " << v[i].second << endl;
	}
	
	cout << "-------Pair< , Pair< , > >"<< endl;
	vector<pair<string, pair<int, int> > > v_pairinpair;
	v_pairinpair.push_back(pair<string, pair<int, int> >  ("first", pair<int, int> (1, 9))); 
	v_pairinpair.push_back(pair<string, pair<int, int> >  ("second", pair<int, int> (5, 3)));
	v_pairinpair.push_back(pair<string, pair<int, int> >  ("third", pair<int, int> (8, 7)));
	v_pairinpair.push_back(pair<string, pair<int, int> >  ("fourth", pair<int, int> (5, 1)));
	v_pairinpair.push_back(pair<string, pair<int, int> >  ("fifth", pair<int, int> (5, 2)));
	
	sort(v_pairinpair.begin(), v_pairinpair.end(), compair_pairinpair);
	
	for(int j = 0; j < v_pairinpair.size(); j++){
		cout << "string : " <<v_pairinpair[j].first << "  " <<
				 v_pairinpair[j].second.first << ", " << v_pairinpair[j].second.second << endl;
	}
	
	return 0;
}

/*
	코딩 테스트 같은 급박한 시간 및 한정적인 환경에서는 pair라는 라이브러리 함수를 사용하는 것이 더 적절하다고 한다.
	
	하지만 조건이 3개 이상이 되면 차라리 클래스를 구현하는게 더 효과적일 수도 있다고 한다.
*/


