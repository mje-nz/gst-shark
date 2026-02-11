/* GstShark - A Front End for GstTracer
 * Copyright (C) 2016-2018 RidgeRun Engineering <carlos.rodriguez@ridgerun.com>
 *
 * This file is part of GstShark.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __GST_SHARK_HELPERS_H__
#define __GST_SHARK_HELPERS_H__

#include <gst/gst.h>

G_BEGIN_DECLS

/**
 * gst_shark_get_parent_element:
 * @pad: a #GstPad
 *
 * Gets the parent element of a pad, handling proxy pads correctly.
 *
 * Returns: (transfer full): the parent #GstElement, or NULL. Unref after use.
 */
GstElement * gst_shark_get_parent_element (GstPad * pad);

/**
 * gst_shark_get_parent_bin_name:
 * @element: a #GstElement
 *
 * Gets the hierarchical name of all parent bins (excluding pipelines).
 * Returns a path like "bin1/bin2/bin3" for nested bins.
 *
 * Returns: (transfer full): the bin path as a string, or an empty string if
 * no parent bins exist. Free with g_free() after use.
 */
gchar * gst_shark_get_parent_bin_name (GstElement * element);

G_END_DECLS

#endif /* __GST_SHARK_HELPERS_H__ */
