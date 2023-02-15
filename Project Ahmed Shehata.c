#include<stdio.h>
#include<math.h>
#include<chplot.h>

void TrajPlot(float,float,float,float,float,float);
void WindTrajPlot(float,float,float,float,float,float,float);

float Vo,Voy,Voz,theta,A,Vx,Vy,Vz,g=9.81;
double x,y,z,T,Thmax,Ttotal,Zo,Xo,Yo;

void main()

{
    char Option;
    
        printf("Please select one of the following options: \n A, a, or 1 to plot projectile trajectory without wind \n B, b, or 2 to plot projectile trajectory with wind speed A\n");
        scanf("%c",&Option);
    
    while(1)
    {
        if(Option!='1' && Option!='2' && Option!='A' && Option!='a' && Option!='B' && Option!='b')
        {
            printf("Please select a valid option.\n");
            scanf(" %c",&Option);
        }
            else {break;}
    }

        switch (Option)
            {
                case 'A': case 'a': case '1': 
                    
                    printf("Please enter initial velocity, Vo, launch angle theta in degrees, and initial displacements Xo, Yo, and Zo. \n");
                    scanf("%f%f%f%f%f", &Vo,&theta,&Xo,&Yo,&Zo);
                    TrajPlot(Vo,theta,Xo,Yo,Zo,T);
                    break;
                    
                case 'B': case 'b': case '2': 
                     
                                        
                    printf("Please enter initial velocity, Vo, launch angle theta in degrees, wind speed +-A, and initial displacements Xo, Yo, and Zo. \n");
                    scanf("%f%f%f%f%f%f", &Vo,&theta,&A,&Xo,&Yo,&Zo);
                    WindTrajPlot(Vo,theta,A,Xo,Yo,Zo,T);
                    break;
                
                default:
                        printf("Please choose a valid option.\n");
                        scanf (" %c",&Option);
                        break;

            }
}

void TrajPlot(float Voo,float Theta,float Xoo,float Yoo,float Zoo,float t)
{
    Vx=0;
    Voy=Voo*cos(Theta*3.1416/180);
    Voz=Voo*sin(Theta*3.1416/180);
    Thmax=Voz/g;
    Ttotal=2*Thmax;
    
    x=Xoo+Vx*Ttotal;
    y=Yoo+Voy*Ttotal;
    z=(Zoo+Voz*Thmax)-(0.5*g*Thmax*Thmax);
    
    int i,N;
    
    printf("Please enter number of plot points N such that N>0\n");
    scanf("%d",&N);
    while (N<=0) 
    {
        printf("Please re-enter number of plot points N such that N>0\n");
        scanf("%d",&N);
    }
    
    printf("\nThe maximum height attained by the object = %lf m \nThe maximum traveled distance in x-direction = %lf m \nThe maximum traveled distance in y-direction = %lf m \n" ,z,x,y);
    
    float x[N],y[N],z[N],t[N];
    
    lindata(0,Ttotal,t,N);
    
    for(i=0;i<N;i++)
    {
        x[i]=Xoo+Vx*t[i];
        y[i]=Yoo+Voy*t[i];
        z[i]=(Zoo+Voz*t[i])-(0.5*g*t[i]*t[i]);
    }
    
    plotxyz(x,y,z);
}

void WindTrajPlot(float Voo,float Theta,float AA,float Xoo,float Yoo,float Zoo,float t)
{
    Vx=AA;
    Voy=Voo*cos(Theta*3.1416/180);
    Voz=Voo*sin(Theta*3.1416/180);
    Thmax=Voz/g;
    Ttotal=2*Thmax;
    
    x=Xoo+Vx*Ttotal;
    y=Yoo+Voy*Ttotal;
    z=(Zoo+Voz*Thmax)-(0.5*g*Thmax*Thmax);
    
    int i,N;
    
    printf("Please enter number of plot points N such that N>0\n");
    scanf("%d",&N);
    while (N<=0) 
    {
        printf("Please re-enter number of plot points N such that N>0\n");
        scanf("%d",&N);
    }
    
    printf("\nThe maximum height attained by the object = %lf m \nThe maximum traveled distance in x-direction = %lf m \nThe maximum traveled distance in y-direction = %lf m \n" ,z,x,y);
    
    float x[N],y[N],z[N],t[N];
    
    lindata(0,Ttotal,t,N);
    
    for(i=0;i<N;i++)
    {
        x[i]=Xoo+Vx*t[i];
        y[i]=Yoo+Voy*t[i];
        z[i]=(Zoo+Voz*t[i])-(0.5*g*t[i]*t[i]);
    }
    
    plotxyz(x,y,z);
}
