/**
 * Copyright (C) 2011-2013 Aratelia Limited - Juan A. Rubio
 *
 * This file is part of Tizonia
 *
 * Tizonia is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Tizonia is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tizonia.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   OMX_TizoniaExt.h
 * @author Juan A. Rubio <juan.rubio@aratelia.com>
 *
 * @brief  Tizonia OpenMAX IL - OpenMAX IL Extensions
 *
 *
 */

#ifndef OMX_TizoniaExt_h
#define OMX_TizoniaExt_h

#include "OMX_Core.h"
#include "OMX_Types.h"
#include "OMX_Audio.h"

#define OMX_TIZONIA_PORTSTATUS_AWAITBUFFERSRETURN   0x00000004


/**
 * Extension index used to select or deselect the buffer pre-announcements
 * feature on a particular port.
 */
#define OMX_TizoniaIndexParamBufferPreAnnouncementsMode OMX_IndexVendorStartUnused + 1

/**
 * The name of the pre-announcements mode extension.
 */
#define OMX_TIZONIA_INDEX_PARAM_BUFFER_PREANNOUNCEMENTSMODE     \
  "OMX.Tizonia.index.param.preannouncementsmode"

typedef struct OMX_TIZONIA_PARAM_BUFFER_PREANNOUNCEMENTSMODETYPE
{
  OMX_U32 nSize;
  OMX_VERSIONTYPE nVersion;
  OMX_U32 nPortIndex;
  OMX_BOOL bEnabled;
} OMX_TIZONIA_PARAM_BUFFER_PREANNOUNCEMENTSMODETYPE;

/**
 * Icecast-like audio renderer components
 */

#define OMX_ROLE_AUDIO_RENDERER_ICECAST_MP3    "audio_renderer.icecast.mp3"
#define OMX_ROLE_AUDIO_RENDERER_ICECAST_VORBIS "audio_renderer.icecast.vorbis"
#define OMX_ROLE_AUDIO_RENDERER_ICECAST_OPUS   "audio_renderer.icecast.opus"

#define OMX_TizoniaIndexParamHttpServer 0x7F000002           /**< reference: OMX_TIZONIA_HTTPSERVERTYPE */
#define OMX_TizoniaIndexParamIcecastMountpoint 0x7F000003    /**< reference: OMX_TIZONIA_ICECASTMOUNTPOINTTYPE */
#define OMX_TizoniaIndexConfigIcecastMetadata 0x7F000004     /**< reference: OMX_TIZONIA_ICECASTMETADATATYPE */

typedef struct OMX_TIZONIA_HTTPSERVERTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_STRING cBindAddress;
    OMX_U32 nListeningPort;
    OMX_U32 nMaxClients;
} OMX_TIZONIA_HTTPSERVERTYPE;

typedef struct OMX_TIZONIA_ICECASTMOUNTPOINTTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_U8 cMountName[OMX_MAX_STRINGNAME_SIZE];
    OMX_U8 cStationName[OMX_MAX_STRINGNAME_SIZE];
    OMX_U8 cStationDescription[OMX_MAX_STRINGNAME_SIZE];
    OMX_U8 cStationGenre[OMX_MAX_STRINGNAME_SIZE];
    OMX_U8 cStationUrl[OMX_MAX_STRINGNAME_SIZE];
    OMX_AUDIO_CODINGTYPE eEncoding;
    OMX_U32 nIcyMetadataPeriod;
    OMX_BOOL bBurstOnConnect;
    OMX_U32 nInitialBurstSize;
    OMX_U32 nMaxClients;
} OMX_TIZONIA_ICECASTMOUNTPOINTTYPE;

#define OMX_TIZONIA_MAX_SHOUTCAST_METADATA_SIZE OMX_MAX_STRINGNAME_SIZE

typedef struct OMX_TIZONIA_ICECASTMETADATATYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_U8 cStreamTitle[1];     /* Max length is OMX_TIZONIA_MAX_SHOUTCAST_METADATA_SIZE */
} OMX_TIZONIA_ICECASTMETADATATYPE;

/**
 * Opus encoder/decoder components
 * References:
 * - http://tools.ietf.org/html/rfc6716
 * - http://www.opus-codec.org/
 *
 * Description: (from opus-codec.org)
 *     Bit-rates from 6 kb/s to 510 kb/s
 *     Sampling rates from 8 kHz (narrowband) to 48 kHz (fullband)
 *     Frame sizes from 2.5 ms to 60 ms
 *     Support for both constant bit-rate (CBR) and variable bit-rate (VBR)
 *     Audio bandwidth from narrowband to fullband
 *     Support for speech and music
 *     Support for mono and stereo
 *     Support for up to 255 channels (multistream frames)
 *     Dynamically adjustable bitrate, audio bandwidth, and frame size
 *     Good loss robustness and packet loss concealment (PLC)
 *     Floating point and fixed-point implementation
 */

#define OMX_ROLE_AUDIO_ENCODER_OPUS "audio_encoder.opus"
#define OMX_ROLE_AUDIO_DECODER_OPUS "audio_decoder.opus"

/**
 * Extension index used to select or deselect the buffer pre-announcements
 * feature on a particular port.
 */
#define OMX_IndexParamAudioOpus OMX_IndexVendorStartUnused + 2 /**< reference: OMX_AUDIO_PARAM_OPUSTYPE */

/**
 * OMX_AUDIO_CODINGTYPE extension
 */
#define OMX_AUDIO_CodingOPUS OMX_AUDIO_CodingVendorStartUnused + 1

typedef enum OMX_AUDIO_OPUSSTREAMFORMATTYPE {
    OMX_AUDIO_OPUSStreamFormatVBR = 0,
    OMX_AUDIO_OPUSStreamFormatCBR,
    OMX_AUDIO_OPUSStreamFormatConstrainedVBR,
    OMX_AUDIO_OPUSStreamFormatHardCBR,
    OMX_AUDIO_OPUSStreamFormatUnknown           = 0x6EFFFFFF,
    OMX_AUDIO_OPUSStreamFormatKhronosExtensions = 0x6F000000, /**< Reserved region for introducing Khronos Standard Extensions */ 
    OMX_AUDIO_OPUSStreamFormatVendorStartUnused = 0x7F000000, /**< Reserved region for introducing Vendor Extensions */
    OMX_AUDIO_OPUSStreamFormatMax = 0x7FFFFFFF
} OMX_AUDIO_OPUSSTREAMFORMATTYPE;

typedef struct OMX_AUDIO_PARAM_OPUSTYPE {
    OMX_U32 nSize;
    OMX_VERSIONTYPE nVersion;
    OMX_U32 nPortIndex;
    OMX_U32 nChannels;
    OMX_U32 nBitRate; /** 6-256 per channel */
    OMX_U32 nSampleRate; /** 8 kHz (narrowband) to 48 kHz (fullband) */
    OMX_S32 nFrameDuration; /** 2.5, 5, 10, 20, 40, or 60 ms. */
    OMX_U32 nEncoderComplexity; /** From 0 to 10, default 0 */
    OMX_BOOL bPacketLossResilience; /** default, false  */
    OMX_BOOL bForwardErrorCorrection; /** default, false  */
    OMX_BOOL bDtx; /** default, false  */
    OMX_AUDIO_CHANNELMODETYPE eChannelMode;
    OMX_AUDIO_OPUSSTREAMFORMATTYPE eFormat;
} OMX_AUDIO_PARAM_OPUSTYPE;

#endif /* OMX_TizoniaExt_h */
