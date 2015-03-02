/// \file LevelingManager.cpp
/// \brief Code for the leveling manager class CLevelingManager.

#include "stdafx.h"
#include "levelingmanager.h"

void CLevelingManager::BuildHashMaps()
{
	m_levelUpMapErratic->put(1, 0);
	m_levelUpMapFast->put(1, 0);
	m_levelUpMapMedFast->put(1, 0);
	m_levelUpMapMedSlow->put(1, 0);
	m_levelUpMapSlow->put(1, 0);
	m_levelUpMapFlux->put(1, 0);

	for(int i = 2; i <= 100; i++){
		//Erratic Map
		if(i < 50) m_levelUpMapErratic->put(i, static_cast<int>((pow(i, 3.0) * (100 - i))/50));
		else if(i >= 50 && i < 68) m_levelUpMapErratic->put(i, static_cast<int>(pow(i, 3.0) * (150 - i)/100));
		else if(i >= 68 && i < 98) m_levelUpMapErratic->put(i, static_cast<int>(pow(i, 3.0) * static_cast<UINT>(floor((1911 - (10 * i))/3.0))/500));
		else m_levelUpMapErratic->put(i, static_cast<int>(pow(i, 3.0) * (160 - i)/100));
		//Fast Map
		m_levelUpMapFast->put(i, static_cast<int>((4*pow(i,3.0))/5));
		//Med_Fast Map
		m_levelUpMapMedFast->put(i, static_cast<int>(pow(i,3.0)));
		//Med_Slow Map
		m_levelUpMapMedSlow->put(i, static_cast<int>(((6/5)*pow(i,3.0)) - (15*pow(i,2.0)) + (100*i) - 140));
		//Slow
		m_levelUpMapSlow->put(i, static_cast<int>((5*pow(i, 3.0))/4));
		//Flux
		if(i < 15) m_levelUpMapFlux->put(i, static_cast<int>(pow(i, 3.0) * ((static_cast<UINT>(floor((i + 1)/3.0))) + 24)/50));
		else if(i >=15 && i < 36) m_levelUpMapFlux->put(i, static_cast<int>(pow(i, 3.0) * ((i + 14)/50)));
		else m_levelUpMapFlux->put(i, static_cast<int>(pow(i, 3.0) * ((static_cast<UINT>(floor(i/2.0)) + 32)/50)));
	}
}


////Does not include variables p and s; see http://bulbapedia.bulbagarden.net/wiki/Experience#Experience_underflow_glitch for details.  Also, IsOriginalOwner doesn't take Internation trades into account.
//#pragma warning( disable: 4244 )
//UINT CLevelingManager::CalculateEarnedExp(const EGrowthRate rate, const bool FlatFormula, const bool IsWild, const UINT ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const UINT DefeatedLvl, const UINT Lvl, const bool IsOriginalOwner, const bool EvolveElligible) const
//{
//	double a, e, f, t, v;
//	UINT b, L, Lp, earnedExp;
//
//	if(IsWild) a = 1;
//	else a = 1.5;
//
//	b = ExpYield;
//
//	if(HoldLuckyEgg) e = 1.5;
//	else e = 1;
//
//	if(IsAffectionate) f = 1.2;
//	else f = 1;
//
//	L = DefeatedLvl;
//
//	Lp = Lvl;
//
//	if(IsOriginalOwner) t = 1;
//	else t = 1.5;
//
//	if(EvolveElligible) v = 1.2;
//	else v = 1;
//
//	if(FlatFormula) earnedExp = (a * t * b * e * L /* * p*/ * f * v) /  (7 /* * s*/); 
//	else earnedExp = ((a * b * L)/(5 /* * s*/)) * ((pow(2L + 10, 2.5)/pow(L + Lp + 10, 2.5)) + 1) * t * e /* * p*/; 
//
//	UINT lvlUpExp = get(rate, Lvl + 1);
//
//		 
//	return earnedExp;
//}

CLevelingManager::CLevelingManager()
{
	m_levelUpMapErratic = new HashMap();
	m_levelUpMapFast = new HashMap();
	m_levelUpMapFlux = new HashMap();
	m_levelUpMapMedFast = new HashMap();
	m_levelUpMapMedSlow = new HashMap();
	m_levelUpMapSlow = new HashMap();
	BuildHashMaps();
}
CLevelingManager::~CLevelingManager()
{
	m_levelUpMapErratic->~HashMap();
	m_levelUpMapFast->~HashMap();
	m_levelUpMapFlux->~HashMap();
	m_levelUpMapMedFast->~HashMap();
	m_levelUpMapMedSlow->~HashMap();
	m_levelUpMapSlow->~HashMap();
}


////Need to code a table of base experience values gained on defeating a pokemon.
//bool CLevelingManager::AddExperience(const bool FlatFormula, const bool IsWild, const unsigned int ExpYield, const bool HoldLuckyEgg, const bool IsAffectionate, const unsigned int DefeatedLvl, const bool IsOriginalOwner, const bool EvolveElligible)
//{
//	bool lvluphappnd = false;
//	UINT exptoadd = CalculateEarnedExp(FlatFormula, IsWild, ExpYield, HoldLuckyEgg, IsAffectionate, DefeatedLvl, IsOriginalOwner, EvolveElligible);
//	m_exp += exptoadd;
//	if(m_exp >= m_lvlupexp)
//	{
//		LvlUp();
//		lvluphappnd = true;
//	}
//	return lvluphappnd;
//}

UINT CLevelingManager::get(const EGrowthRate rate, const UINT key) const
{
	UINT value = 0;
	switch(rate)
	{
	case ERRATIC:
		value = m_levelUpMapErratic->get(key);
		break;
	case FAST:
		value = m_levelUpMapFast->get(key);
		break;
	case FLUX:
		value = m_levelUpMapFlux->get(key);
		break;
	case MED_FAST:
		value = m_levelUpMapMedFast->get(key);
		break;
	case MED_SLOW:
		value = m_levelUpMapMedSlow->get(key);
		break;
	case SLOW:
		value = m_levelUpMapSlow->get(key);
		break;
	}
	return value;
}

void CLevelingManager::put(const EGrowthRate rate, const unsigned int key, const unsigned int value)
{
	switch(rate)
	{
	case ERRATIC:
		m_levelUpMapErratic->put(key, value);
		break;
	case FAST:
		m_levelUpMapFast->put(key, value);
		break;
	case FLUX:
		m_levelUpMapFlux->put(key, value);
		break;
	case MED_FAST:
		m_levelUpMapMedFast->put(key, value);
		break;
	case MED_SLOW:
		m_levelUpMapMedSlow->put(key, value);
		break;
	case SLOW:
		m_levelUpMapSlow->put(key, value);
		break;
	}
}