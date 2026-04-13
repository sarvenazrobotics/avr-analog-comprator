#include <io.h>
#include <delay.h>

#define LED1(x) (x==1 ? (PORTB|=1<<0):(PORTB&=~(1<<0)));
#define LED2(x) (x==1 ? (PORTB|=1<<1):(PORTB&=~(1<<1)));
#define LED3(x) (x==1 ? (PORTB|=1<<2):(PORTB&=~(1<<2)));
#define LED4(x) (x==1 ? (PORTB|=1<<3):(PORTB&=~(1<<3)));
#define LED5(x) (x==1 ? (PORTB|=1<<4):(PORTB&=~(1<<4)));
#define LED6(x) (x==1 ? (PORTB|=1<<5):(PORTB&=~(1<<5)));

void main(void)
{
    DDRB=0xFF;
    ADCSRA=0;
    ADCSRB=(1<<ACME); //analog comprator multiplexer enable
    ACSR=0; 
    
    while(1)
    {
     ADMUX=0;
     delay_ms(2);
     LED1(!!(ACSR & (1<<ACO)));
    
    ADMUX=2;
    delay_ms(2);
    LED2(!!(ACSR & (1<<ACO)));
    
    ADMUX=3;
    delay_ms(2);
    LED3(!!(ACSR & (1<<ACO)));
    
    
    
    
    
    }
}