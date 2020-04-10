//#include "Drawing.h"
#include "Rest\Restaurant.h"
#include "GUI\GUI.h"
#include "Generic_DS/Queue.h"
#include"Events/Event.h"
int main()
{
	
	Restaurant* pRest = new Restaurant;
	//pRest->FileLoading("FileInput.txt");
	pRest->RunSimulation();
	
	delete pRest;
	
	return 0;
}
