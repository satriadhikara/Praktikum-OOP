#include "SpacingGuildShip.hpp"

#include <iostream>
#include <cmath>

using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : serialNum(producedShips + 1), maxPassengerCap(50), guildNavigatorCount(3)
{
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = 50;
    producedShips += 1;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : serialNum(producedShips + 1), maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount)
{
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips += 1;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip &other) : serialNum(producedShips + 1), maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount)
{
    this->passengerCount = other.passengerCount;
    this->operatingGuildNavigator = other.operatingGuildNavigator;
    this->spiceStock = other.spiceStock;
    producedShips += 1;
}

SpacingGuildShip::~SpacingGuildShip()
{
}

int SpacingGuildShip::getShipSerialNum() const
{
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const
{
    return passengerCount;
}

void SpacingGuildShip::travel(float distance)
{
    if (operatingGuildNavigator != 0)
    {
        totalGuildTravel += (distance / (pow(E, 2) * operatingGuildNavigator));
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers)
{
    passengerCount += addedPassengers;
    if (passengerCount > maxPassengerCap)
    {
        passengerCount = maxPassengerCap;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers)
{
    passengerCount -= droppedPassengers;
    if (passengerCount < 0)
    {
        passengerCount = 0;
    }
}

void SpacingGuildShip::refreshNavigator(int n)
{
    if (n <= guildNavigatorCount)
    {
        spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
        operatingGuildNavigator += n;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice)
{
    spiceStock += addedSpice;
}