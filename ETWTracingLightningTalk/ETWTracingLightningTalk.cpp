// ETWTracingLightningTalk.cpp : Defines the entry point for the application.
//

#include "ETWTracingLightningTalk.h"
#include "EtwTracing.h"

int main() {
    trace_logging::setEtwLoggingEnabled(true);
    
    library::do_the_thing();

    trace_logging::setEtwLoggingEnabled(false);
	return 0;
}
