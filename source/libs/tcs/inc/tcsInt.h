/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TD_TCS_INT_H_
#define _TD_TCS_INT_H_

#include "os.h"
#include "tarray.h"
#include "tdef.h"
#include "tlog.h"
#include "tmsg.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int8_t tsS3Ablob;

typedef enum {
  TOS_PROTO_NIL,
  TOS_PROTO_S3,
  TOS_PROTO_ABLOB,
} STosProto;

typedef struct {
  int32_t (*Begin)();
  void (*End)();
  int32_t (*CheckCfg)();

  int32_t (*PutObjectFromFileOffset)(const char* file, const char* object_name, int64_t offset, int64_t size);
  int32_t (*GetObjectBlock)(const char* object_name, int64_t offset, int64_t size, bool check, uint8_t** ppBlock);

  void (*DeleteObjectsByPrefix)(const char* prefix);

  int32_t (*PutObjectFromFile2)(const char* file, const char* object, int8_t withcp);
  int32_t (*GetObjectsByPrefix)(const char* prefix, const char* path);
  int32_t (*DeleteObjects)(const char* object_name[], int nobject);
  int32_t (*GetObjectToFile)(const char* object_name, const char* fileName);
} STcs;

extern STcs tcs;

#ifdef __cplusplus
}
#endif

#endif  // _TD_TCS_INT_H_
