#include "LibraryImpl.h"

LibraryImpl::LibraryImpl()
{
    Logger::setCurrentLogger(this);
}

LibraryImpl::~LibraryImpl()
{
    Logger::setCurrentLogger (nullptr);
}

void LibraryImpl::logMessage (const juce::String& message)
{
    outputDebugString("[LibraryImpl]: " + message);
}
