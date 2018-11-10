#include "PdalRust.hpp"
#include "BuildInfo.hpp"

#include <pdal/Kernel.hpp>
#include <pdal/PointTable.hpp>

#include <memory>
#include <string>


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
        args.add("input,i", "Input filename", m_input_file).setPositional();
        args.add("output,o", "Output filename", m_output_file).setPositional();
    }

    int PdalRust::execute()
    {
        PointTable table;
        Stage& reader = makeReader(m_input_file, "readers.las");

        return 0;
    }
}
