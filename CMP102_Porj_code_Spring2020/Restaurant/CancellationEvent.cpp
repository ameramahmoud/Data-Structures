#include "CancellationEvent.h"
#include"Rest/Restaurant.h"

CancellationEvent::CancellationEvent(int eTime, int oID) :Event(eTime, oID)
{
	
}

void CancellationEvent::Execute(Restaurant* pRest)
{
	//This function should create an order and fills its data 
	// Then adds it to normal, vegan, or VIP order lists that you will create in phase1

	pRest->CancelOrderByID(Event::getOrderID());

	///For the sake of demo, this function will just create an order and add it to DemoQueue
	/*///Remove the next code lines in phases 1&2
	Order* pOrd = new Order(OrderID, OrdType);
	pRest->AddtoDemoQueue(pOrd);*/
}

CancellationEvent::~CancellationEvent()
{
}