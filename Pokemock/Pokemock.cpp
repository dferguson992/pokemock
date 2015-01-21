// Pokemock.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cmath>
#include <math.h>
#include "pokemon.h"

using namespace std;

int main()
{
	CTackle t;
	CLeer l;
	CMove* m = &t;
	cout << l.GetId();
	cout << m->GetId();
	_getch();
    return 0;
}
