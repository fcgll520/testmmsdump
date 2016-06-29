/*
 * Copyright (C) 2000-2003 the xine project
 *
 * This file is part of xine, a free video player.
 *
 * xine is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * xine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 *
 * $Id: mmstest.c,v 1.2 2005/12/12 09:24:19 theuraeus Exp $
 *
 * demultiplexer for asf streams
 *
 * based on ffmpeg's
 * ASF compatible encoder and decoder.
 * Copyright (c) 2000, 2001 Gerard Lantau.
 *
 * GUID list from avifile
 * some other ideas from MPlayer
 */
/*此流媒体下载函数为修改的开源mms库函数
 **/

#include"mmsx.h"
void main()
{
	mmsdown("mms://alive.rbc.cn/fm1039","a.asf",60);
	//mmsdown("mms://mpl.dyndns.tv/videos/HAK/HAK007.wmv","HAK007.wmv",0);
}
