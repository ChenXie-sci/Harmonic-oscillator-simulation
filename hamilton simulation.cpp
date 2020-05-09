//
//  main.cpp
//  hamilton
//
//  Created by Chen Xie on 2019/10/3.
//  Copyright © 2019 Chen Xie. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <random>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::default_random_engine e;
    std::normal_distribution<double> d(6,2);
    std::normal_distribution<double> n(0,1);
    std::vector<unsigned> vals(20000);
    int i,j,m;
    double wc=2,wmax=10,N=20;
    double M=1e-23,t=273,k=1.38e-23,q=0,H[20],h=0;
    double w[20];
    w[0]=wc*(1-exp(-wmax/wc))/N;
          for (i=1;i<20;i++){
              w[i]=-wc*log(1-i*w[0]/wc);
           //   printf("%f \n",w[i]);
          }
    for(std::size_t i=0;i!=1000000000;++i){
        for (m=0;m<20;m++){
        double  v=std::lround(n(e));
         double r=std::lround(d(e));
               H[m]=0.5*v*v+0.5*w[m]*w[m]*r*r;
            h+=H[m];
        }
     //  printf("%f \n",h);
      if(h<vals.size()){
           ++vals[h];}
        h=0;
        }
    for(std::size_t m=0;m!=vals.size();++m){
        std::cout<<vals[m]<<std::endl;
    }
    return 0;
}
