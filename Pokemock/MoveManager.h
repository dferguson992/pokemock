/// \file MoveManager.h
/// \brief Declaration of the base move class, child move classes, the move manager class, as well as a special data structure which maps move ids to levels learned.

#define UINT unsigned int

#pragma once
#include <string>
#include <vector>
#include "pokemetadata.h"

using namespace std;

class CPokemon;	//forward declaration circumvents circular dependency between MoveManager.h and Pokemon.h...Need a better way to resolve this.
//See http://stackoverflow.com/questions/625799/resolve-circular-dependencies-in-c
//And also http://make-aitee-work.blogspot.de/2013/12/resolving-circular-dependencies-in-c.html

class CMove
{
private:
protected:
	static UINT counter;
	EType m_type;
	ECategory m_category;
	bool m_outofbattleuse;
	UINT m_id;
	UINT m_pp;
	UINT m_maxpp;
	UINT m_basepower;
	UINT m_accuracy;
	string m_name;
	string m_description;
public:
	EType GetMoveType() const;
	ECategory GetMoveCategory() const;
	bool CanUseOutOfBattle() const;
	UINT GetPP() const;
	UINT GetMaxPP() const;
	UINT GetBasePower() const;
	UINT GetAccuracy() const;
	UINT GetId() const;
	string GetName() const;
	string GetDescription() const;
	virtual void Cast(CPokemon* castor, CPokemon* target[]) const = 0;
	CMove();
};

///////////////////////////////////////////////////////////////////////
class CLeer : public CMove
{
private:
protected:
public:
	CLeer();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};

///////////////////////////////////////////////////////////////////////
class CTackle : public CMove
{
private:
protected:
public:
	CTackle();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};

///////////////////////////////////////////////////////////////////////
class CGrowl : public CMove
{
private:
protected:
public:
	CGrowl();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};

///////////////////////////////////////////////////////////////////////
class CScratch : public CMove
{
private:
protected:
public:
	CScratch();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};

///////////////////////////////////////////////////////////////////////
class CHyperBeam : public CMove
{
private:
protected:
public:
	CHyperBeam();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};
///////////////////////////////////////////////////////////////////////
class CBite : public CMove
{
private:
protected:
public:
	CBite();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};
///////////////////////////////////////////////////////////////////////
class CSurf : public CMove
{
private:
protected:
public:
	CSurf();
	void Cast(CPokemon* castor, CPokemon* target[]) const;
};
///////////////////////////////////////////////////////////////////////
class CMoveVector
{
private:
	vector<CMove*> m_moves;
protected:
public:
	CMoveVector();
	CMove* operator[](int& moveid)
	{
		CMove* mptr;
		for(int i = 0; i < m_moves.size(); i++)
		{
			if(m_moves[i]->GetId() == moveid)
			{
				mptr = m_moves[i];
				break;
			}
		}
		return mptr;
	}
};
///////////////////////////////////////////////////////////////////////
class CLearnableMoveItem
{
private:
	CMove* m_move;
	int m_lvl;
	mutable bool m_offered;
protected:
public:
	CLearnableMoveItem(CMove* move, const int lvllearned);
	void OfferToLearn();
	bool GetOfferStatus() const;
	int GetMoveOfferLevel() const;
	CMove* GetMove() const;
};
///////////////////////////////////////////////////////////////////////
class CMoveLevelingMap
{
private:
	vector<CLearnableMoveItem> m_map;
	int m_nextlvl;
protected:
public:
	CMoveLevelingMap(vector<CLearnableMoveItem> map, int lvl);
	void IncrementLevel();
	vector<CLearnableMoveItem> GetAllLearnableMoves() const;
};
///////////////////////////////////////////////////////////////////////
class CMoveManager
{
private:
	vector<CMove*> m_moveset;
	CMoveLevelingMap m_movemapping;
protected:
public:
	CMoveManager(vector<CMove*> moveset, CMoveLevelingMap map);
	void SwapMoves(CMove* target, CMove* replacement);
	void LevelUp();
	
};
///////////////////////////////////////////////////////////////////////