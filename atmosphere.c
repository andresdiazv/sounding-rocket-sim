# print temperature, pressure, airdensity from 0m to 11000m in 500m steps

#include <stdio.h>
#include <math.h>

int main(void)
{
    #define LOWER 0
    #define UPPER 11000
    #define STEPS 500
    

    int height_m; // height in meters

    for (height_m = LOWER; height_m <= UPPER; height_m += STEPS)
    {
        /*formula for temperature
        y = mx + b
        y = temperature (dependent variable)
        m = Coeficient, Rate and Slope of Line (Growth)
        x = independent variable
        b = y-intercept, where line crosses the y-axis
        */ 
    }

    return 0;
}