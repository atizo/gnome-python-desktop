/* 
 * Copyright (C) 2004 Tiago Cogumbreiro <cogumbreiro@users.sf.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Authors: Tiago Cogumbreiro <cogumbreiro@users.sf.net>
 */

#include <nautilus-burn-drive.h>
#include <nautilus-burn-recorder.h>
#include <nautilus-burn-drive-selection.h>

GType
nautilus_burn_media_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NAUTILUS_BURN_MEDIA_TYPE_BUSY, "NAUTILUS_BURN_MEDIA_TYPE_BUSY", "busy" },
      { NAUTILUS_BURN_MEDIA_TYPE_ERROR, "NAUTILUS_BURN_MEDIA_TYPE_ERROR", "error" },
      { NAUTILUS_BURN_MEDIA_TYPE_UNKNOWN, "NAUTILUS_BURN_MEDIA_TYPE_UNKNOWN", "unknown" },
      { NAUTILUS_BURN_MEDIA_TYPE_CD, "NAUTILUS_BURN_MEDIA_TYPE_CD", "cd" },
      { NAUTILUS_BURN_MEDIA_TYPE_CDR, "NAUTILUS_BURN_MEDIA_TYPE_CDR", "cdr" },
      { NAUTILUS_BURN_MEDIA_TYPE_CDRW, "NAUTILUS_BURN_MEDIA_TYPE_CDRW", "cdrw" },
      { NAUTILUS_BURN_MEDIA_TYPE_DVD, "NAUTILUS_BURN_MEDIA_TYPE_DVD", "dvd" },
      { NAUTILUS_BURN_MEDIA_TYPE_DVDR, "NAUTILUS_BURN_MEDIA_TYPE_DVDR", "dvdr" },
      { NAUTILUS_BURN_MEDIA_TYPE_DVDRW, "NAUTILUS_BURN_MEDIA_TYPE_DVDRW", "dvdrw" },
      { NAUTILUS_BURN_MEDIA_TYPE_DVD_RAM, "NAUTILUS_BURN_MEDIA_TYPE_DVD_RAM", "dvd-ram" },
      { NAUTILUS_BURN_MEDIA_TYPE_DVD_PLUS_R, "NAUTILUS_BURN_MEDIA_TYPE_DVD_PLUS_R", "dvd-plus-r" },
      { NAUTILUS_BURN_MEDIA_TYPE_DVD_PLUS_RW, "NAUTILUS_BURN_MEDIA_TYPE_DVD_PLUS_RW", "dvd-plus-rw" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("NautilusBurnMediaType", values);
  }
  return etype;
}

GType
nautilus_burn_drive_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { NAUTILUS_BURN_DRIVE_TYPE_FILE, "NAUTILUS_BURN_DRIVE_TYPE_FILE", "file" },
      { NAUTILUS_BURN_DRIVE_TYPE_CD_RECORDER, "NAUTILUS_BURN_DRIVE_TYPE_CD_RECORDER", "cd-recorder" },
      { NAUTILUS_BURN_DRIVE_TYPE_CDRW_RECORDER, "NAUTILUS_BURN_DRIVE_TYPE_CDRW_RECORDER", "cdrw-recorder" },
      { NAUTILUS_BURN_DRIVE_TYPE_DVD_RAM_RECORDER, "NAUTILUS_BURN_DRIVE_TYPE_DVD_RAM_RECORDER", "dvd-ram-recorder" },
      { NAUTILUS_BURN_DRIVE_TYPE_DVD_RW_RECORDER, "NAUTILUS_BURN_DRIVE_TYPE_DVD_RW_RECORDER", "dvd-rw-recorder" },
      { NAUTILUS_BURN_DRIVE_TYPE_DVD_PLUS_R_RECORDER, "NAUTILUS_BURN_DRIVE_TYPE_DVD_PLUS_R_RECORDER", "dvd-plus-r-recorder" },
      { NAUTILUS_BURN_DRIVE_TYPE_DVD_PLUS_RW_RECORDER, "NAUTILUS_BURN_DRIVE_TYPE_DVD_PLUS_RW_RECORDER", "dvd-plus-rw-recorder" },
      { NAUTILUS_BURN_DRIVE_TYPE_CD_DRIVE, "NAUTILUS_BURN_DRIVE_TYPE_CD_DRIVE", "cd-drive" },
      { NAUTILUS_BURN_DRIVE_TYPE_DVD_DRIVE, "NAUTILUS_BURN_DRIVE_TYPE_DVD_DRIVE", "dvd-drive" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("NautilusBurnDriveType", values);
  }
  return etype;
}


