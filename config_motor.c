/*
 * File:   motor_de_passo.c
 * Author: 20185087
 *
 * Created on 20 de Maio de 2021, 15:51
 */

#include "config.h"
#include "delay.h"
#include <xc.h>

char unipasso[4] = {0x08, 0x04, 0x02, 0x01 };
char meipasso[8] = {0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09};
int ppr;

void motor_init(int passos_motor) 
{

    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    
    PORTDbits.RD0 = 0;
    PORTDbits.RD0 = 0;
    PORTDbits.RD0 = 0;
    PORTDbits.RD0 = 0;
    
    ppr = passos_motor;
    
}

void motor(int graus, int sentido, unsigned int t )
{    
    int i;
    long passo = ((graus*ppr)/360); 
    int y = passo/4;
    
    
    if(sentido == 1)
    {
        while(y)
        {
            for(i=0; i<4; i++)
            {
                PORTD = unipasso[i];
                delay(t);
            }
            y--;
        }
    }
    
    
    if(sentido == 0)
    {
        while(y)
        {
            for(i=3; i<=0; i--)
            {
                PORTD = unipasso[i];
                delay(t);
            }
            y--;
        }
    
    }
}

