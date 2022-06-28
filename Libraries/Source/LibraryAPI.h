#pragma once

#if _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * Object instance type
     */
    typedef void* LibraryInstance;

    /**
     * Creates a library instance
     *
     * Once the library is not used anymore it should be deallocated
     * by calling the LibraryDestroy function.
     *
     * @returns the noise filter instance
     */
    LibraryInstance EXPORT LibraryCreate();

    /**
     * Destroys the library instance and deallocates the memory.
     *
     * @param noiseFilter the noiseFilter instance
     */
    void EXPORT LibraryDestroy(LibraryInstance instance);

    /**
     * Log levels
     */
    typedef enum
    {
        LogLevelTrace = 0, /**< Trace log level. Might impact performance. */
        LogLevelDebug, /**< Debug log level. Might impact performance. */
        LogLevelInfo, /**< Info log level. Default log level. */
        LogLevelWarning, /**< Warning log level */
        LogLevelError /**< Error log level */
    } LogLevel;

    /**
     * Sets logging level
     *
     * @param level the new logging level
     */
    void EXPORT SetLogLevel(LogLevel level);

    /**
     * Logging callback function type
     *
     * @param level the logging level
     * @param message the log message
     */
    typedef void (*LogCallback)(LogLevel level, const char* message);

    /**
     * Sets logging callback
     *
     * When the logging callback is set, the library does not output messages to console
     * and all log messages are sent to the callback.
     *
     * @param callback the logging callback
     */
    void EXPORT SetLogCallback(LogCallback callback);

#ifdef __cplusplus
}
#endif