GType
nautilus_burn_recorder_track_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NAUTILUS_BURN_RECORDER_TRACK_TYPE_AUDIO, "NAUTILUS_BURN_RECORDER_TRACK_TYPE_AUDIO", "audio" },
      { NAUTILUS_BURN_RECORDER_TRACK_TYPE_DATA, "NAUTILUS_BURN_RECORDER_TRACK_TYPE_DATA", "data" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("NautilusBurnRecorderTrackType", values);
  }
  return etype;
}

GType
nautilus_burn_recorder_blank_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NAUTILUS_BURN_RECORDER_BLANK_FAST, "NAUTILUS_BURN_RECORDER_BLANK_FAST", "fast" },
      { NAUTILUS_BURN_RECORDER_BLANK_FULL, "NAUTILUS_BURN_RECORDER_BLANK_FULL", "full" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("NautilusBurnRecorderBlankType", values);
  }
  return etype;
}

GType
nautilus_burn_recorder_result_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NAUTILUS_BURN_RECORDER_RESULT_ERROR, "NAUTILUS_BURN_RECORDER_RESULT_ERROR", "error" },
      { NAUTILUS_BURN_RECORDER_RESULT_CANCEL, "NAUTILUS_BURN_RECORDER_RESULT_CANCEL", "cancel" },
      { NAUTILUS_BURN_RECORDER_RESULT_FINISHED, "NAUTILUS_BURN_RECORDER_RESULT_FINISHED", "finished" },
      { NAUTILUS_BURN_RECORDER_RESULT_RETRY, "NAUTILUS_BURN_RECORDER_RESULT_RETRY", "retry" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("NautilusBurnRecorderResult", values);
  }
  return etype;
}

GType
nautilus_burn_recorder_write_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { NAUTILUS_BURN_RECORDER_WRITE_EJECT, "NAUTILUS_BURN_RECORDER_WRITE_EJECT", "eject" },
      { NAUTILUS_BURN_RECORDER_WRITE_BLANK, "NAUTILUS_BURN_RECORDER_WRITE_BLANK", "blank" },
      { NAUTILUS_BURN_RECORDER_WRITE_DUMMY_WRITE, "NAUTILUS_BURN_RECORDER_WRITE_DUMMY_WRITE", "dummy-write" },
      { NAUTILUS_BURN_RECORDER_WRITE_DISC_AT_ONCE, "NAUTILUS_BURN_RECORDER_WRITE_DISC_AT_ONCE", "disc-at-once" },
      { NAUTILUS_BURN_RECORDER_WRITE_DEBUG, "NAUTILUS_BURN_RECORDER_WRITE_DEBUG", "debug" },
      { NAUTILUS_BURN_RECORDER_WRITE_OVERBURN, "NAUTILUS_BURN_RECORDER_WRITE_OVERBURN", "overburn" },
      { NAUTILUS_BURN_RECORDER_WRITE_BURNPROOF, "NAUTILUS_BURN_RECORDER_WRITE_BURNPROOF", "burnproof" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("NautilusBurnRecorderWriteFlags", values);
  }
  return etype;
}

GType
nautilus_burn_recorder_actions_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NAUTILUS_BURN_RECORDER_ACTION_PREPARING_WRITE, "NAUTILUS_BURN_RECORDER_ACTION_PREPARING_WRITE", "preparing-write" },
      { NAUTILUS_BURN_RECORDER_ACTION_WRITING, "NAUTILUS_BURN_RECORDER_ACTION_WRITING", "writing" },
      { NAUTILUS_BURN_RECORDER_ACTION_FIXATING, "NAUTILUS_BURN_RECORDER_ACTION_FIXATING", "fixating" },
      { NAUTILUS_BURN_RECORDER_ACTION_BLANKING, "NAUTILUS_BURN_RECORDER_ACTION_BLANKING", "blanking" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("NautilusBurnRecorderActions", values);
  }
  return etype;
}

GType
nautilus_burn_recorder_media_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NAUTILUS_BURN_RECORDER_MEDIA_CD, "NAUTILUS_BURN_RECORDER_MEDIA_CD", "cd" },
      { NAUTILUS_BURN_RECORDER_MEDIA_DVD, "NAUTILUS_BURN_RECORDER_MEDIA_DVD", "dvd" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("NautilusBurnRecorderMedia", values);
  }
  return etype;
}
