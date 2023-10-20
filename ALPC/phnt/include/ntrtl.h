/*
* RTL support functions
*
* This file is part of System Informer.
*/

#ifndef _NTRTL_H
#define _NTRTL_H

#include "phnt_ntdef.h"

#define RtlOffsetToPointer(Base, Offset) ((PCHAR)(((PCHAR)(Base)) + ((ULONG_PTR)(Offset))))
#define RtlPointerToOffset(Base, Pointer) ((ULONG)(((PCHAR)(Pointer)) - ((PCHAR)(Base))))

#define RTL_PTR_ADD(Pointer, Value) ((PVOID)((ULONG_PTR)(Pointer) + (ULONG_PTR)(Value)))
#define RTL_PTR_SUBTRACT(Pointer, Value) ((PVOID)((ULONG_PTR)(Pointer) - (ULONG_PTR)(Value)))

#define RTL_MILLISEC_TO_100NANOSEC(m) ((m) * 10000ui64)
#define RTL_SEC_TO_100NANOSEC(s) ((s) * 10000000ui64)
#define RTL_SEC_TO_MILLISEC(s) ((s) * 1000ui64)

#define RTL_MEG (1024UL * 1024UL)
#define RTL_IMAGE_MAX_DOS_HEADER (256UL * RTL_MEG)


NTSYSAPI
VOID
NTAPI
RtlInitUnicodeString(
	_Out_ PUNICODE_STRING DestinationString,
	_In_opt_z_ __drv_aliasesMem PCWSTR SourceString
);

NTSYSAPI
NTSTATUS
NTAPI
ZwCreateSection(
	_Out_ PHANDLE SectionHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_opt_ PLARGE_INTEGER MaximumSize,
	_In_ ULONG SectionPageProtection,
	_In_ ULONG AllocationAttributes,
	_In_opt_ HANDLE FileHandle
);

#endif // _NTRTL_FWD_H

