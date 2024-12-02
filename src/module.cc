// Copyright (c) 2009-2024 The Regents of the University of Michigan.
// Part of HOOMD-blue, released under the BSD 3-Clause License.

// TODO: Include the header files of classes that will be exported to Python.

#include "hoomd/hpmc/ComputeFreeVolume.h"
#include "hoomd/hpmc/IntegratorHPMC.h"
#include "hoomd/hpmc/IntegratorHPMCMono.h"
#include <pybind11/pybind11.h>

#include "hoomd/hpmc/ComputeSDF.h"
#include "hoomd/hpmc/ShapeUnion.h"

#include "hoomd/hpmc/ExternalFieldHarmonic.h"
#include "hoomd/hpmc/ExternalFieldWall.h"

#include "hoomd/hpmc/UpdaterGCA.h"
#include "hoomd/hpmc/UpdaterMuVT.h"

#include "ShapeMySphere.h"

#ifdef ENABLE_HIP
#include "hoomd/hpmc/ComputeFreeVolumeGPU.h"
#include "hoomd/hpmc/IntegratorHPMCMonoGPU.h"
#include "hoomd/hpmc/UpdaterGCAGPU.h"
#endif

using namespace hoomd::hpmc::detail;

namespace hoomd
    {
namespace hpmc
    {

// TODO: Set the name of the python module to match ${COMPONENT_NAME} (set in
// CMakeLists.txt), prefixed with an underscore.
PYBIND11_MODULE(_template, m)
    {
    // TODO: Call export_Class(m) for each C++ class to be exported to Python.
    export_IntegratorHPMCMono<ShapeMySphere>(m, "IntegratorHPMCMonoMySphere");
    export_ComputeFreeVolume<ShapeMySphere>(m, "ComputeFreeVolumeMySphere");
    export_ComputeSDF<ShapeMySphere>(m, "ComputeSDFMySphere");
    export_UpdaterMuVT<ShapeMySphere>(m, "UpdaterMuVTMySphere");
    export_UpdaterGCA<ShapeMySphere>(m, "UpdaterGCAMySphere");

    export_ExternalFieldWall<ShapeMySphere>(m, "WallMySphere");

    pybind11::class_<MySphereParams, std::shared_ptr<MySphereParams>>(m, "MySphereParams")
        .def(pybind11::init<pybind11::dict>())
        .def("asDict", &MySphereParams::asDict);

#ifdef ENABLE_HIP
    // TODO: Call export_ClassGPU(m) for each GPU enabled C++ class to be exported
    // to Python.
    export_IntegratorHPMCMonoGPU<ShapeMySphere>(m, "IntegratorHPMCMonoMySphereGPU");
    export_ComputeFreeVolumeGPU<ShapeMySphere>(m, "ComputeFreeVolumeMySphereGPU");
    export_UpdaterGCAGPU<ShapeMySphere>(m, "UpdaterGCAMySphereGPU");
#endif
    }

    } // namespace hpmc
    } // end namespace hoomd
