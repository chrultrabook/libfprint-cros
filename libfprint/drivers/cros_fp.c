/*
 * ChromeOS Fingerprint driver for libfprint
 *
 * Copyright (C) 2023 WeirdTreeThing <bradyn127@protonmail.com>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#define FP_COMPONENT "cros_fp"

#include "drivers_api.h"
#include "cros_fp.h"

struct _FpiDeviceCrosFp
{
  FpDevice   parent;
  int        fpmode;
  int        fd;         
};

G_DEFINE_TYPE (FpiDeviceCrosFp, fpi_device_cros_fp, FP_TYPE_DEVICE);

static const FpIdEntry id_table[] = {
  { .vid = 0x1d6b,  .pid = 0x0002,  },
  { .vid = 0,  .pid = 0,  .driver_data = 0 },
};

static void
fpi_device_cros_fp_class_init (FpiDeviceCrosFpClass *klass)
{
  FpDeviceClass *dev_class = FP_DEVICE_CLASS (klass);

  dev_class->id = "cros_fp";
  dev_class->full_name = "ChromeOS Fingerprint Scanner";
  dev_class->type = FP_DEVICE_TYPE_USB;
  dev_class->id_table = id_table;
  dev_class->nr_enroll_stages = 5;
  dev_class->scan_type = FP_SCAN_TYPE_PRESS;
  fpi_device_class_auto_initialize_features (dev_class);

  //dev_class->open = dev_init;
  //dev_class->close = dev_exit;
  //dev_class->probe = dev_probe;
  //dev_class->verify = verify;
  //dev_class->identify = identify;
  //dev_class->enroll = enroll;
  //dev_class->delete = delete_print;
  //dev_class->clear_storage = clear_storage;
  //dev_class->cancel = cancel;
  //dev_class->suspend = suspend;
  //dev_class->resume = resume;
}
