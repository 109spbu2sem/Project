#include <iostream>
#include "storage_list.h"
#include "storage_array.h"
#include "structures.h"

int main()
{
	Storage_List<int> store;
	for (int i = 0; i < 10; i++)
	{
		store.add(i);
	}
	ListViewer<int> v(store);
	while (v.canMoveNext())
	{
		std::cout << v.getValue() << std::endl;
		v.moveNext();
	}
	std::cout << "--" << std::endl;
	v = store.getStartingViewer();
	while (v.canMoveNext())
	{
		std::cout << v.getValue() << std::endl;
		v.moveNext();
	}
	std::cout << "--" << std::endl;
	Storage_Array<int> arrstorage;
	for (int i = 0; i < 10; i++)
	{
		arrstorage.add(i);
	}
	ArrayViewer<int> av(arrstorage);
	while (av.canMoveNext())
	{
		std::cout << av.getValue() << std::endl;
		av.moveNext();
	}
	std::cout << "--" << std::endl;
	av = arrstorage.getStartingViewer();
	while (av.canMoveNext())
	{
		std::cout << av.getValue() << std::endl;
		av.moveNext();
	}
	return 0;
}
