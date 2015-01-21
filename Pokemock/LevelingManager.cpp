/// \file LevelingManager.cpp
/// \brief Code for the leveling manager class CLevelingManager.

#include "stdafx.h"
#include "levelingmanager.h"
#include <cmath>

void CLevelingManager::SetNextLvlExp()
{
	UINT exp = 0;
	UINT targetlvl = m_lvl + 1;
	switch(m_growthrate)
	{
		case ERRATIC:
			if(m_lvl < 50)
				exp = ((targetlvl * targetlvl * targetlvl) * (100 - targetlvl))/50;
			else if(m_lvl >= 50 && m_lvl < 68)
				exp = ((targetlvl * targetlvl * targetlvl) * (150 - targetlvl))/100;
			else if(m_lvl >= 68 && m_lvl < 98)
				exp = ((targetlvl * targetlvl * targetlvl) * static_cast<UINT>(floor((1911 - (10 * targetlvl))/3.0))/500);
			else
				exp = ((targetlvl * targetlvl * targetlvl) * (160 - targetlvl)/100);
			break;
		case FAST:
			exp = (4 * (targetlvl * targetlvl * targetlvl))/5;
			break;
		case MED_FAST:
			exp = (targetlvl * targetlvl * targetlvl);
			break;
		case MED_SLOW:
			exp = ((6/5) * (targetlvl * targetlvl * targetlvl)) - (15 * (targetlvl * targetlvl)) + (100 * targetlvl) - 140;
			break;
		case SLOW:
			exp = (5 * (targetlvl * targetlvl * targetlvl))/4;
			break;
		case FLUX:
			if(m_lvl < 15)
				exp = (targetlvl * targetlvl * targetlvl) * (((static_cast<UINT>(floor((targetlvl + 1)/3.0))) + 24)/50);
			else if(m_lvl >= 15 && m_lvl < 36)
				exp = (targetlvl * targetlvl * targetlvl) * ((targetlvl + 14)/50);
			else
				exp = (targetlvl * targetlvl * targetlvl) * ((static_cast<UINT>(floor(targetlvl/2.0)) + 32)/50);
			break;
		default:
			exp = 100;
			break;
	}
	m_lvlupexp = exp;
}

void CLevelingManager::SetThisLvlExp()
{
	UINT exp = 0;
	UINT targetlvl = m_lvl;
	switch(m_growthrate)
	{
		case ERRATIC:
			if(m_lvl < 50)
				exp = ((targetlvl * targetlvl * targetlvl) * (100 - targetlvl))/50;
			else if(m_lvl >= 50 && m_lvl < 68)
				exp = ((targetlvl * targetlvl * targetlvl) * (150 - targetlvl))/100;
			else if(m_lvl >= 68 && m_lvl < 98)
				exp = ((targetlvl * targetlvl * targetlvl) * static_cast<UINT>(floor((1911 - (10 * targetlvl))/3.0))/500);
			else
				exp = ((targetlvl * targetlvl * targetlvl) * (160 - targetlvl)/100);
			break;
		case FAST:
			exp = (4 * (targetlvl * targetlvl * targetlvl))/5;
			break;
		case MED_FAST:
			exp = (targetlvl * targetlvl * targetlvl);
			break;
		case MED_SLOW:
			exp = ((6/5) * (targetlvl * targetlvl * targetlvl)) - (15 * (targetlvl * targetlvl)) + (100 * targetlvl) - 140;
			break;
		case SLOW:
			exp = (5 * (targetlvl * targetlvl * targetlvl))/4;
			break;
		case FLUX:
			if(m_lvl < 15)
				exp = (targetlvl * targetlvl * targetlvl) * (((static_cast<UINT>(floor((targetlvl + 1)/3.0))) + 24)/50);
			else if(m_lvl >= 15 && m_lvl < 36)
				exp = (targetlvl * targetlvl * targetlvl) * ((targetlvl + 14)/50);
			else
				exp = (targetlvl * targetlvl * targetlvl) * ((static_cast<UINT>(floor(targetlvl/2.0)) + 32)/50);
			break;
		default:
			exp = 100;
			break;
	}
	m_lvlupexp = exp;
}

void CLevelingManager::LvlUp()
{
	m_lvl++;
	SetNextLvlExp();
}

//Does not include variables p and s; see http://bulbapedia.bulbagarden.net/wiki/Experience#Experience_underflow_glitch for details.  Also, IsOriginalOwner doesn't take Internation trades into account.
#pragma warning( disable: 4244 )
UINT CLevelingManager::CalculateEarnedExp(const bool FlatFormula, const bool IsWild, const unsigned int ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const unsigned int DefeatedLvl, const bool IsOriginalOwner, const bool EvolveElligible) const
{
	double a, e, f, t, v;
	UINT b, L, Lp, earnedExp;

	if(IsWild) a = 1;
	else a = 1.5;

	b = ExpYield;

	if(HoldLuckyEgg) e = 1.5;
	else e = 1;

	if(IsAffectionate) f = 1.2;
	else f = 1;

	L = DefeatedLvl;

	Lp = m_lvl;

	if(IsOriginalOwner) t = 1;
	else t = 1.5;

	if(EvolveElligible) v = 1.2;
	else v = 1;

	if(FlatFormula) earnedExp = (a * t * b * e * L /* * p*/ * f * v) /  (7 /* * s*/); 
	else earnedExp = ((a * b * L)/(5 /* * s*/)) * ((pow(2L + 10, 2.5)/pow(L + Lp + 10, 2.5)) + 1) * t * e /* * p*/; 

	return earnedExp;
}
CLevelingManager::CLevelingManager(const EGrowthRate growthrate)
{
	m_lvl = 2;
	m_growthrate = growthrate;
	SetNextLvlExp();
	SetThisLvlExp();
}
CLevelingManager::CLevelingManager(const unsigned int lvl, const EGrowthRate growthrate)
{
	m_lvl = lvl;
	m_growthrate = growthrate;
	SetNextLvlExp();
	SetThisLvlExp();
}
//Need to code a table of base experience values gained on defeating a pokemon.
bool CLevelingManager::AddExperience(const bool FlatFormula, const bool IsWild, const unsigned int ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const unsigned int DefeatedLvl, const bool IsOriginalOwner, const bool EvolveElligible)
{
	bool lvluphappnd = false;
	UINT exptoadd = CalculateEarnedExp(FlatFormula, IsWild, ExpYield, HoldLuckyEgg, IsAffectionate, DefeatedLvl, IsOriginalOwner, EvolveElligible);
	m_exp += exptoadd;
	if(m_exp >= m_lvlupexp)
	{
		LvlUp();
		lvluphappnd = true;
	}
	return lvluphappnd;
}
UINT CLevelingManager::GetLvl() const
{ return m_lvl; }
UINT CLevelingManager::GetExp() const
{ return m_exp; }
UINT CLevelingManager::GetNextLvlExp() const
{ return m_lvlupexp; }