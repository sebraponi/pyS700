#include "Python.h"
#include "gpio_lib.h"


static PyObject *SetupException;
static PyObject *OutputException;
static PyObject *InputException;
static PyObject *inp;
static PyObject *out;
static PyObject *per;
static PyObject *high;
static PyObject *low;

#define PA0    OWL_GPA(0)
#define PA1    OWL_GPA(1)
#define PA2    OWL_GPA(2)
#define PA3    OWL_GPA(3)
#define PA4    OWL_GPA(4)
#define PA5    OWL_GPA(5)
#define PA6    OWL_GPA(6)
#define PA7    OWL_GPA(7)
#define PA8    OWL_GPA(8)
#define PA9    OWL_GPA(9)
#define PA10    OWL_GPA(10)
#define PA11    OWL_GPA(11)
#define PA12    OWL_GPA(12)
#define PA13    OWL_GPA(13)
#define PA14    OWL_GPA(14)
#define PA15    OWL_GPA(15)
#define PA16    OWL_GPA(16)
#define PA17    OWL_GPA(17)
#define PA18    OWL_GPA(18)
#define PA19    OWL_GPA(19)
#define PA20    OWL_GPA(20)
#define PA21    OWL_GPA(21)
#define PA22    OWL_GPA(22)
#define PA23    OWL_GPA(23)
#define PA24    OWL_GPA(24)
#define PA25    OWL_GPA(25)
#define PA26    OWL_GPA(26)
#define PA27    OWL_GPA(27)
#define PA28    OWL_GPA(28)
#define PA29    OWL_GPA(29)
#define PA30    OWL_GPA(30)
#define PA31    OWL_GPA(31)

#define PB0    OWL_GPB(0)
#define PB1    OWL_GPB(1)
#define PB2    OWL_GPB(2)
#define PB3    OWL_GPB(3)
#define PB4    OWL_GPB(4)
#define PB5    OWL_GPB(5)
#define PB6    OWL_GPB(6)
#define PB7    OWL_GPB(7)
#define PB8    OWL_GPB(8)
#define PB9    OWL_GPB(9)
#define PB10    OWL_GPB(10)
#define PB11    OWL_GPB(11)
#define PB12    OWL_GPB(12)
#define PB13    OWL_GPB(13)
#define PB14    OWL_GPB(14)
#define PB15    OWL_GPB(15)
#define PB16    OWL_GPB(16)
#define PB17    OWL_GPB(17)
#define PB18    OWL_GPB(18)
#define PB19    OWL_GPB(19)
#define PB20    OWL_GPB(20)
#define PB21    OWL_GPB(21)
#define PB22    OWL_GPB(22)
#define PB23    OWL_GPB(23)
#define PB24    OWL_GPB(24)
#define PB25    OWL_GPB(25)
#define PB26    OWL_GPB(26)
#define PB27    OWL_GPB(27)
#define PB28    OWL_GPB(28)
#define PB29    OWL_GPB(29)
#define PB30    OWL_GPB(30)
#define PB31    OWL_GPB(31)

#define PC0    OWL_GPC(0)
#define PC1    OWL_GPC(1)
#define PC2    OWL_GPC(2)
#define PC3    OWL_GPC(3)
#define PC4    OWL_GPC(4)
#define PC5    OWL_GPC(5)
#define PC6    OWL_GPC(6)
#define PC7    OWL_GPC(7)
#define PC8    OWL_GPC(8)
#define PC9    OWL_GPC(9)
#define PC10    OWL_GPC(10)
#define PC11    OWL_GPC(11)
#define PC12    OWL_GPC(12)
#define PC13    OWL_GPC(13)
#define PC14    OWL_GPC(14)
#define PC15    OWL_GPC(15)
#define PC16    OWL_GPC(16)
#define PC17    OWL_GPC(17)
#define PC18    OWL_GPC(18)
#define PC19    OWL_GPC(19)
#define PC20    OWL_GPC(20)
#define PC21    OWL_GPC(21)
#define PC22    OWL_GPC(22)
#define PC23    OWL_GPC(23)
#define PC24    OWL_GPC(24)
#define PC25    OWL_GPC(25)
#define PC26    OWL_GPC(26)
#define PC27    OWL_GPC(27)
#define PC28    OWL_GPC(28)
#define PC29    OWL_GPC(29)
#define PC30    OWL_GPC(30)
#define PC31    OWL_GPC(31)

