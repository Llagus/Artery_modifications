#include "artery/traci/MobilityBase.h"
#include <omnetpp/ccomponent.h>

using namespace traci;

namespace artery
{

omnetpp::simsignal_t MobilityBase::stateChangedSignal = omnetpp::cComponent::registerSignal("mobilityStateChanged");

void MobilityBase::initializeSink(LiteAPI* api, const std::string& id, const Boundary& boundary, std::shared_ptr<VehicleCache> cache)
{
    ASSERT(api);
    ASSERT(cache);
    ASSERT(cache->getVehicleId() == id);
    ASSERT(&cache->getLiteAPI() == api);
    mTraci = api;
    mVehicleId = id;
    mNetBoundary = boundary;
    mController.reset(new VehicleController(cache));
}

void MobilityBase::initializeVehicle(const TraCIPosition& traci_pos, TraCIAngle traci_heading, double traci_speed)
{
    const auto opp_pos = position_cast(mNetBoundary, traci_pos);
    const auto opp_angle = angle_cast(traci_heading);
    initialize(opp_pos, opp_angle, traci_speed); 

    std::string path = "/home/llagus/Documents/Telecos/Pràctiques/Artery_modifications/results/" +  mVehicleId ;
    
    m_text = "Vehicle " + mVehicleId + ":\n\n";
    m_file.open(path.c_str(), std::ofstream::out); 
    m_file.write(m_text.c_str(), m_text.length());
    m_file.close();  
    
}

void MobilityBase::updateVehicle(const TraCIPosition& traci_pos, TraCIAngle traci_heading, double traci_speed)
{
    const auto opp_pos = position_cast(mNetBoundary, traci_pos);
    const auto opp_angle = angle_cast(traci_heading);
    update(opp_pos, opp_angle, traci_speed);

    /*Eudald changes to store the data*/
    std::string path = "/home/llagus/Documents/Telecos/Pràctiques/Artery_modifications/results/" +  mVehicleId ;
    auto x = opp_pos.x; 
    
    m_text = "Position: " + std::to_string(x.value()) + " " + std::to_string(opp_pos.y.value()) + "\n";
    m_text += "Speed: " + std::to_string(traci_speed) + "\n"; 
    m_text += "Angle: " + std::to_string(opp_angle.degree()) + "\n";
    m_file.open(path.c_str(), std::ofstream::app); 
    m_file.write(m_text.c_str(), m_text.length());
    m_file.close();  
    
}

VehicleController* MobilityBase::getVehicleController()
{
    ASSERT(mController);
    return mController.get();
}

} // namespace artery
