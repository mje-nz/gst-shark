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

#include "gstsharkhelpers.h"

GstElement *
gst_shark_get_parent_element (GstPad * pad)
{
  GstElement *element;
  GstObject *parent;
  GstObject *child = GST_OBJECT (pad);

  do {
    parent = GST_OBJECT_PARENT (child);

    if (GST_IS_ELEMENT (parent))
      break;

    child = parent;

  } while (GST_IS_OBJECT (child));

  element = gst_pad_get_parent_element (GST_PAD (child));

  return element;
}

gchar *
gst_shark_get_parent_bin_name (GstElement * element)
{
  GstObject *object;
  GString *path;
  gchar *result;
  GSList *bins = NULL;
  GSList *iter;

  if (!element)
    return g_strdup ("");

  object = GST_OBJECT_PARENT (element);

  /* Traverse up the hierarchy collecting all bins (excluding pipelines) */
  while (object) {
    if (GST_IS_BIN (object) && !GST_IS_PIPELINE (object)) {
      bins = g_slist_prepend (bins, object);
    }
    object = GST_OBJECT_PARENT (object);
  }

  if (!bins) {
    return g_strdup ("");
  }

  /* Build the path string */
  path = g_string_new (NULL);
  for (iter = bins; iter != NULL; iter = iter->next) {
    if (path->len > 0) {
      g_string_append_c (path, '/');
    }
    g_string_append (path, GST_OBJECT_NAME (iter->data));
  }

  g_slist_free (bins);
  result = g_string_free (path, FALSE);

  return result;
}
