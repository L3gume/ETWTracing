#pragma once

// always include Windows.h
#include <Windows.h>
// include the TraceLogging library
#include <TraceLoggingProvider.h>
#include <TraceLoggingActivity.h>

#include <functional>
#include "dbg.h" // Very nice debug macro

TRACELOGGING_DECLARE_PROVIDER(g_trace_logging_provider);

namespace trace_logging {

using Activity = TraceLoggingThreadActivity<g_trace_logging_provider>;
using TraceFunc = std::function<void(Activity&) noexcept>;

struct EtwLoggingActivityWrapper {
    EtwLoggingActivityWrapper(TraceFunc start_func, TraceFunc stop_func);
    ~EtwLoggingActivityWrapper();  // NOLINT(bugprone-exception-escape)

    EtwLoggingActivityWrapper(EtwLoggingActivityWrapper const&) = delete;
    EtwLoggingActivityWrapper(EtwLoggingActivityWrapper&&) = delete;
    void operator=(EtwLoggingActivityWrapper const&) = delete;
    void operator=(EtwLoggingActivityWrapper&&) = delete;

    Activity m_activity{};
    TraceFunc m_startFunc;
    TraceFunc m_stopFunc;
};

inline EtwLoggingActivityWrapper::EtwLoggingActivityWrapper(TraceFunc start_func, TraceFunc stop_func)
    : m_startFunc(std::move(start_func)), m_stopFunc(std::move(stop_func)) {
    dbg("Starting activity");
    m_startFunc(m_activity);
}

inline EtwLoggingActivityWrapper::~EtwLoggingActivityWrapper() { // NOLINT(bugprone-exception-escape)
    dbg("Stopping activity");
    m_stopFunc(m_activity);
}

inline void setEtwLoggingEnabled(const bool enabled) {
    dbg("setEtwLoggingEnabled: ");
    if (dbg(enabled)) {
        TraceLoggingRegister(g_trace_logging_provider);
    }
    else {
        TraceLoggingUnregister(g_trace_logging_provider);
    }
}

}

#define ETW_LOG_CURRENT_SCOPE(name, ...)                                                                            \
    trace_logging::EtwLoggingActivityWrapper _etw_activity_(                                                        \
        [&](trace_logging::Activity& act){ TraceLoggingWriteStart(act, name, __VA_ARGS__); },                       \
        [&](trace_logging::Activity& act){ if (act.IsStarted()) TraceLoggingWriteStop(act, name, __VA_ARGS__); }    \
    )
