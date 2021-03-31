#include "State.h"

State::State(string state, int dosesDelivered, float dosesDeliveredPer100k, int dosesAdministered, float dosesAdministeredPer100k, float percentOfPopWithAtLeastOneDose)
{
	// Fill in state information
	m_state = state;
	m_dosesDelivered = dosesDelivered;
	m_dosesDeliveredPer100k = dosesDeliveredPer100k;
	m_doesesAdministered = dosesAdministered;
	m_dosesAdministeredPer100k = dosesAdministeredPer100k;
	m_percentOfPopWithAtLeastOneDose = percentOfPopWithAtLeastOneDose;
}
