#include "time.h"


void TIM_CONF()   //APB2  72M
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    /* 使能时钟 */
    RCC_APB2PeriphClockCmd ( SYS_RCC_TIMx, ENABLE );

    TIM_DeInit ( SYS_TIMx );

    /* 自动重装载寄存器周期的值(计数值) */
    TIM_TimeBaseStructure.TIM_Period = 25000-1;

    /* 累计 TIM_Period个频率后产生一个更新或者中断 */
    /* 时钟预分频数为72 */
    TIM_TimeBaseStructure.TIM_Prescaler = 72 - 1;

    /* 对外部时钟进行采样的时钟分频,这里没有用到 */
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;

    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	
	 //高级定时器需要设置
		TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;//重复计数设置

    TIM_TimeBaseInit ( SYS_TIMx, &TIM_TimeBaseStructure );

    TIM_ClearFlag ( SYS_TIMx, TIM_FLAG_Update );

    TIM_ITConfig ( SYS_TIMx, TIM_IT_Update, ENABLE );


    TIM_Cmd ( SYS_TIMx, ENABLE );

    RCC_APB2PeriphClockCmd (  SYS_RCC_TIMx , DISABLE );		/*先关闭等待使用*/
}
void TIM_NVIC()
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = SYS_TIMx_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = NVIC_TIME_P;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = NVIC_TIME_S;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init ( &NVIC_InitStructure );
}

void TIM_INIT()
{
    TIM_CONF();
    TIM_NVIC();
    /* TIM2 重新开时钟，开始计时 */
    RCC_APB2PeriphClockCmd ( SYS_RCC_TIMx , ENABLE );
}


volatile uint32_t sysTickUptime = 0;

void  SysTick_Configuration ( void )
{

    uint32_t         cnts;

    cnts = SystemCoreClock / TICK_PER_SECOND;
    cnts = cnts / 8;

	
    SysTick_Config ( cnts );
    SysTick_CLKSourceConfig ( SysTick_CLKSource_HCLK_Div8 );
}

uint32_t GetSysTime_us ( void )
{
    register uint32_t ms;
    u32 value;
	do
	{
    ms = sysTickUptime;
    value = ms * TICK_US + ( SysTick->LOAD - SysTick->VAL ) * TICK_US / SysTick->LOAD;
	}
	while(ms != sysTickUptime);
	return value;
}

void Delay_us ( uint32_t us )
{
    uint32_t now = GetSysTime_us();
    while ( GetSysTime_us() - now < us );
}

void Delay_ms ( uint32_t ms )
{
    while ( ms-- )
        Delay_us ( 1000 );
}

u32 systime_ms;

void sys_time()
{
	systime_ms++;
}
u32 SysTick_GetTick(void)
{
	return systime_ms;
}



u32 Get_Delta_T(_get_dT_st *data)
{
    data->old = data->now;	//上一次的时间
    data->now = GetSysTime_us(); //本次的时间
    data->dT = ( ( data->now - data->old ) );//间隔的时间（周期）
	
	if(data->init_flag == 0)
	{
		data->init_flag = 1;//第一次调用时输出 0 作为初始化，以后正常输出
		return 0;
	}
	else
	{
    return data->dT;
	}
}

void SysTick_Handler(void)
{
	sysTickUptime++;
	sys_time();

}




