/*********************************************************************
	Copyright	: Draegerwerk AG & Co. KGaA
	Rhapsody	: 7.5 
	Login		: karlitsc
	Component	: Framework 
	Configuration 	: DefaultConfig
	Model Element	: ComponentKind
//!	Generated Date	: Mi, 17, Jun 2009  
	File Path	: ..\Framework\Global\ComponentKind.h
*********************************************************************/

#ifndef Framework_Global_ComponentKind_H
#define Framework_Global_ComponentKind_H



//## class ComponentKind
class  ComponentKind {
public :

    //## operation ComponentKind()
    inline ComponentKind();
    
    //## operation ComponentKind(ComponentKind)
    inline ComponentKind(const ComponentKind& right);
    
    //## operation ComponentKind(unsigned short)
    ComponentKind(unsigned short componentPart);
    
    //## operation ~ComponentKind()
    inline ~ComponentKind();
    
    //## operation operator=(ComponentKind)
    inline ComponentKind& operator=(const ComponentKind& right);
    
    //## operation operator==(ComponentKind) const
    inline bool operator==(const ComponentKind& right) const;
    
    //## operation operator!=(ComponentKind) const
    inline bool operator!=(const ComponentKind& right) const;
    
    //## operation operator<(ComponentKind) const
    inline bool operator<(const ComponentKind& right) const;
    
    //## operation operator>(ComponentKind) const
    inline bool operator>(const ComponentKind& right) const;
    
    //## operation operator<=(ComponentKind) const
    inline bool operator<=(const ComponentKind& right) const;
    
    //## operation operator>=(ComponentKind) const
    inline bool operator>=(const ComponentKind& right) const;
    
    //## operation getInternal() const
    inline unsigned short getInternal() const;
    
    //## operation toString(char,size_t) const
    char* toString(char* aBuffer, size_t aBufferLen) const;

private :

    unsigned short m_value;		//## attribute m_value

public :

    //## type BitNumbers
    typedef enum BitNumbers {
        ComponentBitAmount = 10,
        MaxValue = (1U <<ComponentBitAmount) - 1
    } BitNumbers;
};

inline ComponentKind::ComponentKind() : m_value(0U) {
    //#[ operation ComponentKind()
    //#]
}

inline ComponentKind::ComponentKind(const ComponentKind& right) : m_value(right.m_value) {
    //#[ operation ComponentKind(ComponentKind)
    //#]
}

inline ComponentKind::~ComponentKind() {
    //#[ operation ~ComponentKind()
    //#]
}

inline ComponentKind& ComponentKind::operator=(const ComponentKind& right) {
    //#[ operation operator=(ComponentKind)
    
     if (this != &right)
     {
        m_value = right.m_value;
     }
    
     return *this;
    
    
    //#]
}

inline bool ComponentKind::operator==(const ComponentKind& right) const {
    //#[ operation operator==(ComponentKind) const
    
     return (m_value == right.m_value);
    
    
    //#]
}

inline bool ComponentKind::operator!=(const ComponentKind& right) const {
    //#[ operation operator!=(ComponentKind) const
    
     return (m_value != right.m_value);
    
    
    //#]
}

inline bool ComponentKind::operator<(const ComponentKind& right) const {
    //#[ operation operator<(ComponentKind) const
    
     return (m_value < right.m_value);
    
    
    //#]
}

inline bool ComponentKind::operator>(const ComponentKind& right) const {
    //#[ operation operator>(ComponentKind) const
    
     return (m_value > right.m_value);
    
    
    //#]
}

inline bool ComponentKind::operator<=(const ComponentKind& right) const {
    //#[ operation operator<=(ComponentKind) const
    
     return (m_value <= right.m_value);
    
    
    //#]
}

inline bool ComponentKind::operator>=(const ComponentKind& right) const {
    //#[ operation operator>=(ComponentKind) const
    
     return (m_value >= right.m_value);
    
    
    //#]
}

inline unsigned short ComponentKind::getInternal() const {
    //#[ operation getInternal() const
    
       return m_value;
    //#]
}

#endif
