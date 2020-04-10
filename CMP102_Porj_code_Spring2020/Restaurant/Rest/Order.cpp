#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	status = WAIT;
}

Order::Order(int id, ORD_TYPE r_Type, int rSize, double rMoney, int rDist)
{
	ID = (id > 0 && id < 1000) ? id : 0;	//1<ID<999
	type = r_Type;
	Size = rSize;
	totalMoney = rMoney;
	Distance = rDist;
}

Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


void Order::SetType(ORD_TYPE t)
{
	type = t;
}

ORD_TYPE Order::GetType() const
{
	return type;
}


void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}

void Order::SetTotalMoney(int m)
{
	totalMoney = m;
}

int Order::GetTotalMoney() const
{
	return totalMoney;
}

void Order::SetArrTime(int at)
{
	ArrTime = at;
}

int Order::GetArrTime() const
{
	return ArrTime;
}

void Order::SetServTime(int st)
{
	ServTime = st;
}

int Order::GetServTime() const
{
	return ServTime;
}

void Order::SetFinishTime(int ft)
{
	FinishTime = ft;
}

int Order::GetFinishTime() const
{
	return FinishTime;
}

void Order::SetSize(int s)
{
	Size = s;
}

int Order::GetSize() const
{
	return Size;
}


void Order::setStatus(ORD_STATUS s)
{
	status = s;
}

ORD_STATUS Order::getStatus() const
{
	return status;
}

