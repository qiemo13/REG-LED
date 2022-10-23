#include "stm32f10x.h"

//  &= ~ ������0
//  |=  ����д1

void soft_delay( unsigned int count )
{
	for(; count!=0; count--);
}

int main(void)
{

	/* ����RCC�Ĵ�����ʹ��GPIOC�ڵ�ʱ�� */
	*(unsigned int *)0X40021018 |= (1<<4);

	
	/* ����CRL�Ĵ�����GPIO2/3����Ϊ������� */
	*(unsigned int *)0X40011000 |= ( 1<<(4*2) );
	*(unsigned int *)0X40011000 |= ( 1<<(4*3) );
	
	/* ����ODR�Ĵ��� */
	*(unsigned int *)0X4001100C &= ~( 1<<2 );
	*(unsigned int *)0X4001100C &= ~( 1<<3 );
	
	while(1)
	{
		*(unsigned int *)0X4001100C &= ~( 1<<2 );//��D4
		*(unsigned int *)0X4001100C |= ( 1<<3 );//��D5
		soft_delay(0xfffff);
		
		*(unsigned int *)0X4001100C |= ( 1<<2 );//��D4
		*(unsigned int *)0X4001100C &= ~( 1<<3 );//��D5
		soft_delay(0xfffff);
	}
	
}

void SystemInit(void)
{
	/* ������Ϊ�գ�Ŀ����Ϊ��ƭ�������������� */
}


