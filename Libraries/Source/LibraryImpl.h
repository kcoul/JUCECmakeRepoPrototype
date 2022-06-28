#pragma once

#include <juce_core/juce_core.h>

class LibraryImpl : juce::Logger
{
public:
    LibraryImpl();
    ~LibraryImpl();
    void logMessage (const juce::String& message) override;
private:
};


