#ifndef REAL_TIME_EFFECTS_H
#define REAL_TIME_EFFECTS_H

#include <string>

namespace my_streaming_software {
namespace effects {

class RealTimeEffects {
public:
    bool applyEffect(const std::string& effectName, const std::string& inputFilePath, const std::string& outputFilePath);
};

} // namespace effects
} // namespace my_streaming_software

#endif // REAL_TIME_EFFECTS_H
