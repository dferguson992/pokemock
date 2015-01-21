/// \file MoveManager.cpp
/// \brief Contains the definition for the CMoveLearningMap and CMoveManager object.

#pragma once
#include "stdafx.h"
#include "movemanager.h"

///////////////////////////////////////////////////////////////////////
CLearnableMoveItem::CLearnableMoveItem(CMove* move, const int lvllearned) : m_move(move), m_lvl(lvllearned), m_offered(false)
{ };
void CLearnableMoveItem::OfferToLearn()
{
	m_offered = true;
};
bool CLearnableMoveItem::GetOfferStatus() const
{
	return m_offered;
};
int CLearnableMoveItem::GetMoveOfferLevel() const
{
	return m_lvl;
};
CMove* CLearnableMoveItem::GetMove() const
{
	return m_move;
};
///////////////////////////////////////////////////////////////////////
CMoveLevelingMap::CMoveLevelingMap(vector<CLearnableMoveItem> map, int lvl) : m_map(map), m_nextlvl(lvl)
{};
void CMoveLevelingMap::IncrementLevel()
{
	m_nextlvl++;
};
vector<CLearnableMoveItem> CMoveLevelingMap::GetAllLearnableMoves() const
{
	int _nvctrstrt;
	for(int i = 0; i < m_map.size(); i++)
	{
		if(m_nextlvl > m_map[i].GetMoveOfferLevel())
		{
			_nvctrstrt = i;
			break;
		}
	}
	vector<CLearnableMoveItem> _rtrnths;
	for(int i = 0; _nvctrstrt < m_map.size(); _nvctrstrt++)
		_rtrnths.push_back(m_map[_nvctrstrt]);
	return _rtrnths;
};
///////////////////////////////////////////////////////////////////////
CMoveManager::CMoveManager(vector<CMove*> moveset, CMoveLevelingMap map) : m_moveset(moveset), m_movemapping(map)
{ };
void CMoveManager::SwapMoves(CMove* target, CMove* replacement)
{
	int targetid = target->GetId();
	for(int i = 0; i < m_moveset.size(); i++)
	{
		if(m_moveset[i]->GetId() == targetid)
		{	
			m_moveset[i] = replacement;
			break;
		}
	}
};
void CMoveManager::LevelUp()
{
	m_movemapping.IncrementLevel();
};

