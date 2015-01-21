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

//class CMove;

//MAKE AN ARRAY OBJECT THAT HOLDS VALUES FOR THE BATTLE STATISTICS USED BY THE POKEMON
//THEN, DO SOME MATRIX OPS TO IMITATE STAT CHANGES!!!
class CBattleStatArray
{
private:
	UINT m_vstat_hp;
	UINT m_vstat_attack;
	UINT m_vstat_defense;
	UINT m_vstat_spattack;
	UINT m_vstat_spdefense;
	UINT m_vstat_speed;
	UINT m_stats[6];
protected:
public:
	CBattleStatArray(UINT hp, UINT atk, UINT def, UINT spatk, UINT spdef, UINT spd);
	CBattleStatArray& operator +(CBattleStatArray& addend)
	{
		
	}
};
class CSubtleStatArray
{

};

class CPokemon
{
private:
protected:
	UINT m_pokedexnum;
	UINT m_hp;
	CBattleStatArray* m_battlestat;
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
	CLevelingManager* m_lvlengine;
	CMoveManager* m_movemanager;
	CPokemon* m_nextevolve;

	//item m_itemheld;
	//egggroup m_egggroups[];
public:
	CPokemon();
	void LevelUp();
};
///////////////////////////////////////////////////////////////////////
class CBulbasaur : public CPokemon
{
private:
protected:
public:
	CBulbasaur();
};