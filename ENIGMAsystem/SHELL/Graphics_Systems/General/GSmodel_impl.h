/** Copyright (C) 2013 Robert Colton, Adriano Tumminelli
*** Copyright (C) 2014 Seth N. Hetu, Josh Ventura, Harijs Grinbergs
*** Copyright (C) 2015 Harijs Grinbergs
*** Copyright (C) 2018 Robert Colton
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

#ifdef INCLUDED_FROM_SHELLMAIN
#  error This file includes non-ENIGMA STL headers and should not be included from SHELLmain.
#endif

#ifndef ENIGMA_GSMODEL_IMPL_H
#define ENIGMA_GSMODEL_IMPL_H

#include "GScolors.h"
#include "Universal_System/scalar.h"

#include <vector>
using std::vector;

namespace enigma {

struct Primitive {
  int type; // one of the enigma_user primitive type constants (e.g, pr_trianglelist)
  int format; // index of the user vertex format that describes the vertex data of this primitive
  bool format_defined; // if the format has been guessed yet from how vertex data is being specified
  unsigned vertex_offset; // byte offset into the vertex buffer where this primitive's data begins
  unsigned vertex_count; // number of vertices this primitive is composed of

  // NOTE: format may not exist until d3d_model_primitive_end is called
  // NOTE: when format_defined is true the format may still not exist yet

  Primitive(int type, int format, bool format_defined, unsigned offset):
    type(type), format(format), format_defined(format_defined), vertex_offset(offset), vertex_count(0) {}
};

struct Model {
  int type; // one of the enigma_user model type constants (e.g, model_static is the default)
  int vertex_buffer; // index of the user vertex buffer this model uses to buffer its vertex data
  Primitive* current_primitive; // pointer to the current primitive being specified by the user
  bool vertex_started; // whether the user has begun specifying the model by starting a primitive
  vector<Primitive> primitives; // all primitives the user has finished specifying for this model

  bool use_draw_color; // whether to store the current color per-vertex when no format given
  bool vertex_colored; // whether the last vertex specified color or not
  int vertex_color; // the color that was set when the last vertex was added
  gs_scalar vertex_alpha; // the alpha that was set when the last vertex was added

  // NOTE: vertex_buffer should always exist but not outlive the model
  // NOTE: current_primitive does not exist outside of the begin/end calls
  // NOTE: vertex_started is true until the user attempts to draw the model
  // NOTE: vertex_colored waits until the next vertex or primitive end to add the color
  //       because GM has always specified color as the last argument on its vertex formats

  Model(int type, bool use_draw_color):
    type(type), vertex_buffer(-1), current_primitive(0), vertex_started(false), use_draw_color(use_draw_color),
    vertex_colored(false), vertex_color(enigma_user::c_white), vertex_alpha(1.0) {}
};


extern vector<Model*> models;

}

#endif
