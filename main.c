#include <stdio.h>
#include <tgmath.h>
#include <math.h>

float f(float x)
{
    return(pow(1.5, x) - 5);
}

float main()
{
    float a, b, c, e, rae;
    int itr=1;

    printf("\n\nEnter X0 and X1:\n");
    scanf("%f%f",&a,&b);

    printf("Enter allowed RAE:\n");
    scanf("%f",&e);

    do
    {
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        rae = fabs((b - a) / b);
        printf("\nIteration no-%d    x = %f\n",itr,c);
        printf("RAE pada iterasi ke-%d is %f", itr, rae);
        itr++;
        printf("\n");
    } while(rae > e);

    printf("\nAfter %d iterations, root = %8.6f\n",itr-1,c);

    return 0;
}