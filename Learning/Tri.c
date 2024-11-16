#include <stdio.h>
#include <math.h>

int main ()
{

    double A;
    double B;
    double C;

    printf("enter side A: ");
    scanf("%lf" ,&A);

    printf("enter side B: ");
    scanf("%lf" ,&B);

    C = sqrt(A*A + B*B); //hypotenuse

    printf("side C: %lf" ,C);

    return 0;
}