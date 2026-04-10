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
    ADCSRB=(1<<ACME);
    ACSR=0;
}