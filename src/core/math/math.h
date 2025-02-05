#pragma once
#include <stdlib.h>
#include <math.h>
#include "core/core.h"

/// it's pi
const double ST_PI = 3.141592653589793238463;

/// returns a random integer equal or greater than the min parameter and less than the max parameter
int64 st_rand_int(int64 min, int64 max)
{
    return rand() % (max - min) + min;
}

/// returns a random unsigned integer equal or greater than the min parameter and less than the max parameter
uint64 st_rand_uint(uint64 min, uint64 max)
{
    return rand() % (max - min) + min;
}

/// returns a random float equal or greater than the min parameter and less than the max parameter
float64 st_rand_float(float64 min, float64 max)
{
    float64 scale = rand() / (float64)RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );
}

/// returns a random character equal or greater than the min parameter and less than the max parameter
char st_rand_char(char min, char max)
{
    return rand() % (max - min) + min;
}

/// converts degrees to radians
float64 st_deg2rad(float64 deg)
{
    return deg * (ST_PI / 180);
}

/// converts radians to degrees
float64 st_rad2deg(float64 rad)
{
    return rad * (180 / ST_PI);
}

/// returns a random base64 string (-_ instead of +=) with the specified length
char* st_rand_base64(nint len)
{
    // this is probably busted
    /*char* str[len + 1];

    for (nint i = 0; i < len; i++) {
        uint64 type = st_rand_uint(0, 5);
        switch (type) {
            case 0: str[i] = (char*)st_rand_char('a', 'z' + 1); break;
            case 1: str[i] = (char*)st_rand_char('A', 'Z' + 1); break;
            case 2: str[i] = (char*)st_rand_char('0', '9' + 1); break;
            case 3: str[i] = (char*)'-'; break;
            case 4: str[i] = (char*)'_'; break;
        }
    }
    // mate
    str[len] = '\0';
    return str;*/
    return "nah";
}