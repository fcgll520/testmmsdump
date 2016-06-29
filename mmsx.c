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
 * $Id: mmsx.c,v 1.2 2005/12/12 09:24:19 theuraeus Exp $
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
#include <stdlib.h>
#include "mmsx.h"
#include "mms.h"
//#include "mmsh.h"

struct mmsx_s {
  mms_t *connection;
//  mmsh_t *connection_h;
};

mmsx_t *mmsx_connect(mms_io_t *io, void *data, const char *url, int bandwidth)
{
  mmsx_t *mmsx = calloc(1, sizeof(mmsx_t));
  
  if (!mmsx)
    return mmsx;
    
  mmsx->connection = mms_connect(io, data, url, bandwidth);
  if (mmsx->connection)
    return mmsx;
    
 // mmsx->connection_h = mmsh_connect(io, data, url, bandwidth);
 // if (mmsx->connection_h)
 //   return mmsx;

  free(mmsx);
  return NULL;
}

double mmsx_read (mms_io_t *io, mmsx_t *mmsx, void *data, int len)
{
  if(mmsx->connection)
    return mms_read(io, mmsx->connection,data, len);
  else
    return 0;//mmsh_read(io, mmsx->connection_h, data, len);
}

void mmsx_close (mmsx_t *mmsx)
{
  if(mmsx->connection)
    mms_close(mmsx->connection);
 // else
  //  mmsh_close(mmsx->connection_h);

  free(mmsx);
}

void mmsdown(const char *url,const char *filename,double sumtime)
{
	mmsx_t* mmsx;
	mms_io_t *io = NULL;
	void *data;
	FILE *file;
	int length=1024;
	int bandwidth=1000;
	int stop=0;
	double time;

	file=fopen(filename,"wb+");
	data=file;
	mmsx=mmsx_connect (io, data, url,bandwidth);//请求文件头，开始接受asf数据
	while(!stop && mmsx != NULL)
	{
		time=mmsx_read (io, mmsx, file, length);//下载流媒体包，长度为length,返回音频时间
		if(sumtime > 0 && time>=sumtime)
			stop=1;
		//{
		//	int iresult;
		//	struct _stat buf;
		//	iresult = _stat(filename, &buf);
		//	printf("%f\n", (double)buf.st_size / 1024 / 1024);
		//}
	}
	if(mmsx)
		mmsx_close (mmsx);
	if(file)
		fclose(file);
}
