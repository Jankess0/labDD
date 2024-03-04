#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define lp 1000

double c_od,c_do;

double f3(double x)
{
 return -1;      
}      
double f4(double x) {

 return 1;
}


double prostokaty(double( *f)(double))
{
       double krok, p, suma=0;
       int i =0;
       krok=(c_do-c_od)/lp;
       for(p=c_od; p<c_do; p+=krok)
       {
               suma+=(*f)((p+p+krok)/2);
               i++;
       }
        suma*=krok;
       return suma;      
}

double trapezy(double (*f)(double))
{
        double krok, p, pole=0;
        krok=(c_do-c_od)/lp;
        pole=0.5*((*f)(c_od)+(*f)(c_do));
        for(p=c_od+krok;p<c_do;p+=krok)
                pole+=(*f)(p);
        pole*=krok;
return pole;
}
       
double mc(double(*f)(double))
{
       double fmax= 0, fmin=0, ff, x, y, krok, pole=0, T=0, suma;
       int n=1000;
       srand(time(NULL));
        krok=(c_do-c_od)/lp;
        for(x=c_od; x<=c_do; x+=krok)
        {
                ff=(*f)(x);
                if(ff>fmax) fmax=ff;
                else
                if(ff<fmin) fmin=ff;
        }
        for (int i=0; i<n; i++)
        {
                x=((double)rand() / RAND_MAX) * (c_do - c_od) + c_od;
                y=((double)rand() / RAND_MAX) * (fmax - fmin) + fmin;
                if(y>0&&(*f)(x)>y) T++;
                else
                if(y<0&&(*f)(x)<y) T--;
        }
        pole=(c_do-c_od)*(fmax-fmin);
        suma=pole*T/n;

 return suma;
}

