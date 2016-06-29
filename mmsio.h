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
 * $Id: mmsio.h,v 1.2 2005/12/12 09:24:19 theuraeus Exp $
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
#ifndef __MMS_IO_H__
#define __MMS_IO_H__

#include "mms_config.h"

/* On 64 bit file offset capable systems, libmms' configure script adds
   -D_FILE_OFFSET_BITS=64 to the CFLAGS. This causes off_t to be 64 bit,
   When an app which includes this header file gets compiled without
   -D_FILE_OFFSET_BITS=64, it should still expect / pass 64 bit ints for
   off_t, this acomplishes this: */
typedef __int64           int64_t;
typedef long off_t;

#if defined LIBMMS_HAVE_64BIT_OFF_T && !defined __MMS_C__
#define mms_off_t int64_t
#else
#define mms_off_t off_t
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef mms_off_t (*mms_io_write_func)(void *data, int socket, char *buf, mms_off_t num);
typedef mms_off_t (*mms_io_read_func)(void *data, int socket, char *buf, mms_off_t num);

/* select states */
#define MMS_IO_READ_READY    1
#define MMS_IO_WRITE_READY   2

enum
  {
    MMS_IO_STATUS_READY, 		/* IO can be safely performed */
    MMS_IO_STATUS_ERROR,		/* There was IO error */
    MMS_IO_STATUS_ABORTED,		/* IO command was (somehow)
	   aborted. This is not error, but invalidates IO for further operations*/
    MMS_IO_STATUS_TIMEOUT		/* Timeout was exceeded */
  };

/*
 * Waits for a file descriptor/socket to change status.
 *
 * users can use this handler to provide their own implementations,
 * for example abortable ones
 *
 * params :
 *   data          whatever parameter may be needed by implementation
 *   fd            file/socket descriptor
 *   state         MMS_IO_READ_READY, MMS_IO_WRITE_READY
 *   timeout_sec   timeout in seconds
 *
 *
 * return value :
 *   MMS_IO_READY     the file descriptor is ready for cmd
 *   MMS_IO_ERROR     an i/o error occured
 *   MMS_IO_ABORTED   command aborted
 *   MMS_IO_TIMEOUT   the file descriptor is not ready after timeout_msec milliseconds
 * every other return value is interpreted same as MMS_IO_ABORTED
 */
typedef int (*mms_io_select_func)(void *data, int fd, int state, int timeout_msec);

/*
 * open a tcp connection
 *
 * params :
 *   stream        needed for reporting errors but may be NULL
 *   host          address of target
 *   port          port on target
 *
 * returns a socket descriptor or -1 if an error occured
 */
//typedef int (*fallback_io_tcp_connect)(void *data, const char *host, int port);
typedef int (*mms_io_tcp_connect_func)(void *data, const char *host, int port);

typedef struct
{
  mms_io_select_func select;
  void *select_data;
  mms_io_read_func read;
  void *read_data;
  mms_io_write_func write;
  void *write_data;
  mms_io_tcp_connect_func  connect;
  void *connect_data;
} mms_io_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MMS_IO_H__ */