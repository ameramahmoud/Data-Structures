#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "../LinkedList.h"
#include "../PriorityQueue.h"
#include "..\Events\Event.h"


#include "Order.h"
#include"Cook.h"

// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file

	
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	/// ==>
	
	
	
	//
	// TODO: Add More Data Members As Needed
	//

	int NoOfEvents;
	int AutoP;          //the number of timesteps after which an order is automatically promoted to VIP.
	int bo;             // The no. of orders a cook must prepare before taking a break.
	LinkedList<Order*>NormalOrderList;
	Queue<Order*>VeganOrderQueue;
	PriorityQueue<Order*>VipOrderQueue;

public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	void AddToNormal(Order* pOrd); //adds an order to normal order queue
	void AddToVegan(Order* pOrd);	//adds an order to vegan order queue
	void AddToVIP(Order* pOrd);	//adds an order to VIP order queue


	void FillDrawingList();

	void CancelOrderByID(int id); //cancels order in queue by its ID //MUST BE NORMAL ONLY//
	
	void PromoteToVipById(int id, int m);
								  
	//
	// TODO: Add More Member Functions As Needed
	//
	void FileLoading(string name);
	void SimpleSimulation();

/// ===================    DEMO-related functions. Should be removed in phases 1&2   ================= 

	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue

/// ================================================================================================== 



};

#endif