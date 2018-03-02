#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265


int main()
{


    printf("Welcome to G3OM3TRY. Type 1 to calculate Area or type 2 to calculate Volume \n");
        int v;
        scanf("%d", &v);

        if (v==1){
                int n2d;
            printf("Calculate the area of 2d objects. Press 3 for triangle, 4 for quadrilaterals, 5 for pentagon or 6 for hexagon  \n");
                scanf("%d", &n2d);

                if (n2d==3){
                    int vT;
                    printf("Choose the method for calculating the area: 1 for (b*h)/2; 2 for Heron's Formula; 3 With an angle and both adjacent sides \n"); //add method by angle
                        scanf("%d", &vT);

                        if (vT==1){
                            float b, h, A;
                            printf("Type in the base of the triangle \n"); scanf("%f", &b);
                            printf("Type in the height of the triangle \n"); scanf("%f", &h);
                                A=(b*h)/2;
                            printf("Area=%.4f", A);
                            return 0;
                        }

                        else if (vT==2){
                            float a, b, c, sp, A;
                            printf("Type in the values of the three sides of the triangle \n"); scanf("%f %f %f", &a, &b, &c);
                                sp=(a+b+c)/2;
                                A=sqrt(sp*(sp-a)*(sp-b)*(sp-c));
                            printf("Area=%.4f", A);
                            return 0;
                        }

                        else if (vT==3){
                            float s1, s2, an, A;
                            printf("Type in the values of both adjacent sides \n"); scanf("%f %f", &s1, &s2);
                            printf("Type in the angle between both sides in degrees \n"); scanf("%f", &an);
                                A=(((s1*s1)/2)*(sin(an*PI/180)));
                            printf("Area=%.4f", A);
                            return 0;
                        }



                }

                if (n2d==4){
                    int vSq;
                    printf("Choose the desired quadrilateral: 1 for parallelogram; 2 for trapezoid; 3 for kite \n");
                        scanf("%d", &vSq);

                        if (vSq==1){
                            float b, h, A;
                            printf("Type in the height and the base of the parallelogram \n"); scanf("%f %f", &h, &b);
                                A=b*h;
                            printf("Area=%.4f", A);
                            return 0;
                        }

                        else if (vSq==2){
                            float b1, b2, h, A;
                            printf("Type in base 1 and base 2 of the trapezoid \n"); scanf("%f %f", &b1, &b2);
                            printf("Type in the height \n"); scanf("%f", &h);
                                A=((b1+b2)/2)*h;
                            printf("Area=%.4f", A);
                            return 0;
                        }

                        else if (vSq==3){
                            float d, D, A;
                            printf("Type in the diagonals of the kite \n"); scanf("%f %f", &d, &D);
                                A=(d*D)/2;
                            printf("Area=%f", A);
                            return 0;
                        }




                }

                if (n2d==5){
                    int vPe;
                    printf("Calculate the area of a pentagon \n");
                }


        }

        else if (v==2){
            printf("Calculate the volume of 3d objects.  \n");

            return 0;
        }

        else ((v!=2)||(v!=1));{
            printf("Please type a valid number  \n");
        }




        return 0;
}
