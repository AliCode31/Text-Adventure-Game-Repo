#include "Room.h"
#include "iostream"

Room::Room()
{
	description = "";
}

Room::Room(String descript)
{
	description = descript;
}

Room::Room(String descript, Item* item)
{
	description =  descript;
	this->item = item;
	

}

Room::~Room()
{

}

const void Room::Description()
{
	std::cout << description.CString() << std::endl << std::endl;

	return void();
}

const void Room::DescriptionWithItem()
{
	std::cout << description.CString() << std::endl << std::endl;
	item->Description();

	return void();
}
