#include "Cook.h"


Cook::Cook()
{
}

Cook::Cook(int id,ORD_TYPE oType, int s, int b)
{
	ID=id;
	type = oType;
	speed = s;
	Break = b;
}

Cook::~Cook()
{
}


int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}


void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}


