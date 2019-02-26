#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x)
{
    return(pow(1.5, x) - 5);
}

main()
{
    clock_t start = clock();
    double a = 10, b = 8, c, e = 0.01, rae;
    int itr=1;

    do
    {
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        rae = fabs((b - a) / b);
        printf("\nIteration no-%d    x = %f    f(x) = %f\n",itr,c, f(c));
        printf("RAE in iteration no-%d is %f", itr, rae);
        itr++;
        printf("\n");
    } while(rae > e);

    printf("\nAfter %d iterations, root = %f\n",itr-1,c);

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}
