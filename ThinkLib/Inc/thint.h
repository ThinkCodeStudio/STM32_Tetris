#ifndef __THINT_H__
#define __THINT_H__
#include "stdint.h"

#define i8 		int8_t
#define i16		int16_t
#define i32 	int32_t
#define i64		int64_t

#define vi8 	volatile int8_t
#define vi16	volatile int16_t
#define vi32 	volatile int32_t
#define vi64	volatile int64_t

#define ci8 	const int8_t
#define ci16	const int16_t
#define ci32 	const int32_t
#define ci64	const int64_t

#define u8		uint8_t
#define u16		uint16_t
#define u32		uint32_t
#define u64		uint64_t

#define vu8		volatile uint8_t
#define vu16	volatile uint16_t
#define vu32	volatile uint32_t
#define vu64	volatile uint64_t

#define cu8		const uint8_t
#define cu16	const uint16_t
#define cu32	const uint32_t
#define cu64	const uint64_t

#define f32		float
#define f64		double

#define cf32	const float
#define cf64	const double

//#define bool	_Bool
typedef enum {FALSE = 0,TRUE = 1} bool;

#define I8_MIN 	INT8_MIN
#define I16_MIN INT16_MIN
#define I32_MIN	INT32_MIN
#define I64_MIN	INT64_MIN

#define I8_MAX 	INT8_MAX
#define I16_MAX INT16_MAX
#define I32_MAX	INT32_MAX
#define I64_MAX	INT64_MAX

#define U8_MAX 	UINT8_MAX
#define U16_MAX UINT16_MAX
#define U32_MAX	UINT32_MAX
#define U64_MAX	UINT64_MAX

#endif
