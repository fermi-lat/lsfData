# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/lsfData/SConscript,v 1.17 2012/01/21 00:13:31 jrb Exp $
# Authors: Heather Kelly <heather@lheapop@gsfc.nasa.gov>
# Version: lsfData-04-03-04
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='lsfData', toBuild='shared')
lsfData = libEnv.SharedLibrary('lsfData', listFiles(['src/*.cxx']))

progEnv.Tool('lsfDataLib')

if progEnv['PLATFORM'] == 'win32':
    progEnv.AppendUnique(CPPDEFINES = ['__i386'])

test_lsfData = progEnv.Program('test_lsfData',[ 'src/test/test_lsfData.cxx'])
test_lsfDataReader = progEnv.Program('test_lsfDataReader',
                                 ['src/test/test_LSFReader.cxx'])
#dumpEnv = progEnv.Clone()
#dumpEnv.Tool('addLibrary', library = dumpEnv['ldfLibs'])
#dumpEvent = dumpEnv.Program('dumpEvent',
#                            ['src/test/dumpEvent.cxx', 'src/test/LDFdump.cxx'])

progEnv.Tool('registerTargets', package = 'lsfData',
             libraryCxts = [[lsfData, libEnv]],
             testAppCxts =[[test_lsfData, progEnv],
                           [test_lsfDataReader, progEnv]],
             includes = listFiles(['lsfData/*.h']))




