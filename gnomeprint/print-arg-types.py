import argtypes

class GnomePrintReturnCodeArg(argtypes.IntArg):
    def write_return(self, ptype, ownsreturn, info):
        info.varlist.add('GnomePrintReturnCode', 'ret')
	info.codeafter.append('    if (pygnomeprint_check_error(ret))\n'
			      '        return NULL;\n'
			      '    Py_INCREF(Py_None);\n'
			      '    return Py_None;')

argtypes.matcher.register('GnomePrintReturnCode', GnomePrintReturnCodeArg())

