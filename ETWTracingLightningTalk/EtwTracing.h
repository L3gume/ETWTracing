#pragma once

#include <Windows.h>
// include the TraceLogging library
#include <TraceLoggingProvider.h>
#include <TraceLoggingActivity.h>

#include <functional>

TRACELOGGING_DECLARE_PROVIDER(g_trace_logging_provider);

using Activity = TraceLoggingThreadActivity<g_trace_logging_provider>;
using TraceFunc = std::function<void(Activity&)>;

struct EtwLoggingActivityWrapper {
	EtwLoggingActivityWrapper(TraceFunc startFunc, TraceFunc stopFunc);
	~EtwLoggingActivityWrapper();
    
	EtwLoggingActivityWrapper(EtwLoggingActivityWrapper const&) = delete;
	EtwLoggingActivityWrapper(EtwLoggingActivityWrapper &&) = delete;
	void operator=(EtwLoggingActivityWrapper const&) = delete;
	void operator=(EtwLoggingActivityWrapper &&) = delete;
    
	Activity m_activity {};
	TraceFunc m_startFunc;
	TraceFunc m_stopFunc;
};

inline EtwLoggingActivityWrapper::EtwLoggingActivityWrapper(TraceFunc startFunc, TraceFunc stopFunc) 
    : m_startFunc(std::move(startFunc)), m_stopFunc(std::move(stopFunc)) {
    m_startFunc(m_activity);
}

inline EtwLoggingActivityWrapper::~EtwLoggingActivityWrapper() {
    m_stopFunc(m_activity);
}

inline void setEtwLoggingEnabled(const bool enabled) {
    if (enabled) {
        TraceLoggingRegister(g_trace_logging_provider);
    } else {
		TraceLoggingUnregister(g_trace_logging_provider);
    }
}

#define ETW_LOG_CURRENT_SCOPE(name, ...)                                                             \
    EtwLoggingActivityWrapper _etw_activity_(                                                        \
        [&](Activity& act){ TraceLoggingWriteStart(act, name, __VA_ARGS__); },                       \
        [&](Activity& act){ if (act.IsStarted()) TraceLoggingWriteStop(act, name, __VA_ARGS__); }    \
    )
