#include "PdalRust.hpp"
#include "BuildInfo.hpp"

#include <pdal/Kernel.hpp>
#include <pdal/PointTable.hpp>

#include <memory>
#include <string>

#include <libbackend.hpp>


namespace pdal {

    static PluginInfo const s_info{
            BuildInfo::PDALStageName,
            BuildInfo::PluginDescription,
            BuildInfo::PluginURL
    };

    CREATE_SHARED_KERNEL(PdalRust, s_info);
    std::string PdalRust::getName() const { return s_info.name; }

    PdalRust::PdalRust() : Kernel() {
    }

    void PdalRust::addSwitches(ProgramArgs& args) {
        args.add("say", "something", sayWhat);
    }

    int PdalRust::execute()
    {
        say(sayWhat.c_str());
        return 0;
    }
}
