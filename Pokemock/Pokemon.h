/// \file Pokemon.h
/// \brief Interface for the pokemon base class CPokemon.

#define UINT unsigned int
#define ULNG unsigned long

#pragma once
#include "movemanager.h"
#include "pokemetadata.h"
#include "levelingmanager.h"
#include <string>

using namespace std;

class CMove;

//MAKE AN ARRAY OBJECT THAT HOLDS VALUES FOR THE BATTLE STATISTICS USED BY THE POKEMON
//THEN, DO SOME MATRIX OPS TO IMITATE STAT CHANGES!!!
class CPokemon
{
private:
	UINT m_pokedexnum;
	UINT m_hp;
	UINT m_vstat_hp;
	UINT m_vstat_attack;
	UINT m_vstat_defense;
	UINT m_vstat_spattack;
	UINT m_vstat_spdefense;
	UINT m_vstat_speed;
	UINT m_invstat_friendship;
	UINT m_invstat_accuracy;
	UINT m_invstat_runaway;
	UINT m_capturerate;
	UINT m_baseeggsteps;
	ULNG m_serialnumber;
	float m_maleratio;
	string m_name;
	string m_ogowner;
	string m_description;
	EType m_type[2];
	ENature m_nature;
	SPhysSpecs m_physspecs;
	CLevelingManager m_lvlengine;
	CMoveManager m_movemanager;

	//egggroup m_egggroups[];
protected:
public:
	CPokemon();
};