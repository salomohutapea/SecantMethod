#include <stdio.h>
#include <math.h>

float f(float x)
{
    return(pow(1.5, x) - 5);
}

float main()
{

    float a = 10, b = 8, c, e = 0.01, rae;
    int itr=1;

    do
    {
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        rae = fabs((b - a) / b);
        printf("\nIteration no-%d    x = %f\n",itr,c);
        printf("RAE in iteration no-%d is %f", itr, rae);
        itr++;
        printf("\n");
    } while(rae > e);

    printf("\nAfter %d iterations, root = %f\n",itr-1,c);

    return 0;
}
