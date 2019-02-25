#include <stdio.h>
#include <math.h>
#include <time.h>

float f(float x)
{
    return(pow(1.5, x) - 5);
}

float main()
{
    double time_spent = 0.0;
    clock_t begin = clock();

    float a = 10, b = 8, c, e = 0.01, rae;
    int itr=1;

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

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime elpased is %f seconds", time_spent);
    return 0;
}