// ETWTracingLightningTalk.cpp : Defines the entry point for the application.
//

#include "ETWTracingLightningTalk.h"
#include "EtwTracing.h"

int main() {
    setEtwLoggingEnabled(true);
    
	DoTheThing();
    
	setEtwLoggingEnabled(false);
	return 0;
}
