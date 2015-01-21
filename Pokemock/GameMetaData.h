/// \file GameMetaData.h
/// \brief Contains lists of objects that are created once and only once on the game's startup.

#define UINT unsigned int

#pragma once
#include "movemanager.h"
#include "pokemetadata.h"
#include "levelingmanager.h"

class CGameVectors
{
private:
	CMoveVector* m_moves;
protected:
public:
	void Init();
};