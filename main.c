/*
 * File:   main.c
 * Author: 20185087
 *
 * Created on 20 de Maio de 2021, 15:50
 */

//============================================================================//

#include "config.h"
#include "delay.h"
#include "config_motor.h"
#include <xc.h>


void main(void) 
{
    motor_init(32);

    
    {    
        motor(360,0,100); //void motor( int graus, int sentido, unsigned int t )
        motor(180,1,100);
    }

    return;
}
//============================================================================//