#define PD0    OWL_GPD(0)
#define PD1    OWL_GPD(1)
#define PD2    OWL_GPD(2)
#define PD3    OWL_GPD(3)
#define PD4    OWL_GPD(4)
#define PD5    OWL_GPD(5)
#define PD6    OWL_GPD(6)
#define PD7    OWL_GPD(7)
#define PD8    OWL_GPD(8)
#define PD9    OWL_GPD(9)
#define PD10    OWL_GPD(10)
#define PD11    OWL_GPD(11)
#define PD12    OWL_GPD(12)
#define PD13    OWL_GPD(13)
#define PD14    OWL_GPD(14)
#define PD15    OWL_GPD(15)
#define PD16    OWL_GPD(16)
#define PD17    OWL_GPD(17)
#define PD18    OWL_GPD(18)
#define PD19    OWL_GPD(19)
#define PD20    OWL_GPD(20)
#define PD21    OWL_GPD(21)
#define PD22    OWL_GPD(22)
#define PD23    OWL_GPD(23)
#define PD24    OWL_GPD(24)
#define PD25    OWL_GPD(25)
#define PD26    OWL_GPD(26)
#define PD27    OWL_GPD(27)
#define PD28    OWL_GPD(28)
#define PD29    OWL_GPD(29)
#define PD30    OWL_GPD(30)
#define PD31    OWL_GPD(31)

#define PE0    OWL_GPE(0)
#define PE1    OWL_GPE(1)
#define PE2    OWL_GPE(2)
#define PE3    OWL_GPE(3)
#define PE4    OWL_GPE(4)
#define PE5    OWL_GPE(5)
#define PE6    OWL_GPE(6)
#define PE7    OWL_GPE(7)
#define PE8    OWL_GPE(8)
#define PE9    OWL_GPE(9)
#define PE10    OWL_GPE(10)
#define PE11    OWL_GPE(11)
#define PE12    OWL_GPE(12)
#define PE13    OWL_GPE(13)
#define PE14    OWL_GPE(14)
#define PE15    OWL_GPE(15)
#define PE16    OWL_GPE(16)
#define PE17    OWL_GPE(17)
#define PE18    OWL_GPE(18)
#define PE19    OWL_GPE(19)
#define PE20    OWL_GPE(20)
#define PE21    OWL_GPE(21)
#define PE22    OWL_GPE(22)
#define PE23    OWL_GPE(23)
#define PE24    OWL_GPE(24)
#define PE25    OWL_GPE(25)
#define PE26    OWL_GPE(26)
#define PE27    OWL_GPE(27)
#define PE28    OWL_GPE(28)
#define PE29    OWL_GPE(29)
#define PE30    OWL_GPE(30)
#define PE31    OWL_GPE(31)


static int module_setup(void) {
    int result;

    result = owl_gpio_init();
    if(result == SETUP_DEVMEM_FAIL) {
        PyErr_SetString(SetupException, "No access to /dev/mem. Try running as root!");
        return SETUP_DEVMEM_FAIL;
    }
    else if(result == SETUP_MALLOC_FAIL) {
        PyErr_NoMemory();
        return SETUP_MALLOC_FAIL;
    }
    else if(result == SETUP_MMAP_FAIL) {
        PyErr_SetString(SetupException, "Mmap failed on module import");
        return SETUP_MMAP_FAIL;
    }
    else {
        return SETUP_OK;
    }

    return SETUP_OK;
}

static PyObject* py_output(PyObject* self, PyObject* args) {
    int gpio;
    int value;

    if(!PyArg_ParseTuple(args, "ii", &gpio, &value))
        return NULL;

    if(value != 0 && value != 1) {
        PyErr_SetString(OutputException, "Invalid output state");
        return NULL;
    }

    if(owl_gpio_get_cfgpin(gpio) != OWL_GPIO_OUTPUT) {
        PyErr_SetString(OutputException, "GPIO is no an output");
        return NULL;
    }
    owl_gpio_output(gpio, value);

    Py_RETURN_NONE;
}
static PyObject* py_input(PyObject* self, PyObject* args) {
    int gpio;
    int result;

    if(!PyArg_ParseTuple(args, "i", &gpio))
        return NULL;

    if(owl_gpio_get_cfgpin(gpio) != OWL_GPIO_INPUT) {
        PyErr_SetString(InputException, "GPIO is not an input");
        return NULL;
    }
    result = owl_gpio_input(gpio);

    if(result == -1) {
        PyErr_SetString(InputException, "Reading pin failed");
        return NULL;
    }


    return Py_BuildValue("i", result);
}

