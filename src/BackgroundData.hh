// $Id: BackgroundData.hh,v 1.2 2000/08/02 19:02:04 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef BACKGROUNDDATA_HH
#define BACKGROUNDDATA_HH

#include "ResDescriptor.hh"
#include "Color.hh"

///
class BackgroundData
{
public:
  ///
  ResDescriptor desc;
  ///
  float para_x;
  ///
  float para_y;

  /** The amount of pixel the background is scrolled each frame in x
      direction. */
  float scroll_x;

  /** The amount of pixel the background is scrolled each frame in x
      direction. */
  float scroll_y;

  /** fill_rect() components
      An fill_rect() can be drawn over the background, the following
      for components are passed to the fill_rect() call. */
  Color color;

  /// Stretch the background to the full screen size in x direction
  bool stretch_x;

  /// Stretch the background to the full screen size in x direction
  bool stretch_y;

  /// Init all fields with some usefull defaults values.
  BackgroundData() 
  {
    scroll_x = 0.0;
    scroll_y = 0.0;
    para_x = 0.5;
    para_y = 0.5;
    stretch_x = false;
    stretch_y = false;
  }
};

#endif

/* EOF */
