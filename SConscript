# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/lsfData/SConscript,v 1.8 2008/09/19 15:30:23 glastrm Exp $
# Authors: Heather Kelly <heather@lheapop@gsfc.nasa.gov>
# Version: lsfData-04-03-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('lsfDataLib', depsOnly = 1)
lsfData = libEnv.SharedLibrary('lsfData', listFiles(['src/*.cxx']))

progEnv.Tool('lsfDataLib')
if progEnv['PLATFORM'] == 'win32':
    progEnv.AppendUnique(CPPDEFINES = ['__i386'])
test_lsfData = progEnv.Program('test_lsfData',[ 'src/test/test_lsfData.cxx'])
test_LSFReader = progEnv.Program('test_LSFReader',[ 'src/test/test_LSFReader.cxx'])
dumpEvent = progEnv.Program('dumpEvent', ['src/test/dumpEvent.cxx', 'src/test/LDFdump.cxx'])

progEnv.Tool('registerObjects', package = 'lsfData', libraries = [lsfData], testApps = [test_lsfData, test_LSFReader, dumpEvent], includes = listFiles(['lsfData/*.h']))
