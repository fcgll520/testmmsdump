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
 * $Id: mms.h,v 1.2 2005/12/12 09:24:19 theuraeus Exp $
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
#ifndef HAVE_MMS_H
#define HAVE_MMS_H

#include "inttypes.h"
#include <stdio.h>
#include <sys/types.h>

/* #include "xine_internal.h" */

#include "bswap.h"
#include "mmsio.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct mms_s mms_t;

mms_t*   mms_connect (mms_io_t *io, void *data, const char *url, int bandwidth);

double      mms_read (mms_io_t *io, mms_t *instance, void *data, int len);

void     mms_close (mms_t *instance);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif