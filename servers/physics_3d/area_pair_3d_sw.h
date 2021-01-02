/*************************************************************************/
/*  area_pair_3d_sw.h                                                    */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef AREA_PAIR_SW_H
#define AREA_PAIR_SW_H

#include "area_3d_sw.h"
#include "body_3d_sw.h"
#include "constraint_3d_sw.h"

class AreaPair3DSW : public Constraint3DSW {
	Body3DSW *body = nullptr;
	Area3DSW *area = nullptr;
	int body_shape = 0;
	int area_shape = 0;
	bool colliding = false;

public:
	bool setup(real_t p_step);
	void solve(real_t p_step);

	AreaPair3DSW(Body3DSW *p_body, int p_body_shape, Area3DSW *p_area, int p_area_shape);
	~AreaPair3DSW();
};

class Area2Pair3DSW : public Constraint3DSW {
	Area3DSW *area_a = nullptr;
	Area3DSW *area_b = nullptr;
	int shape_a = 0;
	int shape_b = 0;
	bool colliding = false;

public:
	bool setup(real_t p_step);
	void solve(real_t p_step);

	Area2Pair3DSW(Area3DSW *p_area_a, int p_shape_a, Area3DSW *p_area_b, int p_shape_b);
	~Area2Pair3DSW();
};

#endif // AREA_PAIR__SW_H
