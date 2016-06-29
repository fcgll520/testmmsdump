#ifndef BSWAP_H_INCLUDED
#define BSWAP_H_INCLUDED

/*
 * Copyright (C) 2004 Maciej Katafiasz <mathrick@users.sourceforge.net>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


/* Go cheap now, will rip out glib later. *Sigh* */
//#include "glibconfig.h"

/* NOTE:
 * Now, to clear up confusion: LE_XX means "from LE to native, XX bits wide"
 * I know it's not very clear naming (tell me about it, I
 * misinterpreted in first version and caused bad nasty bug, *sigh*),
 * but that's inherited code, will clean up as things go
 * Oh, and one more thing -- they take *pointers*, not actual ints
 */

typedef signed char gint8;
typedef unsigned char guint8;
typedef signed short gint16;
typedef unsigned short guint16;
typedef signed int gint32;
typedef unsigned int guint32;
typedef signed __int64 gint64;
typedef unsigned __int64 guint64;


#define GUINT16_SWAP_LE_BE_CONSTANT(val)	((guint16) ( \
    (guint16) ((guint16) (val) >> 8) |	\
    (guint16) ((guint16) (val) << 8)))

#define GUINT32_SWAP_LE_BE_CONSTANT(val)	((guint32) ( \
    (((guint32) (val) & (guint32) 0x000000ffU) << 24) | \
    (((guint32) (val) & (guint32) 0x0000ff00U) <<  8) | \
    (((guint32) (val) & (guint32) 0x00ff0000U) >>  8) | \
    (((guint32) (val) & (guint32) 0xff000000U) >> 24)))

#define GUINT64_SWAP_LE_BE_CONSTANT(val)	((guint64) ( \
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x00000000000000ffU)) << 56) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x000000000000ff00U)) << 40) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x0000000000ff0000U)) << 24) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x00000000ff000000U)) <<  8) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x000000ff00000000U)) >>  8) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x0000ff0000000000U)) >> 24) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0x00ff000000000000U)) >> 40) |	\
      (((guint64) (val) &						\
	(guint64) G_GINT64_CONSTANT (0xff00000000000000U)) >> 56)))

#define GUINT16_SWAP_LE_BE(val) (GUINT16_SWAP_LE_BE_CONSTANT (val))
#define GUINT32_SWAP_LE_BE(val) (GUINT32_SWAP_LE_BE_CONSTANT (val))
#define GUINT64_SWAP_LE_BE(val) (GUINT64_SWAP_LE_BE_CONSTANT (val))

#define GINT16_TO_LE(val)	((gint16) (val))
#define GINT16_FROM_LE(val)	(GINT16_TO_LE (val))

#define GINT16_TO_BE(val)	((gint16) GUINT16_SWAP_LE_BE (val))
#define GINT16_FROM_BE(val)	(GINT16_TO_BE (val))

#define GINT32_TO_LE(val)	((gint32) (val))
#define GINT32_FROM_LE(val)	(GINT32_TO_LE (val))


#define GINT32_TO_BE(val)	((gint32) GUINT32_SWAP_LE_BE (val))
#define GINT32_FROM_BE(val)	(GINT32_TO_BE (val))

#define GINT64_TO_LE(val)	((gint64) (val))
#define GINT64_FROM_LE(val)	(GINT64_TO_LE (val))

#define GINT64_TO_BE(val)	((gint64) GUINT64_SWAP_LE_BE (val))
#define GINT64_FROM_BE(val)	(GINT64_TO_BE (val))

#define LE_16(val) (GINT16_FROM_LE (*((guint16*)(val))))
#define BE_16(val) (GINT16_FROM_BE (*((guint16*)(val))))

#define LE_32(val) (GINT32_FROM_LE (*((guint32*)(val))))
#define BE_32(val) (GINT32_FROM_BE (*((guint32*)(val))))

#define LE_64(val) (GINT64_FROM_LE (*((guint64*)(val))))
#define BE_64(val) (GINT64_FROM_BE (*((guint64*)(val))))

#endif /* BSWAP_H_INCLUDED */
