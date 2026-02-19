#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	float a = 0 , b = 0;
	cin>>a >> b;
	int n = 0;
	cin>> n;
	printf("%.*f" , n , a/b);
	return 0;
}