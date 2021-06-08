#include "State.h"

State::State()
{
}


void State::setState(const string& state)
{
	m_state = state;
}

void State::setDosesDelivered(const int& dosesDelivered)
{
	m_dosesDelivered = dosesDelivered;
}

void State::setDosesDeliveredPer100k(const int& dosesDeliveredPer100k)
{
	m_dosesDeliveredPer100k = dosesDeliveredPer100k;
}

void State::setDosesAdministered(const int& dosesAdministered)
{
	m_dosesAdministered = dosesAdministered;
}

void State::setDosesAdministeredPer100k(const int& dosesAdministeredPer100k)
{
	m_dosesAdministeredPer100k = dosesAdministeredPer100k;
}

void State::setPercentOfPopWithAtLeastOneDose(const float& percentOfPopWithAtLeastOneDose)
{
	m_percentOfPopWithAtLeastOneDose = percentOfPopWithAtLeastOneDose;
}

void State::setPercentFullyVaccinated(const float& percentFullyVaccinated)
{
	m_percentFullyVaccinated = percentFullyVaccinated;
}

void State::setJandJDosesAdministered(const int& JandJDosesAdministered)
{
	m_JandJDosesAdministered = JandJDosesAdministered;
}

void State::setModernaDosesAdministered(const int& ModernaDosesAdministered) 
{
	m_ModernaDosesAdministered = ModernaDosesAdministered;
}

void State::setPfizerDosesAdministered(const int& PfizerDosesAdministered)
{
	m_PfizerDosesAdministered = PfizerDosesAdministered;
}

string State::getState() 
{
	return m_state;
}

int State::getDosesDelivered() const
{
	return m_dosesDelivered;
}

int State::getDosesDeliveredPer100k() const
{
	return m_dosesDeliveredPer100k;
}

int State::getDosesAdministered() const
{
	return m_dosesAdministered;
}

int State::getDosesAdministeredPer100k() const
{
	return m_dosesAdministeredPer100k;
}

float State::getPercentOfPopWithAtLeastOneDose() const
{
	return m_percentOfPopWithAtLeastOneDose;
}

float State::getPercentFullyVaccinated() const
{
	return m_percentFullyVaccinated;
}

int State::getJandJDosesAdministered() const
{
	return m_JandJDosesAdministered;
}

int State::getModernaDosesAdministered() const
{
	return m_ModernaDosesAdministered;
}

int State::getPfizerDosesAdministered() const
{
	return m_PfizerDosesAdministered;
}



