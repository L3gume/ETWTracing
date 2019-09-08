// ETWTracingLightningTalk.h : Include file for standard system include files,
// or project specific include files.
#pragma once

#include <iostream>
#include "EtwTracing.h"

namespace library {
    
static void do_the_thing() {
    ETW_LOG_CURRENT_SCOPE("TheThing", TraceLoggingValue(42, "SomeParameter"));

    std::cout << "I did the thing!" << '\n';
}

}
