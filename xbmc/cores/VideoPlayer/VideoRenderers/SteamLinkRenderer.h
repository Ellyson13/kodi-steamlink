/*
 *      Copyright (C) 2016 Team Kodi
 *      Copyright (C) 2016 Valve Corporation
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "system.h" // for HAS_GLES, needed for LinuxRendererGLES.h

#include "cores/VideoPlayer/VideoRenderers/LinuxRendererGLES.h"

namespace STEAMLINK
{

class CSteamLinkRenderer : public CLinuxRendererGLES
{
public:
  CSteamLinkRenderer() { }
  virtual ~CSteamLinkRenderer() { }

  // implementation of CBaseRenderer via CLinuxRendererGLES
  virtual bool IsGuiLayer() override { return false; }
  virtual bool SupportsMultiPassRendering() override { return false; }
  virtual bool Supports(ERENDERFEATURE feature) override { return false; }
  virtual bool Supports(ESCALINGMETHOD method) override { return false; }

protected:
  // implementation of CLinuxRendererGLES
  bool LoadShadersHook();
  bool RenderHook(int index) { return true; }
  bool RenderUpdateVideoHook(bool clear, DWORD flags = 0, DWORD alpha = 255) { return true; }
  int  GetImageHook(YV12Image *image, int source = -1, bool readonly = false);
};

}
