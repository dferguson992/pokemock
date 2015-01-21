/// \file Pokemon.cpp
/// \brief Definition for the Pokemon object.

#pragma once
#include "stdafx.h"
#include "pokemon.h"

CBattleStatArray::CBattleStatArray(UINT hp, UINT atk, UINT def, UINT spatk, UINT spdef, UINT spd)
	: m_vstat_hp(hp), m_vstat_attack(atk), m_vstat_defense(def), m_vstat_spattack(spatk), m_vstat_spdefense(spdef), m_vstat_speed(spd)
{
	m_stats = { m_vstat_hp, m_vstat_attack, m_vstat_defense, m_vstat_spattack, m_vstat_spdefense, m_vstat_speed };
};

CPokemon::CPokemon()
{

}

CBulbasaur::CBulbasaur()
	: CPokemon()
{
	m_pokedexnum = 1;
	m_capturerate = 45;
	m_baseeggsteps = 5500;
	m_maleratio = .875;
	m_name = "Bulbasaur";
	m_description = "";
	m_type = { GRASS, POISON };
	m_physspecs = { {2, 4 }, { 15, 2 }, false, false };
	
}