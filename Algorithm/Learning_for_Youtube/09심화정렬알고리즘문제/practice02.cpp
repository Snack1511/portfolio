#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int Sum(string s){
	int n = s.length();
	int result = 0;
	for(int i = 0; i < n; i++){
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			result += s[i]-'0';
		}
	}
	return result;
}

/*
int Sum(string s){
	int n = s.length();
	int result = 0;
	for(int i = 0; i < n; i++){
		if((int)s[i] > 47 && (int)s[i] < 58)
		{
			result += s[i];
		}
	}
	return result;
}
*/
//int 48 -> 0
//int 57 -> 9

bool compare(string a, string b){
	if(a.length() != b.length()){
		return a.length() < b.length();
	}
	else{
		int aSum = Sum(a);
		int bSum = Sum(b);
		if(Sum(a) != Sum(b)){
		
			return aSum<bSum;
		}
		else{
			return a<b;
		}
	}
	
}

int main(){
	int n;
	cin >> n;
	vector<string> v;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0; i < n; i++){
		cout  << v[i] << endl;
	}
    return 0;
}
