#include "EtwTracing.h"

// This file's only purpose is to avoid multiple definitions of the extern g_trace_logging_provider variable

// Guid: 9fe7b3db-e437-488f-9c52-681ab10463ea
// The guid is very useful for collecting traces in perfview
TRACELOGGING_DEFINE_PROVIDER(g_trace_logging_provider,
	"DemoTraceLoggingProvider",
	(0x9fe7b3db, 0xe437, 0x488f, 0x9c, 0x52, 0x68, 0x1a, 0xb1, 0x04, 0x63, 0xea));