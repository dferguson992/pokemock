/// \file LevelingManager.h
/// \brief Interface for the level manager class CLevelingManager.

#define UINT unsigned int

#pragma once
#include "pokemetadata.h"

/// \brief The level manager.
///
/// The level manager is responsible for managing the experience and levels of a pokemon, as well as facilitating level ups.

class CLevelingManager{
private:
	UINT m_lvl;
	UINT m_exp;
	UINT m_lvlupexp;
	EGrowthRate m_growthrate;
protected:
	void SetNextLvlExp();
	void SetThisLvlExp();
	void LvlUp();
	UINT CalculateEarnedExp(const bool FlatFormula, const bool IsWild, const UINT ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const UINT DefeatedLvl, const bool IsOriginalOwner, const bool EvolveEligible) const;
public:
	CLevelingManager(const EGrowthRate growthrate);
	CLevelingManager(const unsigned int lvl, const EGrowthRate growthrate);
	bool AddExperience(const bool FlatFormula, const bool IsWild, const UINT ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const UINT DefeatedLvl, const bool IsOriginalOwner, const bool EvolveEligible);
	UINT GetLvl() const;
	UINT GetExp() const;
	UINT GetNextLvlExp() const;
};
