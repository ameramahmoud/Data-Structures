#pragma once
#include"Events/Event.h"
class PromotionEvent : public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, vegan, VIP	                
	double ExMoney;        //The extra money the customer paid for promotion.
public:
	PromotionEvent(int eTime, int oID, double exmoney);
	//Add more constructors if needed

	virtual void Execute(Restaurant* pRest);	//override execute function

	~PromotionEvent();
};

