#pragma once
#include"Events/Event.h"
class CancellationEvent:public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, vegan, VIP	                
	
public:
	CancellationEvent(int eTime, int oID);
	//Add more constructors if needed

	virtual void Execute(Restaurant* pRest);	//override execute function

	~CancellationEvent();
};

