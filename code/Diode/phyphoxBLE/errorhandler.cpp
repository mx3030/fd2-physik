#include "phyphoxBleExperiment.h"
#include "copyToMem.h"


PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkLength(const char *input, int maxLength, const char *origin) {
    Error ret;
    if(strlen(input) > maxLength) {
        copyToMem(&ret.MESSAGE, ("ERR_01, in " + std::string(origin) + "(). \n").c_str());
    }
    return ret;
}

PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkUpper(int input, int upperValue, const char *origin) {
    Error ret;
    if(input > upperValue) {
        copyToMem(&ret.MESSAGE, ("ERR_02, in " + std::string(origin) + "(). \n").c_str());
    }
    return ret;
}

PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkHex(const char* input, const char *origin){
    Error ret;
    if(strlen(input) != 6) {
        copyToMem(&ret.MESSAGE, ("ERR_03, in " + std::string(origin) + "(). \n").c_str());
    };
    for(int i=0; i<=5; i++) {
		if(!((input[i] <='f' && input[i] >='a') || (input[i] <='F' && input[i] >='A') || (input[i] <='9' && input[i] >='0'))) {
            copyToMem(&ret.MESSAGE, ("ERR_03, in " + std::string(origin) + "(). \n").c_str());
		}
	}
    return ret;
}

PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkStyle(const char *input, const char *origin) {
    Error ret;
    if(strcmp(input,"lines")!=0 && strcmp(input,"dots")!=0 && strcmp(input,"vbars")!=0 && strcmp(input,"hbars")!=0 && strcmp(input,"map")!=0) {
        copyToMem(&ret.MESSAGE, ("ERR_04, in " + std::string(origin) + "(). \n").c_str());
    }
    return ret;
}

PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkLayout(const char *input, const char *origin) {
    Error ret;
    copyToMem(&ret.MESSAGE, ("ERR_05, in " + std::string(origin) + "(). \n").c_str());
    return ret;
}

PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkSensor(const char *input, const char *origin) {
    Error ret;
    if(strcmp(input,"accelerometer")!=0 && strcmp(input,"linear_acceleration")!=0 && strcmp(input,"gyroscope")!=0 && strcmp(input,"light")!=0 && strcmp(input,"magnetic_field")!=0 && strcmp(input,"pressure")!=0 && strcmp(input,"temperature")!=0) {
        copyToMem(&ret.MESSAGE, ("ERR_04, in " + std::string(origin) + "(). \n").c_str());
    }
    return ret;
}

PhyphoxBleExperiment::Error PhyphoxBleExperiment::Errorhandler::err_checkComponent(const char *input, const char *origin) {
    Error ret;
    if(strcmp(input,"x")!=0 && strcmp(input,"y")!=0 && strcmp(input,"z")!=0 && strcmp(input,"abs")!=0 && strcmp(input,"accuracy")!=0 && strcmp(input,"t")!=0) {
        copyToMem(&ret.MESSAGE, ("ERR_04, in " + std::string(origin) + "(). \n").c_str());
    }
    return ret;
}