# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/lsfData/SConscript,v 1.5 2008/07/31 04:31:00 glastrm Exp $
# Authors: Heather Kelly <heather@lheapop@gsfc.nasa.gov>
# Version: lsfData-04-01-00
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
