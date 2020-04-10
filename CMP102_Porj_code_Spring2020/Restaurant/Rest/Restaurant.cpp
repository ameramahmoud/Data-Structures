#include <cstdlib>
#include <time.h>
#include <iostream>
#include<fstream>
using namespace std;

#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
#include"..\PromotionEvent.h"
#include"..\CancellationEvent.h"



Restaurant::Restaurant() 
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Just_A_Demo();
	case MODE_SIM:
		SimpleSimulation();
	};

}
void Restaurant::AddToNormal(Order* pOrd)
{
	NormalOrderList.Insert(pOrd);
}
void Restaurant::AddToVegan(Order* pOrd)
{
	VeganOrderQueue.enqueue(pOrd);
}
void Restaurant::AddToVIP(Order* pOrd)
{
	VipOrderQueue.enqueue(pOrd,2); //CALCULATE PRIORITY//
}

void Restaurant::FileLoading(string fname)
{
	ifstream inputFile;
	inputFile.open(fname);
	if (inputFile.is_open())
	{
		int n, g, v;
		inputFile >> n >> g >> v;
		int sn, sg, sv;
		inputFile >> sn >> sg >> sv;
		int bn, bg, bv;
		inputFile >> bo >> bn >> bg >> bv;
		Cook *c;
		ORD_TYPE type;
		int id = 1;
		for (int j = 0; j < n; j++)
		{
			type = TYPE_NRM;
			c = new Cook(id,(ORD_TYPE)type,sn,bn);
			id++;
		}
		for (int k = 0; k < g; k++)
		{
			type = TYPE_VGAN;
			c = new Cook(id,(ORD_TYPE)type,sg,bg);
			id++;
		}
		for (int l = 0; l < v; l++)
		{
			type = TYPE_VIP;
			c = new Cook(id,(ORD_TYPE)type,sv,bv);
			id++;
		}
		
		inputFile >> AutoP >> NoOfEvents;
		Event* Tevent;
		char check;
		int TS;
		int ID;
		char oType;
		for (int i = 0; i < NoOfEvents; i++)
		{
			inputFile >> check;
			if (check == 'R')
			{
				int Size;
				int Money;
				int oDist = 0;
				inputFile >> oType;
				if (oType == 'N')
				{
					type = TYPE_NRM;
				}
				else if (oType == 'V')
				{
					type = TYPE_VIP;
				}
				else if (oType == 'G')
				{
					type = TYPE_VGAN;
				}
				inputFile >> TS >> ID >> Size >> Money;
				Tevent = new ArrivalEvent(TS, ID, (ORD_TYPE)type, Size, Money,oDist);
				EventsQueue.enqueue(Tevent);
			}
			else if (check == 'X')
			{
				inputFile >> TS >> ID;
				Tevent = new CancellationEvent(TS, ID);
				EventsQueue.enqueue(Tevent);
			}
			else if (check == 'P')
			{
				int ExMon;
				inputFile >> TS >> ID >> ExMon;
				Tevent = new PromotionEvent(TS, ID, ExMon);
				EventsQueue.enqueue(Tevent);
			}
		}


	}
}

void Restaurant::SimpleSimulation()
{
	pGUI = new GUI;
	pGUI->PrintMessage("Enter file name");
	string iFile = pGUI->GetString();
	FileLoading(iFile);
}


//////////////////////////////////  Event handling functions   /////////////////////////////

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current timestep
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


Restaurant::~Restaurant()
{
		if (pGUI)
			delete pGUI;
}

void Restaurant::FillDrawingList()
{
	//This function should be implemented in phase1
	//It should add ALL orders and Cooks to the drawing list
	//It should get orders from orders lists/queues/stacks/whatever (same for Cooks)
	//To add orders it should call function  void GUI::AddToDrawingList(Order* pOrd);
	//To add Cooks it should call function  void GUI::AddToDrawingList(Cook* pCc);

}

void Restaurant::CancelOrderByID(int id)
{
	NormalOrderList.CancelOrder(id);
}

void Restaurant::PromoteToVipById(int id, int m)
{
	Order* pOrd = NormalOrderList.getItem(id);
	pOrd->SetType(TYPE_VIP);
	VipOrderQueue.enqueue(pOrd, 2); //CALCULATE PRIORITY//
	CancelOrderByID(id);
}




//////////////////////////////////////////////////////////////////////////////////////////////
/// ==> 
///  DEMO-related functions. Should be removed in phases 1&2

//Begin of DEMO-related functions

//This is just a demo function for project introductory phase
//It should be removed starting phase 1
void Restaurant::Just_A_Demo()
{
	
	//
	// THIS IS JUST A DEMO FUNCTION
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	
	int EventCnt;	
	Order* pOrd;
	Event* pEv;
	srand(time(NULL));

	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Events randomly... In next phases, Events should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();
		
	//Just for sake of demo, generate some cooks and add them to the drawing list
	//In next phases, Cooks info should be loaded from input file
	int C_count = 12;	
	Cook *pC = new Cook[C_count];
	int cID = 1;

	for(int i=0; i<C_count; i++)
	{
		cID+= (rand()%15+1);	
		pC[i].setID(cID);
		pC[i].setType((ORD_TYPE)(rand()%TYPE_CNT));
	}	

		
	int EvTime = 0;

	int O_id = 1;
	
	//Create Random events and fill them into EventsQueue
	//All generated event will be "ArrivalEvents" for the demo
	for(int i=0; i<EventCnt; i++)
	{
		O_id += (rand()%4+1);		
		int OType = rand()%TYPE_CNT;	//Randomize order type		
		EvTime += (rand()%5+1);			//Randomize event time
		pEv = new ArrivalEvent(EvTime,O_id,(ORD_TYPE)OType);
		EventsQueue.enqueue(pEv);

	}	

	// --->   In next phases, no random generation is done
	// --->       EventsQueue should be filled from actual events loaded from input file

	
	
	
	
	//Now We have filled EventsQueue (randomly)
	int CurrentTimeStep = 1;
	

	//as long as events queue is not empty yet
	while(!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep,timestep,10);	
		pGUI->PrintMessage(timestep);


		//The next line may add new orders to the DEMO_Queue
		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
		

/////////////////////////////////////////////////////////////////////////////////////////
		/// The next code section should be done through function "FillDrawingList()" once you
		/// decide the appropriate list type for Orders and Cooks
		
		//Let's add ALL randomly generated Cooks to GUI::DrawingList
		for(int i=0; i<C_count; i++)
			pGUI->AddToDrawingList(&pC[i]);
		
		//Let's add ALL randomly generated Ordes to GUI::DrawingList
		int size = 0;
		Order** Demo_Orders_Array = DEMO_Queue.toArray(size);
		
		for(int i=0; i<size; i++)
		{
			pOrd = Demo_Orders_Array[i];
			pGUI->AddToDrawingList(pOrd);
		}
/////////////////////////////////////////////////////////////////////////////////////////

		pGUI->UpdateInterface();
		Sleep(1000);
		CurrentTimeStep++;	//advance timestep
		pGUI->ResetDrawingList();
	}

	delete []pC;


	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();

	
}
////////////////

void Restaurant::AddtoDemoQueue(Order *pOrd)
{
	DEMO_Queue.enqueue(pOrd);
}

/// ==> end of DEMO-related function
//////////////////////////////////////////////////////////////////////////////////////////////


