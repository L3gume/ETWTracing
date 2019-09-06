// ETWTracingLightningTalk.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <iostream>
#include "EtwTracing.h"

static void DoTheThing() {
	EtwLoggingActivityWrapper _etw_activity_([&](Activity& act) {
	                                             __pragma(warning(push))
	                                             __pragma(warning(disable:4127))
	                                             do {
	                                                 auto& _TlgActivity(act);
	                                                 static const UINT64 _TlgActivity_Keyword = _TlgActivity.Keyword;
	                                                 static const UINT8 _TlgActivity_Level = _TlgActivity.Level;
	                                                 static_assert(_TlgActivity_Keyword == (_TlgActivity_Keyword),
	                                                     "Do not use TraceLoggingKeyword in TraceLoggingWriteStart. Keywords for START events are "
	                                                     "specified in the activity type, e.g. TraceLoggingActivity<Provider,Keyword,Level>."
	                                                 );
	                                                 static_assert(_TlgActivity_Level == (_TlgActivity_Level),
	                                                     "Do not use TraceLoggingLevel in TraceLoggingWriteStart. The Level for START events is "
	                                                     "specified in the activity type, e.g. TraceLoggingActivity<Provider,Keyword,Level>."
	                                                 );
	                                                 _TlgActivity.zInternalStart();
	                                                 do {
	                                                     __pragma(warning(push))
	                                                     __pragma(warning(disable:4127 4132 6001))
	                                                     __pragma(warning(error:4047))
	                                                     __pragma(execution_character_set(push, "UTF-8"))
	                                                     __pragma(pack(push, 1))
	                                                     typedef _TlgTagEnc<0> _TlgTagTy;
	                                                     enum {
	                                                         _TlgLevelConst = 5 & 0 | _TraceLoggingLevel<
	                                                             _TlgActivity_Level>::value
	                                                     };
	                                                     static struct {
	                                                         UCHAR _TlgBlobTyp;
	                                                         UCHAR _TlgChannel;
	                                                         UCHAR _TlgLevel;
	                                                         UCHAR _TlgOpcode;
	                                                         ULONGLONG _TlgKeyword;
	                                                         UINT16 _TlgEvtMetaSize;
	                                                         _TlgTagTy::type _TlgEvtTags;
	                                                         char _TlgName[sizeof(("TheThingThatIsBeingDone"))];
	                                                         char _TlgName4[sizeof("Some Parameter")];
	                                                         _TlgTypeMap<decltype(42)>::_TlgTypeType0 _TlgTy4;
	                                                     } __declspec(allocate(".rdata$zETW1")) __declspec(align(1))
	                                                         const _TlgEvent = {
	                                                             _TlgBlobEvent3, 11, _TlgLevelConst,
	                                                             0 & 0 | _TraceLoggingOpcode<1>::value,
	                                                             0 | _TraceLoggingKeyword<_TlgActivity_Keyword>::value,
	                                                             sizeof(_TlgEvent) - 11 - 1, _TlgTagTy::value,
	                                                             (("TheThingThatIsBeingDone")), ("Some Parameter"),
	                                                             _TlgTypeMap<decltype(42)>::_TlgType0
	                                                         };
	                                                     TraceLoggingHProvider const _TlgProv = (_TlgActivity.Provider()
	                                                     );
	                                                     if ((UCHAR)_TlgLevelConst < _TlgProv->LevelPlus1 &&
	                                                         _TlgKeywordOn(_TlgProv, _TlgEvent._TlgKeyword)) {
	                                                         EVENT_DATA_DESCRIPTOR _TlgData[2 + 1];
	                                                         UINT32 _TlgIdx = 2;
	                                                         (_TlgCreateAuto(&_TlgData[_TlgIdx], (42)), _TlgIdx += 1,
	                                                             __pragma(warning(disable:26000)) __annotation(
	                                                                 L"_TlgWrite:|" L"9" L"|" L"_TlgActivity.Provider()"
	                                                                 L"|" L"(\"TheThingThatIsBeingDone\")" L"=" L"~^"
	                                                                 L"act" L"^~" L"|" LL"\"Some Parameter\""LL),
	                                                             _TlgWrite(_TlgProv, &_TlgEvent._TlgChannel,
	                                                                       (_TlgActivity.Id()),
	                                                                       (_TlgActivity.zInternalRelatedId()), _TlgIdx,
	                                                                       _TlgData));
	                                                     }
	                                                     __pragma(pack(pop))
	                                                     __pragma(execution_character_set(pop))
	                                                     __pragma(warning(pop))
	                                                 }
	                                                 while (0);
	                                             }
	                                             while (0) __pragma(warning(pop));
	                                         }, [&](Activity& act) {
	                                             if (act.IsStarted()) __pragma(warning(push)) __pragma(warning(disable:
	                                             4127)) do {
	                                                 auto& _TlgActivity(act);
	                                                 static const UINT64 _TlgActivity_Keyword = _TlgActivity.Keyword;
	                                                 static const UINT8 _TlgActivity_Level = _TlgActivity.Level;
	                                                 static_assert(_TlgActivity_Keyword == (_TlgActivity_Keyword),
	                                                     "Do not use TraceLoggingKeyword in TraceLoggingWriteStop. Keywords for STOP events are "
	                                                     "specified in the activity type, e.g. TraceLoggingActivity<Provider,Keyword,Level>."
	                                                 );
	                                                 static_assert(_TlgActivity_Level == (_TlgActivity_Level),
	                                                     "Do not use TraceLoggingLevel in TraceLoggingWriteStop. The Level for STOP events is "
	                                                     "specified in the activity type, e.g. TraceLoggingActivity<Provider,Keyword,Level>."
	                                                 );
	                                                 _TlgActivity.zInternalStop();
	                                                 do {
	                                                     __pragma(warning(push))
	                                                     __pragma(warning(disable:4127 4132 6001))
	                                                     __pragma(warning(error:4047))
	                                                     __pragma(execution_character_set(push, "UTF-8"))
	                                                     __pragma(pack(push, 1))
	                                                     typedef _TlgTagEnc<0> _TlgTagTy;
	                                                     enum {
	                                                         _TlgLevelConst = 5 & 0 | _TraceLoggingLevel<
	                                                             _TlgActivity_Level>::value
	                                                     };
	                                                     static struct {
	                                                         UCHAR _TlgBlobTyp;
	                                                         UCHAR _TlgChannel;
	                                                         UCHAR _TlgLevel;
	                                                         UCHAR _TlgOpcode;
	                                                         ULONGLONG _TlgKeyword;
	                                                         UINT16 _TlgEvtMetaSize;
	                                                         _TlgTagTy::type _TlgEvtTags;
	                                                         char _TlgName[sizeof(("TheThingThatIsBeingDone"))];
	                                                         char _TlgName4[sizeof("Some Parameter")];
	                                                         _TlgTypeMap<decltype(42)>::_TlgTypeType0 _TlgTy4;
	                                                     } __declspec(allocate(".rdata$zETW1")) __declspec(align(1))
	                                                         const _TlgEvent = {
	                                                             _TlgBlobEvent3, 11, _TlgLevelConst,
	                                                             0 & 0 | _TraceLoggingOpcode<2>::value,
	                                                             0 | _TraceLoggingKeyword<_TlgActivity_Keyword>::value,
	                                                             sizeof(_TlgEvent) - 11 - 1, _TlgTagTy::value,
	                                                             (("TheThingThatIsBeingDone")), ("Some Parameter"),
	                                                             _TlgTypeMap<decltype(42)>::_TlgType0
	                                                         };
	                                                     TraceLoggingHProvider const _TlgProv = (_TlgActivity.Provider()
	                                                     );
	                                                     if ((UCHAR)_TlgLevelConst < _TlgProv->LevelPlus1 &&
	                                                         _TlgKeywordOn(_TlgProv, _TlgEvent._TlgKeyword)) {
	                                                         EVENT_DATA_DESCRIPTOR _TlgData[2 + 1];
	                                                         UINT32 _TlgIdx = 2;
	                                                         (_TlgCreateAuto(&_TlgData[_TlgIdx], (42)), _TlgIdx += 1,
	                                                             __pragma(warning(disable:26000)) __annotation(
	                                                                 L"_TlgWrite:|" L"9" L"|" L"_TlgActivity.Provider()"
	                                                                 L"|" L"(\"TheThingThatIsBeingDone\")" L"=" L"~^"
	                                                                 L"act" L"^~" L"|" LL"\"Some Parameter\""LL),
	                                                             _TlgWrite(_TlgProv, &_TlgEvent._TlgChannel,
	                                                                       (_TlgActivity.Id()), (0), _TlgIdx,
	                                                                       _TlgData));
	                                                     }
	                                                     __pragma(pack(pop))
	                                                     __pragma(execution_character_set(pop))
	                                                     __pragma(warning(pop))
	                                                 }
	                                                 while (0);
	                                             }
	                                             while (0) __pragma(warning(pop));
	                                         });
    
	std::cout << "I did the thing!" << '\n';
}
