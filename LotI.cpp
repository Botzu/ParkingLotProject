#pragma once
#include "LotI.h"
LotI* LotI::i_instance = 0;
string LotI::getLotName()
{
	return LotName;
}
int LotI::getTotalNoOfSpots()
{
	return TotalNoOfSpots;
}
bool LotI::checkIsLotFull()
{
	for (int i = 0; i < pSpaceI.size(); i++)
	{
		if (!pSpaceI[i]->checkIsFull()) //if even one space is free, it is not full
		{
			isLotFull = false;
			return isLotFull;
		}
	}
	isLotFull = true;
	return isLotFull;
}
LotI* LotI::getInstance()
{
	if (!i_instance)
		i_instance = new LotI();
	return i_instance;
}
bool LotI::reserve(time_t startTime, time_t endTime)
{
	tm* st = new tm();
	gmtime_s(st, &startTime);
	int start_hour = st->tm_hour;
	int start_min = st->tm_min;
	bool reserve_flag = false;
	int blocks = int(difftime(endTime, startTime) / 900);

	for (int i = 0; i < pSpaceI.size(); i++)
	{
		if (pSpaceI[i]->reserve(start_hour, start_min, blocks))
		{
			reserve_flag = true;
			break;
		}
	}
	return reserve_flag;
}
// !LotI