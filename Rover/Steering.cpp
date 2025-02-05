#include "Rover.h"

/*****************************************
    Set the flight control servos based on the current calculated values
*****************************************/
float time_accumulator = 0.0f;

void Rover::set_servos(void)
{
    // send output signals to motors
    if (motor_test) {
        motor_test_output();
    } else {
        // get ground speed
        float speed = 0.0f;
        g2.attitude_control.get_forward_speed(speed);

        
        
        float pitch = 0.0f;
        pitch = g2.attitude_control.get_pitch_water();
        
        
        
        g2.motors.output(arming.is_armed(), speed, G_Dt, pitch);
        
        
        
        
        
        
        
        
        time_accumulator += G_Dt;
         if (time_accumulator >= 1.0f) {
            // float pitch = ahrs.get_yaw();
            hal.console->printf("Pitch value: %f\n", pitch);

            // 重置時間累加器
            time_accumulator = 0.0f;
        }
    }
}
