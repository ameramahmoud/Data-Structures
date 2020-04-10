#include "PromotionEvent.h"
#include"Rest/Restaurant.h"

PromotionEvent::PromotionEvent(int eTime, int oID , double exmoney) :Event(eTime, oID)
{
	ExMoney = exmoney;
}

void PromotionEvent::Execute(Restaurant* pRest)
{
	//This function should create an order and fills its data 
	// Then adds it to normal, vegan, or VIP order lists that you will create in phase1

	pRest->PromoteToVipById(Event::getOrderID(), ExMoney);

	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phases 1&2
	/*Order* pOrd = new Order(OrderID, OrdType);
	pRest->AddtoDemoQueue(pOrd);*/
}

PromotionEvent::~PromotionEvent()
{
}
