#include <bits/stdc++.h>

using namespace std;

// quick inverse square root
double q_isqrt(double x) {
    double xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(double*)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
}

float InvSqrt(float x){
        float xhalf = 0.5f * x;
        int i = *(int*)&x;            // store floating-point bits in integer
        i = 0x5f3759df - (i >> 1);    // initial guess for Newton's method
        x = *(float*)&i;              // convert new bits into float
        x = x*(1.5f - xhalf*x*x);     // One round of Newton's method
        return x;
    }

int main(){

    const int operation = 100000000;

    int start = clock();
    for(int i = 0; i<operation; i++){
        double x = 1.0/sqrt(i);
    }
    int end1 = clock();
    for(int i = 0; i<operation; i++){
        double x = q_isqrt(i);
    }
    int end2 = clock();

    cout << "quick inverse square root for " << operation << " times: " << (end2-end1)/double(CLOCKS_PER_SEC) << " seconds" << endl;
    cout << "1/sqrt for " << operation << " times: " << (end1-start)/double(CLOCKS_PER_SEC) << " seconds" << endl;

    return 0;
}