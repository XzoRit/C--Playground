/********************************************************************
	Copyright	: Draegerwerk AG & Co. KGaA
	Rhapsody	: 7.5
	Login		: karlitsc
	Component	: Framework
	Configuration 	: DefaultConfig
	Model Element	: ComponentKind
//!	Generated Date	: Mi, 17, Jun 2009
	File Path	: ..\Framework\Global\ComponentKind.cpp
*********************************************************************/

//## dependency BaseException
#include "exception"
//## auto_generated
#include "ComponentKind.h"
//## auto_generated
#include <stdio.h>
//## auto_generated
#include <string.h>
//## package Framework::Global

//## class ComponentKind

//#[ ignore
    enum
    {
      TextSize = 32
    };

//#]

ComponentKind::ComponentKind(unsigned short componentPart) : m_value(componentPart) {
    //#[ operation ComponentKind(unsigned short)

     if (componentPart > MaxValue)
     {
		 throw std::exception ("id range exceeded");
     }

    //#]
}

char* ComponentKind::toString(char* aBuffer, size_t aBufferLen) const {
    //#[ operation toString(char,size_t) const
     char printText[TextSize]; // this is sufficient, we can use sprintf

     sprintf_s(printText,
              "ComponentKind (%u)",
              m_value);

     strncpy(aBuffer,
              printText,
              aBufferLen);
     aBuffer[aBufferLen - 1] = '\0';

     return aBuffer;

    //#]
}