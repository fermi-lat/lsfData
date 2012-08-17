# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/lsfData/lsfDataLib.py,v 1.4 2009/08/25 23:24:21 jrb Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['lsfData'])
        if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
	    env.Tool('findPkgPath', package = 'lsfData') 
    env.Tool('eventFileLib')
    if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
        env.Tool('findPkgPath', package = 'enums') 
    # env.Tool('addLibrary', library = env['ldfLibs'])
def exists(env):
    return 1;
