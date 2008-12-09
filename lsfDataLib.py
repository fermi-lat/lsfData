# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/lsfData/lsfDataLib.py,v 1.1 2008/07/09 21:13:47 glastrm Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['lsfData'])
    env.Tool('eventFileLib')
    env.Tool('addLibrary', library = env['ldfLibs'])
def exists(env):
    return 1;
