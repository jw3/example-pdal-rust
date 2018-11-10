#pragma once

#include <pdal/Kernel.hpp>

#include <string>

namespace pdal
{

    class PDAL_DLL PdalRust : public Kernel
    {
    public:
        PdalRust();

        std::string getName() const override;
        int execute() override;

    private:
        void addSwitches(ProgramArgs& args) override;

        std::string m_input_file;
        std::string m_output_file;
    };
}
