#include <stdio.h>
#include <math.h>

#define LOWER 0
#define UPPER 11000
#define STEPS 500

#define SEA_LVL_STD_TEMP 288.15 // K
#define SEA_LVL_STD_ATM_PRESSURE 101325 // Pa
#define TEMP_LAPSE_RATE 0.0065 // K/m
#define EARTH_SURF_GRAV_ACC 9.80665 // m/s^2
#define MOLAR_MASS_DRY_AIR 0.0289652 // kg/mol
#define IDEAL_GAS_CONST 8.31446 // J/(mol * K)

int main(void)
{
    int height_m; // height/altitude in meters
    double pressure_exp = (EARTH_SURF_GRAV_ACC * MOLAR_MASS_DRY_AIR) / (IDEAL_GAS_CONST * TEMP_LAPSE_RATE);
    double density_exp = pressure_exp - 1;
    double density_sea_lvl = (SEA_LVL_STD_ATM_PRESSURE * MOLAR_MASS_DRY_AIR) / (IDEAL_GAS_CONST * SEA_LVL_STD_TEMP);

    printf("%8s %15s %19s %11s\n", "Temperature", "Pressure", "Density", "Altitude");
    printf("----------------------------------------------------------------\n");

    for (height_m = LOWER; height_m <= UPPER; height_m += STEPS)
    {
        double temperature = SEA_LVL_STD_TEMP - (TEMP_LAPSE_RATE * height_m);
        double temp_ratio = 1 - ((TEMP_LAPSE_RATE * height_m) / SEA_LVL_STD_TEMP);
        double pressure = SEA_LVL_STD_ATM_PRESSURE * pow(temp_ratio, pressure_exp);
        double density = density_sea_lvl * pow(temp_ratio, density_exp);
        printf("%10.2fC\t%9.2fPa\t%9.4fkg/m^3\t%10dm\n", (temperature - 273.15), pressure, density, height_m);
    }

    return 0;
}