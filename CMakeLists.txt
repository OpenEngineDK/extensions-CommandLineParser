SET( EXTENSION_NAME "Extensions_CommandLineParser")

ADD_LIBRARY( ${EXTENSION_NAME}
    Utils/CommandLineParser.cpp
    Utils/CommandLineParser.h
)

TARGET_LINK_LIBRARIES( ${EXTENSION_NAME}
  OpenEngine_Utils
)
