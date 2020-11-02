//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/artery/extern/inet/src/inet/networklayer/contract/generic/GenericNetworkProtocolControlInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "GenericNetworkProtocolControlInfo_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

GenericNetworkProtocolControlInfo_Base::GenericNetworkProtocolControlInfo_Base() : ::omnetpp::cObject()
{
    this->interfaceId = -1;
    this->protocol = 0;
    this->hopLimit = 0;
}

GenericNetworkProtocolControlInfo_Base::GenericNetworkProtocolControlInfo_Base(const GenericNetworkProtocolControlInfo_Base& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

GenericNetworkProtocolControlInfo_Base::~GenericNetworkProtocolControlInfo_Base()
{
}

GenericNetworkProtocolControlInfo_Base& GenericNetworkProtocolControlInfo_Base::operator=(const GenericNetworkProtocolControlInfo_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void GenericNetworkProtocolControlInfo_Base::copy(const GenericNetworkProtocolControlInfo_Base& other)
{
    this->destinationAddress = other.destinationAddress;
    this->sourceAddress = other.sourceAddress;
    this->interfaceId = other.interfaceId;
    this->protocol = other.protocol;
    this->hopLimit = other.hopLimit;
}

void GenericNetworkProtocolControlInfo_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->hopLimit);
}

void GenericNetworkProtocolControlInfo_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->hopLimit);
}

L3Address& GenericNetworkProtocolControlInfo_Base::_getDestinationAddress()
{
    return this->destinationAddress;
}

void GenericNetworkProtocolControlInfo_Base::setDestinationAddress(const L3Address& destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

L3Address& GenericNetworkProtocolControlInfo_Base::_getSourceAddress()
{
    return this->sourceAddress;
}

void GenericNetworkProtocolControlInfo_Base::setSourceAddress(const L3Address& sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

int GenericNetworkProtocolControlInfo_Base::getInterfaceId() const
{
    return this->interfaceId;
}

void GenericNetworkProtocolControlInfo_Base::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

short GenericNetworkProtocolControlInfo_Base::getProtocol() const
{
    return this->protocol;
}

void GenericNetworkProtocolControlInfo_Base::setProtocol(short protocol)
{
    this->protocol = protocol;
}

short GenericNetworkProtocolControlInfo_Base::getHopLimit() const
{
    return this->hopLimit;
}

void GenericNetworkProtocolControlInfo_Base::setHopLimit(short hopLimit)
{
    this->hopLimit = hopLimit;
}

class GenericNetworkProtocolControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    GenericNetworkProtocolControlInfoDescriptor();
    virtual ~GenericNetworkProtocolControlInfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(GenericNetworkProtocolControlInfoDescriptor)

GenericNetworkProtocolControlInfoDescriptor::GenericNetworkProtocolControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::GenericNetworkProtocolControlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

GenericNetworkProtocolControlInfoDescriptor::~GenericNetworkProtocolControlInfoDescriptor()
{
    delete[] propertynames;
}

bool GenericNetworkProtocolControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GenericNetworkProtocolControlInfo_Base *>(obj)!=nullptr;
}

const char **GenericNetworkProtocolControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *GenericNetworkProtocolControlInfoDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int GenericNetworkProtocolControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int GenericNetworkProtocolControlInfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *GenericNetworkProtocolControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destinationAddress",
        "sourceAddress",
        "interfaceId",
        "protocol",
        "hopLimit",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int GenericNetworkProtocolControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocol")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopLimit")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *GenericNetworkProtocolControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "L3Address",
        "int",
        "short",
        "short",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **GenericNetworkProtocolControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "getter",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *GenericNetworkProtocolControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"getter")) return "_getDestinationAddress";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"getter")) return "_getSourceAddress";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"enum")) return "inet::IPProtocolId";
            return nullptr;
        default: return nullptr;
    }
}

int GenericNetworkProtocolControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    GenericNetworkProtocolControlInfo_Base *pp = (GenericNetworkProtocolControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *GenericNetworkProtocolControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenericNetworkProtocolControlInfo_Base *pp = (GenericNetworkProtocolControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GenericNetworkProtocolControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenericNetworkProtocolControlInfo_Base *pp = (GenericNetworkProtocolControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->_getDestinationAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->_getSourceAddress(); return out.str();}
        case 2: return long2string(pp->getInterfaceId());
        case 3: return enum2string(pp->getProtocol(), "inet::IPProtocolId");
        case 4: return long2string(pp->getHopLimit());
        default: return "";
    }
}

bool GenericNetworkProtocolControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    GenericNetworkProtocolControlInfo_Base *pp = (GenericNetworkProtocolControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setInterfaceId(string2long(value)); return true;
        case 3: pp->setProtocol((inet::IPProtocolId)string2enum(value, "inet::IPProtocolId")); return true;
        case 4: pp->setHopLimit(string2long(value)); return true;
        default: return false;
    }
}

const char *GenericNetworkProtocolControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *GenericNetworkProtocolControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    GenericNetworkProtocolControlInfo_Base *pp = (GenericNetworkProtocolControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->_getDestinationAddress()); break;
        case 1: return (void *)(&pp->_getSourceAddress()); break;
        default: return nullptr;
    }
}

Register_Class(GenericRoutingDecision)

GenericRoutingDecision::GenericRoutingDecision() : ::omnetpp::cObject()
{
    this->interfaceId = -1;
}

GenericRoutingDecision::GenericRoutingDecision(const GenericRoutingDecision& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

GenericRoutingDecision::~GenericRoutingDecision()
{
}

GenericRoutingDecision& GenericRoutingDecision::operator=(const GenericRoutingDecision& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void GenericRoutingDecision::copy(const GenericRoutingDecision& other)
{
    this->interfaceId = other.interfaceId;
    this->nextHop = other.nextHop;
}

void GenericRoutingDecision::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->nextHop);
}

void GenericRoutingDecision::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->nextHop);
}

int GenericRoutingDecision::getInterfaceId() const
{
    return this->interfaceId;
}

void GenericRoutingDecision::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

L3Address& GenericRoutingDecision::getNextHop()
{
    return this->nextHop;
}

void GenericRoutingDecision::setNextHop(const L3Address& nextHop)
{
    this->nextHop = nextHop;
}

class GenericRoutingDecisionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    GenericRoutingDecisionDescriptor();
    virtual ~GenericRoutingDecisionDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(GenericRoutingDecisionDescriptor)

GenericRoutingDecisionDescriptor::GenericRoutingDecisionDescriptor() : omnetpp::cClassDescriptor("inet::GenericRoutingDecision", "omnetpp::cObject")
{
    propertynames = nullptr;
}

GenericRoutingDecisionDescriptor::~GenericRoutingDecisionDescriptor()
{
    delete[] propertynames;
}

bool GenericRoutingDecisionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GenericRoutingDecision *>(obj)!=nullptr;
}

const char **GenericRoutingDecisionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *GenericRoutingDecisionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int GenericRoutingDecisionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int GenericRoutingDecisionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *GenericRoutingDecisionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "nextHop",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int GenericRoutingDecisionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHop")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *GenericRoutingDecisionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "L3Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **GenericRoutingDecisionDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *GenericRoutingDecisionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int GenericRoutingDecisionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    GenericRoutingDecision *pp = (GenericRoutingDecision *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *GenericRoutingDecisionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenericRoutingDecision *pp = (GenericRoutingDecision *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GenericRoutingDecisionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenericRoutingDecision *pp = (GenericRoutingDecision *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        case 1: {std::stringstream out; out << pp->getNextHop(); return out.str();}
        default: return "";
    }
}

bool GenericRoutingDecisionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    GenericRoutingDecision *pp = (GenericRoutingDecision *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *GenericRoutingDecisionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *GenericRoutingDecisionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    GenericRoutingDecision *pp = (GenericRoutingDecision *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getNextHop()); break;
        default: return nullptr;
    }
}

} // namespace inet

