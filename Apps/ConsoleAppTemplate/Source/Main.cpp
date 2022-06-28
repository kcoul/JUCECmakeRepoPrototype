#include <juce_core/juce_core.h>
#include "LibraryAPI.h"

int main()
{
    juce::Logger::writeToLog("Hello World");

    LibraryInstance i = LibraryCreate();

    juce::Logger::writeToLog("Hello World");

    LibraryDestroy(i);

    return 0;
}
