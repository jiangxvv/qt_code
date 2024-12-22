#ifndef ENVIRONMENTLOADS_H
#define ENVIRONMENTLOADS_H

#include <QObject>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_spline.h>


class EnvironmentLoads : public QObject
{
    Q_OBJECT
public:
    explicit EnvironmentLoads(
                             const double& windSpeed,
                             const double& wind_speed_data,
                             const double& windDirection,
                             const double& currentSPeed,
                             const double& current_speed_data,
                             const double& currentDirection ,
                             const double& waveHeight ,
                             const double& wavePeriod ,
                             const double& waveDirection ,
                             const std::string& data_path,
                             QObject *parent = nullptr);


private:
    double windSpeed_;
    double wind_speed_data_;
    double windDirection_;
    double currentSPeed_;
    double current_speed_data_;
    double currentDirection_;
    double waveHeight_;
    double wavePeriod_;
    double waveDirection_;
    std::string data_path_;


    //插值用
    gsl_spline *wind_spline_;
    gsl_interp_accel *wind_acc_;
    gsl_spline *current_spline_;
    gsl_interp_accel *current_acc_;


    std::vector<double> wind_dir_data_;
    std::array<std::vector<double>, 3> wind_force_data_;
    std::vector<double> current_dir_data_;
    std::array<std::vector<double>, 3> current_force_data_;

    std::array<std::vector<double>, 3> wave_height_data_;
    std::array<std::vector<double>, 3> wave_period_data_;
    std::vector<double> wave_dir_data_;

    std::vector<double> time_data_;


void readWindData();

void readCurrentData( );









signals:

};

#endif // ENVIRONMENTLOADS_H
