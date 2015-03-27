#include "core.h"
#include "gui.h"

int main()
{
	CORE testcore;
	//while (1)
	{
		for (int i = 0; i < 120; i++)
		{
			testcore.AddObject(i, i + 1);
		}
	}
	return 0;
}
