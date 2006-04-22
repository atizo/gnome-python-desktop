import argtypes

class AttrList(argtypes.ArgType):
    def write_param(self, ptype, pname, pdflt, pnull, info):
        info.varlist.add('GnomeKeyringAttributeList *', pname)
        info.varlist.add('PyObject *', 'py_' + pname)
        info.add_parselist('O', ['&py_' + pname], [pname])
        info.codebefore.append(
            ("    %(pname)s = pygnome_keyring_attribute_list_from_pyobject(py_%(pname)s);\n")
            % vars())
        info.arglist.append(pname)
        info.codeafter.append("    gnome_keyring_attribute_list_free(%(pname)s);\n" % vars())

argtypes.matcher.register('GnomeKeyringAttributeList*', AttrList())

