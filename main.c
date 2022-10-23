#include "stm32f10x.h"

//  &= ~ 用来清0
//  |=  用来写1

void soft_delay( unsigned int count )
{
	for(; count!=0; count--);
}

int main(void)
{

	/* 配置RCC寄存器，使能GPIOC口的时钟 */
	*(unsigned int *)0X40021018 |= (1<<4);

	
	/* 配置CRL寄存器，GPIO2/3配置为推挽输出 */
	*(unsigned int *)0X40011000 |= ( 1<<(4*2) );
	*(unsigned int *)0X40011000 |= ( 1<<(4*3) );
	
	/* 配套ODR寄存器 */
	*(unsigned int *)0X4001100C &= ~( 1<<2 );
	*(unsigned int *)0X4001100C &= ~( 1<<3 );
	
	while(1)
	{
		*(unsigned int *)0X4001100C &= ~( 1<<2 );//开D4
		*(unsigned int *)0X4001100C |= ( 1<<3 );//关D5
		soft_delay(0xfffff);
		
		*(unsigned int *)0X4001100C |= ( 1<<2 );//关D4
		*(unsigned int *)0X4001100C &= ~( 1<<3 );//开D5
		soft_delay(0xfffff);
	}
	
}

void SystemInit(void)
{
	/* 函数体为空，目的是为了骗过编译器不报错 */
}


