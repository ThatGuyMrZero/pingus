//  $Id: ice_block.cxx,v 1.24 2003/10/20 13:11:09 grumbel Exp $
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

#include "../col_map.hxx"
#include "../game_time.hxx"
#include "../display/scene_context.hxx"
#include "../pingu.hxx"
#include "../pingu_holder.hxx"
#include "../ground_map.hxx"
#include "../resource.hxx"
#include "../world.hxx"
#include "ice_block.hxx"

namespace WorldObjs {

IceBlock::IceBlock(const FileReader& reader)
  : thickness(1.0),
    is_finished(false),
    last_contact(0),
    block_sur(Resource::load_sprite ("worldobjs/iceblock"))
{
  reader.read_vector("position", pos);
  reader.read_int   ("width",    width);
}

void
IceBlock::on_startup ()
{
  PixelBuffer surf(Resource::load_pixelbuffer("worldobjs/iceblock_cmap"));

  world->get_colmap()->put(surf,
                           static_cast<int>(pos.x),
                           static_cast<int>(pos.y),
			   Groundtype::GP_GROUND);
}

void
IceBlock::draw (SceneContext& gc)
{
  if (is_finished)
    return;

  gc.color().draw(block_sur,
          pos);
					//, static_cast<int>((1.0 - thickness) * (block_sur.get_frame_count() - 1)));
}

void
IceBlock::update()
{
  if (is_finished)
    return;

  PinguHolder* holder = world->get_pingus();

  for (PinguIter pingu = holder->begin(); pingu != holder->end(); ++pingu)
    {
      if (   (*pingu)->get_x() > pos.x     && (*pingu)->get_x() < pos.x + block_sur.get_width()
	  && (*pingu)->get_y() > pos.y - 4 && (*pingu)->get_y() < pos.y + block_sur.get_height())
	{
	  last_contact = world->get_game_time()->get_ticks();
	}
    }

  if (last_contact && last_contact + 1000 > world->get_game_time()->get_ticks())
    {
      //std::cout << "IceBlock: Catched Pingu: " << thickness  << std::endl;
      thickness -= 0.01f;

      if (thickness < 0)
	{
	  is_finished = true;
	  thickness = 0;

	  PixelBuffer surf(Resource::load_pixelbuffer("worldobjs/iceblock_cmap"));
	  world->get_colmap ()->remove(surf, static_cast<int>(pos.x), static_cast<int>(pos.y));
	  world->get_gfx_map()->remove(surf, static_cast<int>(pos.x), static_cast<int>(pos.y));
	  return;
	}
    }
}

} // namespace WorldObjs

/* EOF */
