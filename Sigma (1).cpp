
#include <iostream>
#include <math.h>
using namespace std;

   int main() {
       
        int n ;
        int m ;
        cin>>n;
        cin>>m;
        int sum = 0;
        int temp = 0;

        if(n < 0 ||m > 10)
            return 0;

        for (int i = -10; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if(j == 0)
                    continue;

                temp=(i+j)*(i+j)*(i+j);
                sum += temp /(j*j);
            }
        }

       cout<<sum;


    

}