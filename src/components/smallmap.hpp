//  $Id$
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

#ifndef HEADER_PINGUS_SMALLMAP_HPP
#define HEADER_PINGUS_SMALLMAP_HPP

#include "../sprite.hpp"
#include "../gui/component.hpp"

class GameSession;
class Vector3f;
class SmallMapImage;

/** This is the map that appears in the corner of the screen */
class SmallMap : public GUI::Component
{
private:
  GameSession* session;

  /** Graphic surface of the exit */
  Sprite exit_sur;

  /** Graphic surface of the entrance */
  Sprite entrance_sur;

  SmallMapImage* image;

  /** Horizontal position of the small map */
  int x_pos;

  /** Vertical position of the small map */
  int y_pos;

  /** Width of the small map */
  int width;

  /** Height of the small map */
  int height;

  /** Indicates whether the playfield should can be scrolled around depending
      on the position of the cursor in the small map */
  bool scroll_mode;

  bool has_focus;

  /** Pointer to the current GC, only valid inside draw() */
  DrawingContext* gc_ptr;

public:
  SmallMap(GameSession* c);
  virtual ~SmallMap();

  /*{ @name Stuff called from the GUIManager */
  void on_primary_button_press(int x, int y);
  void on_primary_button_release(int x, int y);
  void on_pointer_move(int x, int y);

  // Events
  void on_pointer_enter ();
  void on_pointer_leave ();

  void set_session(GameSession* c);

  bool is_at (int x, int y);
  bool mouse_over();

  void draw(DrawingContext& gc);
  void update(float delta);
  /*}*/

  /** draws a symbolic sprite onto the smallmap
      @param sprite the Sprite to draw, it will keep its original size
      @param pos the position to draw it in World COs, it will get
      recalculated to screen CO */
  void draw_sprite(Sprite sprite, Vector3f pos);

private:
  SmallMap (const SmallMap&);
  SmallMap& operator= (const SmallMap&);
};


#endif

/* EOF */
