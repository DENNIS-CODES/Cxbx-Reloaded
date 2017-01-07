// ******************************************************************
// *
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : io.h
// *
// * note : XBox Kernel *I/O Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_IO_H
#define XBOXKRNL_IO_H

// ******************************************************************
// * 0x003B - IoAllocateIrp()
// ******************************************************************
XBSYSAPI EXPORTNUM(59) PVOID NTAPI IoAllocateIrp
(
	IN CHAR StackSize
);

// ******************************************************************
// * 0x003C - IoBuildAsynchronousFsdRequest()
// ******************************************************************
XBSYSAPI EXPORTNUM(60) PVOID NTAPI IoBuildAsynchronousFsdRequest
(
	IN ULONG MajorFunction,
	PDEVICE_OBJECT	DeviceObject,
	OUT PVOID Buffer OPTIONAL,
	ULONG Length OPTIONAL,
	PLARGE_INTEGER StartingOffset OPTIONAL,
	PIO_STATUS_BLOCK IoStatusBlock OPTIONAL
);

// ******************************************************************
// * 0x003D - IoBuildDeviceIoControlRequest()
// ******************************************************************
XBSYSAPI EXPORTNUM(61) PVOID NTAPI IoBuildDeviceIoControlRequest
(
	IN ULONG IoControlCode,
	IN PDEVICE_OBJECT DeviceObject,
	IN PVOID InputBuffer OPTIONAL,
	IN ULONG InputBufferLength,
	OUT PVOID OutputBuffer OPTIONAL,
	IN ULONG OutputBufferLength OPTIONAL,
	BOOLEAN InternalDeviceIoControl,
	PKEVENT Event,
	OUT PIO_STATUS_BLOCK IoStatusBlock OPTIONAL
);

// ******************************************************************
// * 0x003E - IoBuildSynchronousFsdRequest()
// ******************************************************************
XBSYSAPI EXPORTNUM(62) PVOID NTAPI IoBuildSynchronousFsdRequest
(
	IN ULONG MajorFunction,
	IN PDEVICE_OBJECT DeviceObject,
	OUT PVOID Buffer OPTIONAL,
	IN ULONG Length OPTIONAL,
	PLARGE_INTEGER StartingOffset OPTIONAL,
	PKEVENT Event,
	OUT PIO_STATUS_BLOCK IoStatusBlock
);

// ******************************************************************
// * 0x003F - IoCheckShareAccess()
// ******************************************************************
XBSYSAPI EXPORTNUM(63) NTSTATUS NTAPI IoCheckShareAccess
(
	IN ACCESS_MASK DesiredAccess,
	IN ULONG DesiredShareAccess,
	OUT PFILE_OBJECT FileObject,
	OUT PSHARE_ACCESS ShareAccess,
	IN BOOLEAN Update
);

// ******************************************************************
// * 0x0040 - IoCompletionObjectType
// ******************************************************************
XBSYSAPI EXPORTNUM(64) OBJECT_TYPE IoCompletionObjectType;

// ******************************************************************
// * 0x0041 - IoCreateDevice()
// ******************************************************************
XBSYSAPI EXPORTNUM(65) NTSTATUS NTAPI IoCreateDevice
(
	IN  PDRIVER_OBJECT		DriverObject,
	IN  ULONG				DeviceExtensionSize,
	IN  PSTRING				DeviceName  OPTIONAL,
	IN  ULONG				DeviceType,
	IN  BOOLEAN				Exclusive,
	OUT PDEVICE_OBJECT*		DeviceObject
);

// ******************************************************************
// * 0x0042 - IoCreateFile()
// ******************************************************************
XBSYSAPI EXPORTNUM(66) NTSTATUS NTAPI IoCreateFile
(
    OUT PHANDLE             FileHandle,
    IN  ACCESS_MASK         DesiredAccess,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes,
    OUT PIO_STATUS_BLOCK    IoStatusBlock,
    IN  PLARGE_INTEGER      AllocationSize,
    IN  ULONG               FileAttributes,
    IN  ULONG               ShareAccess,
    IN  ULONG               Disposition,
    IN  ULONG               CreateOptions,
    IN  ULONG               Options
);

// ******************************************************************
// * 0x0043 - IoCreateSymbolicLink()
// ******************************************************************
XBSYSAPI EXPORTNUM(67) NTSTATUS NTAPI IoCreateSymbolicLink
(
    IN PSTRING SymbolicLinkName,
    IN PSTRING DeviceName
);

// ******************************************************************
// * 0x0044 - IoDeleteDevice()
// ******************************************************************
XBSYSAPI EXPORTNUM(68) VOID NTAPI IoDeleteDevice
(
	IN PDEVICE_OBJECT irql
);

// ******************************************************************
// * 0x0045 - IoDeleteSymbolicLink
// ******************************************************************
XBSYSAPI EXPORTNUM(69) NTSTATUS NTAPI IoDeleteSymbolicLink
(
    IN PSTRING SymbolicLinkName
);

// ******************************************************************
// * 0x0046 - IoDeviceObjectType
// ******************************************************************
XBSYSAPI EXPORTNUM(70) OBJECT_TYPE IoDeviceObjectType;

// ******************************************************************
// * 0x0047 - IoFileObjectType
// ******************************************************************
XBSYSAPI EXPORTNUM(71) OBJECT_TYPE IoFileObjectType;

// ******************************************************************
// * 0x0048 - IoFreeIrp()
// ******************************************************************
XBSYSAPI EXPORTNUM(72) VOID NTAPI IoFreeIrp
(
	IN PIRP Irp
);

// ******************************************************************
// * 0x0049 - IoInitializeIrp()
// ******************************************************************
XBSYSAPI EXPORTNUM(73) PVOID NTAPI IoInitializeIrp
(
	IN PIRP Irp,
	IN USHORT PacketSize,
	IN CHAR StackSize
);

XBSYSAPI VOID *IoInvalidDeviceRequest;
XBSYSAPI VOID *IoQueryFileInformation;
XBSYSAPI VOID *IoQueryVolumeInformation;
XBSYSAPI VOID *IoQueueThreadIrp;
XBSYSAPI VOID *IoRemoveShareAccess;
XBSYSAPI VOID *IoSetIoCompletion;
XBSYSAPI VOID *IoSetShareAccess;
XBSYSAPI VOID *IoStartNextPacket;
XBSYSAPI VOID *IoStartNextPacketByKey;
XBSYSAPI VOID *IoStartPacket;
XBSYSAPI VOID *IoSynchronousDeviceIoControlRequest;
XBSYSAPI VOID *IoSynchronousFsdRequest;
XBSYSAPI VOID *IofCallDriver;
XBSYSAPI VOID *IofCompleteRequest;

// ******************************************************************
// * 0x005A - IoDismountVolume()
// ******************************************************************
XBSYSAPI EXPORTNUM(90) NTSTATUS NTAPI IoDismountVolume
(
	IN PDEVICE_OBJECT DeviceObject
);

// ******************************************************************
// * 0x005B - IoDismountVolumeByName()
// ******************************************************************
XBSYSAPI EXPORTNUM(91) NTSTATUS NTAPI IoDismountVolumeByName
(
	IN PSTRING VolumeName
);

XBSYSAPI VOID *IoMarkIrpMustComplete;

#endif


