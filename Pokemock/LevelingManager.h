/// \file LevelingManager.h
/// \brief Interface for the level manager class CLevelingManager.

#define UINT unsigned int

#pragma once
#include <vector>
#include <cmath>
#include "hashmap.h"
#include "pokemetadata.h"

/// \brief The level manager.
///
/// The level manager is responsible for managing the experience and levels of a pokemon, as well 
/// as facilitating level ups.



class CLevelingManager{
private:
	static HashMap* m_levelUpMapErratic;
	static HashMap* m_levelUpMapFast;
	static HashMap* m_levelUpMapFlux;
	static HashMap* m_levelUpMapMedFast;
	static HashMap* m_levelUpMapMedSlow;
	static HashMap* m_levelUpMapSlow;
	
protected:
	void BuildHashMaps();
	//UINT CalculateEarnedExp(const EGrowthRate rate, const bool FlatFormula, const bool IsWild, const UINT ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const UINT DefeatedLvl, const UINT Lvl, const bool IsOriginalOwner, const bool EvolveEligible) const;
public:
	CLevelingManager();
	~CLevelingManager();
	//bool AddExperience(const bool FlatFormula, const bool IsWild, const UINT ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const UINT DefeatedLvl, const bool IsOriginalOwner, const bool EvolveEligible);
	UINT get(const EGrowthRate rate, const UINT key) const;
	void put(const EGrowthRate rate, const UINT key, const UINT value);
};
