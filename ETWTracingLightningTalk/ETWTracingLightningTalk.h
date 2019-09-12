// ETWTracingLightningTalk.h : Include file for standard system include files,
// or project specific include files.
#pragma once

#include <iostream>
#include "EtwTracing.h"

namespace library {
    
static void do_the_thing() {
    ETW_LOG_CURRENT_SCOPE("Activity",
		TraceLoggingValue(42, "TheAnswer"),
		TraceLoggingValue("ThisWorks", "WithStringsToo"));

	dbg("I did the thing!");
}

static void comparison() {
    
    // start of scope
	TraceLoggingThreadActivity<g_trace_logging_provider> activity{};
	TraceLoggingWriteStart(activity, "Activity",
		TraceLoggingValue(42, "TheAnswer"),
		TraceLoggingValue("ThisWorks", "WithStringsToo"));
    
	dbg("I did the thing!");

	TraceLoggingWriteStop(activity, "Activity");
    // end of scope

    // vs.
    
    // start of scope
    ETW_LOG_CURRENT_SCOPE("Activity",
		TraceLoggingValue(42, "TheAnswer"),
		TraceLoggingValue("ThisWorks", "WithStringsToo"));
    
	dbg("I did the thing!");
    // end of scope

}

}
