﻿// CodeGear C++Builder
// Copyright (c) 1995, 2014 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AbTarTyp.pas' rev: 28.00 (Windows)

#ifndef AbtartypHPP
#define AbtartypHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <AbUtils.hpp>	// Pascal unit
#include <AbArcTyp.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Abtartyp
{
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<char, 8> Arr8;

typedef System::StaticArray<char, 12> Arr12;

typedef System::StaticArray<System::Byte, 12> Arr12B;

typedef System::StaticArray<char, 100> ArrName;

enum DECLSPEC_DENUM TAbTarHeaderFormat : unsigned char { UNKNOWN_FORMAT, V7_FORMAT, OLDGNU_FORMAT, GNU_FORMAT, USTAR_FORMAT, STAR_FORMAT, POSIX_FORMAT };

enum DECLSPEC_DENUM TAbTarItemType : unsigned char { SUPPORTED_ITEM, UNSUPPORTED_ITEM, UNKNOWN_ITEM };

enum DECLSPEC_DENUM TAbTarHeaderType : unsigned char { FILE_HEADER, META_DATA_HEADER, MD_DATA_HEADER, UNKNOWN_HEADER };

enum DECLSPEC_DENUM TAbTarMagicType : unsigned char { GNU_OLD, NORMAL };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TAbTarMagicRec
{
	union
	{
		struct 
		{
			System::StaticArray<char, 6> value;
			System::StaticArray<char, 2> version;
		};
		struct 
		{
			System::StaticArray<char, 8> gnuOld;
		};
		
	};
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TAbTarEnd_Empty_Rec
{
public:
	System::StaticArray<System::Byte, 167> Empty;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TAbTarEnd_UStar_Rec
{
public:
	System::StaticArray<char, 155> Prefix;
	Arr12B Empty;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TAbTarEnd_GNU_old_Rec
{
public:
	Arr12 Atime;
	Arr12 Ctime;
	Arr12 Offset;
	System::StaticArray<System::Byte, 5> Empty1;
	System::StaticArray<System::Byte, 96> Sparse;
	System::Byte IsExtended;
	Arr12 RealSize;
	System::StaticArray<System::Byte, 17> Empty2;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TAbTarEnd_Star_Rec
{
public:
	System::StaticArray<char, 131> Prefix;
	Arr12 Atime;
	Arr12 Ctime;
	Arr12B Empty;
};
#pragma pack(pop)


struct TAbTarHeaderRec;
typedef TAbTarHeaderRec *PAbTarHeaderRec;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TAbTarHeaderRec
{
public:
	ArrName Name;
	Arr8 Mode;
	Arr8 uid;
	Arr8 gid;
	Arr12 Size;
	Arr12 ModTime;
	Arr8 ChkSum;
	char LinkFlag;
	ArrName LinkName;
	TAbTarMagicRec Magic;
	System::StaticArray<char, 32> UsrName;
	System::StaticArray<char, 32> GrpName;
	Arr8 DevMajor;
	Arr8 DevMinor;
	union
	{
		struct 
		{
			TAbTarEnd_Empty_Rec pax;
		};
		struct 
		{
			TAbTarEnd_Star_Rec star;
		};
		struct 
		{
			TAbTarEnd_UStar_Rec ustar;
		};
		struct 
		{
			TAbTarEnd_GNU_old_Rec gnu;
		};
		struct 
		{
			TAbTarEnd_GNU_old_Rec gnuOld;
		};
		struct 
		{
			TAbTarEnd_Empty_Rec v7;
		};
		
	};
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TAbTarItemRec
{
public:
	System::UnicodeString Name;
	unsigned Mode;
	int uid;
	int gid;
	__int64 Size;
	__int64 ModTime;
	bool ChkSumPass;
	char LinkFlag;
	TAbTarItemType ItemType;
	System::UnicodeString LinkName;
	System::AnsiString Magic;
	int Version;
	System::UnicodeString UsrName;
	System::UnicodeString GrpName;
	int DevMajor;
	int DevMinor;
	__int64 AccessTime;
	__int64 ChangeTime;
	TAbTarHeaderFormat ArchiveFormat;
	__int64 StreamPosition;
	bool Dirty;
	bool ItemReadOnly;
	int FileHeaderCount;
};


class DELPHICLASS TAbTarItem;
typedef TAbTarItem* *PTAbTarItem;

class PASCALIMPLEMENTATION TAbTarItem : public Abarctyp::TAbArchiveItem
{
	typedef Abarctyp::TAbArchiveItem inherited;
	
private:
	void __fastcall ParseTarHeaders(void);
	void __fastcall DetectHeaderFormat(void);
	void __fastcall GetFileNameFromHeaders(void);
	void __fastcall GetLinkNameFromHeaders(void);
	bool __fastcall TestCheckSum(void);
	void __fastcall DoGNUExistingLongNameLink(char LinkFlag, int I, const System::AnsiString Value);
	void __fastcall DoGNUNewLongNameLink(char LinkFlag, int I, const System::AnsiString Value);
	
protected:
	TAbTarHeaderRec *PTarHeader;
	System::Classes::TList* FTarHeaderList;
	System::Classes::TList* FTarHeaderTypeList;
	TAbTarItemRec FTarItem;
	int __fastcall GetDevMajor(void);
	int __fastcall GetDevMinor(void);
	int __fastcall GetGroupID(void);
	System::UnicodeString __fastcall GetGroupName(void);
	System::UnicodeString __fastcall GetLinkName(void);
	int __fastcall GetUserID(void);
	System::UnicodeString __fastcall GetUserName(void);
	__int64 __fastcall GetModTime(void);
	int __fastcall GetNumHeaders(void);
	System::UnicodeString __fastcall GetMagic(void);
	void __fastcall SetDevMajor(const int Value);
	void __fastcall SetDevMinor(const int Value);
	void __fastcall SetGroupID(const int Value);
	void __fastcall SetGroupName(const System::UnicodeString Value);
	void __fastcall SetLinkFlag(char Value);
	void __fastcall SetLinkName(const System::UnicodeString Value);
	void __fastcall SetUserID(const int Value);
	void __fastcall SetUserName(const System::UnicodeString Value);
	void __fastcall SetModTime(const __int64 Value);
	void __fastcall SetMagic(const System::UnicodeString Value);
	virtual __int64 __fastcall GetCompressedSize(void);
	virtual unsigned __fastcall GetExternalFileAttributes(void);
	virtual System::UnicodeString __fastcall GetFileName(void);
	virtual bool __fastcall GetIsDirectory(void);
	virtual bool __fastcall GetIsEncrypted(void);
	virtual System::Word __fastcall GetLastModFileDate(void);
	virtual System::Word __fastcall GetLastModFileTime(void);
	virtual System::TDateTime __fastcall GetLastModTimeAsDateTime(void);
	virtual int __fastcall GetNativeFileAttributes(void);
	virtual __int64 __fastcall GetUncompressedSize(void);
	virtual void __fastcall SetCompressedSize(const __int64 Value);
	virtual void __fastcall SetExternalFileAttributes(unsigned Value);
	virtual void __fastcall SetFileName(const System::UnicodeString Value);
	virtual void __fastcall SetIsEncrypted(bool Value);
	virtual void __fastcall SetLastModFileDate(const System::Word Value);
	virtual void __fastcall SetLastModFileTime(const System::Word Value);
	virtual void __fastcall SetLastModTimeAsDateTime(const System::TDateTime Value);
	virtual void __fastcall SetUncompressedSize(const __int64 Value);
	void __fastcall SaveTarHeaderToStream(System::Classes::TStream* AStream);
	void __fastcall LoadTarHeaderFromStream(System::Classes::TStream* AStream);
	__property System::UnicodeString Magic = {read=GetMagic, write=SetMagic};
	
public:
	__property unsigned Mode = {read=GetExternalFileAttributes, write=SetExternalFileAttributes, nodefault};
	__property int UserID = {read=GetUserID, write=SetUserID, nodefault};
	__property int GroupID = {read=GetGroupID, write=SetGroupID, nodefault};
	__property __int64 ModTime = {read=GetModTime, write=SetModTime};
	__property bool CheckSumGood = {read=FTarItem.ChkSumPass, nodefault};
	__property char LinkFlag = {read=FTarItem.LinkFlag, write=SetLinkFlag, nodefault};
	__property System::UnicodeString LinkName = {read=GetLinkName, write=SetLinkName};
	__property System::UnicodeString UserName = {read=GetUserName, write=SetUserName};
	__property System::UnicodeString GroupName = {read=GetGroupName, write=SetGroupName};
	__property int DevMajor = {read=GetDevMajor, write=SetDevMajor, nodefault};
	__property int DevMinor = {read=GetDevMinor, write=SetDevMinor, nodefault};
	__property ExternalFileAttributes;
	__property TAbTarHeaderFormat ArchiveFormat = {read=FTarItem.ArchiveFormat, write=FTarItem.ArchiveFormat, nodefault};
	__property TAbTarItemType ItemType = {read=FTarItem.ItemType, write=FTarItem.ItemType, nodefault};
	__property bool ItemReadOnly = {read=FTarItem.ItemReadOnly, write=FTarItem.ItemReadOnly, nodefault};
	__property int FileHeaderCount = {read=FTarItem.FileHeaderCount, nodefault};
	__property int HeaderCount = {read=GetNumHeaders, nodefault};
	__property __int64 StreamPosition = {read=FTarItem.StreamPosition, write=FTarItem.StreamPosition};
	__fastcall TAbTarItem(void);
	__fastcall virtual ~TAbTarItem(void);
};


class DELPHICLASS TAbTarStreamHelper;
class PASCALIMPLEMENTATION TAbTarStreamHelper : public Abarctyp::TAbArchiveStreamHelper
{
	typedef Abarctyp::TAbArchiveStreamHelper inherited;
	
private:
	bool __fastcall FindItem(void);
	
protected:
	TAbTarHeaderRec FTarHeader;
	__int64 FCurrItemSize;
	int FCurrItemPreHdrs;
	
public:
	__fastcall virtual ~TAbTarStreamHelper(void);
	virtual void __fastcall ExtractItemData(System::Classes::TStream* AStream);
	virtual bool __fastcall FindFirstItem(void);
	virtual bool __fastcall FindNextItem(void);
	virtual void __fastcall ReadHeader(void);
	virtual void __fastcall ReadTail(void);
	virtual bool __fastcall SeekItem(int Index);
	virtual void __fastcall WriteArchiveHeader(void);
	virtual void __fastcall WriteArchiveItem(System::Classes::TStream* AStream);
	void __fastcall WriteArchiveItemSize(System::Classes::TStream* AStream, __int64 Size);
	virtual void __fastcall WriteArchiveTail(void);
	virtual int __fastcall GetItemCount(void);
public:
	/* TAbArchiveStreamHelper.Create */ inline __fastcall TAbTarStreamHelper(System::Classes::TStream* AStream) : Abarctyp::TAbArchiveStreamHelper(AStream) { }
	
};


class DELPHICLASS TAbTarArchive;
class PASCALIMPLEMENTATION TAbTarArchive : public Abarctyp::TAbArchive
{
	typedef Abarctyp::TAbArchive inherited;
	
public:
	TAbTarItem* operator[](int Index) { return Items[Index]; }
	
private:
	bool FArchReadOnly;
	TAbTarHeaderFormat FArchFormat;
	
protected:
	virtual Abarctyp::TAbArchiveItem* __fastcall CreateItem(const System::UnicodeString FileSpec);
	virtual void __fastcall ExtractItemAt(int Index, const System::UnicodeString UseName);
	virtual void __fastcall ExtractItemToStreamAt(int Index, System::Classes::TStream* aStream);
	virtual void __fastcall LoadArchive(void);
	virtual void __fastcall SaveArchive(void);
	virtual void __fastcall TestItemAt(int Index);
	virtual System::UnicodeString __fastcall FixName(const System::UnicodeString Value);
	virtual bool __fastcall GetSupportsEmptyFolders(void);
	TAbTarItem* __fastcall GetItem(int Index);
	void __fastcall PutItem(int Index, TAbTarItem* const Value);
	
public:
	__fastcall virtual TAbTarArchive(System::Classes::TStream* aStream, const System::UnicodeString aArchiveName);
	__property bool UnsupportedTypesDetected = {read=FArchReadOnly, nodefault};
	__property TAbTarItem* Items[int Index] = {read=GetItem, write=PutItem/*, default*/};
protected:
	/* TAbArchive.CreateInit */ inline __fastcall TAbTarArchive(void) : Abarctyp::TAbArchive() { }
	
public:
	/* TAbArchive.Create */ inline __fastcall virtual TAbTarArchive(const System::UnicodeString FileName, System::Word Mode) : Abarctyp::TAbArchive(FileName, Mode) { }
	/* TAbArchive.Destroy */ inline __fastcall virtual ~TAbTarArchive(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word AB_TAR_RECORDSIZE = System::Word(0x200);
static const System::Int8 AB_TAR_NAMESIZE = System::Int8(0x64);
static const System::Byte AB_TAR_V7_EMPTY_SIZE = System::Byte(0xa7);
static const System::Byte AB_TAR_USTAR_PREFIX_SIZE = System::Byte(0x9b);
static const System::Byte AB_TAR_STAR_PREFIX_SIZE = System::Byte(0x83);
static const System::Int8 AB_TAR_OLD_GNU_EMPTY1_SIZE = System::Int8(0x5);
static const System::Int8 AB_TAR_OLD_GNU_SPARSE_SIZE = System::Int8(0x60);
static const System::Int8 AB_TAR_OLD_GNU_EMPTY2_SIZE = System::Int8(0x11);
static const System::Byte AB_TAR_SIZE_AFTER_STDHDR = System::Byte(0xa7);
static const System::Int8 AB_TAR_TUSRNAMELEN = System::Int8(0x20);
static const System::Int8 AB_TAR_TGRPNAMELEN = System::Int8(0x20);
#define AB_TAR_CHKBLANKS L"        "
#define AB_TAR_L_HDR_NAME L"././@LongLink"
#define AB_TAR_L_HDR_USR_NAME L"root"
#define AB_TAR_L_HDR_GRP_NAME L"root"
#define AB_TAR_L_HDR_ARR8_0 L"0000000\u0000"
#define AB_TAR_L_HDR_ARR12_0 L"00000000000\u0000"
#define AB_TAR_MAGIC_VAL L"ustar\u0000"
#define AB_TAR_MAGIC_VER L"00"
#define AB_TAR_MAGIC_GNUOLD L"ustar  \u0000"
#define AB_TAR_MAGIC_V7_NONE L"\u0000\u0000\u0000\u0000\u0000\u0000\u0000\u0000"
static const System::WideChar AB_TAR_LF_OLDNORMAL = (System::WideChar)(0x0);
static const System::WideChar AB_TAR_LF_NORMAL = (System::WideChar)(0x30);
static const System::WideChar AB_TAR_LF_LINK = (System::WideChar)(0x31);
static const System::WideChar AB_TAR_LF_SYMLINK = (System::WideChar)(0x32);
static const System::WideChar AB_TAR_LF_CHR = (System::WideChar)(0x33);
static const System::WideChar AB_TAR_LF_BLK = (System::WideChar)(0x34);
static const System::WideChar AB_TAR_LF_DIR = (System::WideChar)(0x35);
static const System::WideChar AB_TAR_LF_FIFO = (System::WideChar)(0x36);
static const System::WideChar AB_TAR_LF_CONTIG = (System::WideChar)(0x37);
static const System::WideChar AB_TAR_LF_XHDR = (System::WideChar)(0x78);
static const System::WideChar AB_TAR_LF_XGL = (System::WideChar)(0x67);
static const System::WideChar AB_TAR_LF_DUMPDIR = (System::WideChar)(0x44);
static const System::WideChar AB_TAR_LF_LONGLINK = (System::WideChar)(0x4b);
static const System::WideChar AB_TAR_LF_LONGNAME = (System::WideChar)(0x4c);
static const System::WideChar AB_TAR_LF_MULTIVOL = (System::WideChar)(0x4d);
static const System::WideChar AB_TAR_LF_SPARSE = (System::WideChar)(0x53);
static const System::WideChar AB_TAR_LF_VOLHDR = (System::WideChar)(0x56);
static const System::WideChar AB_TAR_LF_EXHDR = (System::WideChar)(0x58);
#define AB_SUPPORTED_F_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x0' << '\x30' << '\x31' << '\x32' << '\x35' )
#define AB_UNSUPPORTED_F_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x33' << '\x34' << '\x36' << '\x37' << '\x44' << '\x4d' << '\x53' << '\x56' )
#define AB_SUPPORTED_MD_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x4b' << '\x4c' )
#define AB_UNSUPPORTED_MD_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x58' << '\x67' << '\x78' )
#define AB_GNU_MD_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x4b' << '\x4c' )
#define AB_PAX_MD_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x67' << '\x78' )
#define AB_IGNORE_SIZE_HEADERS (System::Set<char, _DELPHI_SET_CHAR(0), _DELPHI_SET_CHAR(255)>() << '\x31' << '\x32' << '\x33' << '\x34' << '\x35' << '\x36' )
static const System::Word AB_TAR_TSUID = System::Word(0x800);
static const System::Word AB_TAR_TSGID = System::Word(0x400);
static const System::Word AB_TAR_TSVTX = System::Word(0x200);
extern DELPHI_PACKAGE Abutils::TAbArchiveType __fastcall VerifyTar(System::Classes::TStream* Strm);
}	/* namespace Abtartyp */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_ABTARTYP)
using namespace Abtartyp;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AbtartypHPP