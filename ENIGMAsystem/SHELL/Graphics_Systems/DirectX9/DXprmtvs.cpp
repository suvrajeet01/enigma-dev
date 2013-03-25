/** Copyright (C) 2008-2013 Josh Ventura, Robert B. Colton
***
*** This file is a part of the ENIGMA Development Environment.
***
*** ENIGMA is free software: you can redistribute it and/or modify it under the
*** terms of the GNU General Public License as published by the Free Software
*** Foundation, version 3 of the license or any later version.
***
*** This application and its source code is distributed AS-IS, WITHOUT ANY
*** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
*** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
*** details.
***
*** You should have received a copy of the GNU General Public License along
*** with this code. If not, see <http://www.gnu.org/licenses/>
**/

#include "DirectXHeaders.h"
#include "DXprmtvs.h"
#include "binding.h"

#include <string>
#include "Widget_Systems/widgets_mandatory.h"

#if PRIMBUFFER
enum __primitivetype[PRIMDEPTH2];
int __primitivelength[PRIMDEPTH2];
float __primitivecolor[PRIMBUFFER][PRIMDEPTH2][4];
float __primitivexy[PRIMBUFFER][PRIMDEPTH2][2];
int __currentpcount[PRIMDEPTH2];
int __currentpdepth;
#endif

enum ptypes_by_id
{
	
};

void draw_set_primitive_aa(bool enable, int quality)
{

}

int draw_primitive_begin(int dink)
{

}

int draw_primitive_begin_texture(int dink,unsigned tex)
{

}

int draw_vertex(double x, double y)
{

}

int draw_vertex_color(float x, float y, int col, float alpha)
{

}

int draw_vertex_texture(float x, float y, float tx, float ty)
{

}

int draw_vertex_texture_color(float x, float y, float tx, float ty, int col, float alpha)
{

}

int draw_primitive_end()
{

}