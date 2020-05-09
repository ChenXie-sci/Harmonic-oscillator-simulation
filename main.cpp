//
//  main.cpp
//  count
//
//  Created by Chen Xie on 2019/10/2.
//  Copyright © 2019 Chen Xie. All rights reserved.
//
    #include <iostream>
    #include <cmath>
    #include <random>
    using namespace std;
    int main() {
        // insert code here...
        std::default_random_engine e;
        std::normal_distribution<double> d1(6,2);
        std::normal_distribution<double> n1(0,1);
        std::normal_distribution<double> d2(5,1);
        std::normal_distribution<double> n2(0,2);
        double r1[100000],v1[100000],r2[100000],v2[100000];
        double H[100000],p[100000];
        int i,j,m,f,g;
        double M=1e-23;
        double wc=2,wmax=10,N=20,w0;
        double w[20];
        double t=273,k=1.38e-23;
        double q=0;
        w0=wc*(1-exp(-wmax/wc))/N;
        for (i=0;i<20;i++){
            w[i]=-wc*log(1-i*w0/wc);
        }
        for (i=0;i<100000;i++){
            r1[i]=std::lround(d1(e));
            r2[i]=std::lround(d2(e));
       // printf("%f    %f\n",r1[i],r2[i]);
        }
        for (j=0;j<100000;j++){
            v1[j]=(n1(e));
            v2[j]=(n2(e));
            printf("%f    %f\n",v1[j],v2[j]);
        }
        for (m=0;m<100000;m++){
H[m]=0.5*M*v1[m]*v1[m]+0.5*w[1]*w[1]*M*r1[m]*r1[m]+0.5*M*v2[m]*v2[m]+0.5*w[2]*w[2]*M*r2[m]*r2[m];
        }
        for (f=0;f<100000;f++){
               q+=exp(-H[f]/(k*t));
           }
           for (g=0;g<100000;g++){
               p[g]=exp(-H[g]/(k*t))/q;
            //   printf("%f     %f\n",H[g]*1e23,p[g]);
           }
    return 0;
}