static PyObject* py_output_setcfg(PyObject* self, PyObject* args) {
    int gpio;

    if(!PyArg_ParseTuple(args, "i", &gpio))
        return NULL;

    owl_gpio_set_output_cfgpin(gpio);

    Py_RETURN_NONE;
}

static PyObject* py_input_setcfg(PyObject* self, PyObject* args) {
    int gpio;

    if(!PyArg_ParseTuple(args, "i", &gpio))
        return NULL;

    owl_gpio_set_input_cfgpin(gpio);

    Py_RETURN_NONE;
}

static PyObject* py_getcfg(PyObject* self, PyObject* args) {
    int gpio;
    int result;


    if(!PyArg_ParseTuple(args, "i", &gpio))
        return NULL;

    result = owl_gpio_get_cfgpin(gpio);


    return Py_BuildValue("i", result);


}

static PyObject* py_init(PyObject* self, PyObject* args) {

    module_setup();

    Py_RETURN_NONE;
}

static PyObject* py_cleanup(PyObject* self, PyObject* args) {

    owl_gpio_cleanup();
    Py_RETURN_NONE;
}


PyMethodDef module_methods[] = {
    {"init", py_init, METH_NOARGS, "Initialize module"},
    {"cleanup", py_cleanup, METH_NOARGS, "munmap /dev/map."},
    {"output_setcfg", py_output_setcfg, METH_VARARGS, "Set output direction"},
    {"input_setcfg" , py_input_setcfg, METH_VARARGS, "Set input direction"},
    {"getcfg", py_getcfg, METH_VARARGS, "Get direction."},
    {"output", py_output, METH_VARARGS, "Set output state"},
    {"input", py_input, METH_VARARGS, "Get input state"},
    {NULL, NULL, 0, NULL}
};
#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "pyS700 module",
    NULL,
    -1,
    module_methods
};
#endif
PyMODINIT_FUNC initpyS700(void) {
    PyObject* module = NULL;


#if PY_MAJOR_VERSION >= 3
    module = PyModule_Create(&module_methods);
#else
    module = Py_InitModule("pyS700", module_methods);
#endif


    if(module == NULL)
#if PY_MAJOR_VERSION >= 3
        return module;
#else
        return;
#endif

    SetupException = PyErr_NewException("pyS700.SetupException", NULL, NULL);
    PyModule_AddObject(module, "SetupException", SetupException);
    OutputException = PyErr_NewException("pyS700.OutputException", NULL, NULL);
    PyModule_AddObject(module, "OutputException", OutputException);
    InputException = PyErr_NewException("pyS700.InputException", NULL, NULL);
    PyModule_AddObject(module, "InputException", InputException);

    high = Py_BuildValue("i", HIGH);
    PyModule_AddObject(module, "HIGH", high);

    low = Py_BuildValue("i", LOW);
    PyModule_AddObject(module, "LOW", low);

    inp = Py_BuildValue("i", INPUT);
    PyModule_AddObject(module, "IN", inp);

    out = Py_BuildValue("i", OUTPUT);
    PyModule_AddObject(module, "OUT", out);

    per = Py_BuildValue("i", PER);
    PyModule_AddObject(module, "PER", per);


    PyModule_AddObject(module, "PA0", Py_BuildValue("i", PA0));
    PyModule_AddObject(module, "PA1", Py_BuildValue("i", PA1));
    PyModule_AddObject(module, "PA2", Py_BuildValue("i", PA2));
    PyModule_AddObject(module, "PA3", Py_BuildValue("i", PA3));
    PyModule_AddObject(module, "PA4", Py_BuildValue("i", PA4));
    PyModule_AddObject(module, "PA5", Py_BuildValue("i", PA5));
    PyModule_AddObject(module, "PA6", Py_BuildValue("i", PA6));
    PyModule_AddObject(module, "PA7", Py_BuildValue("i", PA7));
    PyModule_AddObject(module, "PA8", Py_BuildValue("i", PA8));
    PyModule_AddObject(module, "PA9", Py_BuildValue("i", PA9));
    PyModule_AddObject(module, "PA10", Py_BuildValue("i", PA10));
    PyModule_AddObject(module, "PA11", Py_BuildValue("i", PA11));
    PyModule_AddObject(module, "PA12", Py_BuildValue("i", PA12));
    PyModule_AddObject(module, "PA13", Py_BuildValue("i", PA13));
    PyModule_AddObject(module, "PA14", Py_BuildValue("i", PA14));
    PyModule_AddObject(module, "PA15", Py_BuildValue("i", PA15));
    PyModule_AddObject(module, "PA16", Py_BuildValue("i", PA16));
    PyModule_AddObject(module, "PA17", Py_BuildValue("i", PA17));
    PyModule_AddObject(module, "PA18", Py_BuildValue("i", PA18));
    PyModule_AddObject(module, "PA19", Py_BuildValue("i", PA19));
    PyModule_AddObject(module, "PA20", Py_BuildValue("i", PA20));
    PyModule_AddObject(module, "PA21", Py_BuildValue("i", PA21));
    PyModule_AddObject(module, "PA22", Py_BuildValue("i", PA22));
    PyModule_AddObject(module, "PA23", Py_BuildValue("i", PA23));
    PyModule_AddObject(module, "PA24", Py_BuildValue("i", PA24));
    PyModule_AddObject(module, "PA25", Py_BuildValue("i", PA25));
    PyModule_AddObject(module, "PA26", Py_BuildValue("i", PA26));
    PyModule_AddObject(module, "PA27", Py_BuildValue("i", PA27));
    PyModule_AddObject(module, "PA28", Py_BuildValue("i", PA28));
    PyModule_AddObject(module, "PA29", Py_BuildValue("i", PA29));
    PyModule_AddObject(module, "PA30", Py_BuildValue("i", PA30));
    PyModule_AddObject(module, "PA31", Py_BuildValue("i", PA31));

    PyModule_AddObject(module, "PB0", Py_BuildValue("i", PB0));
    PyModule_AddObject(module, "PB1", Py_BuildValue("i", PB1));
    PyModule_AddObject(module, "PB2", Py_BuildValue("i", PB2));
    PyModule_AddObject(module, "PB3", Py_BuildValue("i", PB3));
    PyModule_AddObject(module, "PB4", Py_BuildValue("i", PB4));
    PyModule_AddObject(module, "PB5", Py_BuildValue("i", PB5));
    PyModule_AddObject(module, "PB6", Py_BuildValue("i", PB6));
    PyModule_AddObject(module, "PB7", Py_BuildValue("i", PB7));
    PyModule_AddObject(module, "PB8", Py_BuildValue("i", PB8));
    PyModule_AddObject(module, "PB9", Py_BuildValue("i", PB9));
    PyModule_AddObject(module, "PB10", Py_BuildValue("i", PB10));
    PyModule_AddObject(module, "PB11", Py_BuildValue("i", PB11));
    PyModule_AddObject(module, "PB12", Py_BuildValue("i", PB12));
    PyModule_AddObject(module, "PB13", Py_BuildValue("i", PB13));
    PyModule_AddObject(module, "PB14", Py_BuildValue("i", PB14));
    PyModule_AddObject(module, "PB15", Py_BuildValue("i", PB15));
    PyModule_AddObject(module, "PB16", Py_BuildValue("i", PB16));
    PyModule_AddObject(module, "PB17", Py_BuildValue("i", PB17));
    PyModule_AddObject(module, "PB18", Py_BuildValue("i", PB18));
    PyModule_AddObject(module, "PB19", Py_BuildValue("i", PB19));
    PyModule_AddObject(module, "PB20", Py_BuildValue("i", PB20));
    PyModule_AddObject(module, "PB21", Py_BuildValue("i", PB21));
    PyModule_AddObject(module, "PB22", Py_BuildValue("i", PB22));
    PyModule_AddObject(module, "PB23", Py_BuildValue("i", PB23));
    PyModule_AddObject(module, "PB24", Py_BuildValue("i", PB24));
    PyModule_AddObject(module, "PB25", Py_BuildValue("i", PB25));
    PyModule_AddObject(module, "PB26", Py_BuildValue("i", PB26));
    PyModule_AddObject(module, "PB27", Py_BuildValue("i", PB27));
    PyModule_AddObject(module, "PB28", Py_BuildValue("i", PB28));
    PyModule_AddObject(module, "PB29", Py_BuildValue("i", PB29));
    PyModule_AddObject(module, "PB30", Py_BuildValue("i", PB30));
    PyModule_AddObject(module, "PB31", Py_BuildValue("i", PB31));
	
    PyModule_AddObject(module, "PC0", Py_BuildValue("i", PC0));
    PyModule_AddObject(module, "PC1", Py_BuildValue("i", PC1));
    PyModule_AddObject(module, "PC2", Py_BuildValue("i", PC2));
    PyModule_AddObject(module, "PC3", Py_BuildValue("i", PC3));
    PyModule_AddObject(module, "PC4", Py_BuildValue("i", PC4));
    PyModule_AddObject(module, "PC5", Py_BuildValue("i", PC5));
    PyModule_AddObject(module, "PC6", Py_BuildValue("i", PC6));
    PyModule_AddObject(module, "PC7", Py_BuildValue("i", PC7));
    PyModule_AddObject(module, "PC8", Py_BuildValue("i", PC8));
    PyModule_AddObject(module, "PC9", Py_BuildValue("i", PC9));
    PyModule_AddObject(module, "PC10", Py_BuildValue("i", PC10));
    PyModule_AddObject(module, "PC11", Py_BuildValue("i", PC11));
    PyModule_AddObject(module, "PC12", Py_BuildValue("i", PC12));
    PyModule_AddObject(module, "PC13", Py_BuildValue("i", PC13));
    PyModule_AddObject(module, "PC14", Py_BuildValue("i", PC14));
    PyModule_AddObject(module, "PC15", Py_BuildValue("i", PC15));
    PyModule_AddObject(module, "PC16", Py_BuildValue("i", PC16));
    PyModule_AddObject(module, "PC17", Py_BuildValue("i", PC17));
    PyModule_AddObject(module, "PC18", Py_BuildValue("i", PC18));
    PyModule_AddObject(module, "PC19", Py_BuildValue("i", PC19));
    PyModule_AddObject(module, "PC20", Py_BuildValue("i", PC20));
    PyModule_AddObject(module, "PC21", Py_BuildValue("i", PC21));
    PyModule_AddObject(module, "PC22", Py_BuildValue("i", PC22));
    PyModule_AddObject(module, "PC23", Py_BuildValue("i", PC23));
    PyModule_AddObject(module, "PC24", Py_BuildValue("i", PC24));
    PyModule_AddObject(module, "PC25", Py_BuildValue("i", PC25));
    PyModule_AddObject(module, "PC26", Py_BuildValue("i", PC26));
    PyModule_AddObject(module, "PC27", Py_BuildValue("i", PC27));
    PyModule_AddObject(module, "PC28", Py_BuildValue("i", PC28));
    PyModule_AddObject(module, "PC29", Py_BuildValue("i", PC29));
    PyModule_AddObject(module, "PC30", Py_BuildValue("i", PC30));
    PyModule_AddObject(module, "PC31", Py_BuildValue("i", PC31));
	
    PyModule_AddObject(module, "PD0", Py_BuildValue("i", PD0));
    PyModule_AddObject(module, "PD1", Py_BuildValue("i", PD1));
    PyModule_AddObject(module, "PD2", Py_BuildValue("i", PD2));
    PyModule_AddObject(module, "PD3", Py_BuildValue("i", PD3));
    PyModule_AddObject(module, "PD4", Py_BuildValue("i", PD4));
    PyModule_AddObject(module, "PD5", Py_BuildValue("i", PD5));
    PyModule_AddObject(module, "PD6", Py_BuildValue("i", PD6));
    PyModule_AddObject(module, "PD7", Py_BuildValue("i", PD7));
    PyModule_AddObject(module, "PD8", Py_BuildValue("i", PD8));
    PyModule_AddObject(module, "PD9", Py_BuildValue("i", PD9));
    PyModule_AddObject(module, "PD10", Py_BuildValue("i", PD10));
    PyModule_AddObject(module, "PD11", Py_BuildValue("i", PD11));
    PyModule_AddObject(module, "PD12", Py_BuildValue("i", PD12));
    PyModule_AddObject(module, "PD13", Py_BuildValue("i", PD13));
    PyModule_AddObject(module, "PD14", Py_BuildValue("i", PD14));
    PyModule_AddObject(module, "PD15", Py_BuildValue("i", PD15));
    PyModule_AddObject(module, "PD16", Py_BuildValue("i", PD16));
    PyModule_AddObject(module, "PD17", Py_BuildValue("i", PD17));
    PyModule_AddObject(module, "PD18", Py_BuildValue("i", PD18));
    PyModule_AddObject(module, "PD19", Py_BuildValue("i", PD19));
    PyModule_AddObject(module, "PD20", Py_BuildValue("i", PD20));
    PyModule_AddObject(module, "PD21", Py_BuildValue("i", PD21));
    PyModule_AddObject(module, "PD22", Py_BuildValue("i", PD22));
    PyModule_AddObject(module, "PD23", Py_BuildValue("i", PD23));
    PyModule_AddObject(module, "PD24", Py_BuildValue("i", PD24));
    PyModule_AddObject(module, "PD25", Py_BuildValue("i", PD25));
    PyModule_AddObject(module, "PD26", Py_BuildValue("i", PD26));
    PyModule_AddObject(module, "PD27", Py_BuildValue("i", PD27));
    PyModule_AddObject(module, "PD28", Py_BuildValue("i", PD28));
    PyModule_AddObject(module, "PD29", Py_BuildValue("i", PD29));
    PyModule_AddObject(module, "PD30", Py_BuildValue("i", PD30));
    PyModule_AddObject(module, "PD31", Py_BuildValue("i", PD31));
	
    PyModule_AddObject(module, "PE0", Py_BuildValue("i", PE0));
    PyModule_AddObject(module, "PE1", Py_BuildValue("i", PE1));
    PyModule_AddObject(module, "PE2", Py_BuildValue("i", PE2));
    PyModule_AddObject(module, "PE3", Py_BuildValue("i", PE3));
    PyModule_AddObject(module, "PE4", Py_BuildValue("i", PE4));
    PyModule_AddObject(module, "PE5", Py_BuildValue("i", PE5));
    PyModule_AddObject(module, "PE6", Py_BuildValue("i", PE6));
    PyModule_AddObject(module, "PE7", Py_BuildValue("i", PE7));
    PyModule_AddObject(module, "PE8", Py_BuildValue("i", PE8));
    PyModule_AddObject(module, "PE9", Py_BuildValue("i", PE9));
    PyModule_AddObject(module, "PE10", Py_BuildValue("i", PE10));
    PyModule_AddObject(module, "PE11", Py_BuildValue("i", PE11));
    PyModule_AddObject(module, "PE12", Py_BuildValue("i", PE12));
    PyModule_AddObject(module, "PE13", Py_BuildValue("i", PE13));
    PyModule_AddObject(module, "PE14", Py_BuildValue("i", PE14));
    PyModule_AddObject(module, "PE15", Py_BuildValue("i", PE15));
    PyModule_AddObject(module, "PE16", Py_BuildValue("i", PE16));
    PyModule_AddObject(module, "PE17", Py_BuildValue("i", PE17));
    PyModule_AddObject(module, "PE18", Py_BuildValue("i", PE18));
    PyModule_AddObject(module, "PE19", Py_BuildValue("i", PE19));
    PyModule_AddObject(module, "PE20", Py_BuildValue("i", PE20));
    PyModule_AddObject(module, "PE21", Py_BuildValue("i", PE21));
    PyModule_AddObject(module, "PE22", Py_BuildValue("i", PE22));
    PyModule_AddObject(module, "PE23", Py_BuildValue("i", PE23));
    PyModule_AddObject(module, "PE24", Py_BuildValue("i", PE24));
    PyModule_AddObject(module, "PE25", Py_BuildValue("i", PE25));
    PyModule_AddObject(module, "PE26", Py_BuildValue("i", PE26));
    PyModule_AddObject(module, "PE27", Py_BuildValue("i", PE27));
    PyModule_AddObject(module, "PE28", Py_BuildValue("i", PE28));
    PyModule_AddObject(module, "PE29", Py_BuildValue("i", PE29));
    PyModule_AddObject(module, "PE30", Py_BuildValue("i", PE30));
    PyModule_AddObject(module, "PE31", Py_BuildValue("i", PE31));
    
    if(Py_AtExit(owl_gpio_cleanup) != 0){
        
        owl_gpio_cleanup();
        
#if PY_MAJOR_VERSION >= 3
        return NULL;
#else
        return;
#endif
    }

}

