#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_RPM 7000
#define MIN_RPM 800
#define MAX_THROTTLE 100
#define MIN_THROTTLE 0
#define MAX_TEMP 120  //c
#define MIN_TEMP 20   //c

typedef struct {
    int rpm;
    int throttle;
    float engine_temp;
    float fuel_injection_time;
    float ignition_timing;
    bool error_flag;
} EngineData;

void read_sensors(EngineData *engine) {
    engine->rpm = rand() % (MAX_RPM - MIN_RPM + 1) + MIN_RPM;  
    engine->throttle = rand() % (MAX_THROTTLE + 1);
    engine->engine_temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
}

float calculate_fuel_injection(int rpm, int throttle) {
    float base_injection = 2.5; //ms

    if (rpm > 5000) {
        base_injection += 1.5;
    } else if (rpm > 3000) {
        base_injection += 1.0;
    } else if (rpm > 1500) {
        base_injection += 0.5;
    }

    float throttle_factor = (float)throttle / MAX_THROTTLE; 
    base_injection *= (1.0 + throttle_factor * 0.6);

    return base_injection;
}

//calculate ignition timing before tdc
float calculate_ignition_timing(int rpm) {
    float base_timing = 10.0;

    if (rpm > 6000) {
        base_timing = 15.0;
    } else if (rpm > 4000) {
        base_timing = 12.0;
    } else if (rpm > 2000) {
        base_timing = 8.0;
    }

    return base_timing;
}

//error handling
bool check_engine_status(EngineData *engine) {
    if (engine->engine_temp > MAX_TEMP) {
        printf("Engine overheating. Temp: %.2f°C\n", engine->engine_temp);
        return true;
    }
    if (engine->rpm > MAX_RPM) {
        printf("RPM limit exceeded. RPM: %d\n", engine->rpm);
        return true;
    }
    return false;
}

int main() {
    EngineData engine;
    
    for (int i = 0; i < 5; i++) {  //5 cycle sim
        printf("\n----- Engine Cycle %d -----\n", i + 1);
        
        read_sensors(&engine);

        engine.fuel_injection_time = calculate_fuel_injection(engine.rpm, engine.throttle);
        engine.ignition_timing = calculate_ignition_timing(engine.rpm);

        engine.error_flag = check_engine_status(&engine);

        printf("RPM: %d\n", engine.rpm);
        printf("Throttle: %d%%\n", engine.throttle);
        printf("Engine Temperature: %.2f°C\n", engine.engine_temp);
        printf("Fuel Injection Time: %.2f ms\n", engine.fuel_injection_time);
        printf("Ignition Timing: %.2f° BTDC\n", engine.ignition_timing);

        if (engine.error_flag) {
            printf("error\n");
        }
    }

    return 0;
}
