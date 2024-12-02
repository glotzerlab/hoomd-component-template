# Copyright (c) 2009-2024 The Regents of the University of Michigan.
# Part of HOOMD-blue, released under the BSD 3-Clause License.

"""Example Shape Integrator."""

# Import the C++ module
from . import _template

import hoomd


class MySphere(hoomd.hpmc.integrate.HPMCIntegrator):
    """Example shape integrator."""

    # set static class data
    _ext_module = _template
    _cpp_cls = "IntegratorHPMCMonoMySphere"

    def __init__(
        self,
        default_d=0.1,
        default_a=0.1,
        translation_move_probability=0.5,
        nselect=4,
        kT=1.0,
    ):
        # initialize base class
        super().__init__(
            default_d, default_a, translation_move_probability, nselect, kT
        )

        typeparam_shape = hoomd.data.typeparam.TypeParameter(
            "shape",
            type_kind="particle_types",
            param_dict=hoomd.data.parameterdicts.TypeParameterDict(
                radius=float, ignore_statistics=False, orientable=False, len_keys=1
            ),
        )
        self._add_typeparam(typeparam_shape)

    @hoomd.logging.log(category="object", requires_run=True)
    def type_shapes(self):
        """list[dict]: Description of shapes in ``type_shapes`` format."""
        return super()._return_type_shapes()
