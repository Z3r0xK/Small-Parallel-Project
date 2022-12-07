#include<iostream>
#include<omp.h>
#include<cmath>
using namespace std;

/*
                    =====================Explination================
    if we have num = 56 we first start check primes from 2 until reach to this number. 
    
    *! first if we have even number then it must divided by 2 in first while loop we deal with this case

    *! secound before this while loop then our number become odd b/c we extract all 2s in it (in first while), for this resone in for loop (i = i + 2)  becouse we need skip all even numbers 

    *! third in internal while loop, we do the algorithm of find prime factors (little math)

    *! final and after all of that if n still greater than 2 it must be prime the last condition handel that.
                    =============== End of Expliation ================    

*/
void primeFactors(long long n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
    int num =  sqrt(n); // 1000
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 3; i <=  num; i = i + 2)
    {
        #pragma omp critical
        while (n % i == 0)
        {
            cout << i << " ";    
            n = n/i;
        }
    }

    if (n > 2)
        cout << n << " ";
}


int main(){

    long long num = 600525545234125;
    double start , end;
    
    primeFactors(num);

    return 0;
}