#include <iostream>
#include <fstream>
#define FIN "euclid3.in"
#define FOUT "euclid3.out"

struct pair {

       long x, y;

       pair(long _x, long _y): x(_x), y(_y) {}
};

typedef unsigned int nat;

pair extended_euclid(long a, long b) {

     pair prev(1,0),
          curr(0,1);

     while(b){

          long q = a / b;
          long r = a % b;

          pair old = curr;

               curr.x = prev.x - q * curr.x;     
               curr.y = prev.y - q * curr.y;

               prev = old;
               a = b;
               b = r; 
     } 

     return prev;      
}

int main(int argc, char **argv) {

    std::ifstream fin(FIN); 
    std::ofstream fout(FOUT); 

    nat n;
    fin>>n;
    long a, b, c;

    for(nat i = 0; i < n; ++i) {

        fin>>a>>b>>c;

        pair sol = extended_euclid(a, b);
 
        long gcd = a * sol.x + b * sol.y; 

        if(c % gcd != 0) {
 
           fout<<0<<" "<<0<<"\n";  

        } else {

           fout<<sol.x * (c / gcd)<<" "<<sol.y  * (c / gcd)<<"\n";
        }
        
    }


return(0);
}
