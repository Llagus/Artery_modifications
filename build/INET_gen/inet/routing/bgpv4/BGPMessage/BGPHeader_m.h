//
// Generated file, do not edit! Created by nedtool 5.6 from /home/llagus/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPHeader.msg.
//

#ifndef __INET__BGP_BGPHEADER_M_H
#define __INET__BGP_BGPHEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
namespace inet {
const int BGP_HEADER_OCTETS = 19;
} // namespace inet
// }}


namespace inet {
namespace bgp {

/**
 * Enum generated from <tt>/home/llagus/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPHeader.msg:33</tt> by nedtool.
 * <pre>
 * //
 * // BGPv4 message types
 * //
 * enum BGPType
 * {
 *     BGP_OPEN = 1;
 *     BGP_UPDATE = 2;
 *     BGP_NOTIFICATION = 3;
 *     BGP_KEEPALIVE = 4;
 * }
 * </pre>
 */
enum BGPType {
    BGP_OPEN = 1,
    BGP_UPDATE = 2,
    BGP_NOTIFICATION = 3,
    BGP_KEEPALIVE = 4
};

/**
 * Class generated from <tt>/home/llagus/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPHeader.msg:49</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 message header.
 * //
 * // Header fields modeled:
 * //   - Marker: 16 octets (authentication)
 * //   - Length: 2 octets  (total size of the message)
 * //   - Type: 1 octet
 * //
 * packet BGPHeader
 * {
 *     byteLength = BGP_HEADER_OCTETS;
 *     char type \@enum(BGPType);
 * }
 * </pre>
 */
class BGPHeader : public ::omnetpp::cPacket
{
  protected:
    char type;

  private:
    void copy(const BGPHeader& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGPHeader&);

  public:
    BGPHeader(const char *name=nullptr, short kind=0);
    BGPHeader(const BGPHeader& other);
    virtual ~BGPHeader();
    BGPHeader& operator=(const BGPHeader& other);
    virtual BGPHeader *dup() const override {return new BGPHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual char getType() const;
    virtual void setType(char type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BGPHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BGPHeader& obj) {obj.parsimUnpack(b);}

} // namespace bgp
} // namespace inet

#endif // ifndef __INET__BGP_BGPHEADER_M_H

