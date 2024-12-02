# Copyright (c) 2009-2024 The Regents of the University of Michigan.
# Part of HOOMD-blue, released under the BSD 3-Clause License.

"""Test the shape."""

import hoomd.template


# TODO: rewrite the unit tests to verify that your shape functions correctly.

def test_attach(simulation_factory, two_particle_snapshot_factory):
    """Ensure that an integrator can be created with the shape."""
    mc = hoomd.template.MySphere()
    mc.shape["A"] = dict(radius=0.5)
    mc.d["A"] = 0.1
    mc.a["A"] = 0.1
    sim = simulation_factory(two_particle_snapshot_factory())
    sim.operations.integrator = mc

    sim.run(0)
