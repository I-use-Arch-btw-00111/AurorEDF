/**
 * -------------------------------------------------------------------------
 *                                   AurorOS
 * (c) 2022-2025 Interpuce
 * 
 * You should receive AurorOS license with this source code. If not - check:
 *  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#pragma once

#include <msg.h>
#include <types.h>
#include <screen.h>

extern void invalidop(const char *operation, void (*handler)());

// NOTE 1: 'operation', unlike kernelpanic()'s 'errcode', is supposed to be user-friendly.
/* NOTE 2: 'handler' cannot be NULL. Without handler, the function will crash - in some sensitive situations, this could be a security risk. 
	   To avoid such risks, invalidop() will call a KERNEL PANIC if second argument ('handler') is NULL. This is the intended behavior and is NOT to be changed.*/