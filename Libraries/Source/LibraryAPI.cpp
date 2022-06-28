#include "LibraryAPI.h"
#include "LibraryImpl.h"

LibraryInstance LibraryCreate()
{
    LibraryImpl* impl = new LibraryImpl();
    return impl;
}

void LibraryDestroy(LibraryInstance instance)
{
    LibraryImpl* impl = (LibraryImpl*)instance;
    delete impl;
}

void SetLogLevel(LogLevel level) { /*Logger::setLogLevel(level);*/ }

void SetLogCallback(LogCallback callback) { /*Logger::setLogCallback(callback);*/ }
