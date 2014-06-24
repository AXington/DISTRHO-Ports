/**
 *
 * Copyright (c) 2013 Pascal Gauthier.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 */

#ifndef DXLOOKNFEEL_H_INCLUDED
#define DXLOOKNFEEL_H_INCLUDED

#include "JuceHeader.h"

class DXLookNFeel : public LookAndFeel_V3 {
public:
    static Colour dxDarkBrown;
    static Colour dxLightBrown;
    
    DXLookNFeel();
};

#endif  // DXLOOKNFEEL_H_INCLUDED
