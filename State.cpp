#include "State.h"

State::State()
{
}


void State::setState(string state)
{
	m_state = state;
}

void State::setDosesDelivered(int dosesDelivered)
{
	m_dosesDelivered = dosesDelivered;
}

void State::setDosesDeliveredPer100k(int dosesDeliveredPer100k)
{
	m_dosesDeliveredPer100k = dosesDeliveredPer100k;
}

void State::setDosesAdministered(int dosesAdministered)
{
	m_dosesAdministered = dosesAdministered;
}

void State::setDosesAdministeredPer100k(int dosesAdministeredPer100k)
{
	m_dosesAdministeredPer100k = dosesAdministeredPer100k;
}

void State::setPercentOfPopWithAtLeastOneDose(float percentOfPopWithAtLeastOneDose)
{
	m_percentOfPopWithAtLeastOneDose = percentOfPopWithAtLeastOneDose;
}

string State::getState() 
{
	return m_state;
}

int State::getDosesDelivered()
{
	return m_dosesDelivered;
}

int State::getDosesDeliveredPer100k()
{
	return m_dosesDeliveredPer100k;
}

int State::getDosesAdministered()
{
	return m_dosesAdministered;
}

int State::getDosesAdministeredPer100k()
{
	return m_dosesAdministeredPer100k;
}

float State::getPercentOfPopWithAtLeastOneDose()
{
	return m_percentOfPopWithAtLeastOneDose;
}