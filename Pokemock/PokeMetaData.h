/// \file PokeMetaData.h
/// \brief Declaration of Pokemon Meta Data classes and structures.

#define UINT unsigned int

#pragma once
#include <string>

using namespace std;

enum EGrowthRate 
{
	ERRATIC, 
	FAST, 
	MED_FAST, 
	MED_SLOW, 
	SLOW, 
	FLUX
};

enum EType
{
	NORMAL	= 0,
	BUG		= 1,
	FIGHT	= 10,
	GHOST	= 11,
	ELECTR	= 100,
	FLYING	= 101,
	STEEL	= 110,
	PSYCHIC	= 111,
	POISON	= 1000,
	FIRE	= 1001,
	ICE		= 1010,
	GROUND	= 1011,
	WATER	= 1100,
	DRAGON	= 1101,
	ROCK	= 1110,
	GRASS	= 1111,
	DARK	= 10000,
};

enum ECategory
{
	PHYSICAL	= 0,
	SPECIAL		= 1,
	STATUS		= 10,
};

//MOD 6 INCREASED STAT KEY/FAVORITE FLAVOR:
//	0 = NONE/NONE
//	1 = ATTACK/SPICY
//	2 = DEFENSE/SOUR
//	3 = SPEED/SWEET
//	4 = Sp. ATTACK/DRY
//	5 = Sp. DEFENSE/BITTER
enum ENature
{
	HARDY		= 0,//
	LONELY		= 1,	//DEFENSE
	BOLD		= 2,		//ATTACK
	TIMID		= 3,		//
	MODEST		= 4,		//
	CALM		= 5,		//
	DOCILE		= 6,//
	BRAVE		= 7,			//SPEED
	RELAXED		= 8,			//
	HASTY		= 9,	//DEFENSE
	MILD		= 10,	//
	GENTLE		= 11,	//
	SERIOUS		= 12,//
	ADAMANT		= 13,				//Sp. ATTACK	
	IMPISH		= 14,				//
	JOLLY		= 15,				//
	QUIET		= 16,			//SPEED
	SASSY		= 17,			//
	BASHFUL		= 18,//		
	NAUGHTY		= 19,					//Sp. DEFENSE				
	LAX			= 20,					//
	NAIVE		= 21,					//
	RASH		= 22,					//
	CAREFUL		= 23,				//
	QUIRKY		= 24,//
};

struct SAbility
{
	string name;
	string description;
	//somehow, need to discuss effect of said ability...
	// or perhaps, perhaps have them belong to a table and check ability at certain points...?
};

struct SPhysSpecs
{
	struct SHeight
	{
		UINT feet;
		UINT inches;
	};
	struct SWeight
	{
		UINT pounds;
		UINT ounces;
	};
	bool m_gender;
	bool m_shiny;
};
