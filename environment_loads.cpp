#include "environment_loads.h"

EnvironmentLoads::EnvironmentLoads(
                             const double& windSpeed,
                             const double& windDirection,
                             const double& currentSPeed,
                             const double& currentDirection ,
                             const double& waveHeight ,
                             const double& wavePeriod ,
                             const double& waveDirection ,
                             const std::string& data_path,
                             QObject *parent)
                              : QObject(parent),
                              windSpeed_(windSpeed),
                              windDirection_(windDirection),
                              currentSPeed_(currentSPeed),
                              currentDirection_(currentDirection),
                              waveHeight_(waveHeight), wavePeriod_(wavePeriod), waveDirection_(waveDirection), data_path_(data_path)
{
    

}
