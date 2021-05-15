#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b){
	if (a.second != b.second){
		return a.second < b.second;
	}
	else{
		return a.first < b.first;
	}
}

int main(){
	int n;
	cin >> n;
	vector<pair<string, int> > v;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		
		v.push_back(pair<string, int>(s, s.size()));
	}
	sort(v.begin(), v.end(), compare);
	string comp;
	
	for(int m = 0; m < v.size(); m++){
		if(m != 0){

			comp = v[m-1].first;
			if(comp != v[m].first){
				cout << v[m].first << endl;
			}
		}
		else{
			cout << v[m].first << endl;
		}
	}
    return 0;
}
