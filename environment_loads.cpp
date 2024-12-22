#include "environment_loads.h"

EnvironmentLoads::EnvironmentLoads(
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
                             QObject *parent)
                              : QObject(parent),
                              windSpeed_(windSpeed),
                              wind_speed_data_(wind_speed_data),
                              windDirection_(windDirection),
                              currentSPeed_(currentSPeed),
                              current_speed_data_(current_speed_data),
                              currentDirection_(currentDirection),
                              waveHeight_(waveHeight), wavePeriod_(wavePeriod), waveDirection_(waveDirection), data_path_(data_path)
{
    readCurrentData();
    readWindData();





}


void EnvironmentLoads::readCurrentData(){
    std::string file_name = data_path_ + "/current_data.csv";
    std::ifstream file(file_name);
    int i = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            if (i==0){
                // current_dir_data_.clear();
                while ( std::getline(ss, cell, ',')) {
                    current_dir_data_.push_back(std::stod(cell));
            }
            }
            else {
                while (std::getline(ss, cell, ',')) {
                    current_force_data_[i-1].push_back(std::stod(cell));
            }
            }

            i++;

        }
    }
    else{
        std::cerr<<"Unable to open file"<<file_name<<std::endl;
    }

    current_acc_ = gsl_interp_accel_alloc();
    current_spline_ = gsl_spline_alloc(gsl_interp_cspline, current_dir_data_.size());


}

void EnvironmentLoads::readWindData(){
    std::string file_name = data_path_ + "/wind_data.csv";
    std::ifstream file(file_name);
    int i = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            if (i==0){
                // current_dir_data_.clear();
                while ( std::getline(ss, cell, ',')) {
                    wind_dir_data_.push_back(std::stod(cell));
            }
            }
            else {
                while (std::getline(ss, cell, ',')) {
                    wind_force_data_[i-1].push_back(std::stod(cell));
            }
            }

            i++;

        }
    }
    else{
        std::cerr<<"Unable to open file"<<file_name<<std::endl;
    }

}