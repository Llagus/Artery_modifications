//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/artery/extern/inet/src/inet/networklayer/contract/NetworkProtocolCommand.msg.
//

#ifndef __INET_NETWORKPROTOCOLCOMMAND_M_H
#define __INET_NETWORKPROTOCOLCOMMAND_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace inet {

/**
 * Class generated from <tt>/home/llagus/artery/extern/inet/src/inet/networklayer/contract/NetworkProtocolCommand.msg:22</tt> by nedtool.
 * <pre>
 * message RegisterTransportProtocolCommand
 * {
 *     int protocol;
 * }
 * </pre>
 */
class RegisterTransportProtocolCommand : public ::omnetpp::cMessage
{
  protected:
    int protocol;

  private:
    void copy(const RegisterTransportProtocolCommand& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RegisterTransportProtocolCommand&);

  public:
    RegisterTransportProtocolCommand(const char *name=nullptr, short kind=0);
    RegisterTransportProtocolCommand(const RegisterTransportProtocolCommand& other);
    virtual ~RegisterTransportProtocolCommand();
    RegisterTransportProtocolCommand& operator=(const RegisterTransportProtocolCommand& other);
    virtual RegisterTransportProtocolCommand *dup() const override {return new RegisterTransportProtocolCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getProtocol() const;
    virtual void setProtocol(int protocol);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RegisterTransportProtocolCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RegisterTransportProtocolCommand& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_NETWORKPROTOCOLCOMMAND_M_H

