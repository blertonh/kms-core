/*
 * (C) Copyright 2014 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "kmsagnosticbin3.h"

#define PLUGIN_NAME "agnosticbin3"

#define GST_CAT_DEFAULT kms_agnostic_bin3_debug
GST_DEBUG_CATEGORY_STATIC (GST_CAT_DEFAULT);

#define kms_agnostic_bin3_parent_class parent_class
G_DEFINE_TYPE (KmsAgnosticBin3, kms_agnostic_bin3, GST_TYPE_BIN);

#define KMS_AGNOSTIC_BIN3_GET_PRIVATE(obj) ( \
  G_TYPE_INSTANCE_GET_PRIVATE (              \
    (obj),                                   \
    KMS_TYPE_AGNOSTIC_BIN3,                  \
    KmsAgnosticBin3Private                   \
  )                                          \
)

struct _KmsAgnosticBin3Private
{
  guint src_pad_count;
};

static void
kms_agnostic_bin3_class_init (KmsAgnosticBin3Class * klass)
{
  GstElementClass *gstelement_class;

  gstelement_class = GST_ELEMENT_CLASS (klass);

  gst_element_class_set_details_simple (gstelement_class,
      "Agnostic connector 3rd version",
      "Generic/Bin/Connector",
      "Automatically encodes/decodes media to match sink and source pads caps",
      "Santiago Carot-Nemesio <sancane_at_gmail_dot_com>");

  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, PLUGIN_NAME, 0, PLUGIN_NAME);

  g_type_class_add_private (klass, sizeof (KmsAgnosticBin3Private));
}

static void
kms_agnostic_bin3_init (KmsAgnosticBin3 * self)
{
  self->priv = KMS_AGNOSTIC_BIN3_GET_PRIVATE (self);

  g_object_set (G_OBJECT (self), "async-handling", TRUE, NULL);
}

gboolean
kms_agnostic_bin3_plugin_init (GstPlugin * plugin)
{
  return gst_element_register (plugin, PLUGIN_NAME, GST_RANK_NONE,
      KMS_TYPE_AGNOSTIC_BIN3);
}