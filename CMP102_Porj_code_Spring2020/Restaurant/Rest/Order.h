#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"
#include "../Events/Event.h"

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, vegan, VIP
	ORD_STATUS status;	//waiting, in-service, done
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	
	int Size; // number of orders
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Order(int ID, ORD_TYPE r_Type);
	Order(int id, ORD_TYPE r_Type, int rSize, double rMoney, int rDist);
	virtual ~Order();

	int GetID();

	void SetType(ORD_TYPE t);
	ORD_TYPE GetType() const;

	void SetDistance(int d);
	int GetDistance() const;

	void SetTotalMoney(int m);
	int GetTotalMoney() const;

	void SetArrTime(int at);
	int GetArrTime() const;

	void SetServTime(int st);
	int GetServTime() const;

	void SetFinishTime(int ft);
	int GetFinishTime() const;
	
	void SetSize(int s);
	int GetSize() const;

	void setStatus(ORD_STATUS s);
	ORD_STATUS getStatus() const;
	
	
	//
	// TODO: Add More Member Functions As Needed
	//

};

#endif