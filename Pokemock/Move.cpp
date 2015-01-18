/// \file Move.cpp
/// \brief Definitions for all moves inherited from CMove and declared in MoveManager.h

#include "stdafx.h"
#include "levelingmanager.h"
#include "movemanager.h"

UINT CMove::counter = 0;
CMove::CMove()
{
	counter++;
	m_id = counter;
}
UINT CMove::GetAccuracy() const
{
	return m_accuracy;
}
UINT CMove::GetBasePower() const
{
	return m_basepower;
}
UINT CMove::GetId() const
{
	return m_id;
}
UINT CMove::GetPP() const
{
	return m_pp;
}

UINT CMove::GetMaxPP() const
{
	return m_maxpp;
}
bool CMove::CanUseOutOfBattle() const
{
	return m_outofbattleuse;
}
EType CMove::GetMoveType() const
{
	return m_type;
}
ECategory CMove::GetMoveCategory() const
{
	return m_category;
}
string CMove::GetName() const
{
	return m_name;
}
string CMove::GetDescription() const
{
	return m_description;
}

CLeer::CLeer() 
	: CMove()
{
	m_type = NORMAL;
	m_category = STATUS;
	m_outofbattleuse = false;
	m_pp = 30; 
	m_maxpp = 48;
	m_basepower = 0;
	m_accuracy = 100;
	m_name = "Leer";
	m_description = "The user gives opposing Pokémon an intimidating leer that lowers the Defense stat.";
}
void CLeer::Cast(CPokemon *castor, CPokemon *target[]) const
{
	
}


CTackle::CTackle() 
	: CMove()
{
	m_type = NORMAL;
	m_category = PHYSICAL;
	m_outofbattleuse = false;
	m_pp = 35; 
	m_maxpp = 56;
	m_basepower = 50;
	m_accuracy = 100;
	m_name = "Tackle";
	m_description = "A physical attack in which the user charges and slams into the target with its whole body.";
}

void CTackle::Cast(CPokemon *castor, CPokemon *target[]) const
{}



CGrowl::CGrowl()
	: CMove()
{
	m_type = NORMAL;
	m_category = STATUS;
	m_outofbattleuse = false;
	m_pp = 40;
	m_maxpp = 64;
	m_basepower = 0;
	m_accuracy = 100;
	m_name = "Growl";
	m_description = "The user growls in an endearing way, making opposing Pokémon less wary. This lowers their Attack stats.";
}

void CGrowl::Cast(CPokemon *castor, CPokemon *target[]) const
{}


CScratch::CScratch()
	: CMove()
{
	m_type = NORMAL;
	m_category = PHYSICAL;
	m_outofbattleuse = false;
	m_pp = 35;
	m_maxpp = 56;
	m_basepower = 40;
	m_accuracy = 100;
	m_name = "Scratch";
	m_description = "Hard, pointed, sharp claws rake the target to inflict damage.";
}

void CScratch::Cast(CPokemon *castor, CPokemon *target[]) const
{}