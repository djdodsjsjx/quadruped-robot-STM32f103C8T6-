#include "config.h" 

int main(void)
{	
	data_config();
	init_config();
	
	while(1)
	{
		Scheduler_Run();
	}
}
