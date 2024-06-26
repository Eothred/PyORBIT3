#include "orbit_mpi.hh"

#include "wrap_Frequency_Cav.hh"
#include "wrap_Harmonic_Cav.hh"
#include "wrap_Barrier_Cav.hh"
#include "wrap_Dual_Harmonic_Cav.hh"


static PyMethodDef rfcavitiesMethods[] = {{NULL,NULL}};


namespace wrap_rfcavities
{

#ifdef __cplusplus
extern "C"
{
#endif

static struct PyModuleDef cModRFcav = {
    PyModuleDef_HEAD_INIT,
    "rfcavities", "RFCavities class",
    -1,
     rfcavitiesMethods
     };

PyMODINIT_FUNC initrfcavities()
{
  //create new module;
  PyObject* module = PyModule_Create(&cModRFcav);
  wrap_rfcavities::initFrequency_Cav(module);
  wrap_rfcavities::initHarmonic_Cav(module);
  wrap_rfcavities::initDual_Harmonic_Cav(module);
  wrap_rfcavities::initBarrier_Cav(module);
  return module;
}

PyObject* getRFCavityType(char* name)
{
  PyObject* mod = PyImport_ImportModule("orbit.core.rfcavities");
  PyObject* pyType = PyObject_GetAttrString(mod, name);
  Py_DECREF(mod);
  Py_DECREF(pyType);
  return pyType;
}

#ifdef __cplusplus
}
#endif // __cplusplus

} // end of namespace wrap_rfcavities
