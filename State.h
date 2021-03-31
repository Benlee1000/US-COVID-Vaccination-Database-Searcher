#pragma once
#include <iostream>

using namespace std;
class State
{
private:
	string m_state; 
	int m_dosesDelivered;
	float m_dosesDeliveredPer100k;
	int m_doesesAdministered;
	float m_dosesAdministeredPer100k;
	float m_percentOfPopWithAtLeastOneDose;

public:
	State(string state, int dosesDelivered,  float dosesDeliveredPer100k, int dosesAdministered, float dosesAdministeredPer100k, float percentOfPopWithAtLeastOneDose);
};

