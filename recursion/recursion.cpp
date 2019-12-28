#include<bits/stdc++.h>
using namespace std;

int recur(int i){
	if(i > 1){
		recur(i/2);
//		recur(i/2);
	}
	cout << "*";
}

int main(int argc, char* argv[]){
	string arg(argv[1]);
	recur(std::stoi(arg));
	return 0;
}

// c++ -std=c++11 -o recursion recursion.cpp
