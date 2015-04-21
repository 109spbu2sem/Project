#include "core.h"
#include "gui.h"
#include "storages\storage_array.h"
#include "storages\storage_list.h"

int main()
{
	CORE testcore;
	GUI testgui(&testcore);
	testcore.Connect(&testgui, 0);
	testgui.show();
	return 0;
}
