#include <bits/stdc++.h>

using namespace std;

void foo(char *c){
	*c = 'a';//modify first char
}

int main(){
	char *s = "rohit"; //not a constant string
	foo(s);
	printf("%s", s);
	return 0;
}
