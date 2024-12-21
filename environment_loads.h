#ifndef ENVIRONMENTLOADS_H
#define ENVIRONMENTLOADS_H

#include <QObject>
#include <vector>
#include <array>
#include <string>

class EnvironmentLoads : public QObject
{
    Q_OBJECT
public:
    explicit EnvironmentLoads(
                             const double& windSpeed,
                             const double& windDirection,
                             const double& currentSPeed,
                             const double& currentDirection ,
                             const double& waveHeight ,
                             const double& wavePeriod ,
                             const double& waveDirection ,
                             const std::string& data_path,
                             QObject *parent = nullptr);


private:
    double windSpeed_;
    double windDirection_;
    double currentSPeed_;
    double currentDirection_;
    double waveHeight_;
    double wavePeriod_;
    double waveDirection_;
    std::string data_path_;

    std::vector<double> wind_dir_data_;
    std::array<std::vector<double>, 3> wind_speed_data_;
    std::vector<double> current_dir_data_;
    std::array<std::vector<double>, 3> current_speed_data_;

    std::array<std::vector<double>, 3> wave_height_data_;
    std::array<std::vector<double>, 3> wave_period_data_;
    std::vector<double> wave_dir_data_;

    std::vector<double> time_data_;









signals:

};

#endif // ENVIRONMENTLOADS_H
