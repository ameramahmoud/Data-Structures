#ifndef __ARRIVAL_EVENT_H_
#define __ARRIVAL_EVENT_H_

#include "Event.h"
#include "../Defs.h"


//class for the arrival event
class ArrivalEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, vegan, VIP	                
	double OrdMoney;	//Total order money
	int OrdSize;         //No. of dishes of the order

public:
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType);
	ArrivalEvent(int eTime, int oID, ORD_TYPE oType, int oSize, double oMoney ,int oDist);
	//Add more constructors if needed
	
	virtual void Execute(Restaurant *pRest);	//override execute function
	~ArrivalEvent();
};

#endif