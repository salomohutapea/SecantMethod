#include <stdio.h>
#include <tgmath.h>
#include <math.h>

float f(float x)
{
    return(pow(1.5, x) - 5);
}

float main()
{
    float a,b,c,d,e;
    int count=1;
    printf("\n\nMasukkan X0 dan X1:\n");
    scanf("%f%f",&a,&b);
    printf("Masukkan batas RAE:\n");
    scanf("%f %d",&e);
    do
    {
        if(f(a)==f(b)) {
            printf("\nTidak ada solusi\n");
            return 0;
        }
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        a=b;
        b=c;
        printf("\nIterasi ke-%d    x = %f\n",count,c);
        printf("RAE pada iterasi ke-%d is %f", count, fabs(f(c)));
        count++;
        if(count==10000)
        {
            break;
        }
        printf("\n");
    } while(fabs(f(c)) > e);
    printf("\nAfter %d iterations, root = %8.6f\n",count-1,c);
}