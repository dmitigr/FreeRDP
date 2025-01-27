/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * FreeRDP Interface
 *
 * Copyright 2009-2011 Jay Sorg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_API_H
#define FREERDP_API_H

#include <winpr/winpr.h>
#include <winpr/platform.h>

#ifdef _WIN32
#define FREERDP_CC __cdecl
#else
#define FREERDP_CC
#endif

#if defined _WIN32 || defined __CYGWIN__
#ifdef FREERDP_EXPORTS
#ifdef __GNUC__
#define FREERDP_API __attribute__((dllexport))
#else
#define FREERDP_API __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define FREERDP_API __attribute__((dllimport))
#else
#define FREERDP_API __declspec(dllimport)
#endif
#endif
#else
#if __GNUC__ >= 4
#define FREERDP_API __attribute__((visibility("default")))
#else
#define FREERDP_API
#endif
#endif

#if defined(EXPORT_ALL_SYMBOLS)
#define FREERDP_LOCAL FREERDP_API
#else
#if defined _WIN32 || defined __CYGWIN__
#define FREERDP_LOCAL
#else
#if __GNUC__ >= 4
#define FREERDP_LOCAL __attribute__((visibility("hidden")))
#else
#define FREERDP_LOCAL
#endif
#endif
#endif

#define IFCALL(_cb, ...)      \
	do                        \
	{                         \
		if (_cb != NULL)      \
		{                     \
			_cb(__VA_ARGS__); \
		}                     \
	} while (0)
#define IFCALLRET(_cb, _ret, ...)    \
	do                               \
	{                                \
		if (_cb != NULL)             \
		{                            \
			_ret = _cb(__VA_ARGS__); \
		}                            \
	} while (0)
#define IFCALLRESULT(_default_return, _cb, ...) \
	((_cb != NULL) ? _cb(__VA_ARGS__) : (_default_return))

#ifdef __GNUC__
#define ALIGN64 __attribute__((aligned(8)))
#else
#ifdef _WIN32
#define ALIGN64 __declspec(align(8))
#else
#define ALIGN64
#endif
#endif

#endif /* FREERDP_API */
